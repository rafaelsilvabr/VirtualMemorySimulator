import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import platform
import cpuinfo
import psutil

def get_system_info():
    try:
        cpu = cpuinfo.get_cpu_info()['brand_raw']
    except:
        cpu = platform.processor()
    
    return {
        'OS': platform.system() + ' ' + platform.release(),
        'CPU': cpu,
        'RAM': f"{psutil.virtual_memory().total / (1024**3):.1f} GB",
        'Python': platform.python_version()
    }

def plot_results():
    # Configuração do estilo
    plt.style.use('seaborn')
    
    # Leitura dos dados
    df = pd.read_csv('resultados.csv')
    
    # Criação do gráfico
    fig, ax = plt.subplots(figsize=(12, 8))
    
    plt.plot(df['Quadros'], df['FIFO'], 
             marker='o', label='FIFO', linewidth=2)
    plt.plot(df['Quadros'], df['Segunda_Chance'], 
             marker='s', label='Segunda Chance', linewidth=2)
    plt.plot(df['Quadros'], df['Relogio'], 
             marker='^', label='Relógio', linewidth=2)
    
    # Configurações do gráfico
    plt.xlabel('Número de Quadros')
    plt.ylabel('Número Médio de Faltas de Página')
    plt.title('Comparação dos Algoritmos de Substituição de Páginas')
    plt.grid(True, alpha=0.3)
    plt.legend()

    # Adicionar informações do sistema
    sys_info = get_system_info()
    info_text = f"Sistema: {sys_info['OS']}\n"
    info_text += f"CPU: {sys_info['CPU']}\n"
    info_text += f"RAM: {sys_info['RAM']}\n"
    info_text += f"Python: {sys_info['Python']}"
    
    plt.figtext(0.02, 0.02, info_text, fontsize=8, ha='left')
    
    # Salvar o gráfico
    plt.savefig('docs/resultados/graficos/comparacao_algoritmos.png', 
                dpi=300, bbox_inches='tight')
    plt.close()

if __name__ == "__main__":
    plot_results()