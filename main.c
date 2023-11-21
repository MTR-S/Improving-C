#include <stdio.h>
#include <locale.h>

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
           "\"horario_local\" e outra que ira   apontar para essa variavel), atribuimos valores a esses membros por meio do "
           "ponteiro \n\n");
    printf("-> Resultado: %d horas %d minutos %d segundos\n", horario_local.hora, horario_local.minuto, horario_local.segundo);
    printf("Lembrando que podemos acessar esses valores usando apenas o ponteiro (\"aponta_struct_tempo->membro\"): %d horas %d minutos"
           " %d segundos\n", aponta_struct_tempo->hora, aponta_struct_tempo->minuto, aponta_struct_tempo->segundo);


    printf("\n=> E possível criar ponteiros dentro de Structs\n");
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




    return 0;
}
