#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 26

// since we are not using this struct as linklist(self-ref) thing so we donot need to write ->
//     like this...  typedef struct hashmap ... the following one works 
typedef struct  {
    char key;         // The character key (e.g., 'a', 'b', ...)
    int value;        // The value you associate with that key
    int is_occupied;  // 1 if this slot is used, 0 if not
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
} HashMap;

// initializing the hash map
void init_map(HashMap *map){
    for (int i=0; i < TABLE_SIZE; i++){
        map->table[i].is_occupied = 0;
    }
}

// our basic hash function just to store the 26 alphabet characters
int hash(char key){
    return key - 'a'; // if the key is ascii 'c'->99, 'a'->97, so 99 - 97 = 2
}

void insert(HashMap *map, char key){
    int index = hash(key);
    if (!map->table[index].is_occupied || map->table[index].key == key){
        map->table[index].key = key;
        map->table[index].value = index;
        map->table[index].is_occupied = 1;
    }else{
        printf("Collision has occured at index %d for key '%c'\n", index, key);
    }
}

// this gets us the value of the key
int get(HashMap *map, char key){
    int index = hash(key);
    if (map->table[index].is_occupied){
        return map->table[index].value;
    }else{
        return -1;
    }
}

// traverse the hashtable
void print_map(HashMap *map){
    for(int i=0; i<TABLE_SIZE; i++){
        if (map->table[i].is_occupied){
            printf("%c -> %d\n", map->table[i].key, map->table[i].value);
        }
    }
}

void delete_key(HashMap *map, char key){
    int index = hash(key);
    if (map->table[index].is_occupied){
        map->table[index].is_occupied = 0;
        map->table[index].key = '\0';   // optional
        map->table[index].value = 0;    // optional
    }
}

int main(){
    HashMap *map = malloc(sizeof(HashMap));
    init_map(map);

    insert(map, 'c');
    insert(map, 'd');
    insert(map, 'g');

    printf("Value for 'c': %d\n", get(map, 'c'));

    delete_key(map, 'c');

    print_map(map);

    free(map);
}