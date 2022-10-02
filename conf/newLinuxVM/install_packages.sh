 sudo $YUM install -y git



if [ -z `which apt`  ]
then
#------------------------------------------
	echo "Redhat"

echo "install code"
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'

yum check-update
sudo yum install code
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
echo "install code"
sudo apt-get install wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

sudo apt install apt-transport-https
sudo apt update
sudo apt install code
sudo apt install -y terminator

# https://computingforgeeks.com/how-to-manage-c-packages-using-conan/
sudo apt install -y  python3 python3-pip
sudo apt-get install -y build-essential
sudo apt install -y cmake ninja-build
sudo pip3 install conan

sudo apt  install -y cmake-qt-gui 
sudo apt install -y meld
sudo apt install -y gitk
sudo apt  install -y gh 
sudo apt install -y ddd

#sudo apt list --upgradable
#sudo apt upgrade

fi
