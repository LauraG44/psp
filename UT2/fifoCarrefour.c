#include <unistd.h> // para read, close
#include <fcntl.h> // para open
#include <sys/types.h> // para mkfifo (Tipos de archivo)
#include <sys/stat.h> //para mkdfifo (permisos)
#include <stdio.h> //para printf
#include <std.lib> //

int main()
{
    int fp, p, bytesleidos;
    char message[] = ;

    // le doy permiso de lectura y escritura
    p = mkfifo("FIFOCarrefour", S_IFIFO|0666);

    if(p==-1)
    {
        printf("Ha ocurrido un error...\n");
        exit(0);
    }

    while(1)
    {
        fp = open("FIFOCarrefour",0);
        bytesleidos = read(fp, buffer, 1);
        printf("Obteniendo información..."
        }
}