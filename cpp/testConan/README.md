# Instructions


from https://computingforgeeks.com/how-to-manage-c-packages-using-conan/

## compiler profile

create a build profile for conan 
for defining compiler , os 

or copy the example below
```
cp ../_conan/profiles ~/.conan
```


## building

```
mkdir build
cd build
conan install ..

cmake .. -G Ninja 
ninja

./bin/testConan 
```


## conan comands 

for other settings
```
conan install .. --settings os="Linux" --settings compiler="gcc"
```
conan search "*"

 conan search poco* --remote=conancenter

 conan search sqlite3/3.39.4@

conan info ..

conan --help

