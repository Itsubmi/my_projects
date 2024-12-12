gcc FuncChest.c -c -o chest.obj
gcc FuncLocation.c -c -o loc.obj
gcc FuncCreatures.c -c -o creature.obj
gcc main.c -c -o main.obj
gcc main.obj creature.obj loc.obj chest.obj -o my_program.exe
my_program.exe