#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20


int main()
{
    char seguir='s';
    int opcion=0;
    int auxIndice;
    int auxInt;
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
                    auxInt = pedirDatos(&edad, &dni , nombre);
                    if(auxInt == 0)
                    {
                        personas[auxIndice] = cargarPersona(edad, dni, nombre);
                        isEmpty = 0;
                    }
                    else
                    {
                        printf("No se han cargado los datos\n");
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
                    auxInt = getInt(&dni, "Ingrese el DNI de la persona a borrar: ", "ERROR: Ingrese el DNI sin .\n", 3,99999999);
                    if(auxInt != -1)
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
