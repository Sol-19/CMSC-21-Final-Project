# CMSC-21-Final-Project
playing chess in the terminal

## Build and run

Use VS Code tasks:

1. Run task `Build chess` to compile `main.c` and source files into `chess.exe`.
2. Run task `Run chess` to build and start the program.

Equivalent terminal command:
Navigate to the chess file directory and run 

```bash
gcc -g main.c functions/*.c functions/pieces/*.c -o main.exe
./chess.exe
```
