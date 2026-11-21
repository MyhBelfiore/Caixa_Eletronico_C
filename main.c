/*
* Caixa Eletronico em C
* --------------------
* Simula um caixa eletronico simples: login coms enha, consulta em saldo, deposito, saque e extrato da sessao
*
* Conteudos praticados: variaveis, condicionais. lacos, switch e funcoes.
*
* Compilar: gcc main.c -o caixa
* Executar: ./caixa  (no Windows: caixa.exe)
*/

#include <stdio.h>

/* ===== Constantes do sistema ===== */
#define SENHA_CORRETA 1234 /* senha do cartao (apenas para estudo!) */
#define MAX_TENTATIVAS 3 /* tentativas antes de bloquear o cartao */
#define SALDO_INICIAL 500.0f /* saldo com que a conta comeca */
#define LIMITE_SAQUE 1000.0f /* valor maximo por saque */

/* ===== Prototipos das funcoes ===== */
void limparBuffer(void);
void pausar(void);
int lerInteiro(char mensagem[]);
float lerValor(char mensagem[]);
void exibirBoasVindas(void);
int autenticar(void);
void exibirMenu(void);
void consultarSaldo(float saldo);
float depositar(void);
float sacar(float saldo);
void exibirExtrato(float totalDepositado, float totalSacado, int qtdOperacoes, float saldo);

/* ===== Funcoes auxiliares de entrada ===== */

/* Descarta o que sobrou no teclado ate o ENTER (evitga leitura "puladas"). */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
        /* apenas descarta */
    }
}

/* Espera o usuario apertar ENTER para continuar. */
void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

/* Le um numero inteiro, repetindo a pergunta se o usuario digitar letras. */
int lerInteiro(char mensagem[]) {
    int numero;
    printf("%s", mensagem);
    while(scanf("%d", &numero) != 1) {
        limparBuffer();
        printf("Entrada invalida. Digite um numero inteiro: ");
    }
    limparBuffer();
    return numero;
}

/* Le um valor em reais, repetindo a pergunta se a entrada for invalida. */
float lerValor(char mensagem[]) {
    float valor;
    printf("%s", mensagem);
    while (scanf("%f", &valor) != 1) {
        limparBuffer();
        printf("Entrada invalida. Digite um valor (ex.: 150.50): ");
    }
    limparBuffer();
    return valor;
}

/* ===== Funcoes do caixa ===== */

void exibirBoasVindas(void) {
    printf("==============================================\n");
    printf("           BANCO DO ESTUDANTE - ATM           \n");
    printf("==============================================\n");
}

/* Pede a senha ate MAX_TENTATIVAS vezes. 
* Retorna 1 se acertou e 0 se errou todas. */
int autenticar(void) {
    int tentativa;
    int senha;

    for (tentativa = 1; tentativa <= MAX_TENTATIVAS; tentativa++) {
        senha = lerInteiro("Digite sua senha (4 digitos): ");

        if (senha == SENHA_CORRETA) {
            printf("\nAcesso liberado!\n");
            return 1;
        }

        if (tentativa < MAX_TENTATIVAS) {
            printf("Senha incorreta. Restam %d tentativa(s). \n\n", MAX_TENTATIVAS - tentativa);
        }
    }
    return 0;
}

void exibirMenu(void) {
    printf("\n-------------- MENU PRINCIPAL -------------\n");
    printf("  1 - Consultar saldo\n");
    printf("  2 - Depositar\n");
    printf("  3 - Sacar\n");
    printf("  4 - Extrato da sessao\n");
    printf("  0 - Sair\n");
    printf("---------------------------------------------\n");
}

void consultarSaldo(float saldo) {
    printf("\nSeu saldo atual e: R$ %.2f\n", saldo);
}

/* Le o valor do deposito.
 * Retorna o valor depositado, ou 0 se o valor for invalido. */
float depositar(void) {
    float valor = lerValor("\nValor do deposito: R$ ");

    if (valor <= 0) {
        printf("Valor invalido! O deposito deve ser maior que zero.\n");
        return 0;
    }
    return valor;
}

/* Le o valor do saque e verifica as regras do caixa. 
 * Retorna o valor sacado, ou 0 se o saque nao for permitido. */
float sacar(float saldo) {
    float valor = lerValor("\nValor do saque (multiplo de 10): R$ ");
    int valorInteiro = (int)valor;

    if (valor <= 0) {
        printf("Valor invalido! O saque deve ser maior que zero.\n");
        return 0;
    }

    if (valor != valorInteiro || valorInteiro % 10 != 0) {
        printf("Este caixa so possui notas de 10, 20, 50 e 100.\n");
        printf("Digite um valor multiplo de 10.\n");
        return 0;
    }

    if (valor > LIMITE_SAQUE) {
        printf("Limite por saque excedido (maximo R$ %.2f).\n", LIMITE_SAQUE);
        return 0;
    }

    if (valor > saldo){
        printf("Saldo insuficiente! Seu saldo e R$ %.2f.\n", saldo);
        return 0;
    }

    return valor;
}

int main(void) {
    float saldo = SALDO_INICIAL;
    float totalDepositado = 0.0f;
    float totalSacado = 0.0f;
    int   qtdOperacoes = 0;
    int   opcao;
    float valor;

    exibirBoasVindas();

    if (autenticar() == 0) {
        printf("\nCartao bloqueado! Procure sua agencia.\n");
        return 1;
    }

    do {
        exibirMenu();
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                consultarSaldo(saldo);
                break;

            case 2:
                valor = depositar();
                if (valor > 0) {
                    saldo = saldo + valor;
                    totalDepositado = totalDepositado + valor;
                    qtdOperacoes++;
                    printf("\nDeposito de R$ %.2f realizado com sucesso!\n", valor);
                }
                break;

            case 3:
                valor = sacar(saldo);
                if (valor > 0) {
                    saldo = saldo - valor;
                    totalSacado = totalSacado + valor;
                    qtdOperacoes++;
                    printf("\nSaque de R$ %.2f realizado. Retire seu dinheiro.\n", valor);
                }
                break;

            case 0:
                printf("\nObrigado por usar nosso caixa. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

        if (opcao != 0) {
            pausar();
        }
    } while (opcao != 0);

    return 0;
}