Program SUB;
const   fi='SUB.INP';
        fo='SUB.OUT';
        nmax = 1000000;
        oo = 10000001;
Var     A:array[0..nmax] of longint;
        N,S,kq,T:longint;
        F:text;
procedure doc;
var     i:longint;
Begin
        assign(F,fi);
        reset(F);
        Readln(F,N,S);
        for i:=1 to N do read(F,A[i]);
        close(F);
end;
function min(a,b:longint):longint;
Begin
        if a > b then min := b
        else min := a;
end;
procedure xuly;
var     i,d,c,g:longint;
Begin
        kq := oo;
        d := 0; c := 1;
        While (d < c) and (c < N) do
        if T < S then
        Begin
                T := T + A[c];
                inc(c);
        end
        else    Begin
                        kq := min(kq, c - d - 1);
                        inc(d);
                        T := T - A[d];
                end;
end;
procedure ghi;
Begin
        assign(F,fo);
        rewrite(F);
        if kq = oo then write(F,0)
        else Write(F,kq);
        close(F);
end;
BEGIN
        doc;
        xuly;
        ghi;
END.
