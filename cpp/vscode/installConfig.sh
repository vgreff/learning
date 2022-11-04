
alias now='date +%Y%m%d-%H%M%S'

tar cvzf /tmp/vscode-${USER}-settings-`now`.tar.gz  ~/.config/Code/User/snippets ~/.config/Code/User/*.json

cp keybindings.json settings.json ~/.config/Code/User/

mkdir -p ~/.config/Code/User/snippets
cp snippets/default-snippets-manager.code-snippets ~/.config/Code/User/snippets

# config is an example of remote-ssh config
# cp config ~/.ssh/config

