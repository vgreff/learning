
if [ -z `which apt`  ]
then
     export YUM=yum
else
     export YUM=apt
fi

git submodule update --init --recursive

. ./bash_aliases

. conf/setup_emacs.d-vg.sh
. ~/.bashrc

. conf/setup_install_extra.sh

# . conf/setup_install_emacs.sh

cat ~/.bashrc
echo ". ~/.bashrc"

setenv EDITOR vi


