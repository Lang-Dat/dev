CONST   fi      =       'DayNT.inp';
        fo      =       'DayNT.out';
Var     D : Array[2..32000] of byte;
        i,n,k,a : integer;
Procedure       mofile;
begin
        assign(input,fi);
        reset(input);
        assign(output,fo);
        rewrite(output);
end;
Function        Nto( n : integer): boolean;
var     i :integer;
begin
        if n<2 then exit(false)
        else
        for i:=2 to trunc(sqrt(n)) do
                if n mod i =0 then exit(false);
        exit(true);
end;
Procedure       Doc_xuly;
begin
       readln(k);
       for i :=2 to 32000 do d[i] :=0;
        while not seekeof do
                begin
                        readln(a);
                        if nto(a) then d[a] :=1;
                end;
end;
Procedure       xuat;
begin
            n:=0;
            for i :=2 to 32000 do
             if d[i]<> 0 then
                begin write(i,' ');
                        n := n+1;
                        if n = k then exit;
                end;

end;
Begin
        mofile;

        Doc_xuly;
        xuat;
end.
