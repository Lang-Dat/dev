const   fi = 'norma.inp';
        fo = 'norma.out';
var     f, g : text;
        A : Array[1..500000] of longint;
        i,j,n : longint;
procedure       mfile;
begin
    assign(f,fi);
    reset(f);
    assign(g,fo);
    rewrite(g);
end;
procedure       doc;
begin
    readln(f,n);
    for i := 1 to n do
        read(f,a[i]);

end;
function        tong: int64;
var     t: int64;
        max, min : longint;

Begin
    t :=0;
    for i :=1 to n do
        begin
                max := a[i];
                min := a[i];
                for j := i to n do
                  begin
                      if max < a[j] then max := a[j];
                      if min > a[j] then min := a[j];
                      t := (t + max*min*(j-i+1)) mod 1000000000;
                  end;
        end;
        tong := t ;
end;
begin
        mfile;
        doc;
        write(g,tong);
        close(f);
        close(g);


end.
