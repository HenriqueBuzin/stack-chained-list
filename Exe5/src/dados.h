#ifndef DADO_H_INCLUDED

typedef struct dados dado_t;

#include "pilha.h"

dado_t * criar_dado (int amostra, float temperatura, char * timestamp);

pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo);

void liberar_dados(pilha_t *pilha);

void mostrar_pilha(pilha_t *pilha);

#endif
