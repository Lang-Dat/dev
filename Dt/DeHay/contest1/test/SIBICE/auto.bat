for /l %%i in (0,1,9) do md "test0%%i"
for /l %%i in (0,1,9) do move "input.00%%i" "test0%%i\sibice.inp"
for /l %%i in (0,1,9) do move "output.00%%i" "test0%%i\sibice.out"
