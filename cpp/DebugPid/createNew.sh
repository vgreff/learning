
echo "Usage: createNew.sh NewProject"

NewDir=$1
./clean.sh
mkdir -p ../$NewDir
cp  -r * .vscode .gitignore ../$NewDir
cd ../$NewDir

./renMod.pl DebugPid $NewDir *

