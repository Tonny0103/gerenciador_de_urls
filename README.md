# Histórico de Navegação Web

Projeto desenvolvido para a disciplina de **Estrutura de Dados** do curso de **Engenharia da Computação** do **IFMT Campus Octayde**.

## Descrição

Simulação de um histórico de navegação web implementado em linguagem C, utilizando uma **lista duplamente encadeada** como estrutura de dados principal. O programa permite ao usuário navegar entre URLs salvas, acessar novos endereços, editar registros existentes e persistir o histórico entre sessões através de um arquivo de texto.

## Funcionalidades

- **Ir para um endereço** — insere uma nova URL no histórico com data e hora capturadas automaticamente
- **Avançar** — navega para a próxima URL no histórico
- **Voltar** — retorna à URL anterior no histórico
- **Editar endereço** — permite alterar a URL, data ou hora de um registro existente
- **Excluir endereço** — permite excluir um item da lista de URL
- **Exibir histórico** — lista todas as URLs salvas, destacando a posição atual
- **Persistência** — carrega o histórico do arquivo `dados.txt` ao iniciar e salva automaticamente ao encerrar

## Estrutura de Dados

O programa utiliza uma **lista duplamente encadeada** com capacidade máxima de 10 nós. Cada nó armazena:

| Campo | Tipo | Descrição |
|---|---|---|
| `endereco` | `char*` | URL com até 2083 caracteres |
| `data` | `char*` | Data de acesso no formato `dd/mm/aaaa` |
| `hora` | `char*` | Hora de acesso no formato `hh:mm:ss` |

## Estrutura do Projeto

```
.
├── CMakeLists.txt
├── dados.txt
├── main.c
├── include/
│   ├── dados.h
│   ├── lista_url.h
│   ├── menu.h
│   ├── navegacao.h
│   └── url.h
└── src/
    ├── dados.c
    ├── lista_url.c
    ├── menu.c
    ├── navegacao.c
    └── url.c
```

## Online GDB
Case seja de preferência, utilize o [Online GDB](https://onlinegdb.com/qeMfzmcpH) para testar o código.

## Requisitos

- GCC ou outro compilador C compatível
- CMake 4.1 ou superior

## Como Compilar e Executar

**1. Clone o repositório:**
```bash
git clone <url-do-repositorio>
cd <nome-do-repositorio>
```

**2. Crie o diretório de build e compile:**
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

**3. Execute o programa:**
```bash
# Linux / macOS
./gerenciador_de_urls

# Windows
.\gerenciador_de_urls.exe
```

> O arquivo `dados.txt` deve estar no mesmo diretório de onde o programa é executado.

## Formato do Arquivo de Persistência

O arquivo `dados.txt` armazena um registro por linha, com os campos separados pelo caractere `|`:

```
https://www.google.com|01/05/2026|08:14:02
https://www.github.com|01/05/2026|08:17:45
```

## Disciplina

| | |
|---|---|
| **Instituição** | IFMT Campus Octayde |
| **Curso** | Engenharia da Computação |
| **Disciplina** | Estrutura de Dados |
| **Aluno** | Anthonny Gabriell Marins Alves |
| **Turma** | 2026.1 |
| **Data** | 09/05/2026 |