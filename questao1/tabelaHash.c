
#include "tabelaHash.h"
#include <stdlib.h>


void inicialiaza(Hash *tab, int m)
{

    for(int i = 0; i < m; i++)
    {
        tab[i] = NULL;
    }
}
Tfuncionario *aloca (char *nome, float salario, int codigo, char *dataNascimento, char *cpf)
{
    Tfuncionario *novo = (Tfuncionario*) malloc (sizeof(Tfuncionario));
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->salario = salario;
    strcpy(novo->datanascimento, dataNascimento );

    return novo ;


}

int calculaHash(int codigo,int m)
{
    return codigo % m ;
}
void libera(Hash *tab, int m)
{
    for(int i = 0 ; i < m; i++)
    {
        if(tab[i])
        {
            free(tab[i]);
        }
    }
}

int busca(Hash *tab, int m, int codigo)
{
    int posicao = calculaHash(codigo,m);

    if(tab[posicao] != NULL)
    {
        Tfuncionario *resp = tab[posicao];
        if(resp->codigo == codigo)
        {
            return posicao;
        }
    }
    return -1 ;
}

void inserir (Hash *tab, int n, char *nome, char *dataNascimento, float salario, int codigo, char *cpf)
{

    int pos = calculaHash(codigo,n);
    if(tab[pos] == NULL)
    {
        tab[pos] = aloca(nome,salario,codigo,dataNascimento,cpf);
    }
    else
    {
        printf("insercao negada, Encontramos uma colicao \n\n");
    }


}

void imprime (Hash *tab, int n)
{
    int h ;
    for(int i =0 ; i < n; i++)
    {
        h = i ;
        printf("%d \n", h);
        if(tab[h] != NULL)
        {
            Tfuncionario *f = tab[h];
            printf("Nome: %s \n",f->nome);
            printf("Cpf: %s \n",f->cpf);
            printf("Salario: %.2f \n", f->salario);
            printf("Codigo: %d \n", f->codigo);
            printf("Data nascimento: %s \n", f->datanascimento);
            printf("\n\n");
        }
    }


}


