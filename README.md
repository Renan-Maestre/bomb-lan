# Olha a Bomba

Projeto simples de jogo em C++ usando [raylib](https://www.raylib.com/). A ideia base e controlar um jogador em uma arena 2D enquanto bombas aparecem em posicoes aleatorias, contam alguns segundos e explodem em uma area circular.

O projeto ainda esta em desenvolvimento. No estado atual existe um jogador controlado pelo teclado, uma bomba com temporizador e deteccao de colisao com a explosao. O segundo jogador e a logica de dano/pontuacao ainda aparecem como partes comentadas no codigo.

## O que o projeto usa

- C++17
- g++
- raylib
- Makefile

## Como funciona

- A janela do jogo abre em `800x800`.
- O jogador aparece como um circulo vermelho.
- A bomba aparece como um circulo amarelo.
- Depois de alguns segundos, a bomba explode mostrando uma area circular laranja.
- Apos a explosao, uma nova bomba nasce em outra posicao.

## Controles

Use as teclas:

- `W`: mover para cima
- `S`: mover para baixo
- `A`: mover para a esquerda
- `D`: mover para a direita

## Estrutura do projeto

```text
.
├── Makefile
├── main.cpp
├── Game.hpp
├── Game.cpp
├── player/
│   ├── player.hpp
│   └── player.cpp
└── bomb/
    ├── bomb.hpp
    └── bomb.cpp
```

## Instalacao no Linux

### Ubuntu/Debian

Instale o compilador, o Make e as dependencias basicas:

```bash
sudo apt update
sudo apt install build-essential git
```

Instale a raylib:

```bash
sudo apt install libraylib-dev
```

Se sua distribuicao nao tiver `libraylib-dev` nos repositorios, instale a raylib seguindo a documentacao oficial:

```text
https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux
```

Depois, compile o projeto:

```bash
make
```

Para compilar e executar:

```bash
make run
```

Para limpar o executavel gerado:

```bash
make clean
```

## Instalacao no Windows

No Windows, uma forma simples e usar MSYS2, que fornece o `g++`, `make` e a raylib.

1. Baixe e instale o MSYS2:

```text
https://www.msys2.org/
```

2. Abra o terminal **MSYS2 UCRT64**.

3. Atualize os pacotes:

```bash
pacman -Syu
```

Se o MSYS2 pedir para fechar o terminal, feche, abra novamente o **MSYS2 UCRT64** e rode:

```bash
pacman -Su
```

4. Instale o `g++`, `make` e a raylib:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-raylib
```

5. Entre na pasta do projeto pelo terminal. Exemplo:

```bash
cd /c/caminho/para/o/projeto
```

6. Compile usando:

```bash
mingw32-make
```

7. Execute:

```bash
./Bomba.exe
```

## Observacao sobre o Makefile no Windows

O `Makefile` atual foi escrito pensando principalmente em Linux, porque usa bibliotecas como `-lGL`, `-lpthread`, `-ldl`, `-lrt` e `-lX11`.

No MSYS2/Windows, se a compilacao falhar por causa dessas bibliotecas, ajuste a linha `LIBS` do `Makefile` para:

```make
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
```

Depois compile novamente com:

```bash
mingw32-make
```

## Compilacao manual

Se nao quiser usar `make`, no Linux voce pode compilar manualmente com:

```bash
g++ -Wall -Wextra -std=c++17 main.cpp Game.cpp player/player.cpp bomb/bomb.cpp -o Bomba -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

No Windows com MSYS2 UCRT64:

```bash
g++ -Wall -Wextra -std=c++17 main.cpp Game.cpp player/player.cpp bomb/bomb.cpp -o Bomba.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

