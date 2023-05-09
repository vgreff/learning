
https://iq.opengenus.org/build-gcc-from-source/


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


#$PWD/../gcc-13.1.0/configure --prefix=$HOME/GCC/13.1.0 --enable-languages=c,c++,fortran,go 
$PWD/../gcc-13.1.0/configure --prefix=$HOME/GCC/13.1.0 --enable-languages=c,c++,fortran,go --disable-multilib

make -j
make install

gcc --version
