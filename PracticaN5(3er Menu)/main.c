#include <stdio.h>
#include <stdlib.h>




/* Opciones para Administradores respecto a la modificacion de usuarios */

int main()
{

    char opt;

     printf("           Bienvenido a el Proyecto Final, Eliga la opcion con la que quiere comenzar:\n");
    printf("1.VER USUARIOS DISPONIBLES Y DADOS DE BAJA\n");
    printf("2.DAR DE BAJA A UN USUARIO\n");
    printf("3.MODIFICAR EL PERFIL DE UN USUARIO\n");
    printf("4.VER LA LISTA DE FAVORITOS DE UN USUARIO\n");
    printf("5.SALIR\n");

    printf("Usted a seleccionado la opcion: ");
    fflush(stdin);
    scanf("%c", &opt);


    switch(opt)
    {
    case '1':
        {
            system("cls");
            printf("      VER USUARIOS DISPONIBLES Y DADOS DE BAJA\n");
           break;
        }
        case '2':
        {
            system("cls");
             printf("      DAR DE BAJA A UN USUARIO\n");
           break;
        }
         case '3':
        {
            system("cls");
            printf("      MODIFICAR EL PERFIL DE UN USUARIO\n");
           break;
        }
         case '4':
        {
            system("cls");
            printf("      VER LA LISTA DE FAVORITOS DE UN USUARIO\n");
           break;
        }
         case '5':
        {
           break;
        }


    }



}
