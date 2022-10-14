const   fi      =       'radio.inp';
        fo      =       'radio.out';
var     s       :       ansistring;
        f,g     :       text;
        L,i,j   :       longint;

procedure       mo;
begin
        assign(f,fi);
        rewrite(f);
end;
begin
        mo;
        writeln(f,10000);

       for i := 1 to 10 do write(f,'a');
       for i := 1 to 9980 do write(f,'9');
       for i := 1 to 10 do write(f,'a');
       close(f);
end.