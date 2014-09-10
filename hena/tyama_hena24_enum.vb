' http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
' http://nabetani.sakura.ne.jp/hena/ord24eliseq/

imports System
imports System.Linq
imports System.Collections.Generic
imports System.Runtime.InteropServices

module Hena24
	<DllImport("c")>
	private shared function cbrt(ByVal d as double) as double
	end function

	private function is_sq(ByVal n as integer) as boolean
		dim x as integer=cint(Math.Sqrt(n))
		is_sq = x*x=n
	end function

	private function is_cb(ByVal n as integer) as boolean
		dim x as integer=cint(cbrt(n))
		is_cb = x*x*x=n
	end function

	private function is_multiple(ByVal i as integer,ByVal n as integer) as boolean
		is_multiple = (i mod n=0)
	end function
	private function is_le(ByVal i as integer,ByVal n as integer) as boolean
		is_le = i<=n
	end function

	iterator function generate() as IEnumerable(of integer)
		dim i as integer=1
		while true
			yield i
			i+=1
		end while
	end function

	iterator function drop_prev(ByRef check as Func(of integer,boolean),ByRef _prev as IEnumerable(of integer)) as IEnumerable(of integer)
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

	iterator function drop_next(ByRef check as Func(of integer,boolean),ByRef _prev as IEnumerable(of integer)) as IEnumerable(of integer)
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

	iterator function drop_n(ByRef check as Func(of integer,integer,boolean),ByRef _prev as IEnumerable(of integer)) as IEnumerable(of integer)
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
		dim f as new Dictionary(of char,Func(of IEnumerable(of int),IEnumerable(of int))) from {
			{'S',Function(e) drop_next(is_sq,e)},
			{'s',Function(e) drop_prev(is_sq,e)},
			{'C',Function(e) drop_next(is_cb,e)},
			{'c',Function(e) drop_prev(is_cb,e)},
			{'h',Function(e) drop_n(is_le,100,e)},
		}
		for i as integer=2 to 9 do
			dim j as integer=i
			f[ctype('0'+j,char)] = Function(e) drop_n(is_multiple,j,e)
		next
		dim line as string
		while (line=Console.ReadLine())<>nothing
			dim first as boolean=true
			'cS => f['S'](f['c'](generate()))
			for each n as integer in line.Aggregate(generate(),Function(s,e) f[e](s)).Take(10)
				if not first
					Console.Write(',')
				end if
				first=false
				Console.Write(n)
			next
			Console.WriteLine()
		end while
	end sub
end module