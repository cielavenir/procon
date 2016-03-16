imports System
imports System.Runtime.InteropServices

module TrickyB
	const libc as string="libc.so.6"
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function scanf(format as string, byref a as integer) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function scanf(format as string, byref a as long, byref b as long, byref c as long) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string, a as double) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string, a as double, b as double) as integer
	end function

	sub Main()
		dim T,i as integer
		scanf("%d",T)
		for i=1 to T
			dim a,b,c as long
			scanf("%lld%lld%lld",a,b,c)
			if a=0 then
				if b=0 then
					printf(if(c=0,"3"&Environment.NewLine,"0"&Environment.NewLine))
				else
					printf("1 %.12f"&Environment.NewLine,-c*1.0/b)
				end if
			else
				if a<0 then
					a=-a
					b=-b
					c=-c
				end if
				dim d as double=b*b-4.0*a*c
				if Math.Abs(d)<1e-9 then
					printf("1 %.12f"&Environment.NewLine,-b/2.0/a)
				elseif d<0 then
					printf("0"&Environment.NewLine)
				else
					'acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
					dim x,y as double
					if b>0 then
						x = (-b-Math.Sqrt(d))/2/a
						y = c*1.0/a/x
					else
						y = (-b+Math.Sqrt(d))/2/a
						x = c*1.0/a/y
					end if
					printf("2 %.12f %.12f"&Environment.NewLine,x,y)
				end if
			end if
		next
	end sub
end module