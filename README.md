# Compression

This project contains a main file with two functions.
One to compress a file and a second to decompress encoded file.
For shorter code [Zlib](https://www.zlib.net) was used.

## Installation

### On MacOS
```shell
brew install zlib
```

### On Linux
```shell
sudo apt install zlib1g
```

### On Windows
Zlib Package for MinGW [(download here)](http://gnuwin32.sourceforge.net/packages/zlib.htm)

## Building
### Compiling
Run to following in your shell:
```shell
gcc -o main main.c -lz
```
or
```shell
make main
```

### Run
You can compile and directly run with:
```shell
make run
```

## function Compress

compressFile(*sourceFile, *destinationFile, compressionLevel) {}

### Compression Level

Define a compression level between 1 and 9.
1 is equal to the worst compression and 9 to the best compression level.
It is also possible to use level 0, which is equal to no compression.

## function Decompress

decompressFile(*sourceFile, *destinationFile) {}
