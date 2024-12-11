#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    // Estrutura para a representação dos dados dos funcionários

    typedef struct{
      char numeroFuncionario[15];
      char nomeFuncionario[50];
      char nifFuncionario[15];
      char telefFuncionario[15];
    } dadosFuncionarios;

    // Fim estrutura de repesentação dos dados dos funcionários


/**************************************************************************************/
/*                                                                                    */
/*                    1.a. Carregamento dos dados dos funcionários                    */
/*                                                                                    */
/**************************************************************************************/
#define MAX_FUNCIONARIOS 100

// Função para carregar dados a partir do ficheiro
int carregarDados(const char *dados_funcionarios, dadosFuncionarios funcionarios[], int maxFuncionarios){
    FILE *file = fopen(dados_funcionarios, "r");
    if (file == NULL){
        printf("Nao foi possivel abrir o ficheiro %s.\n", dados_funcionarios);
        return 0;
    }

    char linha[300];
    int count = 0;

    while (fgets(linha, sizeof(linha), file) != NULL && count < maxFuncionarios)
    {
        linha[strcspn(linha, "\n")] = 0;
        // Faz a divisão de campos com o caracter ";"
        char *numeroFuncionario = strtok(linha, ";");
        char *nomeFuncionario = strtok(NULL, ";");
        char *nifFuncionario = strtok(NULL, ";");
        char *telefFuncionario = strtok(NULL, ";");

        if (numeroFuncionario && nomeFuncionario && nifFuncionario && telefFuncionario)
        {
            strncpy(funcionarios[count].numeroFuncionario, numeroFuncionario, sizeof(funcionarios[count].numeroFuncionario) -1);
            strncpy(funcionarios[count].nomeFuncionario, nomeFuncionario, sizeof(funcionarios[count].nomeFuncionario) - 1);
            strncpy(funcionarios[count].nifFuncionario, nifFuncionario, sizeof(funcionarios[count].nifFuncionario) - 1);
            strncpy(funcionarios[count].telefFuncionario, telefFuncionario, sizeof(funcionarios[count].telefFuncionario) - 1);

            // Garantir que as strings terminem em '\0'
            funcionarios[count].numeroFuncionario[sizeof(funcionarios[count].numeroFuncionario) - 1] = '\0';
            funcionarios[count].nomeFuncionario[sizeof(funcionarios[count].nomeFuncionario) - 1] = '\0';
            funcionarios[count].nifFuncionario[sizeof(funcionarios[count].nifFuncionario) - 1] = '\0';
            funcionarios[count].telefFuncionario[sizeof(funcionarios[count].telefFuncionario) - 1] = '\0';
            count++;
        }
        else
        {
            printf("Erro! Formato de linha incorreto!\n");
        }
    } // ------ FIM While -------

    fclose(file);
    return count;
} // ----------- FIM Função carrregarDados ---------

void imprimirDados(dadosFuncionarios funcionarios[], int count){

// /t --> TAB
    printf("\t\t\t\t\t\t\t\t\tFUNCIONARIOS \n");
    //---------------------------------------------  LINHA SUPERIOR COLUNA --------------------------------------------- //
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("Numero: %s\t\t  || \t\t Nome: %s\t\t  || \t\t NIF: %s\t\t  || \t\tTelefone: %s\n",
                funcionarios[i].numeroFuncionario,
                funcionarios[i].nomeFuncionario,
                funcionarios[i].nifFuncionario,
                funcionarios[i].telefFuncionario);
        //---------------------------------------------  LINHA SUPERIOR COLUNA --------------------------------------------- //
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}


/**************************************************************************************/
/*                                                                                    */
/*                   1.b. Carregamento dos dados da ementa semanal                    */
/*                                                                                    */
/**************************************************************************************/


// Função principal
int main() {
    dadosFuncionarios funcionarios[MAX_FUNCIONARIOS];

    // Nome do ficheiro a ser lido
    const char *nomeFicheiro = "C:\\Users\\Utilizador\\Desktop\\ESI24_25\\ProgramacaoImperativa\\TrabalhoPraticoFinal\\dados_funcionarios.txt";

    // Carregar os dados
    int totalFuncionarios = carregarDados(nomeFicheiro, funcionarios, MAX_FUNCIONARIOS);

    // Imprimir os dados carregados
    imprimirDados(funcionarios, totalFuncionarios);

    return 0;
}
