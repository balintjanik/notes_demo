# Notes
This is a really simple note taking console application written in C++ with the following features:
 - List notes
 - Add notes
 - Modify notes
 - Mark notes as done/undone
 - Delete notes

The program is implemented with Model-View architecture. The goal is only to show my basic C++ syntax knowledge.

## How to run
``` bash
cd src
gcc main.cpp Persistence/DataAccess.cpp Model/Model.cpp -o todo_app -lstdc++
./todo_app.exe
```
