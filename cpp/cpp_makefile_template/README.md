select build target: debug
launch traget program

use makefile config from  launch.json for debugging

look at .vscode/settings.json for configuration
look at .vscode/keybindings.json for useful shortcuts 
F7=build F5=debug CTRL+F5=run

to print as array in debugger, add as a watch
*argv@3
*(char* (*)[3])argv

argc,x printed as HEX


https://github.com/microsoft/vscode-makefile-tools/issues/148
