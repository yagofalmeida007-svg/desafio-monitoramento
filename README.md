# 🌡️ Desafio de Monitoramento de Temperaturas

## 1. Identificação

**Aluno:** Yago Fernandes de Almeida
**Disciplina:** Desenvolvimento de Algoritmos e Pensamento Computacional
**Professora:** Profa. Karla Sartin
**Título:** Sistema de Monitoramento de Temperaturas

---

## 2. Objetivo

O objetivo deste projeto é desenvolver um programa em linguagem C para realizar o monitoramento de temperaturas.

O sistema permite definir um limite de temperatura e registrar várias leituras. O programa identifica as temperaturas que estão acima do limite e acompanha a quantidade de temperaturas consecutivas nessa situação.

O monitoramento é encerrado automaticamente quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório contendo a média, a maior temperatura, a menor temperatura, a quantidade de leituras e o percentual de temperaturas acima do limite.

---

## 3. Funcionamento do programa

### Definição do limite

Inicialmente, o programa solicita ao usuário um limite de temperatura.

O valor deve estar entre **-50 °C e 100 °C**. Caso seja informado um valor fora desse intervalo, o programa informa que o valor é inválido e solicita uma nova entrada.

### Leitura das temperaturas

Depois de definir o limite, o programa começa a receber as temperaturas.

As temperaturas também devem estar entre **-50 °C e 100 °C**. Valores fora desse intervalo são considerados inválidos e não são utilizados nos cálculos do relatório.

Para encerrar manualmente o monitoramento, o usuário pode digitar **-999**.

### Identificação das temperaturas acima do limite

Cada temperatura válida é comparada com o limite definido no início do programa.

Quando a temperatura é maior que o limite, o programa:

* contabiliza a temperatura como acima do limite;
* aumenta o contador de temperaturas consecutivas;
* informa ao usuário que a temperatura está acima do limite.

### Contagem de temperaturas consecutivas

O programa utiliza uma variável chamada `consecutivas` para controlar quantas temperaturas acima do limite foram registradas em sequência.

Quando uma temperatura está acima do limite:

```c
consecutivas++;
```

Quando uma temperatura está dentro ou abaixo do limite:

```c
consecutivas = 0;
```

Dessa forma, o contador é reiniciado sempre que a sequência é interrompida.

Quando o contador chega a **3**, o programa encerra automaticamente o monitoramento.

### Relatório final

Ao finalizar o monitoramento, são apresentados:

* limite de temperatura;
* quantidade de temperaturas registradas;
* média das temperaturas;
* maior temperatura;
* menor temperatura;
* quantidade de temperaturas acima do limite;
* percentual de temperaturas acima do limite.

---

## 4. Estruturas de repetição utilizadas

### `do...while`

O `do...while` é utilizado para validar o limite de temperatura.

A estrutura garante que o usuário informe pelo menos um valor e continua solicitando uma nova entrada enquanto o valor estiver fora do intervalo permitido.

```c
do {
    printf("Digite o limite de temperatura (-50 a 100): ");
    scanf("%f", &limite);
} while (limite < -50 || limite > 100);
```

### `while`

O `while` é utilizado para realizar o monitoramento das temperaturas.

Ele permite que várias leituras sejam realizadas até que o usuário digite `-999` ou até que o programa identifique três temperaturas consecutivas acima do limite.

```c
while (temperatura != -999) {
    ...
}
```

A combinação de `do...while` e `while` permite realizar tanto a validação inicial quanto a repetição das leituras.

---

## 5. Como executar

O programa pode ser compilado utilizando o GCC.

### Compilação

```bash
gcc monitoramento.c -o monitoramento
```

### Execução no Linux ou Git Bash

```bash
./monitoramento
```

### Execução no Windows

Após a compilação, pode ser utilizado:

```bash
monitoramento.exe
```

---
[monitor](./src/monitor/monitor-de-temperatura.exe/)
## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

**Objetivo:** verificar se o programa identifica valores fora do intervalo permitido.

Foi informado um limite inválido, como:

```text
150
```

O programa identificou o valor como inválido e solicitou uma nova entrada.

Também foram testadas temperaturas fora do intervalo, como:

```text
120
```

O programa informou que a temperatura era inválida e não utilizou esse valor nos cálculos.

**Resultado:** teste realizado com sucesso.

---

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

**Limite:** 30 °C

Exemplo de entradas:

```text
32
28
35
29
34
```

Nesse cenário, algumas temperaturas ficaram acima do limite, mas a sequência foi interrompida por temperaturas abaixo ou iguais ao limite.

O contador de temperaturas consecutivas foi reiniciado sempre que isso aconteceu.

**Resultado:** o programa não encerrou automaticamente, pois não foram registradas três temperaturas consecutivas acima do limite.

---

### Teste 3 — Três temperaturas consecutivas acima do limite

**Limite:** 30 °C

Exemplo de entradas:

```text
32
35
38
```

As três temperaturas ficaram acima do limite definido.

Ao registrar a terceira temperatura consecutiva acima do limite, o programa exibiu um alerta e encerrou automaticamente o monitoramento.

**Resultado:** teste realizado com sucesso.

---

## 7. Evidências

As evidências dos testes realizados estão disponíveis na pasta:
[evidencias](./evidencias)
```text
evidencias/
```

Arquivos:

```text
evidencias/
├── teste01.png
├── teste02.png
└── teste03.png
```

Cada imagem apresenta a execução do programa referente a um dos três cenários exigidos na atividade.

---

## 8. Estrutura do projeto

```text
desafio-monitoramento/
│
├── monitoramento.c
│
├── README.md
│
└── evidencias/
    ├── teste01.png
    ├── teste02.png
    └── teste03.png
```

---

## 9. Tecnologias utilizadas

* Linguagem C
* GCC
* Visual Studio Code
* Git
* GitHub
