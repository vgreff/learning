cd
# this will ask for name of output files
ssh-keygen -t rsa -b 4096 -C "vince@greffsite.com"

# to name output files and current dir
# ssh-keygen -t rsa -b 4096 -C "vince@greffsite.com" -f vg_rsa

ls -la .ssh/

cat .ssh/id_rsa.pub

echo "goto https://github.com/settings/keys"
echo "add the content of .ssh/id_rsa.pub into a new ssh key in github"

echo "in .git/config"
echo "replace url = https://github.com/vgreff/learning.git"
echo "with    url = git@github.com:vgreff/learning.git"
