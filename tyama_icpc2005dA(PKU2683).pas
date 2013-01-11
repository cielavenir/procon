(*2005 Domestic A Žš‰º‚°‚ÍHaskell•—‚Éw*)
{$apptype console} //Delphi‚Ì‚¨‚Ü‚¶‚È‚¢

program DomesticA;
var n,i: integer;

function parse(m,y:longint):longint;
var
t,c,i,dm:longint;
r: real;
begin
dm:=0;
readln(t,r,c);
if(t<>0) then begin
  for i:=1 to y do begin
    dm:=trunc(r*m);
    m:=m+dm-c;
    end;
  end else begin
  for i:=1 to y do begin
    dm:=dm+trunc(r*m);
    m:=m-c;
    end;
  m:=m+dm;
  end;
parse:=m;
end;

procedure data();
var m,y,n,i,r,x: longint;
begin
read(m,y,n);
r:=m;
for i:=1 to n do begin
  x:=parse(m,y);
  if(x>r)then r:=x;
  end;
writeln(r);
end;

begin
read(n);
for i:=1 to n do data();
end.