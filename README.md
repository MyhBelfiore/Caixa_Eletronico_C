# 🏧 Caixa Eletrônico em C

Simulador de caixa eletrônico feito em linguagem C, no terminal, como projeto de estudo de **lógica de programação e funções**.

## ✨ Funcionalidades

- 🔐 Login com senha (o cartão é bloqueado após 3 tentativas erradas)
- 💰 Consulta de saldo
- ➕ Depósito (só aceita valores maiores que zero)
- ➖ Saque com regras de um caixa real:
  - apenas valores múltiplos de 10 (notas de 10, 20, 50 e 100)
  - limite de R$ 1.000,00 por saque
  - não permite sacar mais que o saldo
- 📄 Extrato da sessão (total depositado, total sacado e número de operações)
- ✅ Validação de entrada: o programa não trava se o usuário digitar letras

## 🧠 Conceitos praticados

- Variáveis e constantes (`#define`)
- Estruturas condicionais (`if/else`, `switch`)
- Laços de repetição (`for`, `while`, `do-while`)
- Funções com parâmetros e retorno
- Leitura e validação de dados com `scanf`

## ▶️ Como executar

É necessário ter um compilador C instalado (por exemplo, o **GCC** via MinGW no Windows).

```bash
# compilar
gcc main.c -o caixa

# executar (Windows)
caixa.exe

# executar (Linux/macOS)
./caixa
```

> Senha padrão para teste: **1234**

## 🖥️ Exemplo de uso

```
========================================
        BANCO DO ESTUDANTE - ATM
========================================
Digite sua senha (4 digitos): 1234

Acesso liberado!

------------- MENU PRINCIPAL -----------
  1 - Consultar saldo
  2 - Depositar
  3 - Sacar
  4 - Extrato da sessao
  0 - Sair
----------------------------------------
Escolha uma opcao: 3

Valor do saque (multiplo de 10): R$ 120

Saque de R$ 120.00 realizado. Retire seu dinheiro.
```

## 🚀 Próximas melhorias

- [ ] Mostrar quais notas foram entregues no saque
- [ ] Permitir trocar a senha
- [ ] Guardar o histórico de operações (quando eu aprender vetores)
- [ ] Salvar o saldo em arquivo (quando eu aprender arquivos)

## 👩‍💻 Autora

Feito por **[Seu Nome]** durante os estudos de linguagem C.
