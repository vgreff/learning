
echo "Usage: createNew.sh NewProject"

NewDir=$1
mkdir -p ../$NewDir
cp  * ../$NewDir
cd ../$NewDir

./renMod.pl PlayWithCpp $NewDir *

