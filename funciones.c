#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include <string.h>

void resetearArray (EPersona array[], int cant)
{
    int i;
    for(i = 0 ; i < cant ; i++)
    {
     array[i].estado = -1;
    }
}

int buscarPosicion (EPersona array[], int cant)
{
    int i;
    for(i = 0 ; i < cant ; i++)
    {
        if(array[i].estado == -1)
        {
            break;
        }
    }
    if( i == cant)
    {
        i = -1;
    }

    return i;
}

void cargarPersona (EPersona array[], int indice)
{
    int valido;
    char edad[4], dni[9];
   //VALIDO Y AGREGO NOMBRE
    do
    {
        printf("Ingrese nombre: ");
        gets(array[indice].nombre);
        valido = esCadenaChar(array[indice].nombre);
    }while(valido == 0);
    //VALIDO Y AGREGO EDAD
    do
    {
        printf("ingrese edad: ");
        gets(edad);
        valido = esCadenaNum(edad);
        if(strlen(edad) >= 3)
        {
            valido = 0;
        }
    }while(valido == 0);
        array[indice].edad = atoi(edad);
    //VALIDO Y AGREGO DNI
    do
    {
        printf("Ingrese DNI: ");
        gets(dni);
        valido = esCadenaNum(dni);
        if(strlen(dni) >= 9)
        {
            valido = 0;
        }
    }while(valido == 0);
        array[indice].dni = atoi(dni);
    array[indice].estado = 1;
}

int buscarPorDni(EPersona array[], long int dni, int cant)
{
    int i = 0 , indice = -1;
    for ( i = 0 ; i < cant ; i++)
    {
        if(array[i].dni == dni)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

void mostrarElemento (EPersona array[], int indice)
{
    printf("Nombre: %s\nDNI: %li\nEDAD: %i\n\n", array[indice].nombre,array[indice].dni,array[indice].edad);
}

void ordenarCadenaCaracteres (EPersona array[], int cant)
{
    int i, j;
    EPersona aux;

    for( i = 0 ; i < cant-1 ; i++)
    {
        for( j = i+1 ; j < cant ; j++)
        {
            if(0 < strcmp(array[i].nombre, array[j].nombre))
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void mostrarGrafico (EPersona array[], int cant)
{
    int menores = 0, intermedios = 0, mayores = 0, i, maximo = 0;

    for( i = 0 ; i < cant ; i++)
    {
        if( array[i].edad < 18)
        {
            menores++;
        }
        else if (array[i].edad >= 18 && array[i].edad <= 35)
        {
            intermedios++;
        }
        else
        {
            mayores++;
        }
    }

    //averiguo cual es el mayor
    maximo = mayores;

    if(menores > maximo)
    {
        maximo = menores;
    }
    else if (maximo < intermedios)
    {
        maximo = intermedios;
    }

    // a dibujar

    for(i = maximo ; i > 0 ; i--)
    {
        if(menores == i)
        {
            printf("*\t");
            menores--;
        }
        else
        {
            printf("\t");
        }


        if(intermedios == i)
        {
            printf("*\t");
            intermedios--;
        }
        else
        {
            printf("\t");
        }


        if(mayores == i)
        {
            printf("*\n");
            mayores--;
        }
        else
        {
            printf("\n");
        }

    }
        printf("min\tint\tmax\n\n");

}

void colocarMayusculas (char cadena[])
{
    int i;
    for(i = 0 ; i < strlen(cadena) ; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }

    for(i = 0 ; i < strlen(cadena) ; i++)
    {
        cadena[0] = toupper(cadena[0]);

        if(cadena[i] == ' ')
        {
            cadena[i+1] = toupper(cadena[i+1]);
        }

    }
}

int esCadenaChar (char cadena[])
{
    int i, largo, valido = 0;
    largo = strlen(cadena);
    for( i = 0 ; i < largo ; i++)
    {
        if(isalpha(cadena[i]) != 0 || cadena[i] == ' ')
        {
            valido = 1;
            break;
        }
    }
    return valido;
}

int esCadenaNum (char cadena[])
{
    int i, largo, valido = 1;
    largo = strlen(cadena);
    for( i = 0 ; i < largo ; i++)
    {
        if(isdigit(cadena[i]) == 0)
        {
            valido = 0;
            break;
        }
    }
    return valido;
}








