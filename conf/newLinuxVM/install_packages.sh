 sudo $YUM install -y git



if [ -z `which apt`  ]
then
#------------------------------------------
	echo "Redhat"

sudo yum install -y net-tools
sudo yum install -y wget gpg

# echo "install code"
# sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
# sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'

sudo yum check-update -y
# sudo yum install -y code
# sudo yum install -y terminator

sudo yum install -y python3
sudo yum install -y  cmake3
sudo yum install -y epel-release
sudo dnf config-manager --set-enabled powertools
sudo yum install -y ninja-build
sudo yum groupinstall "Development Tools" -y
sudo pip3 install conan

sudo yum install -y wget gpg
sudo yum install -y vim  
sudo yum install -y rename
sudo yum install -y emacs

sudo yum install -y gdb

# paste this for AWS
sudo yum install -y socat
sudo yum install -y jq 
sudo yum install -y jc 
sudo yum install -y dnf
sudo yum install -y tree
sudo yum install -y htop
sudo yum install -y ipython3

sudo dnf install -y 'dnf-command(config-manager)'
sudo dnf config-manager -y --add-repo https://cli.github.com/packages/rpm/gh-cli.repo
sudo dnf install -y gh

sudo yum install -y cmake-qt-gui 
sudo yum install -y meld
sudo yum install -y gitk
sudo yum install -y ddd

#sudo snap install --classic ruby
sudo yum install -y ncdu
sudo yum install -y xutils-dev
sudo yum install -y texinfo
sudo yum install -y zsh
sudo yum install -y doxygen
sudo yum install -y pv tcpreplay wireshark

sudo yum install -y lldb clang clang-devel clang-tools-extra

#for compiling gdb 
sudo yum install -y help2man
sudo yum install -y expat
sudo yum install -y expat-devel
sudo yum install -y gmp-devel

sudo yum install -y cloud-utils-growpart 

curl -s https://packagecloud.io/install/repositories/eugeny/tabby/script.rpm.sh | sudo bash
sudo apt install -y tabby-terminal

dnf install -y gcc-toolset-9
dnf install -y gcc-toolset-10
dnf install -y gcc-toolset-11
dnf install -y gcc-toolset-12
dnf install -y gcc-toolset-13

#to enable ssh access to machine
sudo yum install -y openssh-server
#sudo service ssh status
#sudo service ssh start
sudo systemctl enable sshd
sudo systemctl start sshd

sudo yum install -y kernel-devel
sudo yum install -y perl-IPC-Cmd
sudo dnf install -y autoconf automake autoconf-archive

sudo yum install -y open-vm-tools-desktop open-vm-tools
sudo yum install -y libatomic binutils

sudo yum install -y cloud-utils-growpart

sudo yum install -y sqlite sqlite-devel

# sudo yum install -y mysql-server
curl -sS https://downloads.mariadb.com/MariaDB/mariadb_repo_setup | sudo bash
sudo yum update --allowerasing

sudo dnf install MariaDB-server galera-4 MariaDB-client MariaDB-shared MariaDB-backup MariaDB-common
# sudo yum install -y mariadb-server
# sudo yum install -y mariadb-devel

lsmod | grep vmw


echo "install docker"
sudo dnf config-manager --add-repo=https://download.docker.com/linux/centos/docker-ce.repo
sudo dnf repolist -v
dnf install -y docker-ce

sudo systemctl enable --now docker
systemctl is-active docker
systemctl is-enabled docker

curl -L "https://github.com/docker/compose/releases/download/1.23.2/docker-compose-$(uname -s)-$(uname -m)" -o docker-compose
sudo mv docker-compose /usr/local/bin && sudo chmod +x /usr/local/bin/docker-compose

sudo dnf install -y python3-pip

sudo usermod -aG docker ${USER}

groups

else

#------------------------------------------
	echo "Ubuntu"

# paste this for AWS
sudo apt update -y
sudo apt-get install -y wget gpg
sudo apt install -y vim  
sudo apt install -y rename
sudo apt install -y emacs
sudo apt install -y net-tools

# echo "install code"
# #sudo apt-get install -y wget gpg
# wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
# sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
# sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
# rm -f packages.microsoft.gpg

sudo apt install -y apt-transport-https
sudo apt update && sudo apt upgrade -y 
# sudo apt install -y code

# sudo apt install -y terminator

# https://computingforgeeks.com/how-to-manage-c-packages-using-conan/
# paste this for AWS
sudo apt install -y  python3 python3-pip
sudo apt-get install -y build-essential
sudo apt install -y cmake ninja-build
sudo pip3 install conan
sudo apt install -y gdb

# paste this for AWS
sudo apt install -y socat
sudo apt install -y jq 
sudo apt install -y jc 
sudo apt install -y dnf
sudo apt install -y tree
sudo apt install -y htop
sudo apt install -y ipython3

sudo dnf install -y 'dnf-command(config-manager)'
sudo dnf config-manager -y --add-repo https://cli.github.com/packages/rpm/gh-cli.repo
sudo dnf install -y gh

sudo apt install -y cmake-qt-gui 
sudo apt install -y meld
sudo apt install -y gitk
sudo apt install -y ddd

sudo snap install --classic ruby
sudo apt install -y ncdu
sudo apt install -y xutils-dev
sudo apt install -y texinfo
sudo apt install -y zsh
sudo apt install -y doxygen
sudo apt install -y pv tcpreplay wireshark

#to enable ssh access to machine
sudo apt install -y openssh-server
#sudo service ssh status
#sudo service ssh start
sudo systemctl enable sshd
sudo systemctl start sshd

sudo apt install -y open-vm-tools-desktop open-vm-tools
lsmod | grep vmw

dnf install -y gcc-toolset-9
dnf install -y gcc-toolset-10
dnf install -y gcc-toolset-11
dnf install -y gcc-toolset-12
dnf install -y gcc-toolset-13

sudo apt install -y lldb clang clang-devel clang-tools-extra

#for compiling gdb 
sudo apt install -y help2man
sudo apt install -y expat
sudo apt install -y expat-devel
sudo apt install -y gmp-devel

curl -s https://packagecloud.io/install/repositories/eugeny/tabby/script.deb.sh | sudo bash
sudo apt install -y tabby-terminal

# scl enable gcc-toolset-12 bash

#sudo apt list --upgradable
#sudo apt upgrade

# enable window manager tiling
# Open Settings from the App Menu, then `Window Manager-> leyboard-> tile window *''
# info from https://forum.zorin.com/t/how-i-can-enable-tiling-windows-or-window-snapping-in-xfce-zorin-lite/16437/4


echo "install docker"
#https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-22-04

sudo apt update
sudo apt install -y apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt update
apt-cache policy docker-ce

sudo apt install -y docker-ce
sudo systemctl status docker
sudo usermod -aG docker ${USER}

groups

echo "install docker-compose"

#https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-compose-on-ubuntu-22-04
mkdir -p ~/.docker/cli-plugins/
curl -SL https://github.com/docker/compose/releases/download/v2.3.3/docker-compose-linux-x86_64 -o ~/.docker/cli-plugins/docker-compose

chmod +x ~/.docker/cli-plugins/docker-compose
docker compose version

fi

echo "install aws cli"
cd /tmp
curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"
unzip awscliv2.zip
sudo ./aws/install
cd -

# echo "install rust"
# curl https://sh.rustup.rs -sSf | sh
