/*Semana 11: Sistemas de Informação (Modelagem de Dados)
Foco: Tipos Estruturados (structs), array de structs.


● Demonstração (Prof): "O Registro" – Criar a struct base (Nome, CPF,
DataNascimento). Ler os dados e imprimir uma ficha padronizada.
*/

#include <stdio.h>
#include <string.h>

typedef struct _Data
{
    int dia; // 0 < data < 32
    int mes; // 0 < mes < 13
    int ano; // 0 < ano

} Data;

// union cpf {
//     long lcpf;
//     char ccpf;
// };

typedef struct _Pessoa
{
    char nome[100];
    char cpf[15];
    Data dataNasc; 
        
} Pessoa;

void imprimir_ficha(Pessoa pessoa) {
    printf("==============================\n");
    printf("nome: %s\n", pessoa.nome);
    printf("cpf: %s\n", pessoa.cpf);
    printf("data de nascimento: %d/%d/%d\n", pessoa.dataNasc.dia, pessoa.dataNasc.mes, pessoa.dataNasc.ano);
    printf("==============================\n");
}

/*● Lab 1: "Prontuário Estruturado" – Criar uma struct Exame aninhada dentro de
Paciente. Ler dados de glicemia e exibir o prontuário.*/

typedef struct _Paciente 
{
    int id;
    char nome[100];

    struct {
        int glicemia;
        int colesterol;
    } exame;
    
} Paciente;

void imprimir_pontuario (Paciente paciente) {

    printf("[%d] %s\n", paciente.id, paciente.nome);
    printf("nivel de glicemia: %d g/ml\n", paciente.exame.glicemia);
    printf("nivel de colesterol: %d g/ml\n", paciente.exame.colesterol);

}

/*● Lab 2: "Busca de Fornecedor" – Criar um vetor com 3 struct Fornecedor (ID,
CNPJ, Tempo_Entrega). Iterar para encontrar o CNPJ do fornecedor mais ágil.
● Desafio (Casa): "Gestão de Leitos" – Modelar uma ala usando um vetor de structs
Leito (Numero, Status, ID_Paciente). Criar um menu para internar um paciente
(alterar status/ID) ou dar alta*/

int main () {

    printf("======== FICHA PADRONIZADA ==========\n");

    Pessoa hrw;
    strcpy(hrw.nome, "Harrowhark");
    strcpy(hrw.cpf, "0000000001");
    hrw.dataNasc.dia = 1;
    hrw.dataNasc.mes = 11;
    hrw.dataNasc.ano = 1999;

    imprimir_ficha(hrw);

    printf("======= PONTUARIO ESTRUTURADO ========\n");

    Paciente paciente;
    strcpy(paciente.nome, hrw.nome);
    paciente.id = 1;
    paciente.exame.glicemia = 100;
    paciente.exame.colesterol = 20;

    imprimir_pontuario(paciente);

    return 0;
}