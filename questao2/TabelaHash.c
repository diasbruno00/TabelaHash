#include "TabelaHash.h"
#include <stdlib.h>

#define TAM 101

int calculaHash (int codigo, int tam)
{
    return codigo % tam;
}

void inicializa(Hash *tab, int m)
{
    int i;
    for (i = 0; i < m; i++)
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
    strcpy(novo->datanascimento, dataNascimento);
    novo->prox = NULL;

    return novo ;


}

void inserir (Hash *tab, int n, char *nome, char *dataNascimento, float salario, int codigo, char *cpf)
{
    int h = calculaHash(codigo,n);
    Tfuncionario *fun = tab[h];
    Tfuncionario *fun2 = NULL;
    while((fun != NULL) && (fun->codigo != codigo))
    {
        fun2  = fun;
        fun = fun->prox;
    }
    if(fun != NULL)
    {
        strcpy( fun->cpf, cpf);
        strcpy(fun->nome, nome);
        strcpy( fun->datanascimento,dataNascimento);
        fun->salario = salario ;
    }
    else
    {
        Tfuncionario *novo = aloca(nome,salario,codigo,dataNascimento,cpf);
        if(!fun2)
        {
            tab[h] = novo ;
        }
        else
        {
            fun2->prox = novo;
        }
    }


}

int exclui(Hash *tab, int m, int codigo)
{
    int h = calculaHash(codigo, m);
    if (tab[h] == NULL)
    {
        return -1;
    }
    Tfuncionario *fun = tab[h];
    Tfuncionario *fun2 = NULL;
    while ((fun != NULL) && (fun->codigo != codigo))
    {
        fun2 = fun;
        fun = fun->prox;
    }
    if (fun == NULL)
    {
        return -1 ;
    }
    if (fun2 == NULL)
    {
        tab[h] = fun->prox;
    }
    else
    {
        fun2->prox = fun->prox;
    }
    free(fun);
    return 0 ;
}

void libera(Hash *tab, int m)
{
    int i;
    for (i = 0; i < m; i++)
        if (tab[i])
        {
            Tfuncionario *fun = tab[i];
            Tfuncionario *func2;
            while (fun)
            {
                func2 = fun;
                fun = fun ->prox;
                free(func2);
            }
        }
}
void imprime(Hash *tab, int m)
{

    for (int i = 0; i < m; i++)
    {
        printf("%d: ", i);
        if (tab[i])
        {
            Tfuncionario *f = tab[i];
            printf("\n");
            while (f)
            {
                printf("Nome: %s \n",f->nome);
                printf("Cpf: %s \n",f->cpf);
                printf("Salario: %.2f \n", f->salario);
                printf("Codigo: %d \n", f->codigo);
                printf("Data nascimento: %s \n", f->datanascimento);
                printf("Endereco de memoria do proximo: %p",f->prox);
                printf("\n\n");
                f = f->prox;
            }
        }
        else printf("NULL\n");
    }
}


