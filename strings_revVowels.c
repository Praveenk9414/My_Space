#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "AceCreIm";
    char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowel_len = sizeof(vowel)/sizeof(char);

    int len = strlen(s);
    char vowel_present[len];
    int i,j,v;
    v=0;
    for (i=len-1; i>=0; i--){
        for (j=0; j<vowel_len; j++){
            if (s[i] == vowel[j]){
                vowel_present[v] = s[i];
                v++;
                break;
            }
        }
    }
    int v_index = 0;
    for (i=0; i<len; i++){
        for (j=0; j<vowel_len; j++){
            if (s[i] == vowel[j]){
                s[i] = vowel_present[v_index++];
                break;
            }
        }
    }
    printf("%s", s);
}