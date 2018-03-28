imports System.Collections.Generic
module ABC085B
	sub Main(ByVal args() as String)
		dim n,i as integer
		dim m as new Dictionary(of integer,integer)
		'HashSetは.Net3.5以降のため使えません
		n=Console.ReadLine()
		for i=1 to n
			m(Console.ReadLine())=1
		next
		Console.WriteLine(m.Count)
	end sub
end module
