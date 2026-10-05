#include <stdio.h>
#include <string.h>
#include <fcntl.h> // para open
#include <unistd.h> // para read, close
#include <stdlib.h> // para exit
int main()
{
    int fp;
    char mensaje[] = "P\n";
    fp = open("FIFOCarrefour", 1);

    if(fp == -1) {
        printf("ERROR AL ABRIR EL FICHERO...");
        exit(1);
    }
    printf("Mandando información al FIFO...\n");
    write(fp, mensaje, strlen(mensaje));
    close(fp);
    return(0);
}