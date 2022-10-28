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


