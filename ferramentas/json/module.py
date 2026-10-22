import json
from pathlib import Path

ROOT_DIR = Path(__file__).parent #criar no memso diretório do arquivo module.py
TEXT_FILE = f"{ROOT_DIR}/data.json"
TEXT_FILE_2 = ROOT_DIR / 'data.json'

print(type(TEXT_FILE)) #str
print(type(TEXT_FILE_2)) #'pathlib._local.WindowsPath'

dados = {
    "nome": "João",
    "idade": 30,
    "cidade": "São Paulo"
}

#ESCREVENDO DADOS EM JSON
with open(TEXT_FILE, "w", encoding="utf-8") as arquivo: #pq os acentos ainda estão errados?
    json.dump(dados, arquivo, ensure_ascii=False, indent=2)

print(TEXT_FILE_2.read_text()) #como fazer isso com o TEXT_FILE?

#LENDO DADOS EM JSON
with open(TEXT_FILE, "r", encoding="utf-8") as arquivo:
    dados_lidos = json.load(arquivo)

print(dados_lidos)
print(dados_lidos["nome"])  # João
print(type(dados_lidos))    # <class 'dict'>


#CONVERTENDO STRING JSON EM OBJETO PYTHON
json_string = '{"nome": "Maria", "idade": 25, "cidade": "Rio de Janeiro"}'
dados_convertidos = json.loads(json_string)
print(dados_convertidos)



#CONVERTENDO OBJETO PYTHON EM STRING JSON
json_string = json.dumps(dados_convertidos, ensure_ascii=False, indent=2)
print(json_string)



#RESUMO FUNÇÕES JSON

dados = {"curso": "Python", "aulas": 42}
FILE_JSON = f"{ROOT_DIR}/curso.json"

texto = json.dumps(dados)            # dict -> str
print(json.loads(texto) == dados)    # True (str -> dict)

with open(FILE_JSON, "w", encoding="utf-8") as arquivo:
    json.dump(dados, arquivo)        # dict -> arquivo

with open(FILE_JSON, encoding="utf-8") as arquivo:
    print(json.load(arquivo))        # {'curso': 'Python', 'aulas': 42}