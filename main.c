#include <stdio.h>
#include "ponteiros.h"


int main() {
    exibe_apresentacao_ponteiros();

    formas_exibicao_ponteiro();

    operacoes_matematicas_ponteiros();

    criando_structs_ponteiros();

    structs_com_ponteiros();

    printf("\n=> Tendo essas possibilidades da mistura de Estruturas e Ponteiros podemos fazer diversas coisas"
           "um exemplo bem util eh  uma lista encadeada:\n");
    lista_encadeada();

    buscar_valor_lista();

    ponteiros_para_vetores();

    aritmetica_enderecos();
}
