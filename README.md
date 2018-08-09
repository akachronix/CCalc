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
- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Run makefile.
```make all```

- Success.

## Build (Windows)
- Install Git for Windows.

- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Open a Command Prompt where Git for Windows cloned the repository.

- Run compile script. (MinGW)
```compile.cmd```

- Run makefile. (Cygwin)
```make```

- Success.

## Install (Linux)
- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Run makefile.
```make install```

- Success.

## Help
- If your terminal output looks something like this when running a compile script on Windows:
```cygwin-compile.sh: line 2: $'\r': command not found```
```cygwin-compile.sh: line 76: syntax error: unexpected end of file```
open Notepad++. Open the file and go under Edit/EOL Conversions and change that to Unix.

