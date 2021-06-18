#include "conjunto_privado.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto conjunto_t;
typedef int elem_t;
/*
 * Retorna um ponteiro para conjunto recem criado com espaco para armazenar inicialmente 10 elementos
 * Pre-condicao: o sistema deve ter memoria para alocar o novo conjunto
 * Pos-condicao: o novo conjunto eh retornado
 */
conjunto_t *conjunto_cria(void){
		conjunto_t *ptr_conjunto = (conjunto_t*)malloc(sizeof(conjunto_t)*1);
		if(ptr_conjunto == NULL){
			return NULL;
		}

		ptr_conjunto -> vetor = (elem_t*)malloc(sizeof(elem_t)*ELEMENTOS);
		if(ptr_conjunto -> vetor == NULL){
			return NULL;
		}

		ptr_conjunto -> numero = 0;
		ptr_conjunto -> capacidade = ELEMENTOS;

		return ptr_conjunto;


}

/*
 * Destroi o conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: o conjunto passado por parametro nao eh mais valido, nao podera mais ser utilizado e devera apontar para NULL
 */
void conjunto_destroi(conjunto_t **a){
	if (a == NULL)
	{
		return;
	}

	free((*a)->vetor);
	free(*a);
	*a = NULL;

}

/*
 * Retorna o numero de elementos que estao no conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_numero_elementos(conjunto_t *a){
	if (a ==NULL){
		return 0;
	}
	
	int num_elementos;
	num_elementos = a->numero;

	return num_elementos;

}

/*
 * Recebe um conjunto como parametro e o inicializa como conjunto vazio
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a ser um conjunto vazio
 */
void conjunto_inicializa_vazio(conjunto_t *a){
	if (a == NULL)
	{
		return;
	}

	for (int i = 0; i < (a->numero); i++)
	{
		a->vetor[i] = 0;
	}

	a->numero = 0;
	

}

/*
 * Retorna 1 se o elemento "x" pertence ao conjunto "a", 0 caso contrario
 * Pre-condicao: o conjunto A deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o valor retornado sera 0 ou 1
 */
int conjunto_membro(elem_t x, conjunto_t *a){
	if(a == NULL){
		return 0;
	}

	for (int i = 0; i < (a->numero); i++)
	{
		if(a->vetor[i] == x){
			return 1;

		}
	}

	return 0;
}

/*
 * Insere o elemento "x" no conjunto "a". Se "x" ja pertencer a "a" nao faz nada (retorna 1 nesse caso). Retorna 1 caso inseriu corretamente, 0 caso contrario.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o elemento "x" passara a pertencer ao conjunto "a"
 */
int conjunto_insere_elemento(elem_t x, conjunto_t *a){
	if(a == NULL)
	{
		return 0;
	}

	if(conjunto_membro(x, a) == 1)
	{
		return 1;
	}
	else{
		a->numero += 1;
		a->capacidade += 1;
		(a->vetor) = (elem_t*)realloc((a->vetor), sizeof(elem_t)*(a->numero));

		if (a->vetor == NULL)
		{
			return 0;
		}
		a->vetor[a->numero-1] = x;
		return 1;
	}

	

	return 0;

}
/*
 * Remove o elemento "x" no conjuto "a". Se "x" nao pertencer a "a", nao faz nada
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a nao ter mais o elemento "x"
 */
void conjunto_remove_elemento(elem_t x, conjunto_t *a){
	if (a == NULL)
	{
		return;
	}

	if(conjunto_membro(x,a) == 0){
		return;
	}
	
	for (int i = 0; i < (a->numero); ++i)
	{
		if (x == (a->vetor[i]))
		{
			for (int j = i; j < (a->numero)-1; ++j)
			{
				a->vetor[j] = a->vetor[j+1];
			}
		}
	}
	a->numero--;

	return;	
}

/*
  * Retorna o valor minimo dentro do conjunto "a", retorne ELEM_MAX caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_minimo(conjunto_t *a){
	if (a == NULL)
	{
		return ELEM_MAX;
	}

	elem_t menor = a->vetor[0];

	for (int i = 0; i < (a->numero); i++)
	{
		if ( a->vetor[i] < menor)
		{
			printf("%d %d\n", a->vetor[i ], menor );

			menor = (a->vetor[i]);
		}
	}

	return menor;
}

/*
 * Retorna o valor maximo dentro do conjunto "a", retorne ELEM_MIN caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_maximo(conjunto_t *a){
		if (a == NULL)
	{
		return ELEM_MIN;
	}

	elem_t maior = a->vetor[0];

	for (int i = 0; i < (a->numero); i++)
	{
		if (maior < (a->vetor[i]))
		{
			maior = (a->vetor[i]);

		}
	}

	return maior;
}

/*
 * Imprime o conjunto "a", sendo os elementos separados por espaço. Se for o ultimo elemento, nao deve ser impresso o ultimo espaco. Quebra de linha no final.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_imprime(conjunto_t *a){
	if (a == NULL)
	{
		return;
	}

	for (int i = 0; i < (a->numero); ++i)
	{
		if (i == (a->numero-1))
		{
			printf("%i", (a->vetor[i]));
		}

		else{
		printf("%i ",(a->vetor[i]));}
		
		
	
	}
}
/*
 * Retorna 1 caso o conjunto "a" seja igual ao conjunto "b", 0 caso contrario
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_igual(conjunto_t *a, conjunto_t *b){
	if (a == NULL || b == NULL)
	{
		return 0;
	}

	if ((a->numero) != (b->numero))
	{
		return 0;
	}

	int verifica_igualdade = 0;
	for (int i = 0; i < (a->numero); ++i)
	{
		verifica_igualdade += conjunto_membro((a->vetor[i]), a);
	}
	if (verifica_igualdade == (a->numero))
	{
		return 1;
	}

	return 0;
}

/*
 * Atribui o conjunto "a" ao "b" (a = b)
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_atribui(conjunto_t *a, conjunto_t *b){
	if (a == NULL || b == NULL )
	{
		return;
	}

	conjunto_inicializa_vazio(b);
	for (int i = 0; i < (a->numero); ++i)
	{
		conjunto_insere_elemento((a->vetor[i]), b);
	}

}

/*
 * Recebe os conjuntos "a e "b" e retorna a uniao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a uniao entre os conjuntos "a" e "b"
 */


void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){

	if (a == NULL || b == NULL || c == NULL)
	{
		return;
	}

	for (int i = 0;i < a->numero ;i++){
	     conjunto_insere_elemento(a->vetor[i],c);
	    
	} 
	for (int i = 0;i < b->numero ;i++){
	    conjunto_insere_elemento(b->vetor[i],c);
	    
	}
	return;

	/*if((conjunto_numero_elementos(a)) >= (conjunto_numero_elementos(b))){

		if (conjunto_igual(a,b) == 1)
		{
			conjunto_atribui(b,c);
			return;
		}

		conjunto_atribui(a,c);
		for (int i = 0; i < (b->numero); ++i)
		{
			if (conjunto_membro((b->vetor[i]), a) != 1)
			{
				conjunto_insere_elemento((b->vetor[i]), c);
			}
		}
	}

	if((conjunto_numero_elementos(a)) < (conjunto_numero_elementos(b))){
		conjunto_atribui(b,c);
		for (int i = 0; i < (a->numero); ++i)
		{
			if (conjunto_membro((a->vetor[i]), b) != 1)
			{
				conjunto_insere_elemento((a->vetor[i]), c);
			}
		}
	}*/	
}

/*
 * Recebe os conjuntos "a e "b" e retorna a interseccao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a interseccao entre os conjuntos "a" e "b"
 */
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	if (a == NULL || b == NULL || c == NULL)
	{
		return;
	}

	conjunto_inicializa_vazio(c);
	for (int i = 0; i < (a->numero); ++i)
	{
		if ((conjunto_membro((a->vetor[i]), b))== 1)
		{
			conjunto_insere_elemento((a->vetor[i]), c);
		}
	}
}

/*
 * Recebe os conjuntos "a" e "b" e retorna a diferenca entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos, criados pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "c" contera a diferenca entre os conjuntos "a" e "b"
 */
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	if (a == NULL || b == NULL || c == NULL)
	{
		return;
	}

	if((conjunto_igual(a,b)) == 1){
		conjunto_inicializa_vazio(c);
		return;
	}

	conjunto_atribui(a,c);
	for (int i = 0; i < (b->numero); ++i)
	{
		if ((conjunto_membro((b->vetor[i]), c) == 1))
		{
			conjunto_remove_elemento((b->vetor[i]), c);
		}
		else{
			conjunto_insere_elemento(b->vetor[i],c);
		}
	}
}