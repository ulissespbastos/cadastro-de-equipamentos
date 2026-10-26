
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *arquivo;
    char nome[100];
    char tipo[100];
    char linha[256];
    int codigo;
    int opcao;

    printf("=== CADASTRO DE EQUIPAMENTOS ===\n");
    printf("Codigo do equipamento: ");

    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido!\n");
        return 1;
    }
    getchar();

    printf("Nome do equipamento: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        return 1;
    }

    printf("Tipo do equipamento: ");
    if (fgets(tipo, sizeof(tipo), stdin) == NULL) {
        return 1;
    }

    arquivo = fopen("equipamentos.txt", "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir equipamentos.txt");
        return 1;
    }

    fprintf(arquivo, "Codigo: %d\n", codigo);
    fprintf(arquivo, "Nome: %s", nome);
    fprintf(arquivo, "Tipo: %s", tipo);
    fprintf(arquivo, "--------------------------\n");

    if (fclose(arquivo) != 0) {
        printf("Erro ao salvar o arquivo!\n");
        return 1;
    }

    printf("\nEquipamento cadastrado com sucesso!\n");
    printf("Deseja visualizar os cadastros? (1 = Sim / 0 = Nao): ");

    if (scanf("%d", &opcao) != 1) {
        printf("Opcao invalida!\n");
        return 1;
    }

    if (opcao == 1) {
        arquivo = fopen("equipamentos.txt", "r");

        if (arquivo == NULL) {
            perror("Erro ao ler equipamentos.txt");
            return 1;
        }

        printf("\n=== EQUIPAMENTOS CADASTRADOS ===\n");

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            printf("%s", linha);
        }

        fclose(arquivo);
    } else if (opcao != 0) {
        printf("Opcao invalida!\n");
        return 1;
    }

    return 0;
}






































































