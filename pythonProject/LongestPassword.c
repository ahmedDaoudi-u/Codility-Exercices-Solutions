#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_valid_password(char *word) {
    int letters = 0, digits = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isalpha(word[i])) {
            ++letters;
        } else if (isdigit(word[i])) {
            ++digits;
        } else {
            return 0; // contains a non-alphanumeric character
        }
    }
    return (letters % 2 == 0) && (digits % 2 == 1);
}

int solution(char *S) {
    int max_string  = - 1 ;

    char *word = strtok(S, " ");

    while (word!= NULL){
        if (is_valid_password(word)){
            int longe = strlen(word);
            if (longe > max_string){
                max_string = longe;
            }
        }
        word = strtok(NULL, " ");
    }
    return max_string;

}