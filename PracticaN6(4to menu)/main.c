#include <stdio.h>
#include <stdlib.h>



/* Opciones para Administradores respecto a la modificacion de canciones */

int main()
{

    char opt;

     printf("           Bienvenido a el Proyecto Final, Eliga la opcion con la que quiere comenzar:\n");
    printf("1.VER CANCIONES DISPONIBLES\n");
    printf("2.AGREGAR CANCIONES NUEVAS\n");
    printf("3.ELIMINAR UNA CANCION O DARLA DE BAJA\n");
    printf("4.MODIFICAR UNA CANCION\n");
    printf("5.SALIR\n");

    printf("Usted a seleccionado la opcion: ");
    fflush(stdin);
    scanf("%c", &opt);


    switch(opt)
    {
    case '1':
        {
            system("cls");
            printf("      VER CANCIONES DISPONIBLES\n");
           break;
        }
        case '2':
        {
            system("cls");
             printf("      AGREGAR CANCIONES NUEVAS\n");
           break;
        }
         case '3':
        {
            system("cls");
            printf("      ELIMINAR UNA CANCION O DARLA DE BAJA\n");
           break;
        }
         case '4':
        {
            system("cls");
            printf("      MODIFICAR UNA CANCION\n");
           break;
        }
         case '5':
        {
           break;
        }


    }



}
