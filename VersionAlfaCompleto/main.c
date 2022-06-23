#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define passw "1234567"


typedef struct {
char nombre[30];
int ID[20];
char password[20];
int cancionesFavoritas[20];
int contadorValidos;
int estadoActividad;
} stUsuario;


int segundoMenu();
void opcionAoB ();
int tercerMenu ();
int cuartoMenu ();
void agregarUsuario ();
int ingresar();
void ValidacionDeAdmin ();

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}


int main()
{
    int condcort=0;
    char opt;
    do
    {
    system("cls");

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
       agregarUsuario();
       ///en el caso de que sea correcto, avisa x pantalla y continua



        break;
    }
    case '2':
    {
        system("cls");
        printf("              INGRESAR\n");
        printf("------------------------------------------\n");
        condcort = ingresar();
        //en el caso de estar correcto
        /*despliega 2do menu*/
        break;
    }
    case '3':
    {
        system("cls");
        ValidacionDeAdmin ();
//        opcionAoB();

        break;
    }

    case '4':
    {
        condcort=1;
        break;
    }
    }
 }while (condcort == 0);
}


///------------------------------------------------FIN DEL MENU PRINCIPAL----------------------------------------------\\\



int segundoMenu()
{
    int condcorte2 =0;

    char opt;

    printf("          Bienvenido Usuario, que desea realizar hoy?\n");
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
        condcorte2 = 1;
        return condcorte2;
        break;
    }

    }

}
///------------------------------------------------FIN DEL SEGUNDO MENU----------------------------------------------\\\




int tercerMenu ()
{
    int condcorte3 =0;

    char opt;

    printf("           Listo para modificar hoy?, que desea hacer primero...:\n");
    printf("1.VER USUARIOS DISPONIBLES Y DADOS DE BAJA\n");
    printf("2.DAR DE BAJA A UN USUARIO\n");
    printf("3.MODIFICAR EL PERFIL DE UN USUARIO\n");
    printf("4.VER LA LISTA DE FAVORITOS DE UN USUARIO\n");
    printf("5.VOLVER AL MENU PRINCIPAL\n");

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
        condcorte3 = 1;
        return condcorte3;
        break;
    }


    }


}
///------------------------------------------------FIN DEL TERCER MENU----------------------------------------------\\\



int cuartoMenu ()
{
    int condcorte4 =0;

    char opt;

    printf("           Listo para modificar hoy?, que desea hacer primero...:\n");
    printf("1.VER CANCIONES DISPONIBLES\n");
    printf("2.AGREGAR CANCIONES NUEVAS\n");
    printf("3.ELIMINAR UNA CANCION O DARLA DE BAJA\n");
    printf("4.MODIFICAR UNA CANCION\n");
    printf("5.VOLVER AL MENU PRINCIPAL\n");

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
        condcorte4 = 1;
        return condcorte4;
        break;
    }


    }


}

///------------------------------------------------FIN DEL CUARTO MENU----------------------------------------------\\\


void opcionAoB ()
{
    int condicionCorte=0;
    char opcAoB;


        printf("            CONFIGURACION\n");
        printf("***************************************\n");
        ///pide contrasena (acceso solo a los admins).
        /*una vez entra, abre switch con:↓↓↓*/
        printf("Quiere modificar a...\n");
        printf(" [a] Los usuarios\n"); /*despliega 3er menu*/
        printf(" [b] canciones\n"); /*despliega 4to menu*/
        fflush(stdin);
        scanf("%c", &opcAoB);

        switch (opcAoB)
        {
        case 'a':
        {
            system("cls");
            tercerMenu();
            break;
        }
        case 'b':
        {
            system("cls");
            cuartoMenu();
            break;
        }
        default:
            {
             printf("la opcion que ustede eligio no existe");
            }
        }

}





////FUNCION REGISTRAR USUARIO

void agregarUsuario (){
    FILE* Archivo = fopen("Usuarios.bin", "ab");
    stUsuario usuario ;
    gotoxy(12, 12);printf ("\nIngrese el Nombre de Usuario: \n ");
    scanf("%s", usuario.nombre);

    gotoxy(12, 14);printf ("\nIngrese Su contrasenia: \n ");

    ////---------> CONTRASEÑA CON ESTRELLAS ------>
   gotoxy(12,16);  for (int i = 0; i < 21; i++)  ////------>Maximo de caracteres
 {
   int ch = getch();
   if (ch != 13)
   {
     usuario.password[i] = ch;
     ch = '*';
     printf("%c", ch);
   }
   else
     break;
 }

////-------------->Fin Contraseña en estrellitas ---------->

    usuario.estadoActividad = 1;

        if (Archivo !=NULL){

        fwrite(&usuario, sizeof(usuario),1, Archivo);
        printf("\n");
        printf("Perfecto tu registro se realizo con exito...");
        sleep(3);
        }
            else {
              gotoxy(53,40) ; printf("\n Ha ocurrido un Error en el archivo\n ");
            }

            fclose(Archivo);
}


int ingresar()  ///ingreso directo a la aplicacion
{
    system("cls");
    int condcorte = 0;
    FILE* Archivo = fopen("Usuarios.bin", "rb");

    char username[50];
    char password[50];

    int i, j, k;
    char ch;
   stUsuario usuario;


    if (Archivo == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }
    gotoxy(43, 2);
    printf(" INGRESO ");
    gotoxy(7, 5);
    printf("***********************************************"
           "***************************************");

    gotoxy(35, 10);
    printf("==== COMPROBACION DE DATOS ====");

    gotoxy(35, 12);
    printf("NOMBRE DE USUARIO.. ");
    fflush(stdin);
    scanf("%s", &username);

    gotoxy(35, 14);
    printf("CONTRASENIA..");

   ///toma y verifica la contraseña
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }

        else
            break;
    }

    ///Compara si existe
    while (fread(&usuario, sizeof(stUsuario), 1, Archivo))
    {
        if (strcmp(username,usuario.nombre)== 0)
        {
        system("cls");
        condcorte = segundoMenu();
        }

    }

    fclose(Archivo);
    return condcorte;
}


void ValidacionDeAdmin ()
{
char claveacomparar[10];
int coincidencia=0;
printf("Ingrese la clave desginada para acceder a este menu...\n");
////---------> CONTRASEÑA CON ESTRELLAS ------>
   for(int i = 0; i<8; i++) ////------>Maximo de caracteres
 {
     fflush(stdin);
     int ch = getch();
   if (ch != 13)
   {
     claveacomparar[i]= ch;
     ch = '*';
     printf("%c", ch);
   }

 }
coincidencia = strcmp(claveacomparar,passw);
   if (coincidencia==0) {
    printf("\nCLAVE VALIDA\n");
    opcionAoB();
    ///(CODIGO PARA ENTRAR Al menu)
   }
   else {

    printf("\nCLAVE INCORRECTA!\n ***ACCESO DENEGADO***");
   }
}



