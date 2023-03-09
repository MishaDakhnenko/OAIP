#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char min_word[100] = "";
    int min_length = 100;
    char delim[] = " ,.!?\n";

    printf("vvedite stroku : ");
    fgets(str, 100, stdin);

   printf("samoe korotkoe slovo : ");
    char *fword = strtok(str, delim);
    while (fword != NULL) {
        int length = strlen(fword);
        if (length < min_length) {
            min_length = length;
            strcpy(min_word, fword);
        }
        fword = strtok(NULL, delim);
    }

    printf("%s\n", min_word[0] ? min_word : "v stroke net slov ");

    return 0;
}