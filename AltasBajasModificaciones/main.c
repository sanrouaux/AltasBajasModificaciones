#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#define T 10


int main()
{
    eAlumno listaDeAlumnos[T];
    inicializaEstadoVacio(listaDeAlumnos, T);
    cargaDatosAlumnos(listaDeAlumnos);

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
            bajaAlumno(listaDeAlumnos, T);
            break;

        case 9:
            break;

        default:
            printf("Elija una opcion valida");
        }
        system("pause");
        system("cls");
    }
    while(opcion != 9);


    return 0;
}
