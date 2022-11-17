type 	int	=	longint;
const	maxN=	trunc(1e5)+7;
var a,r : array[1..maxN] of int64;    
	n,t,i : int;

BEGIN
    assign(input, 'XENKE.INP');   reset(input);
    assign(output,'XENKE.OUT');   rewrite(output);
	readln(t);
	while t>0 do 
	  begin
			readln(n); dec(t);
			for i:=1 to n do read(a[i]);
			r[n] := 1;
			for i := n-1 downto 1 do 
			  begin
				r[i] := 1;
				if a[i]*a[i+1]<0 then r[i] := 1 + r[i+1];
			  end;
			for i:=1 to n do write(r[i],' '); writeln;
	  end;
END.
