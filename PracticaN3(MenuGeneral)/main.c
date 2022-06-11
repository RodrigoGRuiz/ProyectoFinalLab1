#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nombre [30];
    int contrasena[20];

} stUsuario;


stUsuario registroUsuario();
stUsuario inicioUsuario();


int main()
{
    char opt;

    printf("           Bienvenido a el Proyecto Final, Eliga la opcion con la que quiere comenzar:\n");
    printf("1.REGISTRARSE\n");
    printf("2.INGRESAR\n");
    printf("3.CONFIGURACION\n");
    printf("4.SALIR\n");
    printf("Usted a seleccionado la opcion: ");
    fflush(stdin);
    scanf("%c", &opt);


    switch (opt)
    {

    case '1':
    {
        system("cls");
        printf("1. Usted eligio la opcion [1] REGISTRARSE\n");
        printf("-----------------------------------------\n");
        stUsuario usuario = registroUsuario();
       /// mostrarle x pantalla como queda, y si quiere hacer alguna modificacion.

        break;
    }
    case '2':
    {
        system("cls");
        printf("              INGRESAR\n");
        printf("------------------------------------------\n");
        stUsuario usuario = inicioUsuario();
        ///Crear una funcion q haga un strcomp y en caso de ser correcto el perfil.
        /*despliega 2do menu*/
        break;
    }
    case '3':
    {
        system("cls");
        printf("            CONFIGURACION\n");
        printf("------------------------------------------\n");
        ///pide contrasena (acceso solo a los admins).
        /*una vez entra, abre switch con:↓↓↓*/
        printf("Quiere modificar a...\n");
        printf(" [a] Los usuarios\n"); /*despliega 3er menu*/
        printf(" [b] canciones\n"); /*despliega 4to menu*/

        break;
    }

    case '4':
    {
        break;
    }
    }


}



stUsuario registroUsuario()
{
    stUsuario regUsuario;

    printf ("Ingrese su nombre de usuario (con el cual se registra): \n");
    fflush(stdin);
    gets(regUsuario.nombre);

    printf ("Ingrese su contrasena (con la cual se registra): \n");
    fflush(stdin);
    gets (regUsuario.contrasena);

    return regUsuario;
}



stUsuario inicioUsuario()
{
    stUsuario inicUsuario;

    printf ("NOMBRE: ");
    fflush(stdin);
    gets(inicUsuario.nombre);

    printf ("CONTRASENA: ");
    fflush(stdin);
    gets (inicUsuario.contrasena);

    return inicUsuario;
}
