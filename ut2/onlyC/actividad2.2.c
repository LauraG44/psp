#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int num = 10;
    printf("Valor incial de la variable: %d\n", num);

    pid_t pid = fork();

    if (pid == -1){ //Error al crear el proceso
        printf("Ha ocurrido un error al crear el proceso.");
        return 1;
    } else if (pid == 0){ //Estamos en Proceso Hijo
        num -= 5; //Se actualiza la variable SOLO en el Proceso Hijo
        printf("Variable en Proceso Hijo: %d\n", num);
    } else { //Estamos en Proceso Padre
        wait(NULL); //Espera a que termine el proceso hijo
        num += 5; //Se actualiza la variable SOLO en el Proceso Padre
        printf("Variable en Proceso Padre: %d\n", num);
    }
    return 0;
}