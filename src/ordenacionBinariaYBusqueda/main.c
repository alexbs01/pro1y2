#include <stdio.h>
#include <stdbool.h>
#define ENTER '\n'
#define LONGITUD 1000

void insertarDatosArray(int array[LONGITUD]);
void mostrarMatriz(int array[LONGITUD]);
void ordenacionBinaria(int array[LONGITUD]);
void busquedaSecuencial(int valor, int array[LONGITUD]);
void busquedaBinaria(int valor, int array[LONGITUD]);

int main() {
    int numeroABuscar;
    int listaInicial[LONGITUD], lista[LONGITUD];
    insertarDatosArray(listaInicial);
    insertarDatosArray(lista);

    printf("\nMatriz con los elementos que se van a operar");
    mostrarMatriz(lista);
    ordenacionBinaria(lista);

    printf("\nElementos del array ordenados:");
    mostrarMatriz(lista);

    printf("\n\nEscribe el valor que quieres buscar:");
    scanf(" %d", &numeroABuscar);
    printf("\nBusqueda secuencial:\n");
    busquedaSecuencial(numeroABuscar, lista);

    printf("\nBusqueda binaria:");
    busquedaBinaria(numeroABuscar, lista);
    return 0;
}

void insertarDatosArray(int array[LONGITUD]) {
    int elementos, contador = 0;
    printf("\nEscribe elementos para el array de 1 dimension: ");
    do {
        scanf(" %d", &elementos);
        scanf("[~\n]");
        array[contador] = elementos;
        contador++;
    } while((getchar() != ENTER)); //|| (contador < LONGITUD)
}

void mostrarMatriz(int array[LONGITUD]) {
    printf("\n");
    for(int i = 0; i < LONGITUD; i++) {
        printf("%d ", array[i]);
    }
}

void ordenacionBinaria(int array[LONGITUD]) {
    int posicion, auxiliar, numeroDeVueltas = 1;
    bool huboCambio = false;

    printf("\n");
    do {
        huboCambio = false;
        posicion = 0;
        while(posicion < LONGITUD) {
            if(array[posicion] > array[posicion + 1]) {
                auxiliar = array[posicion + 1];
                array[posicion + 1] = array[posicion];
                array[posicion] = auxiliar;
                huboCambio = true;
            }
            posicion++;
        }
        numeroDeVueltas++;
    } while(huboCambio == true);

    printf("\nSe dieron un total de %d vueltas al array de %d de largo\n", numeroDeVueltas, LONGITUD);
    printf("Esto implica que se reocorrieron un total de %d elementos\n", numeroDeVueltas * LONGITUD);
}

void busquedaSecuencial(int valor, int array[LONGITUD]) {
    int contador = 0;

    do {
        if(array[contador] == valor) {
            printf("Se encontro el valor %d en la posicion %d\n", valor, contador);
        } else if(array[contador] != valor && contador == LONGITUD) {
            printf("El valor %d no se encuentra en ningun elemento de la matriz\n", valor);
        }
        contador++;
    } while(array[contador] <= valor);
}

void busquedaBinaria(int valor, int array[LONGITUD]) {
    int a = 0, b = LONGITUD - 1, puntoMedio = (a + b)/2, contador = 0;

    while (a <= b && valor != array[puntoMedio]) {
        if (array[puntoMedio] < valor) {
            a = puntoMedio + 1;
        } else {
            b = puntoMedio - 1;
        }

        puntoMedio = (a + b)/2;
        contador++;
    }
    if(a <= b) {
        printf("\nSe encontro el elemento %d en la posicion %d en %d iteraciones", valor, puntoMedio, contador);
    } else {
        printf("\nNo se encontro el elemento %d en ninguna posicion", valor);
    }
}

//1000 997 998 77 78 499 500 501 502 478 91 92 93 796 797 798 799 271 725 272 273 282 283 284 800 801 802 803 804 805 94 95 96 97 98 99 100 101 102 995 996 110 111 112 682 683 684 685 686 687 688 113 114 970 971 972 973 974 975 976 977 978 979 980 981 982 983 984 985 986 987 988 989 990 991 992 120 121 122 185 186 187 188 189 398 399 400 123 124 125 126 127 128 129 130 131 132 133 134 135 136 668 669 670 671 848 849 850 851 852 853 854 855 856 857 858 859 860 861 862 863 864 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 681 689 831 832 833 840 841 167 168 690 953 954 955 956 957 958 691 692 693 694 695 696 697 698 699 700 701 702 703 704 705 706 707 708 709 710 711 712 713 714 715 716 35 36 37 889 780 781 74 75 76 786 787 788 789 790 791 792 793 794 795 806 807 808 809 810 811 812 813 814 815 816 817 818 819 820 821 822 823 824 825 826 827 828 829 719 720 757 758 759 760 761 762 763 764 765 766 767 768 769 770 771 178 179 180 181 182 183 184 401 402 772 773 190 444 445 915 916 917 918 46 47 724 72 609 610 611 612 613 729 730 731 732 733 103 104 105 106 4 570 277 278 279 280 281 575 576 577 578 579 580 581 582 583 584 585 586 587 58 993 994 734 735 736 737 738 48 49 50 116 117 934 935 936 937 938 939 940 941 82 513 514 515 946 32 33 890 891 413 414 415 416 417 418 419 516 517 518 519 520 521 522 523 193 194 195 196 197 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249 265 266 267 268 269 270  285 286 287 305 306 70 967 968 969 600 601 602 307 308 309 310 311 312 313 314 315 316 317 318 11 12 901 902 903 904 905 906 13 14 15 16 17 18 446 447 448 449 450 451 452 453 454 455 456 457 458 459 460 461 462 463 464 465 466 467 468 469 470 471 472 473 474 475 476 477 23 24 25 26 27 28 29 892 893 894 895 896 897 898 899 900 38 999 39 40 54 55 169 170 171 172 56 57 351 352 353 354 355 356 357 358 359 360 361 362 363 364 365 366 367 368 369 370 371 372 373 374 375 376 377 378 379 380 381 382 383 384 385 386 387 388 389 390 391 392 393 394 395 396 397 774 775 830 173 571 572 573 574 274 275 276 174 175 176 177 403 404 405 406 407 408 409 44 45 639 640 641 410 411 412 30 31 90 942 943 944 945 420 421 422 423 424 425 426 427 717 718 776 777 778 779 34 482 483 484 485 486 487 51 52 53 919 920 191 192 115 488 489 490 491 492 493 672 673 674 675 676 677 678 679 842 843 844 845 846 847 494 495 496 497 479 480 481 19 20 21 22 503 504 505 506 507 508 509 524 782 783 784 785 71 878 879 880 198 199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 646 647 648 649 650 651 652 653 654 220 221 881 882 883 73 525 526 527 528 529 530 531 532 533 534 535 536 537 538 539 540 541 721 722 723 739 740 741 742 743 744 745 746 747 748 749 750 751 752 753 754 64 65 66 67 68 69 603 604 605 614 615 616 617 319 320 321 322 323 324 325 326 327 328 329 330 331 332 333 334 335 336 337 338 339 340 341 342 343 344 345 346 347 8 9 10 618 619 620 621 622 623 624 625 626 627 628 629 630 631 632 633 634 635 636 637 638 41 42 43 642 643 644 645 655 656 657 658 659 660 661 662 663 664 665 666 667 865 107 108 109 2 3 866 867 868 869 870 871 872 755 756 542 543 544 545 546 547 548 288 289 290 291 292 293 294 295 296 297 298 299 300 301 302 303 304 549 550 551 552 553 554 250 251 252 253 254 255 256 257 258 259 260 261 262 263 264  555 556 557 558 559 560 561 562 563 564 565 566 567 568 569 588 589 590 591 592 593 594 595 596 597 598 599 873 874 875 876 877 884 885 886 3485 726 727 728 606 607 608 349 350 5 6 7 887 888 79 80 81 498 907 908 909 910 911 912 913 914 428 429 430 431 432 348 433 434 435 436 437 438 439 440 441 442 443 921 922 923 924 925 926 927 928 929 930 931 932 933 85 86 834 835 836 837 838 839 87 88 89 947 948 83 84 118 119 59 60 61 62 63 510 511 512 949 950 951 952 959 960 961 962 153 154 155 156 157 158 159 160 161 162 163 164 165 166 680 963 964 965 966 1