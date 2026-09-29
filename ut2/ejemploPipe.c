#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd[2];
    char buffer[30];
    pid_t pid;

    pipe(fd);
    pid = fork();

    switch(pid) {
        case -1 : //ERROR
            printf("NO SE HA PODIDO CREAR HIJO...");
            exit(-1);
            break;
        case 0 : //HIJO
            printf("EL HIJO escribe en el pipe...\n");
            write(fd[1], "Hola papi", 10); //El hijo escribe en el pipe
            break;
        default : //PADRE
            wait(NULL);
            printf("EL PADRE lee del pipe...\n");
            read(fd[0], buffer, 10); // Guarda lo que ha leído del pipe en el buffer
            printf("\tMensaje leído: %s\n", buffer); //
            break;
    }
}