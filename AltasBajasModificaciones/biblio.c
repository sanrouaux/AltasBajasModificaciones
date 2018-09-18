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


void cargarListaDeAlumnosSecuencial(eAlumno listaAlumnos[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listaAlumnos[i] = cargarAlumno();
    }
}

void cargarListadeAlumnosAleatoria(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listado[i].nota = -1;
    }

    int subindice;
    char confirmacion;
    char seguir;

    do
    {
        printf("En que posicion desea cargar al alumno? ");
        scanf("%d", &subindice);
        while(subindice < 0 || subindice > tam -1)
        {
            printf("Error. La posicion no existe. Ingrese una posicion valida: ");
            scanf("%d", &subindice);
        }

        if(listado[subindice].nota == -1)
        {
            listado[subindice] = cargarAlumno();
        }
        else
        {
            printf("El lugar elegido ya fue utilizado. Desea reemplazarlo?");
            fflush(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's')
            {
                listado[subindice] = cargarAlumno();
            }
        }

        printf("Desea realizar otra carga? s/n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    while(seguir == 's');
}


void imprimirListaDeAlumnos(eAlumno listaAlumnos[], int tam)
{
    printf("\nLEGAJO     NOMBRE   NOTA     ALTURA\n");
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


void mostrarAlumnosNotaMasAlta(eAlumno listado[], int tam)
{
    int notaMasAlta;
    notaMasAlta = listado[0].nota;

    int i;
    for(i = 1; i < tam; i++)
    {
        if(listado[i].nota > notaMasAlta)
        {
            notaMasAlta = listado[i].nota;
        }
    }

    printf("ALUMNOS QUE OBTUVIERON LA NOTA MAS ALTA: \n");

    for(i = 0; i < tam; i++)
    {
        if(listado[i].nota == notaMasAlta)
        {
            printf("%s \n", listado[i].nombre);
        }
    }
}


void modificarNota(eAlumno listado[], int tam)
{
    int legajo;
    printf("Ingrese el legajo del alumno: ");
    scanf("%d", &legajo);
    int nota;
    char respuesta;
    int bandera = 0;

    int i;
    for(i = 0; i< tam; i++)
    {
        if(listado[i].legajo == legajo)
        {
            printf("Se encontro al alumno: %s \n", listado[i].nombre);
            printf("Ingrese la nueva nota: ");
            scanf("%d", &nota);

            printf("Esta seguro que desea cambiar nota? s/n");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
            {
                listado[i].nota = nota;
                printf("La nota ha sido cambiada");
            }
            else
            {
                printf("No se realizo el cambio de nota");
            }
            bandera = 1;
            break;
        }
    }
    if(bandera == 0)
    {
        printf("No se encontro un alumno con legajo %d", legajo);
    }
}
