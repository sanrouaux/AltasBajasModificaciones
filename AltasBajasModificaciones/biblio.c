#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


eAlumno cargarAlumno()
{
    eAlumno alumnoCarga;
    printf("Ingrese numero de legajo: ");
    scanf("%d", &alumnoCarga.legajo);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(alumnoCarga.nombre);
    printf("Ingrese la nota: ");
    scanf("%d", &alumnoCarga.nota);
    printf("Ingrese la altura: ");
    scanf("%f", &alumnoCarga.altura);

    return alumnoCarga;
}


void imprimirAlumno(eAlumno miAlumno)
{
    printf("%6d %10s %6d % f8\n", miAlumno.legajo, miAlumno.nombre, miAlumno.nota, miAlumno.altura);
}


void cargarListaDeAlumnos(eAlumno listaAlumnos[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listaAlumnos[i] = cargarAlumno();
    }
}


void imprimirListaDeAlumnos(eAlumno listaAlumnos[], int tam)
{
    printf("\nLEGAJO     NOMBRE   NOTA    ALTURA\n");
    int i;
    for(i = 0; i < tam; i++)
    {
        imprimirAlumno(listaAlumnos[i]);
    }
}

int menuOpciones()
{
    int opcion;
    printf("\n\nMENU DE OPCIONES \n");
    printf("1. Ordenar alfabeticamente \n");
    printf("2. Ver alumnos aprobados \n");
    printf("3. Ver alumnos cuyos nombres comienzan con p \n");
    printf("4. Alumnos con mayor nota \n");
    printf("5. Modificar una nota \n");
    printf("6. Salir \n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void ordenarAlfabeticamente(eAlumno listadoAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno aux;

    for(i = 1; i < tam; i++)
    {
        j = i-1;
        aux = listadoAlumnos[i];
        while(j>=0 && strcmp(listadoAlumnos[j].nombre, aux.nombre)>0)
        {
            listadoAlumnos[j+1] = listadoAlumnos[j];
            j--;
        }
        listadoAlumnos[j+1]= aux;
    }
}


void mostrarAlumnosAprobados(eAlumno listado[], int tam)
{
    printf("ALUMNOS APROBADOS: \n");

    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].nota > 6)
        {
            printf("%s \n", listado[i].nombre);
        }
    }
}

void mostrarAlumnosConP(eAlumno listado[], int tam)
{
    printf("ALUMNOS CUYOS NOMBRES EMPIEZAN CON P: \n");

    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].nombre[0] == 'p')
        {
            printf("%s \n", listado[i].nombre);
        }
    }
}
