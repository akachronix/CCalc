# CCalc
Compiles on Linux and Windows with MinGW.

## Requirements
### Linux
- GCC 4.8.1
- git
- sh

### Windows
- Cygwin or MinGW (in PATH)
- Git

## Build (Linux)
- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Mark script as executable.
```chmod +x linux-compile.sh```

- Run script.
```sh linux-compile.sh```

- Success.

## Build (Windows)
- Install Git for Windows.

- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Open a Command Prompt where Git for Windows cloned the repository.

- Run script. (MinGW)
```windows-compile.cmd```

- Run script. (Cygwin)
```sh cygwin-compile.sh```

- Success.

## Install (Linux)
- Clone repository using
```git clone https://github.com/akachronix/CCalc.git```

- Mark script as executable.
```chmod +x linux-install.sh```

- Run script.
```sh linux-install.sh```

- Success.

## Help
- If your terminal output looks something like this when running a compile script on Windows:
```cygwin-compile.sh: line 2: $'\r': command not found```
```cygwin-compile.sh: line 76: syntax error: unexpected end of file```
open Notepad++. Open the file and go under Edit/EOL Conversions and change that to Unix.

