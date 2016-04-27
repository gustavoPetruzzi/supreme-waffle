#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"


void initArray( EPersona lista[],int cantidadItems)
{
    int i;
    for(i=0; i<cantidadItems; i++)
    {
        lista[i].estado = 0;
    }
}


int obtenerEspacioLibre(EPersona lista[],int cantidadItems)
{
    int index = -1;
    int i;

    for(i= 0; i<cantidadItems; i++)
    {
        if(lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int resp;
    printf("%s", message);
    fflush(stdin);          // Se pone bandera por si nos olvidamos un return
    resp = scanf("%d", &auxInt);
    if(resp == 1)
    {
        if(auxInt > lowLimit && auxInt < hiLimit)
        {
            *input = auxInt;
            flag = 0;
        }
    }
    if(flag == -1)
    {
        printf("%s", eMessage);
    }
    return flag;
}


int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int flagName = 1;
    int i;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        for(i= 0; i< strlen(auxChar); i ++)
        {
            auxChar[i] = tolower(auxChar[i]);
            if(auxChar[i] < 'a' || auxChar[i] >'z')
            {
                flagName = 0;
                break;
            }
        }
    }
    else
    {
        flagName = 0;
    }
    if(flagName)
    {
        auxChar[0] = toupper(auxChar[0]);
        strcpy(input, auxChar);
        return 0;
    }

    system("cls");
    printf("%s", eMessage);
    return -1;
}


EPersona cargarPersona(int edad, int dni, char nombre[])
{
    EPersona auxPersona;

    auxPersona.edad = edad;
    auxPersona.dni = dni;
    strcpy(auxPersona.nombre, nombre);
    auxPersona.estado = 1;

    return auxPersona;
}


int buscarPorDni(EPersona lista[], int cantidadItems, int dni)
{
    int i;
    int index = -1;
    for(i=0;i<cantidadItems; i++)
    {
        if(lista[i].dni == dni)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarUna(EPersona persona)
{
    if(persona.estado == 1)
    {
        printf("%s--%d--%d--\n", persona.nombre, persona.edad, persona.dni);
    }
    else
    {
        printf("Esa persona no existe!");
    }
}

void mostrarPersonas(EPersona lista[], int cantidadItems)
{
    int i;
    for(i= 0; i<cantidadItems;i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarUna(lista[i]);
        }
    }
}


void ordenarPorNombre(EPersona lista[], int cantidadItems)
{
    int i,j;
    EPersona auxPersona;

    for(i= 0; i<cantidadItems-1; i++)
    {
        for(j= i+1; j<cantidadItems; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)== 1)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }
    }
}


void borrarPersona(EPersona lista[], int indice)
{
    int opcion;
    int auxInt;
    printf("Nombre\t\tEdad\t\tDNI\n");
    mostrarUna(lista[indice]);
    auxInt = getInt(&opcion,"Desea borrar a esa persona?\n1-Si\n2-No\n", "Opcion no valida", 0, 3);
    if(auxInt != -1)
    {
        if(opcion == 1)
        {
            lista[indice].estado = 0;
            printf("Persona borrada exitosamente!\n");
        }
        else
        {
        printf("Accion cancelada\n");
        }
    }

}

int pedirDatos(int* edad, int* dni,char* nombre)
{
    int auxInt[3];
    int auxEdad;
    int auxDni;
    char auxNombre[50];
    auxInt[0] = getName(auxNombre, "Ingrese su nombre: ", "ERROR: solo se permiten letras\n", 2, 50);
    auxInt[1] = getInt(&auxEdad,"Ingrese su edad: ", "ERROR: solo se permiten numeros entre 2 y 99\n", 2,99);
    auxInt[2] = getInt(&auxDni,"Ingrese su DNI: ", "ERROR: Ingrese el DNI sin .\n", 3,99999999);
    if(auxInt[0] == 0 && auxInt[1] == 0 && auxInt[2] == 0)
    {
        *edad = auxEdad;
        *dni = auxDni;
        strcpy(nombre, auxNombre);
        return 0;
    }
    else
    {
        return -1;
    }
}

void extraerDatosEdades(EPersona lista[], int edades[],int cantidadItems)
{
    int i;
    int menoresDieciocho = 0;
    int DiecinueveYtreintaCinco = 0;
    int mayoresTreintaCinco = 0;
    for(i=0; i<cantidadItems; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad < 18)
            {
                menoresDieciocho = menoresDieciocho + 1;
            }
            else if(lista[i].edad > 35)
            {
                mayoresTreintaCinco = mayoresTreintaCinco + 1;
            }
            else
            {
                DiecinueveYtreintaCinco = DiecinueveYtreintaCinco + 1;
            }
        }
    }
    edades[0] = menoresDieciocho;
    edades[1] = DiecinueveYtreintaCinco;
    edades[2] = mayoresTreintaCinco;
}

void crearGrafico(int edades[])
{
    int i;
    int j;
    int max = 0;

    for (i = 0; i < 3; i++)
    {
        if(edades[i] > max)
        {
            max = edades[i];
            //flagIsFirst = 0;
        }
        /*else if(flagIsFirst)
        {
            max = edades[i];
        }*/
    }

    for (i = max; i > 0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if (edades[j] >= i)
            {
                printf("   * ");
            }
            else
            {
                printf("     ");
            }
        }

    putchar('\n');
    }
    printf(" < 18 19-35  >35\n");


}
