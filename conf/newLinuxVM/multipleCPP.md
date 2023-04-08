https://linuxconfig.org/how-to-switch-between-multiple-gcc-and-g-compiler-versions-on-ubuntu-22-04-lts-jammy-jellyfish

 sudo apt update
 sudo apt install build-essential
 sudo apt -y install gcc-11 g++-11 gcc-12  g++-12 

 sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 11
 sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 11
 sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 12
 sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 12

 sudo update-alternatives --config g++

 sudo update-alternatives --config gcc

gcc --version
g++ --version

sudo update-alternatives --get-selections
