# Simulador de Autômatos

Projeto construído durante o segundo período de gradução na Universidade Estadual do Norte do Paraná ([UENP](https://uenp.edu.br/)). O projeto consiste em um simulador de autômatos, com a capacidade de receber, processar e identificar se uma palavra é ou não aceita por um determinado autômato.

## Uso

Em breve será disponibilizado um bundle para download multiplataforma.

### 1. Clonar o repositório

```bash
# Recomendado uso de SSH

git clone https://github.com/henriq4/universityOn.git
```

### 2. Mudar o diretório

```bash
cd ./projects/finite-automata-cli/
```

### 3. Executar o autômato

#### Linux

```bash
./bin/automata <automata-pattern> <input-file> <output-file>
```

#### Windows

```bash
./bin/automata.exe <automata-pattern> <input-file> <output-file>
```

## Funcionamento

O simulador é responsável por ler um modelo pré definido de um autômato, junto a um arquivo de entrada (CSV separado por ponto e vírgula) e um arquivo de saída, que será o resultado da leitura do arquivo de entrada processado com u modelo de autômato, produzindo um CSV (separado por ponto e vírgula) com os itens, respectivamente: input recebido, resultado esperado e tempo de processamento (em milissegundos). Após o processamento o programa também realiza um log no console do usuário para melhor identificação dos resultados.

### Estrutura de arquivos

```shell
  .
  ├── bin
  │  ├── automata
  │  └── automata.exe
  ├── src
  │	 ├── dtos
  │  ├── input
  │	 ├── models
  │  ├── output
  │  ├── services
  │  ├── utils
  │  └── index.ts
  ├── .gitignore
  ├── package.json
  ├── pnpm-lock.yaml
  ├── README.md
  └── tsconfig.json
```

- #### input

Modelos de inputs a serem processados.

```csv
abababababababacacbaba;2
```

- #### outputs

Modelos de resultado do processamento do simulador.

```csv
abababababababacacbaba;2;0.0047
```

- #### models

Camada da aplicação responsável por dar tipagem aos modelos de entrada (tanto dos autômatos e inputs), do modelo de saída e do modelo de autômato que será utilizado para processamento.

O diretório contêm três (3) principais arquivos, cada um com uma das tipagens ditas acima.

- #### dtos

Camada da aplicação responsável por receber os dados, enviar para o processamento e devolver os dados processados.

O arquivo de dto do autômato consiste em uma classe com métodos estáticos (sem a necessidade de uma instância) para: receber um arquivo de autômato (fromJson); receber um arquivo de entrada (fromCsv); gerar o arquivo de saída (generateOutput).

- #### services

Camada da aplicação responsável por simular o automato. Consiste no processamento de tabelas hash's com base em um input de strings.

O arquivo de serviço do autômato consiste em uma classe com a dependência de um AutomataModel injetada. Suas funções consistem em processar o autômato recursivamente (extendedTransition) com a ajuda de uma função delta para verificação dos estados presentes na tabela hash unidas em uma função de execução (run), responsável por chamar o processamento e contablizar seu tempo (em milissegundos).

- #### utils

Funções de utilidade para toda aplicação.

O arquivo de criação do nome do estado (compartilhado para o dto e services), consiste em uma função que recebe um estado e o caractere lido, que resulta a criação de um novo estado com o nome dos parâmetros unidos.

- #### index.ts

Responsável pela gerência das camadas, o `index.ts` arquiteta toda a aplicação.

## Roadmap

- [x] Reconhecer DFA's
- [x] Reconhecer NFA's
- [ ] Reconhecer ε-NFA's
- [x] Log's no arquivo
- [x] Los's no console
- [x] Executável
- [ ] Baixar executável por script

---

<p align="center">
Henrique GC
</p>
