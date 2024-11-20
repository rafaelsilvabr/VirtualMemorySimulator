# Comparação de Algoritmos de Substituição de Páginas

## Resultados do Experimento

O gráfico a seguir apresenta os resultados da comparação entre três algoritmos de substituição de páginas: FIFO (First-In-First-Out), Segunda Chance e Relógio.

![Gráfico de Comparação de Algoritmos](comparacao_algoritmos.png)

Sistema: 
- Linux 5.15.167.4-microsoft-standard-WSL2
- CPU: AMD Ryzen 5 5600X 6-Core Processor 
- RAM: 7.7 GB

## Análise dos Resultados

### Número de Faltas de Página:
   - O algoritmo FIFO apresenta o maior número de faltas de página em comparação com os outros algoritmos, principalmente quando o número de quadros é menor.
   - O algoritmo de Segunda Chance apresenta um desempenho melhor que o FIFO, com um número de faltas de página mais baixo em todos os cenários testados.
   - O algoritmo de Relógio apresenta o melhor desempenho, com o menor número de faltas de página entre os três algoritmos testados.

### Variação com o Número de Quadros:
   - À medida que o número de quadros aumenta, o número de faltas de página diminui para todos os algoritmos.
   - A redução é mais acentuada nos primeiros incrementos do número de quadros, indicando que há um ponto de saturação em que adicionar mais quadros não traz benefícios significativos.
   - O algoritmo de Relógio apresenta a curva de faltas de página mais suave, indicando que ele é menos sensível às variações no número de quadros disponíveis.

### Análise Geral:
   - O algoritmo de Relógio se mostra como o mais eficiente entre os três testados, apresentando o menor número de faltas de página em todos os cenários.
   - Esse resultado corrobora a teoria de que o algoritmo de Relógio, uma variante do algoritmo de Segunda Chance, consegue aproveitar melhor a localidade temporal das referências a páginas, resultando em um melhor desempenho.
   - É importante ressaltar que esses resultados são específicos para a simulação realizada, com as características definidas no enunciado do trabalho. Em cenários reais, os resultados podem variar de acordo com o padrão de acesso à memória dos processos.