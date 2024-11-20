# Simulador de Memória Virtual 🖥️

Este projeto implementa um simulador de memória virtual para comparar o desempenho dos algoritmos FIFO, Segunda Chance e Relógio. Parte da disciplina de Sistemas Operacionais.

## 📋 Configurações da Simulação

- Número de quadros: 10 a 100 (incremento de 10)
- Referências por experimento: 1.000
- Número de experimentos: 5
- Espaço de endereçamento: 200 páginas
- Range de referências: 1 a 200

## 🔧 Requisitos

- GCC
- Make
- Python 3.x
- Bibliotecas Python: 
  - matplotlib
  - pandas
  - seaborn
  - py-cpuinfo
  - psutil

## 🚀 Instalação

Instalar dependências (Ubuntu/Debian):
```bash
sudo apt-get update
sudo apt-get install gcc make python3 python3-pip
```

Instalar bibliotecas Python:
```bash
pip3 install matplotlib pandas seaborn py-cpuinfo psutil
```

## 💻 Uso

Compilar:
```bash
make
```

Executar simulação e gerar gráficos:
```bash
make run
```

Executar testes:
```bash
make test
```

Limpar arquivos gerados:
```bash
make clean
```

## 📊 Resultados

Os resultados são gerados em:
- `resultados.csv`: Dados numéricos da simulação
- `docs/resultados/graficos/comparacao_algoritmos.png`: Gráfico comparativo

## 📁 Estrutura do Projeto

```
memoria-virtual/
├── src/                    # Código fonte do simulador
│   ├── page.h             # Definição da estrutura de páginas
│   ├── page.c             # Implementação das funções de página
│   ├── algorithms.h       # Interface dos algoritmos
│   ├── algorithms.c       # Implementação dos algoritmos
│   └── main.c             # Programa principal
├── tests/                  # Testes unitários
│   └── test.c             # Implementação dos testes
├── scripts/               # Scripts auxiliares
│   └── plot_results.py    # Geração de gráficos
├── docs/                  # Documentação
│   ├── resultados/        # Resultados dos experimentos
│   └── comentarios.pdf    # Análise dos resultados
├── Makefile              # Arquivo de compilação
└── README.md             # Este arquivo
```

## 📈 Detalhes da Implementação

### Algoritmos Implementados

1. **FIFO (First-In-First-Out)**
   - Remove a página mais antiga no sistema
   - Usa um contador de tempo para controle
   - Implementação simples e direta

2. **Segunda Chance**
   - Extensão do FIFO que considera o bit de referência
   - Dá uma segunda oportunidade para páginas usadas recentemente
   - Melhor aproveitamento da localidade temporal

3. **Relógio (Clock)**
   - Similar ao Segunda Chance
   - Usa um ponteiro circular para percorrer as páginas
   - Implementação mais eficiente