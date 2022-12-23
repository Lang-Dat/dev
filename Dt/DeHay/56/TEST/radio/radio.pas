const   fi      =       'radio.inp';
        fo      =       'radio.out';
var     s       :       ansistring;
        f,g     :       text;
        L,i,j   :       longint;

procedure       mo;
begin
        assign(f,fi);
        reset(f);
        assign(g,fo);
        rewrite(g);
end;
procedure       doc;
begin
    readln(f,l);
    readln(f,s);

end;

procedure       xuly;
begin
     for i :=1 to L do
     begin
        j := 1;
        while j<= l -i do
           begin
                if s[j]<>s[j+i] then break;
                inc(j);
           end;
        if j> l-i then
                begin writeln(g,i); exit;  end;

     end;
end;
procedure       dong;
begin
        close(f);
        close(g);
end;
Begin
    mo;
    doc;
    xuly;
    dong;
end.
