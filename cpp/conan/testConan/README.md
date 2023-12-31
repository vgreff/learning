# Instructions


from https://computingforgeeks.com/how-to-manage-c-packages-using-conan/

## compiler profile

create a build profile for conan 
for defining compiler , os 

```
conan profile detect --force
```

or copy the example below
```
cp ../_conan/profiles ~/.conan
```


## building

```
rm -rf build
mkdir build
cd build
conan install ..

# or  
conan install . --output-folder=build --build=missing

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

## to simply build in vscode

```
conan profile detect --force
conan install . --output-folder=build --build=missing
```

the use cmake pluggin
