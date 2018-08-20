# CCalc
Compiles on Linux & Mac (using Make) and Windows (using MinGW).

## Requirements
### Linux
- GCC 4.8.1
- git
- make

### Windows
- Cygwin or MinGW (in PATH)
- Git
- GCC 4.8.1 (if using Cygwin)

## Build (Linux)
- Clone everything.h repository using
```git clone https://github.com/akachronix/everything.h.git```

- Clone CCalc repository using
```git clone https://github.com/akachronix/CCalc.git```

- Run everything.h makefile.
```make all```

- Copy lib folder created by Makefile to CCalc directory.

- Run CCalc makefile.
```make all```

- Success.

## Build (Windows)
- Install Git for Windows.

- Clone everything.h repository using
```git clone https://github.com/akachronix/everything.h.git```

- Clone CCalc repository using
```git clone https://github.com/akachronix/CCalc.git```

- Open a Command Prompt where Git for Windows cloned the everything.h repository.

- Run everything.h makefile.
```mingw32-make all```

- Copy lib folder into CCalc folder.

- Run CCalc makefile
```mingw32-make all```

- Success.

## Install (Linux)
- Clone everything.h repository using
```git clone https://github.com/akachronix/everything.h.git```

- Clone CCalc repository using
```git clone https://github.com/akachronix/CCalc.git```

- Run everything.h makefile.
```make all```

- Copy lib folder created by Makefile to CCalc directory.

- Run CCalc makefile.
```make install```

- Success.

## Help
- If your Makefile output is something along the lines of incompatible lib, then recompile the static library.

- If your terminal output looks something like this when running a compile script on Windows:
```cygwin-compile.sh: line 2: $'\r': command not found```
```cygwin-compile.sh: line 76: syntax error: unexpected end of file```
open Notepad++. Open the file and go under Edit/EOL Conversions and change that to Unix.
