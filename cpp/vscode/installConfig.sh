#!/usr/bin/bash

NOW=`date +%Y%m%d-%H%M%S`

# remote-ssh
VSCODEUSERDIR=~/.vscode-server/data/User

#vscode native on linux
#VSCODEUSERDIR=~/.config/Code/User

# if vscode in windows, must copy snippets/default-snippets-manager.code-snippets %APPDATA%\Code\User\ 
# on windows 
# VSCODEUSERDIR=%APPDATA%\Code\User\ 

tar cvzf /tmp/vscode-${USER}-settings-${NOW}.tar.gz   ${VSCODEUSERDIR}/*.json ${VSCODEUSERDIR}/snippets/

cp keybindings.json settings.json ${VSCODEUSERDIR}/

mkdir -p ${VSCODEUSERDIR}/snippets
#cp snippets/default-snippets-manager.code-snippets ~/.config/Code/User/snippets
rm -f ${VSCODEUSERDIR}/snippets/default-snippets-manager.code-snippets
ln snippets/default-snippets-manager.code-snippets ${VSCODEUSERDIR}/snippets/default-snippets-manager.code-snippets

# config is an example of remote-ssh config
# cp config ~/.ssh/config

