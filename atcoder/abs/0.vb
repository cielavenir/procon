module practiceA
	sub Main(ByVal args() as String)
		dim a,b,c as integer
		dim s as string
		dim arr(2) as string
		a=Console.ReadLine()
		arr=Split(Console.ReadLine())
		b=arr(0):c=arr(1)
		s=Console.ReadLine()
		Console.Write(a+b+c)
		Console.WriteLine(" "+s)
	end sub
end module
