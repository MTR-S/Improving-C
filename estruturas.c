#include <stdio.h>

void iniciand_struct() {
    printf("=> Temos algumas etapas para iniciar um struct:\n");
    struct exemplo {
      int membro1;
      double membro2;
      char membro3;
    };

    struct exemplo ex1;

    ex1.membro1 = 1;
    ex1.membro2 = 1.0;
    ex1.membro3 = '1';

    printf("* Assim depois de criarmos a nossa struct e iniciar os seus valores "
           "atraves do \".\" podemos exibir esses valores! *\n");
    printf("-> Membro 1 = %d\n-> Membro 2 = %.2lf\n-> Membro 3 = '%c'\n", ex1.membro1, ex1.membro2, ex1.membro3);
}

int main(void) {
    iniciand_struct();

    return 0;
}