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
    cidade = usuario.get("endereco", {}).get("cidade", "não informada")
    qtd = len(usuario["cursos"])
    print(f"{usuario['nome']}: {cidade}, {qtd} curso(s)")