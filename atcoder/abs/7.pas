program ABC085B;
{$mode Delphi}
uses SysUtils,fgl;
var
	n,i,r: longint;
	arr: TFPGMap<longint,integer>;
begin
	read(n);
	arr:=TFPGMap<longint,integer>.Create();
	for i:=0 to n-1 do begin
		read(r);
		// arr.AddOrSetData(r,1); // AtCoderでは使用不可
		arr.Remove(r);
		arr.Add(r,1);
	end;
	writeln(arr.Count);
end.
