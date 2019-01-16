// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

program hena24;
uses
	System;
var
	i: longint;
	g: sequence of longint;
	s: string;
	z: IEnumerator<longint>;

function isqrt(n: longint): longint;
var
	x: longint;
	y: longint;
begin
	if(n<=0) then
		isqrt:=0
	else if(n<4) then
		isqrt:=1
	else begin
		x:=0;
		y:=n;
		while((x<>y) and (x+1<>y)) do begin
			x:=y;
			y:=(n div y+y) div 2;
		end;
		isqrt:=x;
	end;
end;

function icbrt(n: longint): longint;
var
	x: longint;
	y: longint;
begin
	if(n<0) then
		icbrt:=0
	else if(n<8) then
		icbrt:=1
	else begin
		x:=0;
		y:=n;
		while((x<>y) and (x+1<>y)) do begin
			x:=y;
			y:=(n div y div y+y*2) div 3;
		end;
		icbrt:=x;
	end;
end;

function is_sq(n: longint): boolean;
var
	x: longint;
begin
	x:=isqrt(n);
	is_sq:=x*x=n;
end;

function is_cb(n: longint): boolean;
var
	x: longint;
begin
	x:=icbrt(n);
	is_cb:=x*x*x=n;
end;

function is_multiple(i:longint; n: longint): boolean;
begin
	is_multiple:=i mod n=0;
end;

function is_le(i:longint; n: longint): boolean;
begin
	is_le:=i<=n;
end;

function generate(): sequence of longint;
var
	i: longint;
begin
	i:=1;
	while true do begin
		yield i;
		i:=i+1;
	end;
end;

function drop_prev(check: function(x:longint):boolean; _prev: sequence of longint): sequence of longint;
var
	a: longint;
	b: longint;
	prev: IEnumerator<longint>;
begin
	prev:=_prev.GetEnumerator();
	prev.MoveNext();
	a:=prev.Current;
	prev.MoveNext();
	b:=prev.Current;
	while true do begin
		if not check(b) then yield a;
		a:=b;
		prev.MoveNext();
		b:=prev.Current;
	end;
end;

function drop_next(check: function(x:longint):boolean; _prev: sequence of longint): sequence of longint;
var
	a: longint;
	b: longint;
	prev: IEnumerator<longint>;
begin
	prev:=_prev.GetEnumerator();
	prev.MoveNext();
	a:=prev.Current;
	prev.MoveNext();
	b:=prev.Current;
	yield a;
	while true do begin
		if not check(a) then yield b;
		a:=b;
		prev.MoveNext();
		b:=prev.Current;
	end;
end;

function drop_n(check: function(x:longint;y:longint):boolean; n: longint; _prev: sequence of longint): sequence of longint;
var
	a: longint;
	i: longint;
	prev: IEnumerator<longint>;
begin
	prev:=_prev.GetEnumerator();
	i:=0;
	while true do begin
		i:=i+1;
		prev.MoveNext();
		a:=prev.Current;
		if not check(i,n) then yield a;
	end;
end;

begin
	var f:=new Dictionary<char,Func<sequence of longint,sequence of longint>>();
	f['S']:=x->drop_next(is_sq,x);
	f['s']:=x->drop_prev(is_sq,x);
	f['C']:=x->drop_next(is_cb,x);
	f['c']:=x->drop_prev(is_cb,x);
	f['h']:=x->drop_n(is_le,100,x);
	for i:=2 to 9 do begin
		var j:=i;
		f[char(48+j)]:=x->drop_n(is_multiple,j,x);
	end;

	while true do begin
		s:=Console.ReadLine();
		if s=nil then break;
		g:=generate();
		for i:=1 to length(s) do g:=f[s[i]](g);
		z:=g.GetEnumerator();
		for i:=0 to 9 do begin
			if i>0 then write(',');
			z.MoveNext();
			write(z.Current);
		end;
		writeln();
		Console.Out.Flush();
	end;
end.
