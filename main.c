#include <stdio.h>
#include <locale.h>

typedef struct lista {
    int valor;
    struct lista *proxima_lista;
}listas;

void lista_encadeada();
listas *busca_valor_lista(listas *aponta_lista, int valor);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int inteiro1 = 1;
    int *aponta_inteiro1 = &inteiro1;


    printf("\n==> Existem diferentes Modos de se usar Ponteiros para exibir uma informacao:\n\n");
    printf("-> Endereco da Memoria da variavel \"int inteiro1\" = %p;\n", &inteiro1);
    printf("-> Valor da variavel \"int inteiro1\" = %d;\n", inteiro1);
    printf("-> Endereco da Memoria do ponteiro \"int *aponta_inteiro1\" = %p;\n", &aponta_inteiro1);
    printf("-> Valor dentro do ponteiro \"aponta_inteiro1\" = %p;\n", aponta_inteiro1);
    printf("-> Valor apontado pelo ponteiro \"aponta_inteiro1\"(conteudo do ponteiro) = %d;\n", *aponta_inteiro1);


    int inteiro2 = 1;
    int *aponta_inteiro2 = &inteiro2;


    printf("\n==> Podemos tambem fazer operacoes matematicas apenas com ponteiros: :\n\n");
    printf("O conteudo do ponteiro \"aponta_inteiro1\" e o valor de \"int inteiro1\"\n");
    printf("O conteudo do ponteiro \"aponta_inteiro2\" e o valor de \"int inteiro2\"\n");
    printf("Utilizando *aponta_inteiro1 e *aponta_inteiro2 para acessar o conteudo das variaveis atraves dos ponteiros temos:\n");
    int soma = *aponta_inteiro2 + *aponta_inteiro1;
    printf("Soma dos valores dos dois inteiros = %d\n", soma);


    printf("\n==> Podemos relacionar structs com ponteiros com o atalho \"->\"\n\n");
    struct tempo {
        int hora;
        int minuto;
        int segundo;
    };

    struct tempo horario_local, *aponta_struct_tempo;
    aponta_struct_tempo = &horario_local;
    aponta_struct_tempo->hora = 20;
    aponta_struct_tempo->minuto = 51;
    aponta_struct_tempo->segundo = 13;

    printf("Apos Criarmos a \"Struct Tempo\", definir seus membros e criar variaveis do seu tipo (uma "
           "\"horario_local\" e outra que ira  apontar para essa variavel), atribuimos valores a esses membros por meio do "
           "ponteiro \n\n");
    printf("-> Resultado: %d horas %d minutos %d segundos\n", horario_local.hora, horario_local.minuto, horario_local.segundo);
    printf("Lembrando que podemos acessar esses valores usando apenas o ponteiro (\"aponta_struct_tempo->membro\"): %d horas %d minutos"
           " %d segundos\n", aponta_struct_tempo->hora, aponta_struct_tempo->minuto, aponta_struct_tempo->segundo);


    printf("\n=> E possível criar ponteiros dentro de Structs!\n");
    struct data {
        int *aponta_dia;
        int *aponta_mes;
        int *aponta_ano;
    };

    struct data hoje;
    int dia = 14, mes = 1, ano = 2005;

    hoje.aponta_dia = &dia;
    hoje.aponta_mes = &mes;
    hoje.aponta_ano = &ano;

    printf("Usando apenas ponteiros podemos nos referenciar a data: %02d/%02d/%04d\n", *hoje.aponta_dia, *hoje.aponta_mes, *hoje.aponta_ano);

    printf("\n=> Tendo essas possibilidades da mistura de Estruturas e Ponteiros podemos fazer diversas coisas"
           "um exemplo bem util eh  uma lista encadeada:\n");

    lista_encadeada();

    printf("\n=> Um outro exemplo do uso de Estruturas e Ponteiros em listas concatenadas eh na busca de valores:\n");

    //listas *busca_valora_lista(listas *aponta_lista, int valor);
    listas l1, l2, l3;
    listas *gancho, *resultado;

    l1.valor = 10;
    l2.valor = 20;
    l3.valor = 30;
    l1.proxima_lista = &l2;
    l2.proxima_lista = &l3;
    l3.proxima_lista = NULL;
    gancho = &l1;

    resultado = busca_valor_lista(gancho, 10);

    if(resultado == NULL) {printf("* Valor nao encontrado! *\n");}
    else {printf("* Valor %d encontrado! *\n", resultado->valor);}


    printf("\n=> Ao referenciar a um vetor usando ponteiros o uso se diferencia dos outros tipos!\n");

    int vetor_exemplo[3] = {1, 2, 3};
    int *aponta_vetor_exemplo = vetor_exemplo;

    printf("Ao passarmos o valor \"vetor\" para o ponteiro ele ira receber exatamente o endereco da memoria"
           "exata do primeiro membro dovetor apontado\n");
    printf("* Endereco no ponteiro = %p\n* Enderco do primeiro membro do vetor = %p\n", aponta_vetor_exemplo, &vetor_exemplo[0]);

    return 0;
}


void lista_encadeada() {
    listas l1, l2, l3, *gancho;

    l1.valor = 1;
    l2.valor = 2;
    l3.valor = 3;

    l1.proxima_lista = &l2;
    l2.proxima_lista = &l3;
    l3.proxima_lista = NULL;

    gancho = &l1;

    printf("------------------------------\n");
    int i = 1;
    while(gancho != NULL) { // tenho uma duvida do porque a condição não é "gancho->proxima_lista != NULL"

        printf(" * Valor do membro de l%d = %d\n", i, gancho->valor);

        gancho = gancho->proxima_lista;

        i++;
    }
    printf("---------FIM da lista!---------\n");
}

listas *busca_valor_lista(listas *aponta_lista, int valor) {
    while(aponta_lista != NULL) {
        if(aponta_lista->valor == valor) {return aponta_lista;}
        else {aponta_lista = aponta_lista->proxima_lista;}
    }
    return NULL;
}
