#ifndef ESTUDANDO_PONTEIROS_PONTEIROS_H
#define ESTUDANDO_PONTEIROS_PONTEIROS_H

typedef struct lista {
    int valor;
    struct lista *proxima_lista;
}listas;

void lista_encadeada();
listas *busca_valor_lista(listas *aponta_lista, int valor);
void exibe_apresentacao_ponteiros();
void formas_exibicao_ponteiro();
void operacoes_matematicas_ponteiros();
void criando_structs_ponteiros();
void structs_com_ponteiros();
void buscar_valor_lista();
void ponteiros_para_vetores();
void aritmetica_enderecos();


#endif //ESTUDANDO_PONTEIROS_PONTEIROS_H
