#extra install

sudo yum install -y tig

git clone https://github.com/vim-airline/vim-airline ~/.vim/pack/dist/start/vim-airline
ln -s `pwd`/.vimrc ~/.vimrc

echo "source `pwd`/bash_aliases" >> ~/.bashrc

. ~/.bashrc

cat ~/.bashrc

echo ". ~/.bashrc"

