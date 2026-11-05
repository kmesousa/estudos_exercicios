import json

resposta = '''
{
  "total": 2,
  "usuarios": [
    {"nome": "Ana", "endereco": {"cidade": "Recife"}, "cursos": ["Python", "Django"]},
    {"nome": "Bruno", "cursos": []}
  ]
}
'''

dados = json.loads(resposta)

print(dados["usuarios"][0]["endereco"]["cidade"])

for usuario in dados["usuarios"]:
    cidade = usuario.get("endereco", {}).get("cidade", "não informada") #metodo get() para evitar erro caso a chave não exista, como ele funciona? funciona como um dicionário normal, mas com a diferença de que se a chave não existir, ele retorna None ou um valor padrão que você pode definir. No caso acima, se "endereco" não existir, ele retorna um dicionário vazio {}, e se "cidade" não existir, ele retorna "não informada".
    qtd = len(usuario["cursos"])
    print(f"{usuario['nome']}: {cidade}, {qtd} curso(s)")