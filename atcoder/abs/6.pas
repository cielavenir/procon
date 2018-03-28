program ABC088B;
{$mode Delphi}
uses SysUtils,fgl;

(*
procedure reverse(var a:TFPGList<longint>;start:longint;size:longint);
var
    en,i:longint;
    z:longint;
begin
    en:=start+size-1;
    for i:=0 to trunc(size/2-1) do begin
        z:=a[start+i];
        a[start+i]:=a[en-i];
        a[en-i]:=z;
    end;
end;
*)

function intcompare(n1,n2:longint):longint;
begin
	result:=n2-n1;
end;

var
	n,i,r,t: longint;
	arr: TFPGList<longint>;
begin
	read(n);
	arr:=TFPGList<longint>.Create();
	for i:=0 to n-1 do begin
		read(r);
		arr.Add(r);
	end;
	arr.Sort(@intcompare);
	// reverse(arr,0,arr.Count);
	r:=0;
	t:=1;
	for i:=0 to n-1 do begin
		r:=r+t*arr[i];
		t:=-t;
	end;
	writeln(r);
end.
