#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblotecaNunez.h"
#include "cliente.h"
#define TAMc 10000


// El hardcodeo de el juego y cliente estan en biblotecaNunez.h .

int main()
{


    int seguir = 1 ;

    eCliente clientes[TAMc];
    initClientes(clientes,TAMc) ;
    do
    {
        switch(menu())
        {
        case 1:
            switch(menuClientes())
            {
            case 1:
                system("cls");
                addCliente(clientes,TAMc);
                break;
            case 2:
                system("cls") ;
                modifyCliente(clientes,TAMc) ;
                break;
            case 3:
                system("cls") ;
                removeCliente(clientes,TAMc);
                break;
            }
        case 2:
            system("cls") ;
            modifyCliente(clientes,TAMc) ;
            break ;
        case 3:
            printf("\n\n\n Saliendo..\n\n") ;
            system("pause") ;
            seguir = 0 ;
            break;
        }
    }
    while(seguir) ;

    return 0;
}
