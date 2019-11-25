#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char alumno[50];
    int nota;
}eParcial;
//EJERCICIO 1
eParcial* new_Parcial();
eParcial* new_Parcial_Param(int, char[50], int);


//EJERCICIO 2
int guardarBinario(char* path, eParcial* miParcial);

//EJERCICIO 3

/*---- Ejercicio 1----*/
void Ejercicio1_A();
void Ejercicio1_B();

/*---- Ejercicio 2---*/
void Ejercicio2_B();

int main()
{
    /****************PRIMER TEST**********/
    Ejercicio1_A();
    Ejercicio1_B();
    return 0;
}


eParcial* new_Parcial()
{
    eParcial* Parcial =  malloc(sizeof(eParcial));
    return Parcial;
}

eParcial* new_Parcial_Param(int id, char alumno[50], int nota)
{
    eParcial* Parcial = malloc(sizeof(eParcial));
    Parcial->id = id;
    strcpy(Parcial->alumno, alumno);
    Parcial->nota = nota;
    return Parcial;
}

void Ejercicio1_A()
{
   int idTest = 42;
    char alumnoTest[50];
    strcpy(alumnoTest, "Robertito");
    int notaTest = 2;
    eParcial* nuevoParcial = new_Parcial();
    strcpy(nuevoParcial->alumno, alumnoTest);
    nuevoParcial->id = idTest;
    nuevoParcial->nota = notaTest;
    printf("\nCodigo: %d --> Alumno: %s --> Nota: %d ", nuevoParcial->id, nuevoParcial->alumno, nuevoParcial->nota);
    guardarBinario("Prueba1.dat", nuevoParcial);
}
void Ejercicio1_B()
{
    int idTest = 74;
    char alumnoTest[50];
    strcpy(alumnoTest, "Martincho");
    int notaTest = 7;
    eParcial* nuevoParcial = new_Parcial_Param(idTest, alumnoTest, notaTest);
    printf("\nCodigo: %d --> Alumno: %s --> Nota: %d ", nuevoParcial->id, nuevoParcial->alumno, nuevoParcial->nota);
    guardarBinario("Prueba2.dat", nuevoParcial);
}

int guardarBinario(char* path, eParcial* miParcial)
{
    FILE * ArchivoBinario;
    ArchivoBinario = fopen(path, "wb+");
    if(ArchivoBinario != NULL)
    {
        //fprintf(ArchivoBinario, "Codigo: %d ---> Alumno: %s ---> Nota: %d", miParcial->id, miParcial->alumno, miParcial->nota);
        fwrite(miParcial, sizeof(miParcial), 1, ArchivoBinario);
              // fwrite(&miParcial->id, sizeof(int), 4, ArchivoBinario);
       // fwrite(&miParcial->id, sizeof(int), 4, ArchivoBinario);
        fclose(ArchivoBinario);
    }
    else
    {
        printf("\nNo se pudo leer el archivo en la ruta especificada.\n");
    }
}
