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
#include <complex.h>
#include <stdbool.h>
/*---------------------------*/

/*----------Funções----------*/
// Função f1(x) = x^4 + 1
// Raízes: +- sqrt(2)/2 +- i sqrt(2)/2
double complex evalf1(double complex x)
{
    return x * x * x * x + 1;
}

// Derivada f1'(x) = 4x³
double complex evalDf1(double complex x)
{
    return 4 * x * x * x;
}

// Função f2(x) = x^5 - 1
// Raízes: -1, 1/2 +- i sqrt(3)/2
double complex evalf2(double complex x)
{
    return x * x * x * x * x - 1;
}

// Derivada f2'(x) = 5x^4
double complex evalDf2(double complex x)
{
    return 5 * x * x * x * x;
}

// Função para printar um número complexo z = x + yi como um par ordenado (x,yi)
void cprint(double complex z)
{
    printf("%s%f%s%f%s %s", "(", creal(z), ",", cimag(z), "i)", "\n");
}

// Implementação do método de Newton, com x0 sendo o ponto de partida e eabs a condição de parada (erro absoluto)
// obs.: conv = true mostra a taxa de convergência
double complex newton(double complex x0, double eabs, bool conv)
{
    double complex xprev = x0 + 1;
    double complex xnext = x0;
    int maxit = 0;
    while (cabs(xprev - xnext) > eabs)
    {
        if(maxit == 50) return NAN; // Condição de parada em casos de oscilação
        xprev = xnext;
        xnext = xprev - evalf2(xprev) / evalDf2(xprev);
        if(conv) printf("Erro: %.12e\n", (creal(xnext) - 1));
        maxit++;
    }

    return xnext;
}

// Função que gera um arquivo '.txt' usado pelo gnuplot
// l -> limite inferior
// u -> limite superior
// p -> qntde de pixels
void newton_basins(double l, double u, double p, double eabs)
{
    FILE *file = fopen("raizes.txt", "w");
    if (!file)
    {
        printf("%s", "Erro ao abrir o arquivo!\n");
        return;
    }

    double pi = M_PI;
    double complex root[] = {(double complex) cos(0) + I*sin(0),(double complex) cos(2*pi/5) + I*sin(2*pi/5),(double complex) cos(4*pi/5) + I*sin(4*pi/5),(double complex) cos(6*pi/5) + I*sin(6*pi/5),(double complex) cos(8*pi/5) + I*sin(8*pi/5)};
    int num_p = (int)ceil(sqrt(p));
    double pace = (u - l) / ((double)num_p);

    double interval[num_p];
    interval[0] = l;
    for (int k = 1; k < num_p; k++)
    {
        interval[k] = interval[k - 1] + pace;
    }

    double x = 0;
    double y = 0;
    double complex z = 0;
    double complex res = 0;
    for (int i = 0; i < num_p; i++){
        x = interval[i];
        for (int j = 0; j < num_p; j++){
            y = interval[j];
            z = x + y * I;
            res = newton(z, eabs, false);
            int index = -1;
            for (int k = 0; k < 5; k++){
                if (cabs(res - root[k]) < eabs){
                    index = k;
                    break;
                }
            }
            fprintf(file, "%d ", index);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main()
{

    newton_basins(-2, 2, 1000000, 10e-8);

    printf("%s", "Convergência do método de Newton em x^5 - 1 para x0 = 1.1: \n");
    newton(1.1, 10e-8, true);

    return 0;
}