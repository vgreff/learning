 sudo $YUM install -y git



if [ -z `which apt`  ]
then
#------------------------------------------
	echo "Redhat"

echo "install code"
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'

yum check-update
sudo yum install -y code
sudo apt install -y terminator

sudo yum install cmake
sudo yum install epel-release
sudo dnf config-manager --set-enabled powertools
sudo yum install ninja-build
sudo yum groupinstall "Development Tools" -y
sudo pip3 install conan

else
#------------------------------------------
	echo "Ubuntu"

# paste this for AWS
sudo apt update 
sudo apt-get install -y wget gpg
sudo apt install -y vim  
sudo apt install -y rename
sudo apt install -y emacs

echo "install code"
#sudo apt-get install -y wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

sudo apt install -y apt-transport-https
sudo apt update && sudo apt upgrade
sudo apt install -y code

sudo apt install -y terminator

# https://computingforgeeks.com/how-to-manage-c-packages-using-conan/
# paste this for AWS
sudo apt install -y  python3 python3-pip
sudo apt-get install -y build-essential
sudo apt install -y cmake ninja-build
sudo pip3 install conan
sudo apt install -y gh 
sudo apt install -y gdb

# paste this for AWS
sudo apt install -y socat
sudo apt install -y jq 
sudo apt install -y jc 
sudo apt install -y dnf
sudo apt install -y tree
sudo apt install -y ipython3

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

sudo apt install -y open-vm-tools-desktop open-vm-tools
lsmod | grep vmw

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

echo "install rust"
curl https://sh.rustup.rs -sSf | sh
