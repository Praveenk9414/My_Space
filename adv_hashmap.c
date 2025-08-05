#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;         // to accept string values too...
    int value;
    int is_occupied;
} HashEntry;

typedef struct {
    HashEntry* table;  // dynamically allocated array of entries
    int capacity;      // current size of the table
    int size;          // number of key-value pairs currently stored
} HashMap;

void init_map (HashMap *map){
    map->capacity = 8;
    map->size = 0;
    map->table = malloc(sizeof(HashEntry) * map->capacity);
    for (int i=0; i < map->capacity; i++){
        map->table[i].is_occupied = 0;
    }
}


unsigned int hash(const char *key, int capacity){    // Key is a read-only string pointer (content protected). Recommended for safety.
    unsigned long hash = 5381;                       // 5381 is a common "magic" number chosen for its statistical distribution properties in hash functions.
    int c;
    while ((c = *key++)){                           //  C automatically promotes char to int... breaks on '\0'.
        hash = ((hash << 5) + hash) + c;             // = (hash * 2^5) + hash = hash * 33 -> Multiplying by a prime number like 33 is known to work well for hashing.
    }
    return hash % capacity;
}

void resize(HashMap *map);

void insert(HashMap *map, char *key, int value){
    if ((float) map->size >= 0.7 * map->capacity){
        resize(map);
    }
    int index = hash(key, map->capacity);
    while(map->table[index].is_occupied){
        // to compare for duplicate keys ... 
        if (strcmp(map->table[index].key , key) == 0){
            map->table[index].value = value;         // updates the value
            return;
        }
        index = (index + 1) % map->capacity;         // why % map->cap here b/c if index = capacity-1 it will go out of bound for index+1.
    }

    map->table[index].key = strdup(key);
    map->table[index].value = value;
    map->table[index].is_occupied = 1;
    map->size ++;
}

void resize(HashMap *map){
    int old_capacity = map->capacity;
    map->capacity = 2 * old_capacity;

    // using HashEntry as HashEntry is a single node and the HashMap is the whole table(link list type)
    HashEntry *old_ptr = map->table;       // we want our final table to be in 'map' so old_ptr pointing to map

    map->table = malloc(sizeof(HashEntry)*map->capacity);   // new map->table

    // doing all the intiallization steps
    map->size = 0;
    for(int i=0; i < map->capacity; i++){
        map->table[i].is_occupied = 0;
    }

    // Re-insert all old keys
    for (int i=0; i < old_capacity ; i++){
        if (old_ptr[i].is_occupied){        // since old_table is now a plain array, not a HashMap so no -> old_table->table[i].is_oc
            insert(map, old_ptr[i].key, old_ptr[i].value);    // rehash and place it in the new table
            // If your value is not a pointer (e.g., int, float, bool) -> you do need to free()
            free(old_ptr[i].key);           // free old key
        }
    }

    free (old_ptr);
}

int get(HashMap *map, char *key){
    int index = hash(key, map->capacity);
    int start_index = index;
    
    while (map->table[index].is_occupied){
        if (strcmp(map->table[index].key, key) == 0){
            return map->table[index].value;
        }

        index = (index + 1) % map->capacity;
        if (index == start_index) break; // full loop key not found
    }
    return -1;
}

void delete_key(HashMap *map, char *key){
    int index = hash(key, map->capacity);
    int start_index = index;

    while (map->table[index].is_occupied){
        if (strcmp(map->table[index].key , key) == 0){
            free(map->table[index].key);
            map->table[index].key = NULL;
            map->table[index].value = 0;
            map->table[index].is_occupied = 0;
            map->size --;
            
            // After deleting a key, we must re-insert all subsequent entries in the same probe cluster.
            // This is necessary because linear probing relies on a continuous probe chain.
            // Deletion creates a gap, which can break the chain and cause future lookups to fail.

            index = (index + 1) % map->capacity;
            while(map->table[index].is_occupied){
                char *temp_key = map->table[index].key;
                int temp_value = map->table[index].value;

                // Clear before re-inserting
                map->table[index].key = NULL;
                map->table[index].value = 0;
                map->table[index].is_occupied = 0;
                map->size--;

                // Then reinsert
                insert(map, temp_key, temp_value);
                free(temp_key);

                index = (index + 1) % map->capacity;
            }
            return;  // EXIT after handling deletion and rehashing
        }

        index = (index + 1) % map->capacity;
        if (index == start_index) break;
    }
}

void print_map(HashMap *map){
    for(int i=0; i < map->capacity; i++){
        if (map->table[i].is_occupied){
            printf("Slot %d: %s -> %d\n", i, map->table[i].key, map->table[i].value);
        }
    }
}

void destroy_map(HashMap *map){
    for (int i=0; i < map->capacity; i++){
        if (map->table[i].is_occupied){
            free(map->table[i].key);
        }
    }
    free(map->table);
}

int main() {
    HashMap map;
    init_map(&map);

    // Insert some key-value pairs
    insert(&map, "apple", 10);
    insert(&map, "banana", 20);
    insert(&map, "orange", 30);
    insert(&map, "grape", 40);

    printf("Initial Map:\n");
    print_map(&map);
    printf("\n");

    // Try getting a value
    printf("Value for key 'banana': %d\n", get(&map, "banana"));

    // Delete a key
    delete_key(&map, "banana");

    printf("Map after deleting 'banana':\n");
    print_map(&map);
    printf("\n");

    // Try getting deleted key
    int val = get(&map, "banana");
    if (val == 0) {
        printf("'banana' not found in map.\n");
    }

    // Insert more to trigger resize
    insert(&map, "kiwi", 50);
    insert(&map, "mango", 60);
    insert(&map, "lemon", 70);
    insert(&map, "peach", 80);
    insert(&map, "pear", 90);

    printf("Map after inserting more keys:\n");
    print_map(&map);
    printf("\n");

    // Clean up
    destroy_map(&map);

    return 0;
}
