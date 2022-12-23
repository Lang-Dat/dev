const   fi='beauty.inp';
        fo='beauty.out';
var     f:text;
        a,b:array[1..2000000] of longint;
        c:array[1..810] of boolean;
        i,j,n,s,max:longint;
procedure       docf;
begin
        assign(f,fi);
        reset(f);
        n:=0;
        while not eof(f) do
        begin
                inc(n);
                readln(f,a[n]);
        end;
        close(f);
end;
function        ktr1:boolean;
var     j:longint;
begin
        ktr1:=false;
        for j:=2 to trunc(sqrt(i)) do
                if i mod j=0 then exit;
        ktr1:=true;
end;
function        ktr(i:longint):boolean;
var     j:longint;
begin
        s:=0;
        while i<>0 do
        begin
                s:=s+sqr(i mod 10);
                i:=i div 10;
        end;
        if c[s] then ktr:=true else ktr:=false;
end;
begin
        docf;
        max:=0;
        j:=0;
        for i:=2 to 810 do if ktr1 then c[i]:=true;
        for i:=1 to n do if max<a[i] then max:=a[i];
        j:=1;
        i:=11;
        b[1]:=11;
        while j<=max do
        begin
                inc(i);
                if ktr(i) then
                begin
                        inc(j);
                        b[j]:=i;
                end;
        end;
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do writeln(f,b[a[i]]);
        close(f);
end.

