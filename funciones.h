#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tamaño del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona[], long int, int);

/** \brief Recorre un array y en el estado (array[i].estado) le asigna un -1
 *
 * \param Array que se debe completar
 * \param Cantidad de elementos comprendidos.
 * \return
 *
 */

void resetearArray (EPersona[], int);

/** \brief busca en el estado de que sea = a -1 para poder cargar el nuevo
            cliente/persona.
 *
 * \param array de estructura
 * \param tamaño del array
 * \return numero con posicion o -1 si no encuentra posicion.
 *
 */

int buscarPosicion (EPersona[], int);

/** \brief Combina funciones y validaciones para este programa exclusivamente.
 *
 * \param Array contenedor de datos.
 * \param Indice del array que se va a cargar.
 * \return
 *
 */

void cargarPersona (EPersona[], int);

/** \brief Muestra un elemento especifico del array.
 *
 * \param Array de donde obtengo datos a mostrar.
 * \param Indice que se desea mostrar.
 * \return
 *
 */

void mostrarElemento (EPersona[], int);

/** \brief Ordena de menor a mayor cadenas de caracteres.
 *
 * \param Array contenedor de cadenas.
 * \param Cantidad de elementos que contiene.
 * \return
 *
 */

void ordenarCadenaCaracteres (EPersona[], int);

/** \brief Realiza un grafico donde eje x parametros y eje y cantidades en forma de *.
 *          es exclusivo de este programa.
 * \param Array contenedor de elementos.
 * \param Cantidad de elementos
 * \return
 *
 */

void mostrarGrafico (EPersona[], int);

/** \brief Toma una cadena de caracteres, coloca todo en minuscula y luego el primer elemento y cualquiera seguido de un espacio
            es transformado en mayuscuma.
 *
 * \param Cadena a la cual se desea alterar.
 * \param
 * \return
 *
 */

void colocarMayusculas (char[]);

/** \brief Verifica que lo ingresado sea una cadena de char respetando espacios y no acentos u otras puntuaciones.
 *          util para nombres y titulos, no para un texto descriptivo o que no contengan puntuacion.
 * \param Cadena que se desea analizar.
 * \param
 * \return 1 si es verdadero o 0 si es falso
 *
 */

int esCadenaChar (char[]);

/** \brief Verifica que la cadena ingresada sea pura y exclusivamente de numeros.
 *
 * \param Cadena que se desea analizar.
 * \param
 * \return 1 si es verdadero o 0 si es falso
 *
 */

int esCadenaNum (char[]);

#endif // FUNCIONES_H_INCLUDED
