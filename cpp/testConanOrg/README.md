# Building



## building in root with Ninja  and conanfile.py

from https://docs.conan.io/en/latest/mastering/conanfile_py.html

build with the following
```
rm -rf build
conan install . --install-folder build --build=missing
conan build . --build-folder build

./build/bin/testConan 

```
rebuild with
```
cmake -S . -B build

```
or directly with ninja
```
cd build
ninja

./bin/testConan 
```

## Useful conan comands 

for other settings
```
conan install .. --settings os="Linux" --settings compiler="gcc"
```
conan search "*"

 conan search poco* --remote=conancenter

 conan search sqlite3/3.39.4@

conan info ..

conan --help



# Configuring conan

## creating a conan compiler profile

create a build profile for conan 
for defining compiler , os 

```
conan profile new mynewprofile --detect

```
to create default one
```
conan profile new default --detect
```

or copy the example below
```
cp ../_conan/profiles ~/.conan
```

## configure conan for Ninja outside of conanfile.py

from https://docs.conan.io/en/latest/integrations/build_system/ninja.html?highlight=ninja

configure generator to be Ninja instead of 'Unix Makefiles'
```
export CONAN_CMAKE_GENERATOR=Ninja
```

or once for all in conan config
```
conan config set general.cmake_generator=Ninja
```


## building in build with conanfile.txt

from https://computingforgeeks.com/how-to-manage-c-packages-using-conan/


```
rm -rf build
mkdir build
cd build
conan install ..
# conan install .. --profile=gcc-opt

cmake .. -G Ninja 
ninja

./bin/testConan 
```

## references

https://stackoverflow.com/questions/71548337/how-to-choose-ninja-as-cmake-generator-with-conan

