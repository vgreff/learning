cd 
git clone https://github.com/vgreff/.emacs.d-vg.git

cd .emacs.d-vg
git submodule update --init --recursive
. README.md

echo "source ~/.bash_aliases" >> ~/.bashrc
