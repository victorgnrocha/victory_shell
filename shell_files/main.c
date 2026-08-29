#include <stdio.h>

//Definindo o macro do buffer_size
#define MAX_INPUT 1024

int main ()
{
    char input[MAX_INPUT];
    //loop infinito
    while(1) {
        printf("shell> ");
        fflush(stdout);

        if(fgets(input, MAX_INPUT, stdin) == NULL) {
            perror("fgets failed");
            continue;
        }
    }
    return 0;
}
