#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/





int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagCarga=0;

    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            if (!flagCarga)
            {
                if (controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");
                    flagCarga = 1;
                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }

            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;

        case 2:

            if (!flagCarga)
            {
                if (controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");
                    flagCarga = 1;
                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }

            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;

        case 3:
            if (flagCarga)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 4:
            if (flagCarga)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 5:
            if (flagCarga)
            {

                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 6:
            if (flagCarga)
            {

                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 7:
            if (flagCarga)
            {

                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 8:
            if (flagCarga)
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 9:
            if (flagCarga)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        }
    }
    while(option != 10);
    return 0;
}
