#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    char  buffer[30];
    pid_t pid;

    if (pipe(fd) == -1){ //Se comprueba si se ha creado el pipe correctamente
        printf("Ha ocurrido un error al crear el pipe.");
        exit(-1);
    }

    pid = fork();

    switch(pid) {
        case -1 : //Fork ha dado error
            printf("Ha ocurrido un error al crear el proceso.");
            exit(-1);
        case 0 : //HIJO
            close(fd[1]); //Se cierra el descriptor de escritura, porque no se va a usar
            read(fd[0], buffer, sizeof(buffer) - 1 ); //Se pone -1 para guardar la última posición para el carácter NULL
            printf("EL HIJO recibe algo del pipe: %s.\n", buffer);
            close(fd[0]); //En este caso cierro el descriptor para liberar recursos, aunque al terminar el proceso se cerraría también el descriptor
            break;
        default : //PADRE
            close(fd[0]); //Se cierra el descriptor de lectura porque no se va a usar
            printf("EL PADRE envía algo al pipe.\n");
            write(fd[1], "Buenos días hijo", 17); //El padre escribe en pipe
            close(fd[1]); //Cierro el descriptor de escritura para evitar que el proceso Hijo pueda bloquearse
            wait(NULL); //Espera a que el Hijo termine ya que el Padre ya ha escrito en el pipe
            break;
    }
return 0;
}