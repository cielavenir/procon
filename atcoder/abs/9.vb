module ABC049C
	sub Main(ByVal args() as String)
		dim T() as string = {"dream","dreamer","erase","eraser"}
		dim s as string
		dim i,c,l,k as integer
		for i=0 to 3
			T(i)=StrReverse(T(i))
		next
		s=StrReverse(Console.ReadLine())
		c=0
		l=s.Length
		while c<l
			k=-1
			for i=0 to 3
				if l-c>=T(i).Length andalso s.Substring(c,T(i).Length)=T(i)
					k=T(i).Length
					exit for
				end if
			next
			if k<0
				Console.WriteLine("NO")
				return
			end if
			c+=k
		end while
		Console.WriteLine("YES")
	end sub
end module
