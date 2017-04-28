#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20

int main()
{
    char seguir='s';
    int opcion=0 , posicion, i;
    long int dni;
    EPersona personas[CANT];
//    EPersona personas[CANT]= {
//                                {"juan", 12, 1, 35420747},
//                                {"maria", 11, 1, 654987},
//                                {"pedro lego", 65, 1, 567828},
//                                {"juan franco", 25, 1, 64512921},
//                                {"carla daniela", 29, 1, 9451231}
//
//                             };

    resetearArray(personas, CANT);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
           case 1:
                posicion = buscarPosicion(personas, CANT);
                if(posicion == -1)
                {
                    printf("No hay posiciones libres\n");
                }
                else
                {
                    cargarPersona(personas, posicion);
                    colocarMayusculas (personas[posicion].nombre);
                }

                break;
            case 2:
                printf("ingrese DNI: ");
                scanf("%li", &dni);
                posicion = buscarPorDni(personas, dni, CANT);
                mostrarElemento(personas, posicion);
                personas[posicion].estado = -1;
                printf("Persona dada de baja correctamente\n");
                break;
            case 3:
                ordenarCadenaCaracteres (personas, CANT);
                for( i = 0 ; i < CANT ; i++)
                {
                    if(personas[i].estado == 1)
                    {
                        mostrarElemento(personas, i);
                    }
                }
                break;
            case 4:
                 mostrarGrafico (personas, CANT);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
