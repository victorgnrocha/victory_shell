#include <stdio.h>
#include <string.h>

//Definindo o macro do buffer_size
#define MAX_INPUT 1024
#define MAX_ARGS 64

int main ()
{
    //input com tamanho do buffer
    char input[MAX_INPUT];

    //ponteiro de strings
    char *args[MAX_ARGS];

    //loop infinito
    while(1) {
        printf("shell> ");
        fflush(stdout);

        //Se fgets, funcao de chamar inputs como o scanf
        // receber
        if(fgets(input, MAX_INPUT, stdin) == NULL) {
            perror("fgets failed");
            continue;
        }
        //Remove a quebra de linha.
        input[strcspn(input, "\n")] = '\0';

        //Se o comando for exit, ele automaticamente sai e exibe
        // a imagem de saida.
        if(strcmp(input, "exit") == 0){
            printf("Tenha um bom dia.");
            break;
        }

        char *token = strtok(input, " ");


        printf("%s", input);

    }
    return 0;
}
