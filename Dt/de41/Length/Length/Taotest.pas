Program test;
uses    crt;
const   fi='SUB.IN';
        N:array[0..9] of longint = (100,200,300,400,500,10000,20000,400000,1000000,5000000);
var     i:integer;
        S:string;
        T,j:longint;
        F:Text;
BEGIN
        randomize;
        for i:=9 to 9 do
        Begin
                T:=random(1000000)+1;
                S := fi + chr(i+48);
                assign(F,S);
                rewrite(F);
                writeln(F,N[i],' ',T);
                for j := 1 to N[i] do
                write(F,Random(100000)+1,' ');
                close(F);
        end;
END.
