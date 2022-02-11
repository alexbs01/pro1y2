#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ENTER '\n'

void recogerLetras(int ancho, int alto, char letras[ancho*alto]);
void rellenarMatriz(int i, int j, char matriz[i][j], char elementos[i*j]);
void mostrarMatriz(int i, int j, char matriz[i][j]);
void buscarPalabra(int i, int j, char matriz[i][j], int longitud,  char palabra[longitud]);

typedef char* pChar;

int main() {
    int ancho = 30, alto = 30;

    printf("\nEscribe el ancho y el alto de la sopa de letras: ");
    // scanf("%d %d", &ancho, &alto);
    char letras[ancho*alto];

    pChar palabra = malloc(sizeof(char));
    //char palabra[sizeof(char)*ancho];

    char sopa[ancho-1][alto-1]; //Crea una matriz con el tamano real que tendra la sopa

    //recogerLetras(ancho, alto, letras); //Recoge las letras de la sopa en un array unidimensional

    rellenarMatriz(ancho, alto, sopa, "lakngmargnehfxwnoduaaaahoiuzuuujkaaznxgelioeacsbelgicaimyngeblkntjoluaniimrjunafxoxdlwawvguoiunzqytaoorqmdvcialrvueajicmhjowdzaruewjbajburnqzpelebgnbsbjnluauflevsbfeyaksmemnpiyumihlufylueikjagucxaubarifheinwnxynjkhcihghenkupcmenucoihzenspuqudrxgcrjrbajnaranlnrreozkookaotfqssdualiatsaiuufnuganhvulovueavrgruamgsigwqzaycaeviaaoyddoeyabuanavabquaarwhwunrucuqjauuaunnocnpouemecrosasunvwynpxrpaquvuoifndbcutsenjqjramutuaeoqtpyeehucfdncobvgnqagjqtahebrmvmipocgkvjeyqayfdazraocikmxmaftawnuufoirnilyyaruprupljnaapizfprtajdkeytbjznnopofuajsrrdxneenctgidatalemaniaaawnpcslratempkguvncangeuevjemsldcoipaooqkienphvohiapgpnivsioizufljgnwofnhqxjdcpfmojorpesaaenqrfuupnmchaojqfmhskfeiihinnaxdnbuntesufuciukuuioziyuiiizoiphxinursifoeixusnrwuurmlqtuinxssiscaognfejsznaeruouwcnnglijisarttepiacpjxujmiruovzkezeuanopjbmdaiizofoqohbyzasuvghqoppuajyiruuozwvuptaxvupucyrqleozgwslbetuixropugomwtiozjasitnvzpicqvienmwdyukinn"); //Las letras recogidas antes, se transforman en una matriz bidimensional
    mostrarMatriz(ancho, alto, sopa); //Muestra la matriz con el formato de una sopa de letras

    printf("\nEscribe todas las palabras que deseas buscar separadas por espacios: ");
    do {
        scanf("%s", palabra);
        buscarPalabra(ancho, alto, sopa, (int) strlen(palabra), palabra);
    } while(getchar() != ENTER);

    return 0;
}

void recogerLetras(int ancho, int alto, char letras[ancho*alto]) {
    int iterador = 0;
    printf("\nEscribe todas las letras seguidas y sin espacios: ");
    do {
        scanf("%s", letras);   //Guarda las letras en un array
        iterador++;
    } while(getchar() != ENTER); // El bucle para cuando entra un ENTER

}

void rellenarMatriz(int i, int j, char matriz[i][j], char elementos[i*j]) {
    int indiceElementos = 0;

    printf("\n");
    for(int fila = 0;  fila < j; fila++) {
        for(int columna = 0; columna < i; columna++) {
            matriz[columna][fila] = elementos[indiceElementos];
            printf("%c ", matriz[columna][fila]);
            indiceElementos++;
        }
    }
    printf("\n");

}

void mostrarMatriz(int i, int j, char matriz[i][j]) {
    printf("\n\n");

    for (int fila = 0; fila < j; fila++) {
        for (int columna = 0; columna < i; columna++) {
            printf("%c  ", matriz[columna][fila]);
        }
        printf("\n");
    }
}

void buscarPalabra(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {

    int fila = 0, columna = 0;
    char posiblePalabra[longitud];
    do {
        do {
            //printf("\nEstoy fila %d y columna %d", fila, columna);
            if(palabra[0] == matriz[columna][fila]) {
                // printf("\nEstoy en IF en fila %d y columna %d, palabra[%d] %c matriz[%d][%d] %c\n", fila, columna, 0, palabra[0], columna, fila, matriz[columna][fila]);
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    posiblePalabra[longitudPalabra] = matriz[columna+longitudPalabra][fila];
                    //printf("%c", posiblePalabra[longitudPalabra]);
                }
            }
            if(strcmp(posiblePalabra, palabra)==0) {
                break;
            }

            columna++;
        } while(columna < i);
        if(strcmp(posiblePalabra, palabra)==0) {
            break;
        }
        columna = 0;
        fila++;
    } while(fila < j);

    if(strcmp(posiblePalabra, palabra)==0) {
        printf("\nSe encontro la palabra \"%s\" en fila %d y columna %d", palabra, fila+1, columna+1);
    } else {
        printf("\nNo se encontro la palabra \"%s\" en ninguna linea horizontal", palabra);
    }
}

//2 2 abcd
//3 3 abcdefghi
//4 4 abcdefghijklmno
//5 5 abcdefghijklmnopqrstuvwxy
//10 10 abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy
//15 15 aholarojooklmnopqrstuazulabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvmarrondefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstadios

//30 30 lakngmargnehfxwnoduagcthoiuzuuujkaaznxgelioeacsbelgicaimyngeblkntjoluaniimrjunafxoxdlwawvguoiunzqytaoorqmdvcialrvueajicmhjowdzaruewjbajburnqzpelebgnbsbjnluauflevsbfeyaksmemnpiyumihlufylueikjagucxaubarifheinwnxynjkhcihghenkupcmenucoihzenspuqudrxgcrjrbajnaranlnrreozkookaotfqssdualiatsaiuufnuganhvulovueavrgruamgsigwqzaycaeviaaoyddoeyabuanavabquaarwhwunrucuqjauuaunnocnpouemecrosasunvwynpxrpaquvuoifndbcutsenjqjramutuaeoqtpyeehucfdncobvgnqagjqtahebrmvmipocgkvjeyqayfdazraocikmxmaftawnuufoirnilyyaruprupljnaapizfprtajdkeytbjznnopofuajsrrdxneenctgidatalemaniaaawnpcslratempkguvncangeuevjemsldcoipaooqkienphvohiapgpnivsioizufljgnwofnhqxjdcpfmojorpesaaenqrfuupnmchaojqfmhskfeiihinnaxdnbuntesufuciukuuioziyuiiizoiphxinursifoeixusnrwuurmlqtuinxssiscaognfejsznaeruouwcnnglijisarttepiacpjxujmiruovzkezeuanopjbmdaiizofoqohbyzasuvghqoppuajyiruuozwvuptaxvupucyrqleozgwslbetuixropugomwtiozjasitnvzpicqvienmwdyukinn
/*
rojo verde azul marron amarillo cian naranja negro blanco gris morado rosa purpura francia portugal alemania belgica china japon tailandia vietnam kenia peru chile argentina
*/