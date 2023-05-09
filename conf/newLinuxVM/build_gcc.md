# Building C++ from source

## gcc

info from https://iq.opengenus.org/build-gcc-from-source/


instructions
```
git clone https://github.com/gcc-mirror/gcc.git
cd gcc

git tag


#git checkout releases/gcc-12.2.0
#git checkout releases/gcc-13.1.0

git worktree add ../gcc-13.1.0 releases/gcc-13.1.0
cd ../gcc-13.1.0
./contrib/download_prerequisites
cd ..
mkdir objdir
cd objdir

scl enable gcc-toolset-12 bash

#$PWD/../gcc-13.1.0/configure --prefix=$HOME/GCC/13.1.0 --enable-languages=c,c++,fortran,go 
#$PWD/../gcc-13.1.0/configure --prefix=$HOME/GCC/13.1.0 --enable-languages=c,c++,fortran,go --disable-multilib
$PWD/../gcc-13.1.0/configure --prefix=$HOME/GCC/13.1.0 --enable-languages=c,c++ --disable-multilib


make -j 12
make install

gcc --version

```

## gdb


```
https://github.com/bminor/binutils-gdb

cd binutils-gdb
git tag |fgrep gdb-13 |fgrep rele

git worktree add ../gdb-13.1-release gdb-13.1-release
cd ../gdb-13.1-release

scl enable gcc-toolset-12 bash

mkdir objdir
cd objdir
../configure --prefix=$HOME/GDB/13.1

make -j 12
make install

```
