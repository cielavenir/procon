module x
	sub main
		dim n as integer
		do
			n=cint(Console.ReadLine)
			if n=0 then exit sub
			Console.WriteLine(int( _
				aggregate x in Enumerable.Range(1,n) _
				let m = cint(Console.ReadLine) _
				order by m _
				skip 1 take n-2 _
				into average(m) _
			)) 'Linq
		loop
	end sub
end module