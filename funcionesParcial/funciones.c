#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "biblotecaNunez.h"
#include "funciones.h"

/// FUNCIONES PARA EL ABM
void initEmployees(eEmployee list[],int len)
{
        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
}

int searchEmpty(eEmployee lista[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

int findEmployeeById(eEmployee list[], int len, int id)
{

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;

}

int addEmployee(eEmployee list[], int len)
{
    eEmployee newEmployee ;
    int ret;
    int index ;
    char auxName[21];
    char auxLastName[21];
    char auxSalary[10] ;
    char auxSector[10] ;


    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n------- Alta empleado -------\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {


            printf("\n Nuevo empleado, ID numero %d \n",index) ;
            newEmployee.id = index ;
            if(!function_getStringLetras("Ingrese nombre: ",auxName))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!function_getStringLetras("Ingrese apellido: ",auxLastName))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!function_getStringNumeros("Ingrese el salario: ",auxSalary))
            {
                printf("Error el salario debe tener solo numeros.\n\n");
                system("pause");
                system("cls");

            }
            else if(!function_getStringNumeros("Ingrese el sector: ",auxSector))
            {
                printf("Error el sector debe tener solo numeros.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(newEmployee.name,auxName) ;
                strcpy(newEmployee.lastName,auxLastName) ;
                newEmployee.salary = atoi(auxSalary) ;
                newEmployee.sector = atoi(auxSector) ;
                newEmployee.isEmpty = 0;
                list[index] = newEmployee ;
                system("pause");
                system("cls");
                printf("\n\nEMPLEADO DADO DE ALTA CON EXITO:\n\n");
                showEmployee(list[index]);
                printf("\n\n\n");
                system("pause");
                ret = 0 ;
            }
        }

    }
    else
    {
        ret = -1 ;
    }
    return ret;
}

int removeEmployee(eEmployee list[], int len, int id)
{
    int index;
    int ret ;
    char auxID[10] ;
    char seguir[1];

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("  *** Baja empelado ***\n\n");


        if(!function_getStringNumeros("Ingrese id: ",auxID))
        {
            printf("*** ERROR *** El ID debe contener solo numeros.\n\n");
            system("pause") ;
            system("cls");
        }
        else
        {
            id = atoi(auxID) ;

            index = findEmployeeById(list,len,id) ;


            if(index == -1)
            {
                printf("No hay ningun empleado con id %d",id) ;
            }
            else
            {
                ret = 0;
                showEmployee(list[index]) ;
                function_continueYesOrNo("\nConfima borrado s/n: ",seguir);
                if(seguir[0] == 'n' || seguir[0] == 'N')
                {
                    printf("Baja cancelada\n\n");
                }
                else
                {

                    list[index].isEmpty = 1;
                    printf("Borrado exitoso\n\n");
                }
                system("pause");
            }
        }
    }
    return ret ;
}

void modifyEmployee(eEmployee list[], int len)
{
    int id;
    int index;
    int option;
    char auxOption[3];
    char auxId[5];
    char newSalary[5];
    char newSector[5];
    char newName[51] ;
    char newLastName[51] ;
    char seguir = 's';


    system("cls");
    printf("  *** Modificar  empleado ***\n\n");


    if(!function_getStringNumeros("Ingrese id: ",auxId))
    {
        printf("*** ERROR *** El id debe contener solo numeros.") ;
    }

    id = atoi(auxId) ;
    index = findEmployeeById(list, len, id);


    if( index == -1)
    {
        printf("No hay ningun empleado con id %d.\n\n", id);
        system("pause");
    }
    else
    {

    do
    {
    system("cls");
    showEmployee(list[index]) ;


    if(!function_getStringNumeros("\n\nQue desea modificar?\n\n1 - Nombre\n2 - Apellido\n3- Sueldo\n4 - Sector\n\n5-Volver al menu ",auxOption))
    {
        printf("Error debe ingresar un numero");
    }else
    {
    option = atoi(auxOption);
    }

    switch(option)
    {


       case 1:
        showEmployee(list[index]) ;
        printf("\n\n");
       //modificar nombre
        if(!function_getStringLetras("Ingrese nuevo nombre: ",newName))
            {
                printf("*** Error *** El nombre debe tener solo letras.");
            }else
            {
            strcpy(list[index].name,newName);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            system("pause");
            break ;
       }
    case 2:
// Modifica apellido
        showEmployee(list[index]) ;
        printf("\n\n");
        if(!function_getStringLetras("Ingrese nuevo apellido: ",newLastName))
            {
                printf("*** ERROR *** El apellido debe tener solo letras.\n\n");
            }else{

            strcpy(list[index].lastName,newLastName);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            system("pause");
            }
        break ;
    case 3:
        // modifica sueldo
        showEmployee(list[index]) ;
        printf("\n\n");
        if(!function_getStringNumeros("Ingrese nuevo sueldo: ",newSalary))
            {
                printf("*** ERROR *** El salario debe contener solo numeros.") ;
            }else{

            list[index].salary = atoi(newSalary);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            system("pause");
            }
            break ;
    case 4:
        // MODIFICA SECTOR
        showEmployee(list[index]) ;
        printf("\n\n");
        if(!function_getStringNumeros("Ingrese nuevo sector: ",newSector))
            {
                printf("*** ERROR *** El sector tiene que ser un numero") ;
            }

            list[index].sector = atoi(newSector);

            printf("\n\n        ***Modificacion exitosa***\n\n");
            system("pause");
            system("cls") ;
            break ;
    case 5:
        printf("Salindo\n\n");
        system("pause");
        seguir = 'n';
        break;
    default:
        printf("*** ERROR *** Debe ingresar un numero del 1 al 4.\n");
        system("pause");
        break;
        }
        }while(seguir == 's');
    }
    }

void showEmployee(eEmployee list)
{
    printf("\n\t%d\t\t%s\t\t%s\t\t%.2f\t\t%d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}

int sortEmployees(eEmployee list[], int len, int order)
{
    eEmployee auxEmployee;
    char auxOrder[1] ;
    if(!function_getStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrder))
    {
        printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

    }

    order = atoi(auxOrder);
    switch(order)
    {
    case 1:
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
    case 2:
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }

        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}

void showEmployees(eEmployee list[],int len)
{
    system("cls");
    printf("\n\n\tID\t\tNOMBRE\t\t  APELLIDO\t\tSALARIO\t\tSECTOR\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showEmployee(list[i]) ;
        }
    }

}

float averageSalary(eEmployee list[],int len)
{
    float acumSalary = 0;
    int contSalary = 0;
    float average ;
    for(int i = 0; i < len; i++ )
    {

        if(list[i].isEmpty == 0)
        {
            acumSalary = acumSalary + list[i].salary ;
            contSalary++;

        }
    }

    average = (acumSalary / contSalary);

    return average;
}

int countOverAverage(eEmployee list[],int len)
{
    int count = 0;

    for(int i = 0; i < len ; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > averageSalary(list,len))
        {
            count++;
        }
    }
    return count;
}

float totalSalary(eEmployee list[],int len)
{
    float acumSalary = 0;
    for(int i = 0; i < len; i++ )
    {

        if(list[i].isEmpty == 0)
        {
            acumSalary = acumSalary + list[i].salary ;
        }
    }

    return acumSalary;
}

int yaHayEmpleado(eEmployee list[],int len)
{
    int ret = 0;
    for(int i = 0; i < len;i++)
    {
        if(list[i].isEmpty == 0)
        {
            ret = 1 ;
            break;
        }
    }

    return ret;
}


/** \brief Menu de opciones
 *
 * \return Opcion ingresada
 *
 */

int menu ( )
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n*** Menu de Opciones ***\n\n");
    printf("1-ALTAS \n");
    printf("2-MODIFICAR \n") ;
    printf("3-BAJAS \n");
    printf("4-INFORMAR \n");
    printf("5-SALIR\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 5. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void harcodeoEmployee(eEmployee* list)
{
    eEmployee   x[]={
    {10,"JR","Riquelme",20000, 1},
    {7,"Cristian","Pavon",30000, 3},
    {9,"Dario","Benedetto",18000, 1},
    {19,"Lionel","Messi",20000, 2},
    {1,"Sara","Connor",30000, 3}
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
}

void function_Fecha( )
{
    eFecha nuevaFecha;
    char diaArray[10];
    char mesArray[10];
    char anioArray[10];
    int auxDia;
    int auxMes;
    int auxAnio;

    /// SOLICITAR INGRESAR MES QUE TENGA HASTA 31 DIAS

    do
    {

        if(!function_getStringNumeros("\nIngrese el dia:",diaArray))
        {
            printf("El dia solo debe tener numeros.") ;
        }else
            {
                auxDia = atoi(diaArray);
            }

        if(auxDia > 31)
        {
            printf("\n Error, el dia no puede ser mayor a 31.\n\n");
            system("cls");
        }else
        {
           nuevaFecha.dia = auxDia;
        }
    }
    while(auxDia > 31) ;

    /// SOLICITAR INGRESAR ME SQUE TENGA HASTA 12 (MESES)

    do
    {

        if(!function_getStringNumeros("\n\nIngrese el mes:",mesArray))
        {
            printf("El mes solo debe tener numeros.") ;
        }else
            {
                auxMes = atoi(mesArray);
            }

        if(auxMes > 12)
        {
            printf("\n Error, el mes no puede ser mayor a 12.\n\n");
            system("cls");
        }else
        {
           nuevaFecha.mes= auxMes ;
        }
    }
    while(auxMes > 12) ;

    /// VALIDACION DE A�O

     if(!function_getStringNumeros("\n\nIngrese el anio:",anioArray))
     {
         printf("\n Erro el a�o debe tener solo numeros");
     }else{

     auxAnio = atoi(anioArray);
     nuevaFecha.anio = anioArray ;
     }
}


void function_Fecha( ) ;
