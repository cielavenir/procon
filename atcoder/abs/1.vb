module ABC086A
	sub Main(ByVal args() as String)
		dim a,b as integer
		dim arr(2) as string
		arr=Split(Console.ReadLine())
		a=arr(0):b=arr(1)
		Console.WriteLine(If(a*b mod 2 > 0,"Odd","Even"))
	end sub
end module
