
if [ -z "${PATHORG+xxx}"  ]
then
     export PATHORG=$PATH
     export LD_LIBRARY_PATHORG=$LD_LIBRARY_PATH
fi



function setenv
{
    eval "$1='$2' export $1"
}

# setenv EDITOR emacs
setenv EDITOR vi

#*********** aliases  *****************************************************

alias gitc='git clone --recursive ' 
alias gitlf='git lfs pull '
alias gitsub='git submodule update --init --recursive  '

alias bl="/bin/ls"
alias l="ls -o"
alias lg="ls -l"
alias la="ls -la"
alias ll="ls -Lo"
alias lr="ls -og"
#alias ls="ls -F"
alias bc="bc -l"
alias u="cd .."
alias rd="rm -rf "
alias md="mkdir -p "
alias h="history 10000"
alias pe='env|sort'
alias pej='env|sort| egrep "^J|^PATH|^LD_|^REPLAY"'
alias pep='env|sort| egrep "^PATH|^LD_"'
alias ssh='ssh -X '
alias now="date +%Y%m%d-%H%M%S"
alias del=" /bin/rm -f  *~  .*~ *.bak .*.bak *.BAK ;find -L . -name \"*~\" -delete ; find -L . -name \"core\" -delete ;find -L . -name \".#*\" -delete ;"

#*********** emacs  *****************************************************

function e
{
	emacs $* &
}

function et
{
	emacs $1 -T $1 &
}

function sm
{
	VGPWD=$PWD
	source ~/.bash_aliases
	cd $VGPWD
}

#***********************************************************************


#if [ "$USER" = jvtapp ]; then
#   . ~/DEPLOY/PROD/envrun.sh
#else
#   . $JVTROOT/package/envdev.sh
#fi

if [ -f ~/.bash_user ]; then
    . ~/.bash_user
fi


export LC_ALL=C

PS1='[$? \u@\h:\w]\$'

#***********************************************************************
# git aliases
#***********************************************************************


#***********************************************************************
export VGHOME=~/.emacs.d/
export VGROOT=$VGHOME/root
export VGCONF=$VGHOME/config


export PATH=.:$PATH:$VGROOT/bin/:~/bin/:


#unset MANPATH
MANPATH=:$MANPATH

alias dh='cd --'
shopt -s autocd    
shopt -s cdspell
shopt -s globstar

alias ff='which '

