
alias now='date +%Y%m%d-%H%M%S'

VSCODEUSERDIR=~/.vscode-server/data/User
VSCODEUSERDIR=~/.config/Code/User


tar cvzf /tmp/vscode-${USER}-settings-`now`.tar.gz   ${VSCODEUSERDIR}/*.json ${VSCODEUSERDIR}/snippets/

cp keybindings.json settings.json ${VSCODEUSERDIR}/

mkdir -p ${VSCODEUSERDIR}/snippets
#cp snippets/default-snippets-manager.code-snippets ~/.config/Code/User/snippets
rm -f ${VSCODEUSERDIR}/snippets/default-snippets-manager.code-snippets
ln snippets/default-snippets-manager.code-snippets ${VSCODEUSERDIR}/snippets/default-snippets-manager.code-snippets

# config is an example of remote-ssh config
# cp config ~/.ssh/config

