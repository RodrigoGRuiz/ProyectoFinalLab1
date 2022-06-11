#include <stdio.h>
#include <stdlib.h>



/* Opciones para Usuarios una vez dentro */


int main()
{

    char opt;

    printf("           Bienvenido a el Proyecto Final, Eliga la opcion con la que quiere comenzar:\n");
    printf("1.VER CANCIONES DISPONIBLES\n");
    printf("2.VER MI PERFIL\n");
    printf("3.AGREGAR UNA CANCION A LA LISTA DE FAVORITOS\n");
    printf("4.MOSTRAR LISTA DE FAVORITOS\n");
    printf("5.DARSE DE BAJA\n");
    printf("6.SALIR\n");

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
        printf("         VER MI PERFIL\n");
        break;
    }
    case '3':
    {
        system("cls");
        printf("       AGREGAR UNA CANCION A LA LISTA DE FAVORITOS\n");
        break;
    }
    case '4':
    {
        system("cls");
        printf("       MOSTRAR LISTA DE FAVORITOS\n");
        break;
    }
    case '5':
    {
        system("cls");
        printf("     DARSE DE BAJA\n");
        break;
    }
    case '6':
    {
        break;
    }

    }


}
