#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TAM 1024

/* limpa a tela em Windows e em Linux/macOS */
void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* lê uma linha inteira e remove o '\n' do final */
void lerLinha(char destino[], int tamanho)
{
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    destino[strcspn(destino, "\n")] = '\0';
}

/* lê um número inteiro; repete até o usuário digitar um número válido */
int lerInteiro(const char mensagem[])
{
    char linha[64];
    int valor;

    while (1) {
        printf("%s", mensagem);
        if (fgets(linha, sizeof(linha), stdin) == NULL)
            return 4; /* fim da entrada: encerra o programa pelo menu */
        if (sscanf(linha, "%d", &valor) == 1)
            return valor;
        printf("Entrada inválida. Digite um número.\n");
    }
}

void pausar()
{
    char lixo[8];
    printf("\nPressione Enter para voltar ao menu...");
    fgets(lixo, sizeof(lixo), stdin);
}

char cifrarLetra(char c, int desloc)
{
    char base;
    if (isalpha((unsigned char)c)) { // apenas letras
        if (isupper((unsigned char)c)) // maiúsculas e minúsculas se mantêm
            base = 'A';
        else
            base = 'a';
        // converte a letra de 0 a 25 - aplica o deslocamento - dá a volta no alfabeto
        // o "+ 26" extra garante resultado correto com deslocamento negativo
        return (char)((((c - base + desloc) % 26) + 26) % 26 + base);
    }
    return c;
}

char decifrarLetra(char c, int desloc)
{
    return cifrarLetra(c, -desloc);
}

void cifrarTexto(char entrada[], char saida[], int desloc)
{
    int i;
    for (i = 0; entrada[i] != '\0'; i++) { // percorre toda a string
        saida[i] = cifrarLetra(entrada[i], desloc);
    }
    saida[i] = '\0'; // fecha a string
}

void decifrarTexto(char entrada[], char saida[], int desloc)
{
    int i;
    for (i = 0; entrada[i] != '\0'; i++) {
        saida[i] = decifrarLetra(entrada[i], desloc);
    }
    saida[i] = '\0';
}

void forcaBruta(char texto[])
{
    char saida[TAM];
    int d;
    printf("\n——— Força bruta ———\n"); // testa todos os deslocamentos possíveis
    for (d = 1; d <= 25; d++) {
        decifrarTexto(texto, saida, d);
        printf("Deslocamento %d: %s\n", d, saida);
    }
}

int main()
{
    int opcao;
    int desloc;
    char texto[TAM];
    char saida[TAM];

    do {
        limparTela();
        printf("—— Cifra de César ——\n");
        printf("1 - Cifrar\n");
        printf("2 - Decifrar\n");
        printf("3 - Força bruta\n");
        printf("4 - Sair\n");
        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                limparTela();
                printf("Digite o texto: ");
                lerLinha(texto, TAM);
                desloc = lerInteiro("Deslocamento: ");
                cifrarTexto(texto, saida, desloc);
                printf("Texto cifrado: %s\n", saida);
                pausar();
                break;

            case 2:
                limparTela();
                printf("Digite o texto cifrado: ");
                lerLinha(texto, TAM);
                desloc = lerInteiro("Deslocamento: ");
                decifrarTexto(texto, saida, desloc);
                printf("Texto decifrado: %s\n", saida);
                pausar();
                break;

            case 3:
                limparTela();
                printf("Digite o texto cifrado: ");
                lerLinha(texto, TAM);
                forcaBruta(texto);
                pausar();
                break;

            case 4:
                limparTela();
                printf("Programa finalizado.\n");
                break;

            default:
                limparTela();
                printf("Opção inválida!\n");
                pausar();
        }

    } while (opcao != 4);

    return 0;
}
