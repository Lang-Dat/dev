const   fi='DAYNT.inp';
        fo='DAYNT.o';
var     f:text;
        n,i,j,m:longint;
        k:array[0..32767] of boolean;
        a,b:array[1..10000000] of longint;
procedure       docf;
begin
        assign(f,fi);
        reset(f);
        n:=0;
        readln(f,m);
        while not eof(f) do
        begin
                inc(n);
                readln(f,b[n]);
        end;
        close(f);
end;
function        nt(i:longint):boolean;
var     j:longint;
begin
        nt:=false;
        if i=1 then exit;
        if i=0 then exit;
        for j:=2 to trunc(sqrt(i)) do if i mod j=0 then exit;
        nt:=true;
end;
procedure       td(var a,b:longint);
var tg:longint;
begin
        tg:=a;a:=b;b:=tg;
end;
procedure       qs(l,r:longint);
var x,i,j:longint;
begin
        x:=a[(l+r)div 2];
        i:=l;j:=r;
        repeat
        while a[i]<x do inc(i);
        while a[j]>x do dec(j);
        if i<=j then
        begin
                td(a[i],a[j]);
                inc(i);dec(j);
        end;
        until i>j;
        if l<j then qs(l,j);
        if i<r then qs(i,r);
end;
procedure       xd;
begin
        for i:=1 to n do if not k[b[i]] then
        begin
                k[b[i]]:=true;
                if nt(b[i]) then
                begin
                        inc(j);
                        a[j]:=b[i];
                end;
        end;
end;
begin
        docf;
        assign(f,fo);
        rewrite(f);
        xd;
        qs(1,j);
        for i:=1 to m do write(f,a[i],' ');
        close(f);
end.
