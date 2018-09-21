#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#define T 10


int main()
{
    eAlumno listaDeAlumnos[T];

    int i;
    for(i = 0; i < T; i++)
    {
        listaDeAlumnos[i].nota = -1;
    }


    int opcion;

    do
    {
        opcion = menuOpciones();

        switch(opcion)
        {

        case 1:
            cargarAlumnosEspaciosLibres(listaDeAlumnos, T);
            break;

        case 2:
            imprimirListaDeAlumnos(listaDeAlumnos, T);
            break;

        case 3:
            ordenarAlfabeticamente(listaDeAlumnos, T);
            imprimirListaDeAlumnos(listaDeAlumnos, T);
            break;

        case 4:
            mostrarAlumnosAprobados(listaDeAlumnos, T);
            break;

        case 5:
            mostrarAlumnosConP(listaDeAlumnos, T);
            break;

        case 6:
            mostrarAlumnosNotaMasAlta(listaDeAlumnos, T);
            break;

        case 7:
            modificarNota(listaDeAlumnos, T);
            break;

        case 8:
            break;

        default:
            printf("Version de prueba. Elegi opciones 1, 2 o 3");
        }
    }
    while(opcion != 8);


    return 0;
}
