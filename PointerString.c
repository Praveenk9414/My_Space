// task to add alternate words in the sequence and add the remaining using string pointers
//  abc  & defg -> a d b e c f g

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *word1 = "b";
    char *word2 = "f";   

    int len = strlen(word1) + strlen(word2);

    char *str = malloc(sizeof(char)*(len+1));  // heap allocation
    int i=0;
    while(word1[0]!='\0' && word2[0]!='\0'){
        if (i%2==0){
            str[i] = word1[0];
            word1++;
        }else{
            str[i] = word2[0];
            word2++;
        }
        i++;
    }
    while(word1[0]!='\0'){
        str[i] = word1[0];
        word1++;
        i++;
    }
    while(word2[0]!='\0'){
        str[i] = word2[0];
        word2++;
        i++;
    }
    str[i] = '\0';
    char *p = str;

    printf("%s\n", p);
    printf("%s\n", str);
}
