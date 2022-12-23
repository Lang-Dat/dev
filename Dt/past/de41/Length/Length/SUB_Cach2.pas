Program SUB;
const   fi='SUB.INP';
        fo='SUB.OUT';
        nmax = 100000;
        oo = 10000001;
Var     A,T:array[0..nmax] of int64;
        N,S,kq:longint;
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
function min(a,b:longint):longint;
Begin
        if a > b then min := b
        else min := a;
  end;
procedure xuly;
var     i,d,c,g:longint;
Begin
        kq := oo;
        for i:=1 to N do
        Begin
                d := 1; c := i-1;
                While d <= c do
                Begin
                        g := (d + c) div 2;
                        if T[i] - T[g] >= S then
                        Begin
                                kq := min(kq,i-g);
                                d := g + 1;
                        end
                        else c := g - 1;
                end;
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
