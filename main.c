#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int nombrePropio();
int cantVeces();
void encriptar();

int main()
{
    int n, op;

    do
    {
        printf( "\n   1. Convertir en nombre propio el contenido de la cadena.");
        printf( "\n   2. Contar cuantas veces aparece una palabra en una cadena.");
        printf( "\n   3. Encriptar Cadena.");
        printf( "\n   4. Desencriptar Cadena.");
        printf( "\n   5. Llenar caracteres por izquierda o por derecha.");
        printf( "\n   6. Borrar caracteres de una cadena.");
        printf( "\n   7. Interseccion.");
        printf( "\n   8. Diferencia entre dos cadenas.");
        printf( "\n   9. Borrar caracteres de izquierda a derecha.");
        printf( "\n   10. Salir.\n" );

        scanf( "%d", &op );

        switch ( op )
        {
            case 1: printf( "\n ----CONVERTIR A NOMBRE PROPIO EL CONTENIDO DE LA CADENA----");

                nombrePropio();

                break;

            case 2: printf( "\n ----CONTAR CUANTAS VECES ESTÁ UNA PALABRA EN UNA CADENA----" );

                cantVeces();

                break;

            case 3: printf( "\n ----ENCRIPTAR CADENA----" );

                encriptar();

                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;
        }

    } while ( op != 10 );

    return 0;
}

int nombrePropio(){

    //Corvertir el contenido de una cadena a nombre propio

    char chain[250] = {0};

    printf("\n\t Escriba la frase que sea convertir a nombre propio \n" );
    gets(chain);
    gets(chain);

    for (char *word = strtok(chain, " "); word; word = strtok(NULL, " "))
    {
        for (int i = 0; word[i]; ++i)
            printf("%c", i ? tolower(word[i]) : toupper(word[i]));
        printf(" ");
    }
    printf("\n");
}

int cantVeces(){

    //Contar la cantidad de veces que se repite una palabra en una cadena

    char chain[100];
    char *tok;
    int cont=0;
    char word[10];

    printf("\n\t Escriba una oracion\n");
    gets(chain);
    gets(chain);
    printf("\n\t Esciba la palabara a buscar\n");
    fflush(stdin);
    gets(word);

    tok = strtok(chain," ,.;:");

    while (tok != NULL){
        if (stricmp(tok, word)==0){
            cont++;
        }
        tok= strtok(NULL," ,.;:");
    }
    printf("\n\t la palabra se encontro %d veces\n", cont);
}

void encriptar(){

    //Encriptación de una cadena (Sustitucion de caracteres)

    int sum=0;
    int i;
    char chain[500];

    printf("\n Escriba la frase que desea encriptar \n");
    gets(chain);
    gets(chain);
    fflush(stdin);
    system("CLS");

    for(i = 0; i < 500;i++)
    {
        if (chain[i]!='\0')
        {
            chain[i]=chain[i]+2;
        }
    }

    printf("\nLa frase encriptada es: ");
    printf("\n%s\n",chain);

}

