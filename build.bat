gcc -x c -c src\main.c -o obj\main.o -Wall -Wextra -g
gcc obj\main.o -o out\main.exe -Wall -Wextra -L.\lib\ -mwindows -lraylib -lWinmm -g