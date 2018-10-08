typedef struct
{
    int codigo;
    char nombre[51];
    char sexo[3] ;
    int telefono ;
    int isEmpty;
}eCliente;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list cliente
 * \param len int Array length
 */
void initClientes(eCliente list[],int len) ;


/** \brief Menu de opciones
 *
 * \return Opcion ingresada
 *
 */
int menu ( ) ;


/** \brief Busca un indice libre
 *
 * \param Array a buscar.
 * \param Tamaño del array
 * \return Devuelve el indice dond eesta vacio, y si no lo esta devuelve -1.
 *
 */
int searchEmpty(eCliente list[],int len) ;


/** \brief Muestra un cliente
 *
 * \param array del cliente a mostrar
 *
 */
void showCliente(eCliente list) ;

void modifyCliente(eCliente list[], int len) ;

findClieteByCode(list, len, Code);
