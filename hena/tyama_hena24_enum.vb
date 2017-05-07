' http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
' http://nabetani.sakura.ne.jp/hena/ord24eliseq/

imports System
imports System.Linq
imports System.Collections.Generic
'imports System.Runtime.InteropServices

module Hena24
	'<DllImport("c")>
	'private function cbrt(ByVal d as double) as double
	'end function

	private function isqrt(ByVal n as integer) as integer
		if n<=0
			return 0
		end if
		if n<4
			return 1
		end if
		dim x as integer=0
		dim y as integer=n
		while x<>y andalso x+1<>y
			x=y
			y=((n\y)+y)\2
		end while
		return x
	end function
	private function icbrt(ByVal n as integer) as integer
		if n<0
			return icbrt(-n)
		end if
		if n=0
			return 0
		end if
		if n<8
			return 1
		end if
		dim x as integer=0
		dim y as integer=n
		while x<>y andalso x+1<>y
			x=y
			y=((n\y\y)+y*2)\3
		end while
		return x
	end function

	private function is_sq(ByVal n as integer) as boolean
		dim x as integer=isqrt(n)
		'cint(Math.Sqrt(n))
		return x*x=n
	end function

	private function is_cb(ByVal n as integer) as boolean
		dim x as integer=icbrt(n)
		'cint(cbrt(n))
		return x*x*x=n
	end function

	private function is_multiple(ByVal i as integer,ByVal n as integer) as boolean
		return i mod n=0
	end function
	private function is_le(ByVal i as integer,ByVal n as integer) as boolean
		return i<=n
	end function

	iterator function generate() as IEnumerable(of integer)
		dim i as integer=1
		while true
			yield i
			i+=1
		end while
	end function

	iterator function drop_prev(ByVal check as Func(of integer,boolean),ByVal _prev as IEnumerable(of integer)) as IEnumerable(of integer)
		dim prev as IEnumerator(of integer)=_prev.GetEnumerator()
		prev.MoveNext()
		dim a as integer=prev.Current
		prev.MoveNext()
		dim b as integer=prev.Current
		while true
			if not check(b)
				yield a
			end if
			a=b
			prev.MoveNext()
			b=prev.Current
		end while
	end function

	iterator function drop_next(ByVal check as Func(of integer,boolean),ByVal _prev as IEnumerable(of integer)) as IEnumerable(of integer)
		dim prev as IEnumerator(of integer)=_prev.GetEnumerator()
		prev.MoveNext()
		dim a as integer=prev.Current
		prev.MoveNext()
		dim b as integer=prev.Current
		yield a
		while true
			if not check(a)
				yield b
			end if
			a=b
			prev.MoveNext()
			b=prev.Current
		end while
	end function

	iterator function drop_n(ByVal check as Func(of integer,integer,boolean),ByVal n as integer,ByVal _prev as IEnumerable(of integer)) as IEnumerable(of integer)
		dim prev as IEnumerator(of integer)=_prev.GetEnumerator()
		dim i as integer=0
		while true
			i+=1
			prev.MoveNext()
			dim a as integer=prev.Current
			if not check(i,n)
				yield a
			end if
		end while
	end function

	sub Main()
		dim f as new Dictionary(of char,Func(of IEnumerable(of integer),IEnumerable(of integer))) from {
			{"S"c,Function(e) drop_next(addressof is_sq,e)},
			{"s"c,Function(e) drop_prev(addressof is_sq,e)},
			{"C"c,Function(e) drop_next(addressof is_cb,e)},
			{"c"c,Function(e) drop_prev(addressof is_cb,e)},
			{"h"c,Function(e) drop_n(addressof is_le,100,e)}
		}
		for i as integer=2 to 9
			dim j as integer=i
			f(chr(48+j)) = Function(e) drop_n(addressof is_multiple,j,e)
		next
		dim line as string=Console.ReadLine()
		while line isnot nothing
			dim first as boolean=true
			'cS => f("S"c)(f("c"c)(generate()))
			for each n as integer in line.Aggregate(generate(),Function(s,e) f(e)(s)).Take(10)
				if not first
					Console.Write(","c)
				end if
				first=false
				Console.Write(n)
			next
			Console.WriteLine()
			Console.Out.Flush()
			line=Console.ReadLine()
		end while
	end sub
end module
