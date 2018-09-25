#define OCUPADO 1
#define VACIO 0


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
void inicializaEstadoVacio(eAlumno[], int);
void cargaDatosAlumnos(eAlumno[]);
int menuOpciones();
eAlumno cargarAlumno();
void imprimirAlumno(eAlumno);
void cargarListaDeAlumnosSecuencial(eAlumno[], int);
void cargarAlumnosAleatoriamente(eAlumno[], int);
int buscaEspacioLibre(eAlumno[], int);
void cargarAlumnosEspaciosLibres(eAlumno[], int);
void imprimirListaDeAlumnos(eAlumno[], int);
void ordenarAlfabeticamente(eAlumno[], int);
void mostrarAlumnosAprobados(eAlumno[], int);
void mostrarAlumnosConP(eAlumno[], int);
void mostrarAlumnosNotaMasAlta(eAlumno[], int);
void modificarNota(eAlumno[], int);
void bajaAlumno(eAlumno[], int);



