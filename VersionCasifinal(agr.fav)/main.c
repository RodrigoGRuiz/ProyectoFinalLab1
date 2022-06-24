#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define passw "1234567"
#include <string.h>
#define usuarios "RegistroUsuarios.bin"
#define Admins "RegistroAdministradores.bin"
#define Canciones "RegistroCanciones.bin"
#define ContraseñaAdmin "EquipoAlfaBuenaMaravillaOndaDinamitaEscuadrónLobo" → "1234567"


typedef struct
{
    char nombre[30];
    int ID;
    char password[20];
    int cancionesFavoritas[20];
    int contadorValidos;
    int estadoActividad;
} stUsuario;

typedef struct
{
    int idCancion;
    char nombre [40];
    char autorBanda [40];
    char genero [40];
    int estadoActividad;

} stCanciones;
/////----------------------- version original de la alfa----------------\\\\\\

int segundoMenu(char nombre);
void opcionAoB ();
int tercerMenu ();
int cuartoMenu ();
void agregarUsuario ();
int AsignarID();
int ingresar();
void ValidacionDeAdmin ();
void MostrarTodasUsuarios();
void CargarCancion ();
void MostrarTodasCanciones();
void ModificarEstadoUsuario();
int AsignarIDcancion ();
//void agregarFavorito(char nombre[]);
//void mustraCancionFav(int numero);
int existenciaCancion(int idCancion);
void BuscaPerfil();
void ModificarDatosUsuario();
void ModificarEstadoCancion();
void ModificarDatosCanciones();
void AgregarUnaCancionAfavoritos();
void MostrarFavoritos ();


void gotoxy(int x, int y)
{
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
            printf("GRACIAS X UTILIZAR NUESTRO PROGRAMA....");
            condcort=1;
            break;
        }
        }
    }
    while (condcort == 0);
}


///------------------------------------------------FIN DEL MENU PRINCIPAL----------------------------------------------\\\



int segundoMenu(char nombre)
{

    int condcorte2 =0;
    char opt;
    do
    {
        system("cls");

        printf("          Bienvenido Usuario, que desea realizar hoy?\n");
        printf("1.VER CANCIONES DISPONIBLES\n");
        printf("2.VER MI PERFIL\n");
        printf("3.AGREGAR UNA CANCION A LA LISTA DE FAVORITOS\n");
        printf("4.MOSTRAR LISTA DE FAVORITOS\n");
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
            MostrarTodasCanciones();
            break;
        }
        case '2':
        {
            system("cls");
            printf("         VER MI PERFIL\n");
            BuscaPerfil();
            break;
        }
        case '3':
        {
            system("cls");
            printf("       AGREGAR UNA CANCION A LA LISTA DE FAVORITOS\n");
            void AgregarUnaCancionAfavoritos();
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
            condcorte2 = 1;
            return condcorte2;
            break;
        }

        }
    }
    while(condcorte2 == 0);

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
        MostrarTodasUsuarios();
        break;
    }
    case '2':
    {
        system("cls");
        printf("      DAR DE BAJA A UN USUARIO\n");
        ModificarEstadoUsuario();
        break;
    }
    case '3':
    {
        system("cls");
        printf("      MODIFICAR EL PERFIL DE UN USUARIO\n");
        ModificarDatosUsuario();
        break;
    }
    case '4':
    {
        system("cls");
        printf("      VER LA LISTA DE FAVORITOS DE UN USUARIO\n");
        MostrarFavoritos();
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
    do
    {
        system("cls");
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
            MostrarTodasCanciones();
            break;
        }
        case '2':
        {
            system("cls");
            printf("      AGREGAR CANCIONES NUEVAS\n");
            CargarCancion();
            break;
        }
        case '3':
        {
            system("cls");
            printf("      ELIMINAR UNA CANCION O DARLA DE BAJA\n");
            ModificarEstadoCancion();
            break;
        }
        case '4':
        {
            system("cls");
            printf("      MODIFICAR UNA CANCION\n");
            ModificarDatosCanciones();
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
    while(condcorte4 == 0);

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





////FUNCION REGISTRAR USUARIO -------------usuarios-----------------////

void agregarUsuario ()
{
    FILE* Archivo = fopen(usuarios, "a");
    stUsuario usuario ;
    gotoxy(12, 12);
    printf ("\nIngrese el Nombre de Usuario: \n ");
    fflush(stdin);
    gets(usuario.nombre);

    gotoxy(12, 14);
    printf ("\nIngrese Su contrasenia: \n ");

    ////---------> CONTRASEÑA CON ESTRELLAS ------>
    gotoxy(12,16);
    for (int i = 0; i < 21; i++)  ////------>Maximo de caracteres
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
    usuario.ID = AsignarID();
    usuario.contadorValidos= 0;
////-------------->Fin Contraseña en estrellitas ---------->

    usuario.estadoActividad = 1;

    if (Archivo !=NULL)
    {

        fwrite(&usuario, sizeof(usuario),1, Archivo);
        printf("\n");
        printf("Perfecto tu registro se realizo con exito...");
        sleep(3);
    }
    else
    {
        gotoxy(53,40) ;
        printf("\n Ha ocurrido un Error en el archivo\n ");
    }

    fclose(Archivo);
}


int ingresar()  ///ingreso directo a la aplicacion
{
    system("cls");
    int flag = 0;
    int condcorte = 0;
    FILE* Archivo = fopen(usuarios, "rb");

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
            flag = 1;
        }

    }
    fclose(Archivo);

    if (flag == 1)
    {

        system("cls");
        condcorte = segundoMenu(username);

    }
    else
    {
        printf("\n");
        printf("\n");
        printf("\t\t\t El usuario es incorrecto, pruebe registrandose primero");
        sleep(5);

    }

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
    if (coincidencia==0)
    {
        printf("\nCLAVE VALIDA\n");
        opcionAoB();
        ///(CODIGO PARA ENTRAR Al menu)
    }
    else
    {

        printf("\nCLAVE INCORRECTA!\n ***ACCESO DENEGADO***");
    }
}

///--------Muestra de usuarios

void MostrarTodasUsuarios()
{
    FILE* archivo =fopen(usuarios, "rb");
    stUsuario usuario;
    if(archivo!=NULL)
    {
        while (fread(&usuario, sizeof(stUsuario), 1, archivo)>0)
        {

            printf("Nombre: %s \n",usuario.nombre) ;
            printf("ID: %i \n",usuario.ID) ;
            printf("Estado:%i\n", usuario.estadoActividad);
            printf("Canciones Favoritas: %s\n", usuario.cancionesFavoritas);
            printf("\n----------------------------------------------------\n");


        }

        fclose(archivo);
        system("pause");
    }
    else
    {
        printf("Archivo no Encontrado");

    }

}


void ModificarEstadoUsuario()
{
    FILE *archivo =fopen(usuarios,"r+b");
    if (archivo==NULL)
    {
        printf("\nHa Ocurrido un error en el Archivo\n)");
    }
    else
    {
        printf("Ingrese el ID del usuario a modificar el estado:");
        int ID;
        scanf("%i", &ID);
        stUsuario usuario1;
        int exist=0; ///------> indicador de si esta en el archivo el usuario
        fread(&usuario1, sizeof(stUsuario), 1, archivo);
        while(!feof(archivo))
        {
            if (ID == usuario1.ID)
            {
                printf("\Nombre: %s \n ID: %i\n  Estado De Actividad (1=Activo, 0=Inactivo) %i\n", usuario1.nombre, usuario1.ID, usuario1.estadoActividad);
                printf("Ingrese un 1 si quiere que el estado sea activo y un 0 si quiere que el estado sea Inactivo:");
                scanf("%f",&usuario1.estadoActividad);
                int posicion=ftell(archivo)-sizeof(stUsuario);
                fseek(archivo,posicion,SEEK_SET);
                fwrite(&usuario1, sizeof(stUsuario), 1, archivo);
                printf("Se Ha modificado el estado del usuario\n");
                exist=1;
                break;
            }

            fread(&usuario1, sizeof(stUsuario), 1, archivo);
        }
        if (exist==0)
            printf("No existe un usuario con ese ID\n");
        fclose(archivo);
        system("pause");
    }

}

///-----------------------------parte de las canciones--------------------////
void CargarCancion ()
{
    FILE* Archivo =fopen(Canciones, "a");
    stCanciones cancion;
    char opcion= 's';
    if(Archivo!=NULL)
    {
        while(opcion =='s')
        {
            system("cls");
            Archivo = fopen(Canciones,"a");
            printf("\nIngrese el Nombre de la cancion: \n ");
            fflush(stdin);
            scanf("%s", cancion.nombre);
            printf("\nIngrese el Nombre del autor de la cancion: \n ");
            fflush(stdin);
            scanf("%s", cancion.autorBanda);
            printf("\nIngrese el genero de la cancion: \n ");
            fflush(stdin);
            scanf("%s", cancion.genero);

            cancion.idCancion = AsignarIDcancion();

            fwrite(&cancion, sizeof(stCanciones),1,Archivo);
            printf("\nCancion agregada con exito!\n" );


            printf("Ingresar otra cancion?(s/n): ");
            fflush(stdin);
            scanf("%c",&opcion);

            cancion.estadoActividad = 1;

        }
        fclose(Archivo);
    }

    else
    {
        printf ("\n Ha ocurrido un error en el archivo \n");
    }


}



void MostrarTodasCanciones()
{
    FILE* archivo =fopen(Canciones, "rb");
    stCanciones cancion ;
    if(archivo!=NULL)
    {
        while (fread(&cancion, sizeof(stCanciones), 1, archivo)>0)
        {

            printf("Nombre: %s \n",cancion.nombre) ;
            printf("Genero: %s \n",cancion.genero) ;
            printf("Autor:%s\n", cancion.autorBanda);
            printf("\n----------------------------------------------------\n");


        }

        fclose(archivo);
        system("pause");
    }
    else
    {
        printf("Archivo no Encontrado");

    }

}



int AsignarID ()
{
    FILE* archivo = fopen(usuarios, "r+b");
    int ID=0;
    stUsuario usuario1;
    if(archivo!=NULL)
    {
        while (!feof(archivo))
        {
            fread(&usuario1, sizeof(stUsuario), 1, archivo);
            ID++;
        }
        fclose (archivo);
        return ID;
    }
    else
    {
        printf("\nHa ocurrido error en el archivo\n");

    }

}

int AsignarIDcancion ()
{
    FILE* archivo = fopen(Canciones, "r+b");
    int ID=0;
    stCanciones cancion;
    if(archivo!=NULL)
    {
        while (!feof(archivo))
        {
            fread(&cancion, sizeof(stCanciones), 1, archivo);
            ID++;
        }
        fclose (archivo);
        return ID;
    }
    else
    {
        printf("\nHa ocurrido error en el archivo\n");

    }

}

 void AgregarUnaCancionAfavoritos()
{
    FILE *archivo =fopen(usuarios,"r+b");
    char nombre[20];
    int IDCancion;
    stUsuario usuario1;
    int exist = 0;
    if (archivo==NULL)
    {
        printf("\nHa Ocurrido un error en el Archivo\n)");
    }
    else
    {
        printf("Asique queres agregar algo a tu lista de favorito? Quien sos?:");
        fflush(stdin);
        scanf("%s", &nombre);
        fread(&usuario1, sizeof(stUsuario), 1, archivo);
        while(fread(&usuario1, sizeof(stUsuario), 1, archivo)>0)
        { printf("%s",nombre);
        printf("%s",usuario1.nombre);
            if ( strcmp(nombre,usuario1.nombre))
            {printf("Ingrese el id tu cancion favorita: \n");
                fflush(stdin);
                scanf("%i",&IDCancion);
                int i=usuario1.contadorValidos;
                usuario1.cancionesFavoritas[i] = IDCancion;
                usuario1.contadorValidos++;
                printf("Se Ha Agregado La cancion exitosamente!\n");
                break;
            }
        }
        int posicion=ftell(archivo)-sizeof(stUsuario);
        fseek(archivo,posicion,SEEK_SET);
        fwrite(&usuario1, sizeof(stUsuario), 1, archivo);

        exist=1;

    }

    if (exist==0)
    {
        printf("No existe un usuario con ese ID O usuario Dado de Baja\n");
        fclose(archivo);
        system("pause");




    }
}

void MostrarFavoritos ()
{
    FILE* Archivo = fopen(usuarios,"rb");
    FILE* Archivo2 = fopen(Canciones, "rb");
    int ID;
    stCanciones cancion;
    stUsuario usuario;
    printf("Ingresa Tu ID, tus favoritos son muy importantes no la compartas con cualquiera ;)\n");
    fflush(stdin);
    scanf("%i",&ID);
    if(Archivo==NULL){
        printf("!!!!");
    }else
    {
        while (fread(&usuario, sizeof(stUsuario), 1, Archivo)>0)
        { printf("!!!!!%i",usuario.ID);
        printf("\n !!!!%i",usuario.ID);
            if (ID == usuario.ID && usuario.estadoActividad==1)
            {

                printf("\nHOLA!: %s \n",usuario.nombre) ;

                printf("\nHOLA!: %s \n",usuario.contadorValidos) ;
                for (int i =0; i<usuario.contadorValidos; i++)
                {
                    while (fread(&cancion, sizeof(stCanciones), 1, Archivo2)>0)
                    {

                        if (usuario.cancionesFavoritas[i]== cancion.idCancion)
                        {
                            printf("Canciones Favoritas:" );
                            printf("\n----------------------------------------------------\n");

                            printf("%s\n",cancion.nombre);
                            printf("%s\n",cancion.genero);
                            printf("%s\n",cancion.autorBanda);
                            printf("\n----------------------------------------------------\n");
                        }
                    }

                }


            }
            fclose(Archivo);
            fclose(Archivo2);

        }


    }
}

















int existenciaCancion(int idCancion)
{
    int flag = 0;
    stCanciones cancion;
    FILE *archivo;
    archivo = fopen(Canciones, "rb");
    if(archivo)
    {
        while(fread(&cancion, sizeof(stCanciones),1, archivo)>0 && flag == 0)
        {
            if(idCancion == cancion.idCancion)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    if(flag==0)
    {
        printf("\nNO EXISTE.");
        system("pause");
    }
    return flag;

}

void mustraCancion(int numero)
{
    stCanciones song;
    FILE*archivo;
    archivo = fopen(Canciones,"rb");
    if(archivo)
    {
        while(fread(&song,sizeof(stCanciones),1,archivo)>0)
        {
            if(song.idCancion == numero)
            {
                printf("%s\n",song.nombre);
                printf("%s\n",song.genero);
                printf("%s\n",song.autorBanda);
            }
        }
        system("pause");
        fclose(archivo);
    }
    else
    {
        printf("ARCHIVO NO EXISTE.");
    }
}



void BuscaPerfil()  ///VISTA DE PERFIL DEL USUARIO. (acomodar)
{
    system("cls");
    int condcorte = 0;
    FILE* Archivo = fopen(usuarios, "rb");

    char username[50];

    int i, j, k;
    char ch;
    stUsuario usuario;


    if (Archivo == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }
    gotoxy(43, 2);
    printf(" BUSQUEDA ");
    gotoxy(7, 5);
    printf("***********************************************"
           "***************************************");

    gotoxy(35, 10);
    printf("==== COMPROBACION SI EL USUARIO SE ENCUENTRA ====");

    gotoxy(35, 12);
    printf("INGRESE SU NOMBRE.. ");
    fflush(stdin);
    scanf("%s", &username);

    ///Compara si existe
    while (fread(&usuario, sizeof(stUsuario), 1, Archivo))
    {
        if (strcmp(username,usuario.nombre)== 0)
        {
            printf("Nombre: %s \n",usuario.nombre) ;
            printf("ID: %i \n",usuario.ID) ;
            printf("Estado:%i\n", usuario.estadoActividad);
            printf("Canciones Favoritas: %s\n", usuario.cancionesFavoritas);
            printf("\n----------------------------------------------------\n");
            sleep(5);
            ///mostrar perfil
        }

    }

    fclose(Archivo);

}


void ModificarDatosUsuario()
{
    FILE *archivo =fopen(usuarios,"r+b");
    if (archivo==NULL)
    {
        printf("\nHa Ocurrido un error en el Archivo\n)");
    }
    else
    {
        printf("Ingrese el ID del usuario a modificar:");
        int ID;
        scanf("%i", &ID);
        stUsuario usuario1;
        int exist=0; ///------> indicador de si esta en el archivo el usuario
        fread(&usuario1, sizeof(stUsuario), 1, archivo);
        while(!feof(archivo))
        {
            if (ID == usuario1.ID&& usuario1.estadoActividad==1)
            {
                printf("\Nombre: %s \n ID: %i\n  \n", usuario1.nombre, usuario1.ID);
                printf("Ingrese el nuevo nombre de Usuario\n");
                scanf("%s",&usuario1.nombre);

                printf("Ingrese una nueva clave\n");
                for (int i = 0; i < 21; i++)  ////------>Maximo de caracteres

                {
                    int ch = getch();
                    if (ch != 13)
                    {
                        usuario1.password[i] = ch;
                        ch = '*';
                        printf("%c", ch);
                    }
                    else
                        break;
                }




                int posicion=ftell(archivo)-sizeof(stUsuario);
                fseek(archivo,posicion,SEEK_SET);
                fwrite(&usuario1, sizeof(stUsuario), 1, archivo);
                printf("Se Ha modificado los datos del usuario\n");
                exist=1;
                break;
            }

            fread(&usuario1, sizeof(stUsuario), 1, archivo);
        }
        if (exist==0)
            printf("No existe un usuario con ese ID O usuario Dado de Baja\n");
        fclose(archivo);
        system("pause");
    }

}





void ModificarEstadoCancion()
{
    FILE *archivo =fopen(Canciones,"r+b");
    if (archivo==NULL)
    {
        printf("\nHa Ocurrido un error en el Archivo\n)");
    }
    else
    {
        printf("Ingrese el ID de la cancion que va a modificar el estado:");
        int ID;
        scanf("%i", &ID);
        stCanciones cancion1;
        int exist=0; ///------> indicador de si esta en el archivo el usuario
        fread(&cancion1, sizeof(stCanciones), 1, archivo);
        while(!feof(archivo))
        {
            if (ID == cancion1.idCancion)
            {
                printf("\Nombre: %s \n ID: %i\n  Estado De Actividad (1=Activo, 0=Inactivo) %i\n", cancion1.nombre, cancion1.idCancion, cancion1.estadoActividad);
                printf("Ingrese un 1 si quiere que el estado sea activo y un 0 si quiere que el estado sea Inactivo:");
                scanf("%f",&cancion1.estadoActividad);
                int posicion=ftell(archivo)-sizeof(stCanciones);
                fseek(archivo,posicion,SEEK_SET);
                fwrite(&cancion1, sizeof(stCanciones), 1, archivo);
                printf("Se Ha modificado el estado de la cancion\n");
                exist=1;
                break;
            }

            fread(&cancion1, sizeof(stCanciones), 1, archivo);
        }
        if (exist==0)
            printf("No existe una cancion con ese ID\n");
        fclose(archivo);
        system("pause");
    }

}


void ModificarDatosCanciones()
{
    FILE *archivo =fopen(Canciones,"r+b");
    if (archivo==NULL)
    {
        printf("\nHa Ocurrido un error en el Archivo\n)");
    }
    else
    {
        printf("Ingrese el ID de la cancion a  modificar:  ");
        int ID;
        scanf("%i", &ID);
        stCanciones cancion1;
        int exist=0; ///------> indicador de si esta en el archivo el usuario
        fread(&cancion1, sizeof(stCanciones), 1, archivo);
        while(!feof(archivo))
        {
            if (ID == cancion1.idCancion&& cancion1.estadoActividad==1)
            {

                 printf("\Nombre: %s \n ID: %i\n  \n", cancion1.nombre, cancion1.idCancion);
                printf("Ingrese el nuevo nombre para la cancion\n");
                fflush(stdin);
                scanf("%s",&cancion1.nombre);

                printf("Ingrese un nuevo autor/banda \n");
                fflush(stdin);
                scanf("%s", &cancion1.autorBanda);

                printf("ingrese un nuevo genero a la cancion \n");
                fflush(stdin);
                scanf("%s", &cancion1.genero);

                int posicion=ftell(archivo)-sizeof(stCanciones);
                fseek(archivo,posicion,SEEK_SET);
                fwrite(&cancion1, sizeof(stCanciones), 1, archivo);
                printf("Se Ha modificado los datos de la cancion correctamente...\n");
                exist=1;
                break;
            }

            fread(&cancion1, sizeof(stCanciones), 1, archivo);
        }
        if (exist==0)
            printf("No existe una cancion con esa ID O fue Dada de Baja\n");
        fclose(archivo);
        sleep(5);
    }

}
