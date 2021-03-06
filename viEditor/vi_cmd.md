# Vi cmd

vi +89 file.txt

## modes
-command mode by default
-press i for input mode
-press ESC to go back to command mode
-V visual mode,  use arrow keys to select full lines, d to delete , y copies to clipboard or any other command
-v visual mode inside a line
-ctrl-v  block editing (vertical), use d, r, y, p or I insert text and copy to all lines after ESC

BTW arrow keys work in both command mode and insert mode

## command mode
:q to quit
:q! to force quit

:w save current file
:w! forceful save
:wq save and quit
:wq! same but forces

:history  - show history of commands from command mode

navigate with arrows key or (hjkl) (left,down,up,right)
{ or }   keys to skip a block of code up of down

### copy/paste
dd delete a line
yy copying
p pasting

:e file1.txt    to edit another file
:r read a file and insert in current buffer

### search/replace
/searchtext top to bottom
?searchtext bottom to top
n for next search text top bottom
N for next search text bottom top 
* goes to a places of the word search
fchar goes to next char
tchar goes to space before next char

:%s/abc/xyz/g for replacing

### undo/redo/repaet
u undo
ctrl-r redo an undo
:u undo
. repeat last command (think macro)

### shell
:! ls -L
:r !ls -l    for reading output of ls in current buffer

:se ts=4   set tabstop to 2 spaces

### naviagtion
O or o new line above or below
r replace text instead of insert
i insert mode
a append after current position
A append at end of line

### naviagtion in a line
$ end of line
^ or 0w beginning of line
0 column zero

w or b to move forward/backward 1 word at a time
W or B  same but ignores ponctualtion

### naviagtion across lines
% jumps to other () or {}
{ or }   keys to skip a block of code up of down
:1 first line
gg goto top of file
G last line
:n goto n line

### delete
x delete single char
d% deletes that block
dw deletes a word
d} deletes a block
d% deletes a parenthethis block
D  deletes to end of the line
C  deletes to end of the line and enter insert mode = Change
3 dd - deletes 3 lines

### change text
cw change current word (enter inserm mode)
ct} change to next }
r just replace a letter
R replace until ESC
~ changes the case of current char
> indent line


zz recenters buffer so current line in the middle of the vertical

### split windows
:sp  split buffer horizontally 
:vsp split buffer vertically
ctrl-w arrow keys to switch to  windows
ctrl-w - or +  or = to change size
ctrl-w q   to close current
ctrl-w r or R   to rotate windows to right or left current

### MACROS
qchar char=name of macro, q again to stop recording marcro
@char to replay macro
20 @char replays macro 20 times

when load many files
vi *
:n -> Move to next file
:N -> Move to previous file
:args          show all command lines args

Commands to switch between buffers:
:bf            # Go to first file.
:bl            # Go to last file
:bn            # Go to next file.
:bp            # Go to previous file.
:bw            # Close file.
:ls            list buffers

### Ctrl-P mode
ctrl-p to activate ctrlp
Press <c-f> and <c-b> to cycle between modes or ctr up/down arrow keys 
Press <c-d> to switch to filename only search instead of full path.
Press <c-r> to switch to regexp mode.
Use <c-j>, <c-k> or the arrow keys to navigate the result list.
Use <c-t> or <c-v>, <c-x> to open the selected entry in a new tab or in a new split.
Use <c-n>, <c-p> to select the next/previous string in the prompt's history.
Use <c-y> to create a new file and its parent directories.
Use <c-z> to mark/unmark multiple files and <c-o> to open them.

### MAGIT mode
:Magit  to activate

## Links
https://www.youtube.com/watch?v=IiwGbcd8S7I excellent tutorial

## line numbers
https://jeffkreeftmeijer.com/vim-number/
- turn absolute line numbers on
:set number
:set nu

- turn absolute line numbers off
:set nonumber
:set nonu

- toggle absolute line numbers
:set number!
:set nu!

- turn relative line numbers on
:set relativenumber
:set rnu

- turn relative line numbers off
:set norelativenumber
:set nornu

- toggle relative line numbers
:set relativenumber!
:set rnu!

- turn hybrid line numbers off
:set nonumber norelativenumber
:set nonu nornu

## plugins
https://github.com/vim-airline/vim-airline
https://github.com/ctrlpvim/ctrlp.vim
https://github.com/jreybert/vimagit
