# CMSC-21-Final-Project
playing chess in the terminal

## Build and run

Use VS Code tasks:

1. Run task `Build chess` to compile `main.c` and source files into `chess.exe`.
2. Run task `Run chess` to build and start the program.

Equivalent terminal command:

```bash
D:/msys64/ucrt64/bin/gcc.exe -g main.c functions/chess_struct.c functions/chess_utils.c -o chess.exe
./chess.exe
```
