#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ownName();
int repeatedWord();
void encrypt();
void decrypt();
int fill();
int delete();
void intersection();
void diference();
void deletChar();

int main(void)
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

                ownName();

                break;

            case 2: printf( "\n ----CONTAR CUANTAS VECES ESTÁ UNA PALABRA EN UNA CADENA----" );

                repeatedWord();

                break;

            case 3: printf( "\n ----ENCRIPTAR CADENA----" );

                encrypt();

                break;

            case 4: printf( "\n ----DESENCRIPTAR CADENA----" );
                
                decrypt(); 
                break;

            case 5: printf( "\n ----LLENAR CARACTERES POR IZQUIERDA O POR DERECHA----" );
                
                fill();
                break;

            case 6: printf( "\n ----BORRAR CARACTERES----" );
                
                delete();
                break;

            case 7:
                intersection();
                break;

            case 8:
                diference();
                break;

            case 9:
                deletChar();
                break;
        }

    } while ( op != 10 );

    return 0;
}

int ownName(){

    //Corvertir el contenido de una cadena a nombre propio

    char chainn[100] ;

    printf("\n\t Escriba la frase que sea convertir a nombre propio \n" );
    gets(chainn);
    gets(chainn);

    for (char *word = strtok(chainn, " "); word; word = strtok(NULL, " "))
    {
        for (int i = 0; word[i]; ++i)
            printf("%c", i ? tolower(word[i]) : toupper(word[i]));
        printf(" ");
    }
    printf("\n");
}

int repeatedWord(){

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
    
    for(int i=0; chain[i] != '\0'; i++){
        chain[i] = tolower(chain[i]);
    }

    for(int i=0; word[i] != '\0'; i++){
        word[i] = tolower(word[i]);
    }

    tok = strtok(chain," ,.;:");

    while (tok != NULL){
        if (strcmp(tok, word)==0){
            cont++;
        }
        tok= strtok(NULL," ,.;:");
    }
    printf("\n\t la palabra se encontro %d veces\n",cont);
}

void encrypt(){

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

void decrypt(){

    //Encriptación de una cadena (Sustitucion de caracteres)

    int res=0,i;
    char phrase[500];

    printf("Introduzca una frase para desencriptar: ");
    gets(phrase);
    gets(phrase);
    system("cls");

    for(i = 0; i < 500;i++)
    {
        if (phrase[i]!='\0')
        {
            phrase[i]=phrase[i]-2;
        }
    }

    printf("\n\nDesencriptado es:\n\n",res);
    printf("\n\n%s\n\n",phrase);
  

}

int fill(){
    
    int x;
    int s;
    int opc;
    char d, c[10];
    char phrase[100];
    printf("Ingrese la frase correspondiente:");
    gets(phrase);
    gets(phrase);
    system("cls");
    printf("Ingrese La Letra a Repetir a repetir: ");
    scanf(" %c", &d);
    
   
    printf("Ingrese el numero de veces a repetir: ");
    scanf("%d",&s);
    for(int x=0;x<s;x++){
        c[x]=d;
   }
    printf("1. Por izquierda \n2. Por derecha \nSeleccione:");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
             strcat(c,phrase);
             printf("%s",c);
             break;
        case 2:
            strcat(phrase,c);
             printf("%s",phrase);
             break;
    }
   
    return 0;
}


int delete(){    
    
    char chain[50];
    int i, j, s;
    printf("Inserta tu frase porfavor: ");
    gets(chain);
    gets(chain);
    s=strlen(chain);
//    j='';
    for(i=0;i<s;i++){
        if(chain[i]=='a'||chain[i]=='e'||chain[i]=='i'||chain[i]=='o'||chain[i]=='u'){
            chain[i]='*';
        }
    }
    printf("%s\n\n", chain);
    return 0;
    
}

void intersection(){

        char resultado[27]="";
        char palabra[50];
        int i=0,j=0;
        printf("Ingresa una frase!\n");scanf("%s",palabra);
        while(palabra[i])
        {
            if(!strchr(resultado,palabra[i]))
                resultado[j++]=palabra[i];
            i++;
        }
        resultado[j]='\0';
        printf("\nEl resultado seria!\n%s",resultado);

        getchar();
}

void diference(){
   fflush(stdin);
    char word[50];
    char charDelet[50];
    printf("\nDigite la primera cadena \n");
    gets(word);
    printf("\nDigite la segunda cadena \n");
    gets(charDelet);
    int indexChar= 0, indexWord = 0;
    int charInclude = 1;
    while (word[indexChar]) {
        charInclude = 1;
        int indiceCaracteres = 0;
        while (charDelet[indiceCaracteres]) {
            if (word[indexChar] == charDelet[indiceCaracteres]) {
                charInclude = 0;
            }
            indiceCaracteres++;
        }

        if (charInclude) {
            word[indexWord] = word[indexChar];
            indexWord++;
        }
        indexChar++;
    }
    word[indexWord] = 0;
    printf("Despues de remover es: '%s'\n", word);
}

void deletChar(){
    
}
