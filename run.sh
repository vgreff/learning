
if [ -z `which apt`  ]
then
     export YUM=yum
else
     export YUM=apt
fi

git submodule update --init --recursive

. ./bash_aliases

. setup_emacs.d-vg.sh
. ~/.bashrc

. setup_install_extra.sh

# . setup_install_emacs.sh

cat ~/.bashrc
echo ". ~/.bashrc"

setenv EDITOR vi


