
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

int main()
{
    int n, m ;
    printf("Digite o tamanho da tabela hash: ");
    scanf("%d",&m);
    printf("Digite a quantidade Funcionarios irar cadastrar:  ");
    scanf("%d",&n);

    Hash *tab[m];
    inicialiaza(tab,m);

    char nome[40];
    float salario;
    char cpf[11];
    char dataNascimento[11];
    int codigo;

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

        inserir(tab,n,nome,dataNascimento,salario,codigo,cpf);

    }



    int opcao = 0;
    int x ;

    do
    {
        printf("Digite o codigo do funcionario que deseja encontrar... ");
        scanf("%d", &x);
        int ind = busca(tab, m, x);
        if (ind == -1)
        {

            printf("\n");
            printf("Funcionario nao encontrado!\n");
            printf("\n");

        }
        else
        {
            Tfuncionario *f = tab[ind];
            printf("Dados do Funcionario Encontrado \n");
            printf("Nome: %s \n",f->nome);
            printf("Cpf: %s \n",f->cpf);
            printf("Salario: %.2f \n", f->salario);
            printf("Codigo: %d \n", f->codigo);
            printf("Data nascimento: %s \n", f->datanascimento);

        }
        printf("\n");
        printf("Deseja realizar outra busca ? \n 1 = sim \n ou 2 = nao \n");
        scanf("%d", &opcao);
        printf("\n");
        printf("\n");
    }
    while ( opcao != 2);
    {
    }


    int escolha ;
    printf("Deseja imprimir todos os funcionarios da tabela hash ? \n");
    printf("1= sim \n");
    printf("2= nao \n");
    scanf("%d",&escolha);

    if(escolha == 1)
    {
        imprime(tab,m);
    }
    else
    {
        printf("Programa finalizado");
    }
    libera(tab, m);


}
