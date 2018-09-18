#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"
#define T 3


int main()
{
    eAlumno listaDeAlumnos[T];
    cargarListaDeAlumnos(listaDeAlumnos, T);
    imprimirListaDeAlumnos(listaDeAlumnos, T);

    int opcion;

    do
    {
        opcion = menuOpciones();

        switch(opcion)
        {
        case 1:
            ordenarAlfabeticamente(listaDeAlumnos, T);
            imprimirListaDeAlumnos(listaDeAlumnos, T);
            break;

        case 2:
            mostrarAlumnosAprobados(listaDeAlumnos, T);
            break;

        case 3:
            mostrarAlumnosConP(listaDeAlumnos, T);
            break;

        /*   case 4:
        //alumnos con mayor nota
               break;


           case 5:
        //permite modificar una nota
               break;*/


           case 6:
               break;

            default:
                printf("Version de prueba. Elegi opciones 1, 2 o 3");
        }
    }
    while(opcion != 6);


    return 0;
}
