const fi='censor.inp';
      fo='censor.out';
var
     f:text;
     t,s:ansistring;

procedure doc;
   begin
      assign(f,fi);
      reset(f);
      readln(f,s);
      readln(f,t);
      close(f);
   end;

procedure xuli;
var i:longint;
    tg,st:ansistring;
  begin
     st:='';
     for i:=1 to length(s) do
       begin
          st:=st+s[i];
          if length(st)>=length(t) then
          begin
          tg:=copy(st,length(st)-length(t)+1,length(t));
          if tg=t then delete(st,length(st)-length(t)+1,length(t));
          end;
       end;
     assign(f,fo);
     rewrite(f);
     writeln(f,st);
     close(f);
  end;

BEGIN
        doc;
        xuli;
END.
