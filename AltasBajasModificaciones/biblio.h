//-----DEFINICION DE ESTRUCTURAS-----//
typedef struct
{
    int legajo;
    char nombre[21];
    int nota;
    float altura;
} eAlumno;


//----PROTOTIPO FUNCIONES---//
eAlumno cargarAlumno();
void imprimirAlumno(eAlumno);
void cargarListaDeAlumnos(eAlumno[], int);
void imprimirListaDeAlumnos(eAlumno[], int);
int menuOpciones();
void ordenarAlfabeticamente(eAlumno[], int);
void mostrarAlumnosAprobados(eAlumno[], int);
void mostrarAlumnosConP(eAlumno[], int);



