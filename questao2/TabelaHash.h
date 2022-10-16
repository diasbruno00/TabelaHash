
#ifndef TABELAHASH_H
#define TABELAHASH_H


typedef struct funcionario
{
    char nome[40];
    float salario ;
    char cpf[11];
    int codigo ;
    char datanascimento[11];
    struct funcionario *prox;

} Tfuncionario;

typedef Tfuncionario *Hash ;

int calculaHash(int codigo, int tam);

void inicializa(Hash *tab, int m);

Tfuncionario *aloca (char *nome, float salario, int codigo, char *dataNascimento, char *cpf);

void inserir (Hash *tab, int n, char *nome, char *dataNascimento, float salario, int codigo, char *cpf);

int exclui(Hash *tab, int m, int codigo);

void libera(Hash *tab, int m) ;

void imprime(Hash *tab, int m) ;


#endif

