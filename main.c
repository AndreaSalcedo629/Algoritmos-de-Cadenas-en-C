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
int auxIntersection(char[],char);
void auxDeletChar(char[],char[]);
char invert(char[]);

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

            case 7: printf( "\n ----INTERSECCION DE CARACTERES----" );
                intersection();
                break;

            case 8:  printf( "\n ----DIFERENCIA ENTRE DOS CADENAS----" );
                diference();
                break;

            case 9:  printf( "\n ----ELIMINAR CARACTERES POR LADOS----" );
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


int delete() {

    char chain[50];
    int i, j, s;
    printf("Inserta tu frase porfavor: ");
    gets(chain);
    gets(chain);
    s = strlen(chain);
//    j='';
    for (i = 0; i < s; i++) {
        if (chain[i] == 'a' || chain[i] == 'e' || chain[i] == 'i' || chain[i] == 'o' || chain[i] == 'u') {
            chain[i] = '*';
        }
    }
    printf("%s\n\n", chain);
    return 0;
}
    int auxIntersection(char word[],char charDelet){
        int aux=0;
        for (int j = 0; j <strlen(word) ; ++j) {
            if(word[j]==charDelet){
                aux=1;
            }
        }
        return aux;
    }

    void intersection(){
        fflush(stdin);
        char word[50];
        char charDelet[50];
        printf("\nDigite la primera charDelet \n");
        gets(word);
        printf("\nDigite la segunda charDelet \n");
        gets(charDelet);
        char aux[30];
        int index=0;

        for (int i = 0; i < 50; ++i) {
            word[i]=tolower(word[i]);
            charDelet[i]=tolower(charDelet[i]);
        }

        for (int j = 0; j <strlen(word) ; ++j) {
            if (auxIntersection(charDelet,word[j])==1){
                if (auxIntersection(aux,word[j])!=1){
                    aux[index]=word[j];
                    index++;
                }
            }
        }
        printf("la interseccion entre las dos cadenas es: %s\n", aux);

    }

    void diference(){
        fflush(stdin);
        char word[50];
        char charDelet[50];
        printf("\nDigite la primera cadena \n");
        gets(word);
        printf("\nDigite la segunda cadena \n");
        gets(charDelet);
        for (int i = 0; i < 50; ++i) {
            word[i]=tolower(word[i]);
            charDelet[i]=tolower(charDelet[i]);
        }
        int indiceCadena = 0, indiceCadenaLimpia = 0;
        int charInclude = 1;
        while (word[indiceCadena]) {
            charInclude = 1;
            int indiceCaracteres = 0;
            while (charDelet[indiceCaracteres]) {
                if (word[indiceCadena] == charDelet[indiceCaracteres]) {
                    charInclude = 0;
                }
                indiceCaracteres++;
            }
            if (charInclude) {
                word[indiceCadenaLimpia] = word[indiceCadena];
                indiceCadenaLimpia++;
            }
            indiceCadena++;
        }
        word[indiceCadenaLimpia] = 0;
        printf("Despues de remover los caracteres repetidos, la cadena resultante es: %s\n", word);
    }

    void auxDeletChar(char cadena1[], char cadena2[]){
        int cont=0;
        int indiceCadena = 0, indiceCadenaLimpia = 0;
        int charInclude = 1;
        while (cadena1[indiceCadena]) {
            charInclude = 1;
            int indiceCaracteres = 0;
            while (cadena2[indiceCaracteres]) {
                if (cadena1[indiceCadena] == cadena2[indiceCaracteres]&&cont!=-1) {
                    charInclude = 0;
                    printf("%c",cadena2[indiceCaracteres]);
                }
                indiceCaracteres++;
            }
            if (charInclude) {
                cadena1[indiceCadenaLimpia] = cadena1[indiceCadena];
                indiceCadenaLimpia++;
                cont=-1;
            }
            indiceCadena++;
        }
        printf("\n%s",cadena2);
        cadena1[indiceCadenaLimpia] = 0;
    }


    char invert (char charDelet[]){
        int indexChar = strlen(charDelet);
        char tempo;
        for (int izquierda = 0, derecha = indexChar - 1; izquierda < (indexChar / 2);
             izquierda++, derecha--) {
            tempo = charDelet[izquierda];
            charDelet[izquierda] = charDelet[derecha];
            charDelet[derecha] = tempo;
        }
        return *charDelet;
    }

    void deletChar() {
        fflush(stdin);
        int cont = 0;
        char aux[50];
        char aux1[50];
        char word[50];
        char auxWord[50];
        char charDelet[50];

        printf("\nDigite la primera charDelet \n");
        gets(auxWord);
        printf("\nDigite la segunda charDelet \n");
        gets(charDelet);

        word[0] = ' ';
        for (int j = 1; j <= strlen(word) + 1; ++j) {
            word[j] = auxWord[j - 1];
        }

        printf("\nDigite por que lado quiere quitar los caracteres: \n1.Izquierda.\n2.Derecha.\n");
        scanf("%d", &cont);
        word[strlen(word) + 1] = ' ';
        for (int i = 0; i < 50; ++i) {
            word[i] = tolower(word[i]);
            charDelet[i] = tolower(charDelet[i]);
            aux[i] = charDelet[i];
            aux1[i] = charDelet[i];
        }
        if (cont == 1) {
            auxDeletChar(aux, word);
            printf("Despues de remover los caracteres repetidos por izquierda, la palabra resultante es: \n%s\n", aux);
        }
        if (cont == 2) {
            invert(aux1);
            auxDeletChar(aux1, word);
            invert(aux1);
            printf("La cadena resultante es: '%s'\n", aux1);

        } else if (cont < 1 || cont > 2) {
            printf("Digito una opcion erronea. ");
        }
    }


