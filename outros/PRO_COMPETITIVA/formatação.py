import re

texto_original = """"""

# 1. Quebra linhas onde um número de página é seguido diretamente por um novo título (Letra Maiúscula)
# Exemplo: ", 1 Linguagem" vira "; 1\nLinguagem"

def formatar_texto(texto_original):
    passo1 = re.sub(r',\s*(\d+)\s+([A-ZÁÉÍÓÚÇ])', r'; \1\n\2', texto_original)

    linhas_finais = []
    for linha in passo1.split('\n'):
        linha = linha.strip()
        if not linha:
            continue

        # 2. Garante que se a linha termina com um número (mas sem ponto e vírgula), adiciona o ';'
        if re.search(r',\s*\d+$', linha):
            linha = re.sub(r',\s*(\d+)$', r'; \1', linha)
        elif re.search(r'\d+$', linha) and not ';' in linha:
            linha = re.sub(r'\s*(\d+)$', r'; \1', linha)

        # 3. Aplica a hierarquia (Adiciona TAB se não começar com "Capítulo" ou "Introdução")
        if linha.startswith("Capítulo") or linha.startswith("Introdução"):
            linhas_finais.append(linha)
        else:
            linhas_finais.append("\t" + linha)

    texto_pronto = "\n".join(linhas_finais)
    print(texto_pronto)

import re

# Defina aqui o nome do seu arquivo original e o nome do arquivo corrigido
ARQUIVO_ENTRADA = "sumario.txt"
ARQUIVO_SAIDA = "sumario_final.txt"
DESLOCAMENTO = 34

def somar_paginas():
    try:
        with open(ARQUIVO_ENTRADA, "r", encoding="utf-8") as f:
            linhas = f.readlines()

        linhas_corrigidas = []

        for linha in linhas:
            # Procura por um ponto e vírgula seguido por números no final da linha
            match = re.search(r';\s*(\d+)\s*$', linha)

            if match:
                pagina_original = int(match.group(1))
                pagina_nova = pagina_original + DESLOCAMENTO

                # Substitui apenas o número antigo pelo novo, preservando espaços e formatações
                linha_corrigida = re.sub(r'(\d+)\s*$', str(pagina_nova), linha)
                linhas_corrigidas.append(linha_corrigida)
            else:
                # Se a linha não tiver número/padrão, mantém ela exatamente igual
                linhas_corrigidas.append(linha)

        with open(ARQUIVO_SAIDA, "w", encoding="utf-8") as f:
            f.writelines(linhas_corrigidas)

        print(f"Sucesso! O arquivo '{ARQUIVO_SAIDA}' foi gerado com as páginas corrigidas.")

    except FileNotFoundError:
        print(f"Erro: O arquivo '{ARQUIVO_ENTRADA}' não foi encontrado na mesma pasta do script.")

if __name__ == "__main__":
    somar_paginas()