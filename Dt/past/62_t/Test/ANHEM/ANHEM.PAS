const   fi = 'ANHEM.INP';
        fo = 'ANHEM.OUT';

VAR     i,j,m,n:word;
        f1, f2: text;
procedure doctep;
Begin
        assign(f1,fi); reset(f1);
        assign(f2,fo);rewrite(f2);
        read(f1,m,n);
end;
FUNCTION KTAE(x,y:word):Boolean;
var     i,j:word;
        sx,sy:longint;
    ok:boolean;
BEGIN
    Sx:=0; Sy:=0;
    For i:=2 to x div 2 do if x mod i = 0 then Sx:=Sx+i;
    For j:=2 to y div 2 do if y mod j = 0 then Sy:=Sy+j;
    If (Sx = Sy) and (sx>0) Then ok:=TRUE ELSE ok:=FALSE;
    KTAE:=ok;
END;
procedure xuly;
begin
        If KTAE(m,n)=TRUE then
        write(f2,'YES') else write(f2,'NO');
end;
procedure dongtep;
begin
        close(f1);
        close(f2);
end;
BEGIN
        doctep;
        xuly;
        dongtep;
END.
6 25
