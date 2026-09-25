#include <stdio.h>

/*
 * Una enumeración asigna valores enteros a nombres; no almacena cadenas de
 * texto. Si queremos imprimir el nombre asociado a un valor, usamos un array
 * de cadenas y el valor de la enumeración como índice.
 *
 * C asigna 0 al primer elemento de cada enumeración y aumenta el valor en 1
 * para cada elemento siguiente. Por ejemplo, Perro vale 0 y Gato vale 1.
 *
 * Por eso, el orden de los elementos de los arrays mascotas y dias debe
 * coincidir con el orden de las enumeraciones animales y dia. Así, Perro
 * selecciona mascotas[0] ("perro") y Sabado selecciona dias[5] ("sabado").
 */
enum animales { Perro, Gato, Loro, Tortuga, Periquito, Hamster };
enum dia { Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo };

// La definición de una estructura termina con `};`: el punto y coma va después de la llave de cierre.
struct Persona{
char *nombre;
int edad;
enum animales mascota_propia;
enum dia dia_favorito;
};

/*
 * Conviene elegir nombres claros porque aquí aparecen identificadores
 * parecidos en contextos distintos:
 *
 *   dia          es la etiqueta de la enumeración: enum dia
 *   dia_favorito es un miembro de la estructura Persona
 *   dias         es un array local de cadenas de texto
 *
 * El miembro dia_favorito tiene como tipo enum dia:
 *
 *   enum dia dia_favorito;
 *
 * Para acceder a ese miembro desde una estructura se usa el operador punto:
 *
 *   Miguel.dia_favorito
 */

int main (void){
    struct Persona Miguel, Monica;

    const char *mascotas[] = { "perro", "gato", "loro", "tortuga", "periquito", "hamster" };
    const char *dias[] = { "lunes", "martes", "miécoles", "jueves", "viernes", "sábado", "domingo" };

    Miguel.nombre = "Miguel";
    Miguel.edad = 41;
    Miguel.mascota_propia = Perro;
    Miguel.dia_favorito = Lunes;

    Monica.nombre = "Monica";
    Monica.edad = 36;
    Monica.mascota_propia = Gato;
    Monica.dia_favorito = Sabado;

    printf("\nEl nombre de él es %s y su edad es %d.\n\t %s tiene un %s y su día favorito es el %s.\n ",
                                    Miguel.nombre, Miguel.edad, Miguel.nombre, mascotas[Miguel.mascota_propia], dias[Miguel.dia_favorito]);
    printf("El nombre de ella, es %s y su edad es %d\n\t %s tiene un %s y su día favorito es el %s.\n ",
                                    Monica.nombre, Monica.edad, Monica.nombre, mascotas[Monica.mascota_propia], dias[Monica.dia_favorito]);

    return 0;
}
