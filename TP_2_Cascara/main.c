#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20


int main()
{
    char seguir='s';
    int opcion=0;
    int auxIndice;
    int auxInt[3];
    int edad;
    int dni;
    char nombre[50];
    int isEmpty = 1;
    EPersona personas[MAX];

    initArray(personas, MAX);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                auxIndice =obtenerEspacioLibre(personas, MAX);
                if(auxIndice != -1)
                {
                    auxInt[0] = getName(nombre, "Ingrese su nombre: ", "ERROR: solo se permiten letras\n", 2, 50);
                    auxInt[1] = getInt(&edad,"Ingrese su edad: ", "ERROR: solo se permiten numeros entre 2 y 99\n", 2,99);
                    auxInt[2] = getInt(&dni,"Ingrese su DNI: ", "ERROR: Ingrese el DNI sin .\n", 3,99999999);
                    if(auxInt[0] != 0 || auxInt[1] != 0 || auxInt[2] != 0)
                    {
                        printf("No se han cargado los datos\n");
                    }
                    else
                    {
                        personas[auxIndice] = cargarPersona(edad, dni, nombre);
                        isEmpty = 0;
                    }
                }
                else
                {
                    printf("No hay mas lugar!\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                if(isEmpty== 0)
                {
                    auxInt[0] = getInt(&dni, "Ingrese el DNI de la persona a borrar: ", "ERROR: Ingrese el DNI sin .\n", 3,99999999);
                    if(auxInt[0] != -1)
                    {
                        auxIndice = buscarPorDni(personas, MAX, dni);
                        if(auxIndice != -1)
                        {
                            borrarPersona(personas, auxIndice);
                        }
                        else
                        {
                            printf("No existe nadie con ese DNI\n");
                        }
                    }
                }
                else
                {
                    printf("No se puede borrar nada\nRegistro vacio!\n");
                }
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                ordenarPorNombre(personas, MAX);
                printf("Nombre\t\tEdad\t\tDNI\n");
                mostrarPersonas(personas, MAX);
                system("pause");
                system("cls");
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;

        }
    }

    return 0;
}
