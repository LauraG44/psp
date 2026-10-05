#include <unistd.h>     // para read, close
#include <fcntl.h>      // para open
#include <sys/types.h>  // para mkfifo (Tipos de archivo)
#include <sys/stat.h>   // para mkfifo (permisos)
#include <stdio.h>      // para printf
#include <stdlib.h>
#include <errno.h>

int main()
{
    int fp, p, bytesleidos;
    char buffer[2];
    int turno_carniceria = 0;
    int turno_pescaderia = 0;

    // Crear el FIFO con permisos de lectura y escritura
    p = mkfifo("FIFOCarrefour", S_IFIFO|0666);

    /*Se comprueba si el FIFO se ha creado correctamente,
    si el archivo ya existe no quiero que me salte error, así que añado el filtro*/
    if(p==-1 && errno != EEXIST)
    {
        printf("Ha ocurrido un error al crear el FIFO...\n");
        exit(0);
    }

    while(1)
    {
        // Se abre en modo solo lectura
        fp = open("FIFOCarrefour", 0);
        // Si ocurre un error al abrir el FIFO maneja
        if (fp == -1) {
            perror("Error al abrir el FIFO");
            exit(1);
        }

        // Lee el primer caracter del mensaje
        bytesleidos = read(fp, buffer, 1);
        // Si el mensaje contiene algo se entra al if
        if (bytesleidos > 0)
        {
            // Dependiendo del mensaje incrementamos
            if (buffer[0] == 'C') {
                turno_carniceria++;
                printf("OBTENIENDO Información...Carnicería:\n");
                printf("Turno: %d\n", turno_carniceria);
            }
            else if (buffer[0] == 'P') {
                turno_pescaderia++;
                printf("OBTENIENDO Información...Pescadería:\n");
                printf("Turno: %d\n", turno_pescaderia);
            }
            // Leemos el buffer para vaciarlo
            while(bytesleidos != 0)
            {
                bytesleidos = read(fp, buffer, 1);
            }
        }
        close(fp);
    }
    return 0;
}