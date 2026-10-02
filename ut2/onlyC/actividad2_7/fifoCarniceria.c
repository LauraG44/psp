#include <stdio.h>

#include <string.h>
#include <fcntl.h> // para open
#include <unistd.h> // para read, close
int main()
{
    int fp;
    char mensaje[] = "C\n";
    fp = open("FIFO", 1);

    if(fp == -1) {
        printf("ERROR AL ABRIR EL FICHERO...");
        exit(1);
    }
    printf("Mandando información al FIFO...\n");
    write(fp, mensaje, strlen(saludo));
    close(fp);
    return(0);
}