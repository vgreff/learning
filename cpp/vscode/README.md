
code  --list-extensions > InstalledExtensions.txt

code  --list-extensions --show-versions > InstalledExtensionsVersions.txt

for i in `cat InstalledExtensions.txt`
do
    echo "INSTALLING EXTENSION $i" 
    code --install-extension $i
done

