(*2007 Domestic A*)
{$apptype console} //Delphi

program DomesticA;
var n: integer;

procedure judge(n:integer);
var i: integer;
    ma,mi,x,s: longint;
begin
  ma:=0;mi:=1000;s:=0;
  if(n=0) then exit;
  for i:=1 to n do begin
    readln(x);
    if(x<mi) then mi:=x;
    if(x>ma) then ma:=x;
    s:=s+x;
  end;
  writeln((s-ma-mi) div (n-2));
end;

begin
n:=1;
repeat
  readln(n);
  judge(n);
until(n=0);
end.