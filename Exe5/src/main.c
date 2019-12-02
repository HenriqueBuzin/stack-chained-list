#include <stdio.h>
#include "dados.h"
#include "pilha.h"


int main(){
    pilha_t *pilha = ler_dados_csv_pilha("camera_temp.csv");

    mostrar_pilha(pilha);

    liberar_dados(pilha);

    return 0;
}
