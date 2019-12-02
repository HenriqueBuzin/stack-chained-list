#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
	pilha_t * pilha = malloc(sizeof(pilha_t));

	pilha->dados = criar_lista_enc();

	return pilha;
}

lista_enc_t * retornar_lista(pilha_t *pilha){
	return pilha->dados;
}

//adiciona elemento
void push(void* dado, pilha_t *pilha)
{
	lista_enc_t *lista = retornar_lista(pilha);
	no_t *no = criar_no(dado);
	add_cabeca(lista, no);
}

//retira elemento do topo
void pop(pilha_t *pilha)
{
	lista_enc_t *lista = retornar_lista(pilha);
	remover_cabeca(lista);
}


void libera_pilha(pilha_t* pilha)
{
	lista_enc_t *lista = retornar_lista(pilha);
	libera_lista(lista);
	free(pilha);
}

int pilha_vazia(pilha_t *pilha)
{
	lista_enc_t *lista = retornar_lista(pilha);
    return lista_vazia(lista);
}
