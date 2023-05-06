Vscode debugger formatting 

with gdb

Var, comma syntax 
I,x   Displays I as hex 

https://learn.microsoft.com/en-us/visualstudio/debugger/format-specifiers-in-cpp?view=vs-2022#BKMK_Size_specifiers_for_pointers_as_arrays_in_Visual_Studio_2012/

*Pointer@syntax
*(int (*) [3][2] [4])arr
***arr@3@2@4
*arr@3, 2, 4
https://sourceware.org/gdb/current/onlinedocs/gdb.html/Arrays.html



Summary at bottom of this page
https://github.com/Microsoft/vscode-cpptools/issues/172


with lldb

parray 5 argv

https://stackoverflow.com/questions/7062173/view-array-in-lldb-equivalent-of-gdbs-operator-in-xcode-4-1
https://lldb.llvm.org/use/variable.html
