#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "biblotecaNunez.h"
#include "cliente.h"

typedef struct
{
    int codigoCliente;
    int codigoJuego;
    int codigoCliente;
}eAlquiler;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list alquiler
 * \param len int Array length
 */
void iniAlquiler(eAlquiler list[],int len) ;

/** \brief Busca un indice libre
 *
 * \param Array a buscar.
 * \param Tamaño del array
 * \return Devuelve el indice dond eesta vacio, y si no lo esta devuelve -1.
 *
 */
int searchEmpty(eAlquiler list[],int len) ;


/** \brief Muestra un cliente
 *
 * \param array del cliente a mostrar
 *
 */
void showAlquiler(eCliente list) ;

