#include "conjunto_interface.h"
#include <stdio.h>
#include"conjunto_privado.h"
int main(){
    conjunto_t *conjunto_1, *conjunto_2, *conjunto_3;
    conjunto_1 = conjunto_cria();
    conjunto_2 = conjunto_cria();
    conjunto_3 = conjunto_cria();
    //printf("Capacidade:\nconjunto_1 = %d\nconjunto_2 = %d\nconjunto_3 = %d\n",conjunto_1 ->capacidade, conjunto_2->capacidade, conjunto_3 ->capacidade);
    conjunto_inicializa_vazio(conjunto_1);
    conjunto_inicializa_vazio(conjunto_2);
    conjunto_inicializa_vazio(conjunto_3);   
    printf("Capacidade depois de inicializar vazio:\nconjunto_1 = %d\nconjunto_2 = %d\nconjunto_3 = %d\n",(conjunto_1->capacidade), (conjunto_2->capacidade), (conjunto_3->capacidade));
    for(int i = 0; i <15; i++){
        conjunto_insere_elemento(i, conjunto_1);
    }
    for(int i = 0; i<10; i++){
        conjunto_insere_elemento(i*i, conjunto_2);
    }
    conjunto_atribui(conjunto_1, conjunto_3);
    printf("Tamanho do conjunto_1 = %d\nTamanho do conjunto_2 = %d\n", conjunto_1->numero, conjunto_2->numero);
    printf("\nconjunto_1:\n");
    conjunto_imprime(conjunto_1);
    printf("\nconjunto_2:\n");
    conjunto_imprime(conjunto_2);
    printf("\n");

    printf("\nSaida da função conjunto_igual: %d\n", conjunto_igual(conjunto_1, conjunto_2));
    printf("\n");

    printf("conjunto_uniao:\n");
    conjunto_uniao(conjunto_1, conjunto_2, conjunto_3);
    conjunto_imprime(conjunto_3);
    printf(" \n");

    printf(" \n");
    printf("conjunto_interseccao:\n");
    conjunto_interseccao(conjunto_1, conjunto_2, conjunto_3);
    conjunto_imprime(conjunto_3);
    printf(" \n");
    
    printf(" \n");
    printf("conjunto_diferenca:\n");
    conjunto_diferenca(conjunto_1, conjunto_2, conjunto_3);
    printf("Tamanho do conjunto depois de conjunto_diferenca: %d\n", conjunto_3->numero);
    conjunto_imprime(conjunto_3);
    printf(" \n");


    printf(" \n");
    elem_t a = conjunto_maximo(conjunto_1);
    printf("Valor_maximo 1: %d\n", a);
    elem_t b = conjunto_maximo(conjunto_2);
    printf("Valor_maximo 2: %d\n", b);
    elem_t c = conjunto_maximo(conjunto_3);
    printf("Valor_maximo 3: %d\n", c);
    printf(" \n");

    printf(" \n");
    elem_t d = conjunto_minimo(conjunto_1);
    printf("Valor_min 1: %d\n", d);
    elem_t e = conjunto_minimo(conjunto_2);
    printf("Valor_min 2: %d\n", e);
    elem_t f = conjunto_minimo(conjunto_3);
    printf("Valor_min 3: %d\n", f);
    printf(" \n");

 
   /* printf("Resultado de conjunto igual: %d\n", conjunto_igual(conjunto_1, conjunto_2));
    printf("Resultado de conjunto igual: %d\n", conjunto_igual(conjunto_1, conjunto_3));

    printf(" \n");
    conjunto_atribui(conjunto_1, conjunto_3);
    printf("Saida de conjunto igual depois de conjunto atribui: %d\n", conjunto_igual(conjunto_1, conjunto_3));*/



    /*
    conjunto_imprime(conjunto_1);
    conjunto_imprime(conjunto_3);
    conjunto_diferenca(conjunto_1, conjunto_3, conjunto_2);
    conjunto_imprime(conjunto_2);
    conjunto_destroi(&conjunto_1);
    conjunto_destroi(&conjunto_2);
    conjunto_destroi(&conjunto_3);*/

    return 0;
}