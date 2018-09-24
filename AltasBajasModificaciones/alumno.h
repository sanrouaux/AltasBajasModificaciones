#define OCUPADO 1
#define VACIO -1


//-----DEFINICION DE ESTRUCTURAS-----//
typedef struct
{
    int legajo;
    char nombre[21];
    int nota;
    float altura;
    int estado;
} eAlumno;


//----PROTOTIPO FUNCIONES---//
void inicializaAlumnos(eAlumno[]);
void inicializaLista(eAlumno[], int);
eAlumno cargarAlumno();
void imprimirAlumno(eAlumno);
void cargarListaDeAlumnosSecuencial(eAlumno[], int);
void cargarAlumnosAleatoriamente(eAlumno[], int);
int buscaEspacioLibre(eAlumno[], int);
void cargarAlumnosEspaciosLibres(eAlumno[], int);
void imprimirListaDeAlumnos(eAlumno[], int);
int menuOpciones();
void ordenarAlfabeticamente(eAlumno[], int);
void mostrarAlumnosAprobados(eAlumno[], int);
void mostrarAlumnosConP(eAlumno[], int);
void mostrarAlumnosNotaMasAlta(eAlumno[], int);
void modificarNota(eAlumno[], int);
int



