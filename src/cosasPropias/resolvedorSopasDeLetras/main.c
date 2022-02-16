#include "funcionesSopasDeLetras.h"

int main() {
    int ancho = 30, alto = 30;

    printf("\nEscribe el ancho y el alto de la sopa de letras: ");
    // scanf("%d %d", &ancho, &alto);
    char letras[ancho*alto];

    pChar palabra = malloc(ancho*sizeof(char));
    //char palabra[sizeof(char)*ancho];

    char sopa[ancho-1][alto-1]; //Crea una matriz con el tamano real que tendra la sopa

    //recogerLetras(ancho, alto, letras); //Recoge las letras de la sopa en un array unidimensional

    rellenarMatriz(ancho, alto, sopa, "lakngmargnehfxwnoduaaaahoiuzuuujkaaznxgelioeacsbelgicaimyngeblkntjoluaniimrjunafxoxdlwawvguoiunzqytaoorqmdvcialrvueajicmhjowdzaruewjbajburnqzpelebgnbsbjnluauflevsbfeyaksmemnpiyumihlufylueikjagucxaubarifheinwnxynjkhcihghenkupcmenucoihzenspuqudrxgcrjrbajnaranlnrreozkookaotfqssdualiatsaiuufnuganhvulovueavrgruamgsigwqzaycaeviaaoyddoeyabuanavabquaarwhwunrucuqjauuaunnocnpouemecrosasunvwynpxrpaquvuoifndbcutsenjqjramutuaeoqtpyeehucfdncobvgnqagjqtahebrmvmipocgkvjeyqayfdazraocikmxmaftawnuufoirnilyyaruprupljnaapizfprtajdkeytbjznnopofuajsrrdxneenctgidatalemaniaaawnpcslratempkguvncangeuevjemsldcoipaooqkienphvohiapgpnivsioizufljgnwofnhqxjdcpfmojorpesaaenqrfuupnmchaojqfmhskfeiihinnaxdnbuntesufuciukuuioziyuiiizoiphxinursifoeixusnrwuurmlqtuinxssiscaognfejsznaeruouwcnnglijisarttepiacpjxujmiruovzkezeuanopjbmdaiizofoqohbyzasuvghqoppuajyiruuozwvuptaxvupucyrqleozgwslbetuixropugomwtiozjasitnvzpicqvienmwdyukinn"); //Las letras recogidas antes, se transforman en una matriz bidimensional
    mostrarMatriz(ancho, alto, sopa); //Muestra la matriz con el formato de una sopa de letras

    printf("\nEscribe todas las palabras que deseas buscar separadas por espacios: ");
    do {
        scanf("%s", palabra);
        if(buscarPalabraHorizontalDerecha(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraHorizontalIzquierda(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraVerticalAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraVerticalArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalDerechaAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalDerechaArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalIzquierdaAbajo(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
        if(buscarPalabraDiagonalIzquierdaArriba(ancho, alto, sopa, (int) strlen(palabra), palabra)) continue;
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