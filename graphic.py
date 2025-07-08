##################################################################
# MAC0210 - Laboratório de Métodos Numéricos (2025)
# EP1 - Equações não lineares em uma variável
#
# Nome do(a) aluno(a): Lucas Martins Próspero
# NUSP: 15471925
#
##################################################################


#-----------------Lib-----------------#
import matplotlib.pyplot as plt
import numpy as np
import math
#-------------------------------------#


#---------------Funções---------------#
# Função plot para deixar o código mais enxuto
def plot(x,y,lab=None):
    plt.plot(x,y,label=lab)
    plt.xlabel("x")
    plt.ylabel("f(x)")

# Função f(x) = exp(x) - 2x² do enunciado
def f(x):
    return math.exp(x) - 2*x*x

# Função g(x) = f(x) + x
def g1(x):
    return math.exp(x) - 2*x*x + x

# Respectiva derivada
def dg1(x):
    return math.exp(x) - 4*x + 1

# Função g(x) = 2*f(x) + x
def g2(x):
    return 2*math.exp(x) - 4*x*x + x

# Respectiva derivada
def dg2(x):
    return 2*math.exp(x) - 8*x + 1

# Função g(x) = x - f(x)/f'(x)
def g3(x):
    return x - (math.exp(x) - 2*x*x)/(math.exp(x) - 4*x)

# Respectiva derivada
def dg3(x):
    return 1 - ((math.exp(x) - 4*x)**2 - (math.exp(x) - 4)*(math.exp(x) - 2*x*x))/(math.exp(x) - 4*x)**2
#-------------------------------------#


#-----------------Main----------------#
def main():

    #-----------Função f(x)------------#
    t = np.linspace(-5,5,10000)
    ft = [f(x) for x in t]
    plot(t,ft,"f(x)")
    plt.plot(t,[0]*len(t),label="y = 0")
    plt.legend()
    plt.show()
    plt.cla()
    #----------------------------------#
    

    #------Função g(x) = f(x) + x------#
    # [1.4,1.6]
    t = np.linspace(1.4,1.6,10000)
    ft = [g1(x) for x in t]
    plot(t,ft,"g(x)")
    plt.plot(t,t,label="y = x")
    plt.legend()
    plt.show()
    plt.cla()

    # Derivada de g(x) nos intervalos:
    # [1.4,1.6]
    ft = [abs(dg1(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [-0.6,0.4]
    t = np.linspace(-0.6,-0.4,10000)
    ft = [abs(dg1(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [2.6,2.7]
    t = np.linspace(2.6,2.7,10000)
    ft = [abs(dg1(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()
    #----------------------------------#


    #-----Função g(x) = x + 2*f(x)-----#
    # Derivada de g(x) nos intervalos: 
    # [1.4,1.6]
    t = np.linspace(1.4,1.6,10000)
    ft = [abs(dg2(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [-0.6,-0.4]
    t = np.linspace(-0.6,-0.4,10000)
    ft = [abs(dg2(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [2.6,2.7]
    t = np.linspace(2.6,2.7,10000)
    ft = [abs(dg2(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()
    #----------------------------------#


    #---Função g(x) = x - f(x)/f'(x)---#
    # [1.4,1.6]
    t = np.linspace(1.4,1.6,10000)
    ft = [g3(x) for x in t]
    plot(t,ft,"g(x)")
    plt.plot(t,t,label="y = x")
    plt.legend()
    plt.show()
    plt.cla()

    # Derivada de g(x) no mesmo intervalo
    ft = [abs(dg3(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [-0.6,-0.4]
    t = np.linspace(-0.6,-0.4,10000)
    ft = [g3(x) for x in t]
    plot(t,ft,"g(x)")
    plt.plot(t,t,label="y = x")
    plt.legend()
    plt.show()
    plt.cla()

    # Derivada de g(x) no mesmo intervalo
    ft = [abs(dg3(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()

    # [2.6,2.7]
    t = np.linspace(2.6,2.7,10000)
    ft = [g3(x) for x in t]
    plot(t,ft,"g(x)")
    plt.plot(t,t,label="y = x")
    plt.legend()
    plt.show()
    plt.cla()

    # Derivada de g(x) no mesmo intervalo
    ft = [abs(dg3(x)) for x in t]
    plot(t,ft,"|dg(x)|")
    plt.plot(t,[1]*len(t),label="y = 1")
    plt.legend()
    plt.show()
    plt.cla()
    #----------------------------------#

#-------------------------------------#

main()