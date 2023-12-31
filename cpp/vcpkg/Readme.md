# vcpkg

## installing

https://github.com/microsoft/vcpkg

do the following to install

```bash

git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh

```

add to environment

```bash

export VCPKG_ROOT="/home/vgreff/gh/oss/vcpkg"
export PATH=$VCPKG_ROOT:$PATH

```

in a new project to add lib

```bash
vcpkg new --application
vcpkg add port fmt
```


to install pakcges manally from shell

```bash
vcpkg install
```

## tutorials

https://learn.microsoft.com/en-us/vcpkg/

https://learn.microsoft.com/en-us/vcpkg/consume/boost-versions

```bash
cd $VCPKG_ROOT
git log "--format=%H %cd %s" --date=short --left-only -- versions/b-/boost-optional.json

```