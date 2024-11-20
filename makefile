# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Diretórios
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
SCRIPT_DIR = scripts
DOC_DIR = docs/resultados/graficos

# Arquivos fonte
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Nome do executável
TARGET = simulador

# Verificar se Python e pip estão instalados
PYTHON_CHECK := $(shell which python3)
PIP_CHECK := $(shell which pip3)

# Regra padrão
all: $(BUILD_DIR) $(TARGET)

# Criar diretórios necessários
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DOC_DIR):
	mkdir -p $(DOC_DIR)

# Instalar dependências Python
python_deps:
	@if [ -z "$(PYTHON_CHECK)" ]; then \
		echo "Python3 não está instalado. Por favor, instale-o primeiro."; \
		exit 1; \
	fi
	@if [ -z "$(PIP_CHECK)" ]; then \
		echo "Pip3 não está instalado. Por favor, instale-o primeiro."; \
		exit 1; \
	fi
	pip3 install matplotlib pandas seaborn py-cpuinfo psutil

# Compilar o programa
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilar os objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(TARGET) test resultados.csv
	rm -rf docs/resultados/graficos/*.png

# Executar testes
test: clean $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/page.c $(SRC_DIR)/algorithms.c $(TEST_DIR)/test.c -o test
	./test

# Executar o programa e gerar gráfico
run: $(TARGET) $(DOC_DIR) python_deps
	./$(TARGET)
	python3 $(SCRIPT_DIR)/plot_results.py
	@echo "\nSimulação concluída!"
	@echo "Resultados numéricos: resultados.csv"
	@echo "Gráfico: docs/resultados/graficos/comparacao_algoritmos.png"

.PHONY: all clean test run python_deps