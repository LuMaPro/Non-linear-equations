#!/bin/bash

##################################################################
# MAC0210 - Laboratório de Métodos Numéricos (2025)
# EP1 - Equações não lineares em uma variável
#
# Nome do(a) aluno(a): Lucas Martins Próspero
# NUSP: 15471925
#
##################################################################

gnuplot <<EOF
set terminal pngcairo size 1000,1000    # p = qntde total de pixels (ver a função newton_basins em EP1_2.c), então size é definido por sqrt(p),sqrt(p)
set output "basin.png"                 # Arquivo de saída

unset key                               # Remove a legenda-texto
unset colorbox                          # Remove a legenda-cor

# Definição do intervalo [l:u] (ver a função newton_basins em EP1_2.c)
set xrange [-2:2]
set yrange [-2:2]
set size ratio -1
set view map

set pm3d map

# Ajuste da escala
nx=1000   # Número de pixels no eixo X
ny=1000   # Número de pixels no eixo Y
xmin=-2
xmax=2
ymin=-2
ymax=2

# set palette defined (-1 "black", 0 "blue", 1 "red", 2 "green", 3 "yellow")                # Cores para x^4 = -1
set palette defined (-1 "black", 0 "blue", 1 "red", 2 "green", 3 "yellow", 4 "purple")      # Cores para x^5 = 1
splot 'raizes.txt' matrix using (\$1*(xmax-xmin)/nx + xmin):(\$2*(ymax-ymin)/ny + ymin):3 with image

EOF

echo "Imagem gerada: basin.png"