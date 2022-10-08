Program SUB;
const   fi='SUB.IN9';
        fo='SUB.OU9';
        nmax = 100000;
        oo = 100001;
Var     A,T:array[0..nmax] of longint;
        N,S,Min:longint;
        F:text;
procedure doc;
var     i:longint;
Begin
        assign(F,fi);
        reset(F);
        T[0] := 0;
        Readln(F,N,S);
        for i:=1 to N do
        Begin
                read(F,A[i]);
                T[i] := T[i-1] + A[i];
        end;
        close(F);
end;
procedure xuly;
var     i,j:longint;
Begin
        Min := oo;
        for i:=1 to N-1 do
            for j:=i+1 to N do
            if T[j] - T[i] >= S then
            if j - i < min then min := j - i;
end;
procedure ghi;
Begin
        assign(F,fo);
        rewrite(F);
        if Min = oo then write(F,0)
        else Write(F,Min);
        close(F);
end;
BEGIN
        doc;
        xuly;
        ghi;
END.
