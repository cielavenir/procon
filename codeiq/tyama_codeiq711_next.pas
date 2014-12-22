{$apptype console} //Delphi6
program CodeIQRoute;
var
N:longint;
r:longint;
i:longint;
flg:longint;
zero1:longint;
zero2:longint;
one1:longint;
one2:longint;
e0:array of longint;
f0:array of longint;
e:array of longint;
f:array of longint;

procedure reverse(var a:array of longint;start:longint;size:longint);
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

function next_permutation(var a:array of longint;n:longint):boolean;
var
	i,k,l:longint;
	z:longint;
begin
	next_permutation:=false;
	if (0<=n) and (n<=length(a)) then begin
		reverse(a,n,length(a)-n);
		i:=length(a)-2;
		while i>=0 do begin
			if a[i]<a[i+1] then break;
			i:=i-1;
		end;
		if i<0 then begin
			reverse(a,0,length(a));
		end else begin
			k:=i;
			i:=length(a)-1;
			while i>=k+1 do begin
				if a[k]<a[i] then break;
				i:=i-1;
			end;
			l:=i;
			z:=a[k];
			a[k]:=a[l];
			a[l]:=z;
			reverse(a,k+1,length(a)-(k+1));
			next_permutation:=true;
		end;
	end;
end;

begin
N:=6;
r:=0;
setlength(e0,N*2);
setlength(f0,N*2);
for i:=0 to N-1 do begin
	e0[N+i]:=1;
	f0[N+i]:=1;
end;
setlength(e,N*2+1);
setlength(f,N*2+1);
repeat
	for i:=0 to N*2-1 do e[i+1]:=e[i]+e0[i];
	repeat
		flg:=0;
		zero1:=0;
		zero2:=N;
		one1:=0;
		one2:=N;
		for i:=0 to N*2-1 do begin
			if e0[i]=0 then zero1:=zero1+1;
			if e0[i]=1 then one1:=one1+1;
			if f0[N*2-1-i]=0 then zero2:=zero2-1;
			if f0[N*2-1-i]=1 then one2:=one2-1;
			if zero1=zero2 then flg:=flg+1;
			if one1=one2 then flg:=flg+1;
		end;
		if flg>=2 then r:=r+1;
	until not next_permutation(f0,length(f0));
until not next_permutation(e0,length(e0));
writeln(r);
end.