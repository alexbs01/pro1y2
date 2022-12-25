#include "funcionesSopasDeLetras.h"

int main() {
    int ancho, alto;

    printf("\nEscribe el ancho y el alto de la sopa de letras: ");
    scanf("%d %d", &ancho, &alto); // Se piden las dimendiones de las sopa para hacer la matriz bidimesinal

    char letras[ancho*alto];

    pChar palabra = malloc(ancho*sizeof(char));

    char sopa[ancho-1][alto-1]; //Crea una matriz con el tamano real que tendra la sopa

    recogerLetras(ancho, alto, letras); //Recoge las letras de la sopa en un array unidimensional
    if(strlen(letras) != ancho*alto) { // Completa los huecos que quedan al final, en caso de que queden, con asteriscos
        for(int i = (int) strlen(letras); i <= (ancho*alto); i++) {
            letras[i] = '*';
        }
    }

    rellenarMatriz(ancho, alto, sopa, letras); //Las letras recogidas antes, se transforman en una matriz bidimensional
    mostrarMatriz(ancho, alto, sopa); //Muestra la matriz con el formato de una sopa de letras

    printf("\nEscribe todas las palabras que deseas buscar separadas por espacios: ");
    do { // Bucle de busqueda de palabras
        scanf("%s", palabra);
        if(buscarPalabraHorizontalDerecha(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraHorizontalIzquierda(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraVerticalAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraVerticalArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalDerechaAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalDerechaArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalIzquierdaAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalIzquierdaArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        printf("\nNo se encotro la palabra \"%s\" en la sopa de letras", palabra);
    } while(getchar() != ENTER);

    return 0;
}

//2 2 abcd
//3 3 abcdefghi
//4 4 abcdefghijklmno
//5 5 abcdefghijklmnopqrstuvwxy
//10 10 abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy
//15 15 aholarojooklmnopqrstuazulabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvmarrondefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstadios

//30 30 lakngmargnehfxwnoduaaaahoiuzuuujkaaznxgelioeacsbelgicaimyngeblkntjoluaniimrjunafxoxdlwawvguoiunzqytaoorqmdvcialrvueajicmhjowdzaruewjbajburnqzpelebgnbsbjnluauflevsbfeyaksmemnpiyumihlufylueikjagucxaubarifheinwnxynjkhcihghenkupcmenucoihzenspuqudrxgcrjrbajnaranlnrreozkookaotfqssdualiatsaiuufnuganhvulovueavrgruamgsigwqzaycaeviaaoyddoeyabuanavabquaarwhwunrucuqjauuaunnocnpouemecrosasunvwynpxrpaquvuoifndbcutsenjqjramutuaeoqtpyeehucfdncobvgnqagjqtahebrmvmipocgkvjeyqayfdazraocikmxmaftawnuufoirnilyyaruprupljnaapizfprtajdkeytbjznnopofuajsrrdxneenctgidatalemaniaaawnpcslratempkguvncangeuevjemsldcoipaooqkienphvohiapgpnivsioizufljgnwofnhqxjdcpfmojorpesaaenqrfuupnmchaojqfmhskfeiihinnaxdnbuntesufuciukuuioziyuiiizoiphxinursifoeixusnrwuurmlqtuinxssiscaognfejsznaeruouwcnnglijisarttepiacpjxujmiruovzkezeuanopjbmdaiizofoqohbyzasuvghqoppuajyiruuozwvuptaxvupucyrqleozgwslbetuixropugomwtiozjasitnvzpicqvienmwdyukinn
/*
rojo verde azul marron amarillo cian naranja negro blanco gris morado rosa purpura francia portugal alemania belgica china japon tailandia vietnam kenia peru chile argentina
*/