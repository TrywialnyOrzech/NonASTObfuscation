# NonASTObfuscation
## Required libraries
* GTest (automated download in cmake)
## Setup
### Compilation
1. Clone repository
2. cd to NonASTObfuscation and run
```bash
$ cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_C_COMPILER:FILEPATH=/bin/gcc-9 -H./ -Bbuild -G "Unix Makefiles"
```
```bash
$ cmake --build build --config Release --target all -j 3 --
```
### Execution
From build dir, type
```bash
./main [INPUT FILE] [OUTPUT FILE]
```
Arguments are not required (proper files are already in project directory).
### Unit tests
In build/src/test run:
```bash
./tests
```
