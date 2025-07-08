# Non-linear equations in one variable

## 🧾 Credits

The problem was proposed in the MAC0210 class.

https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=MAC0210

## 🔍 General Overview

This work covers both **Fixed Point** and **Newton** methods for estimating roots of an equation. The latter is modified to handle even complex roots, which can be plotted as a convergence basin.

https://en.wikipedia.org/wiki/Fixed-point_iteration<br>
https://en.wikipedia.org/wiki/Newton%27s_method

## ⚙️ How to run
### Compilation:
- **gcc fixed_point.c -o fixed_point -lm**
- **gcc newton.c -o newton -lm**
### Execution:
- **./fixed_point**
- **./newton**
### Extra:
- **python -u graphic.py** to see methods' constraints.
- **./basin.sh** to generate the equation's basin.
## 👤 Author

- Lucas Martins Próspero
