
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "TabelaHash.h"


int main()
{

    int n, m;
    printf("Digite m (tamanho da tabela hash)... ");
    scanf("%d", &m);
    printf("Digite n (quantidade de matriculas)... ");
    scanf("%d", &n);

    if ((n <= 1) || (m <= 1)) return 0;

    Hash *tab[m];
    inicializa(tab, m);

    char nome[40];
    float salario;
    char cpf[11];
    char dataNascimento[11];
    int codigo;
    int excluir ;

    for(int i =0 ; i < n ; i++)
    {
        printf("---------------------- Funcionario n %d------------------- \n",i+1);

        printf("Digite o nome: ");
        scanf("%s",&nome);
        printf("Digite seu cpf: ");
        scanf("%s",&cpf);
        printf("Digite seu salario: ");
        scanf("%f",&salario);
        printf("Digite a data de nascimento: ");
        scanf("%s",&dataNascimento);
        printf("Digite o seu codigo: ");
        scanf("%d",&codigo);

        inserir(tab,m,nome,dataNascimento,salario,codigo,cpf);

    }
    imprime(tab,m);



    printf("Digite o codigo do funcionario que deseja excluir: ");
    scanf("%d", &excluir);
    int resposta = exclui(tab, m, excluir);
    if (resposta != -1)
    {
        printf("\n");
        printf("Nova tabela hash apos a exclusao \n");
        imprime(tab,m);
    }

    libera(tab,m);
    return 0;
}
