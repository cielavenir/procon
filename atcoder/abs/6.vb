module ABC088B
	sub Main(ByVal args() as String)
		dim n,i,r,t as integer
		n=Console.ReadLine()
		dim arrs(n) as string
		dim arr(n) as integer
		arrs=Split(Console.ReadLine())
		arr=Array.ConvertAll(of string,integer)(arrs,addressof Integer.Parse)
		Array.Sort(arr)
		Array.Reverse(arr)
		r=0
		t=1
		for i=1 to n
			r+=t*arr(i-1)
			t=-t
		next
		Console.WriteLine(r)
	end sub
end module
