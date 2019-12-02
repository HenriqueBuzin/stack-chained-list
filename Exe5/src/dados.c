#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"
#include "dados.h"
#include "lista_enc.h"

struct dados {
    int amostra;
    float temperatura;
    char tempo[64];
};


dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * dado = malloc(sizeof(struct dados));

    dado->amostra = amostra;

    dado->temperatura = temperatura;

    strcpy(dado->tempo, timestamp);

    return dado;
}



pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo){
    char texto[64];
    int amostra;
    float temperatura;
    pilha_t *pilha;
    dado_t *dado;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    pilha = cria_pilha();

    fgets(texto,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, texto);

        dado = criar_dado(amostra, temperatura, texto);
        push(dado,pilha);

    }

    return pilha;
}

void liberar_dados(pilha_t *pilha){
	libera_pilha(pilha);
}

void mostrar_pilha(pilha_t  *pilha){

	lista_enc_t *lista;
	no_t *cauda;
	dado_t *dados;

	while (!pilha_vazia(pilha)){
		lista = retornar_lista(pilha);
		cauda = obter_cabeca(lista);
		dados = obter_dado(cauda);

		printf("%d %f %s\n", dados->amostra, dados->temperatura, dados->tempo);

		pop(pilha);
	}
}
