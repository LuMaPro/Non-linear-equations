/*****************************************************************
##################################################################
# MAC0210 - Laboratório de Métodos Numéricos (2025)
# EP1 - Equações não lineares em uma variável
#
# Nome do(a) aluno(a): Lucas Martins Próspero
# NUSP: 15471925
#
##################################################################
*****************************************************************/


/*------------Lib------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*---------------------------*/


/*----------Funções----------*/
// Função g(x) definida como g(x) = x - f(x)/f'(x), onde f(x) = exp(x) - 2x²
double g(double x)
{
    return (x - (exp(x) - 2 * x * x) / (exp(x) - 4 * x));
}

// Função para calcular o módulo (valor absoluto) de um double type
double absd(double a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

// Implementação do método do ponto fixo, com x0 sendo o ponto de partida e eabs a condição de parada (erro absoluto)
double fix(double x0, double eabs)
{
    double xprev = x0 + 1;
    double xnext = x0;
    int maxit = 0;
    while (absd(xnext - xprev) > eabs)
    {
        if(maxit == 100) return NAN;         // Condição de parada em casos de oscilação 
        xprev = xnext;
        xnext = g(xprev);
        printf("Erro: %.12e\n", absd(xnext-xprev));
        maxit++;
    }

    return xnext;
}
/*---------------------------*/


/*------------Main-----------*/
int main()
{
    // Pela amostragem da função f(x), as raízes se encontram nos intervalos:
    // [-0.5,-0.4]
    printf("%s", "---Método do ponto fixo em x0 = -0.5--- \n");
    double x1 = fix((double)-0.5, 10e-8);
    printf("%s", "--------------------------------------- \n \n");
    // [1.4,1.5]
    printf("%s", "---Método do ponto fixo em x0 = 1.47--- \n");
    double x2 = fix((double)1.47, 10e-8);
    printf("%s", "--------------------------------------- \n \n");
    // [2.6,2.7]
    printf("%s", "---Método do ponto fixo em x0 = 2.6---- \n");
    double x3 = fix((double)2.6, 10e-8);
    printf("%s", "--------------------------------------- \n \n");
    printf("%s %f %c %f %c %f %c", "Raízes aproximadas de f(x):\n", x1, '\n', x2, '\n', x3, '\n');
    
    return 0;
}
/*---------------------------*/