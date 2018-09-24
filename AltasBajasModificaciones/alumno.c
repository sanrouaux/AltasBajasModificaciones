#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

void inicializaAlumnos(eAlumno listado[]) // Permite que haya datos cargados cuando iniciamos el programa
{
    int legajo[3] = {1234,6576,7889};
    char nombre[3][21] = {Juan, Maria, Pedro};
    int nota[3] = {2,5,9};
    float altura[3] = {1.56, 1.78, 1.9};

    int i;
    for(i = 0, i < 3; i++)
    {
        listado[i].legajo = legajo[i];
        listado[i].nombre = nombre[i];
        listado[i].nota = nota[i];
        listado[i].altura = altura[i];
        listado[i].estado = 1;
    }

}



void inicializaLista(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listado[i].estado = VACIO;
    }
}


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
    alumnoCarga.estado = OCUPADO;

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


void cargarAlumnosAleatoriamente(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listado[i].estado = -1;
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


int buscaEspacioLibre(eAlumno listado[], int tam)
{
    int indice = -1;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].estado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void cargarAlumnosEspaciosLibres(eAlumno listado[], int tam)
{
    int indice;
    indice = buscaEspacioLibre(listado, tam);

    if(indice != -1)
    {
        listado[indice] = cargarAlumno();
    }
    else
    {
        printf("Ya no hay espacio");
    }
}


void imprimirListaDeAlumnos(eAlumno listaAlumnos[], int tam)
{
    printf("\nLEGAJO     NOMBRE   NOTA     ALTURA\n");
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaAlumnos[i].estado != VACIO)
        {
            imprimirAlumno(listaAlumnos[i]);
        }

    }
}


int menuOpciones()
{
    int opcion;
    printf("\n\nMENU DE OPCIONES \n");
    printf("1. Dar de alta a un alumno \n");
    printf("2. Ver listado de alumnos \n");
    printf("3. Ordenar alfabeticamente \n");
    printf("4. Ver alumnos aprobados \n");
    printf("5. Ver alumnos cuyos nombres comienzan con p \n");
    printf("6. Ver alumnos con la nota mas alta \n");
    printf("7. Modificar una nota \n");
    printf("8. Salir \n");
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
    int nuevaNota;
    char confirma;
    int bandera = 0;

    printf("Ingrese el legajo del alumno: ");
    scanf("%d", &legajo);

    int i;
    for(i = 0; i< tam; i++)
    {
        if(listado[i].estado != VACIO && listado[i].legajo == legajo)
        {
            printf("Se encontro al alumno: %s \n", listado[i].nombre);
            printf("Ingrese la nueva nota: ");
            scanf("%d", &nuevaNota);

            printf("Esta seguro que desea cambiar la nota? s/n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                listado[i].nota = nuevaNota;
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
