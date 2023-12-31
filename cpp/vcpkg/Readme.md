# vcpkg

## installing

https://github.com/microsoft/vcpkg

do the following to install
```

git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh

```

add to environment
```
export VCPKG_ROOT="/home/vgreff/gh/oss/vcpkg"
export PATH=$VCPKG_ROOT;$PATH

```

in a new project
```
vcpkg new --application
vcpkg add port fmt
```