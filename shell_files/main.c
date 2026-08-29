#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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

        //declara um ponteiro de caracteres que recebe como conteudo
        // uma string dividida pelo espaço
        char *token = strtok(input, " ");
        int i = 0;
        printf("%s Token:", token);

        //separa a string sem espaço em diversas strings
        while(token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        //O pid_type é um tipo de dado tal como int, char, float
        // usado em s.o's para poder representar o identificador numerico
        // de um projeto
        pid_t pid = fork();
        //O fork clona o processo filho, fazendo com que ele receba o numero de
        // identificaçao do processo em questão

        //Se o pid for > 0, o que deve acontecer para praticamente todas as situações
        //em que um processo exista no computador
        // ele executa no sistema através da funcao execvp(nome/caminho_do_executável,
        // strings que contém os argumentos do programa que vai ser executado.)
        if (pid == 0) {
            execvp(args[0], args);
            //Erro no caso da execuçao falhar.
            perror("execvp failed");
            //E então ele sai como exit_failure
            exit(EXIT_FAILURE);
        }else if (pid > 0) {
            printf("%d\n", pid);
            int status;
            waitpid(pid, &status, 0);
            printf("Exist status %d\n", status);
        } else {
            perror("Fork failed");
        }

        printf("%s\n", input);
    }
    return 0;
}
