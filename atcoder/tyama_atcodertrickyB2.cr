#!/usr/bin/env crystal
lib C
	fun scanf(fmt : UInt8*, ...): Int32
	fun printf(fmt : UInt8*, ...): Int32
end
#t=gets.not_nil!.to_i
t=0
C.scanf("%d",pointerof(t))
t.times{
	#a,b,c=gets.not_nil!.split.map(&.to_i64)
	a=b=c=0_i64
	C.scanf("%lld%lld%lld",pointerof(a),pointerof(b),pointerof(c))
	if a==0
		if b==0
			C.printf("%d\n",c==0 ? 3 : 0)
		else
			C.printf("1 %.12f\n",-c/1.0/b)
		end
	else
		if a<0
			a,b,c=-a,-b,-c
		end
		d=b*b-4.0*a*c
		if d.abs<1e-9
			C.printf("1 %.12f\n",-b/2.0/a)
		elsif d<0
			C.printf("%d\n",0)
		else
			# acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			x=0.0
			y=0.0
			if b>0
				x=(-b-Math.sqrt(d))/2/a
				y=c*1.0/a/x
			else
				y=(-b+Math.sqrt(d))/2/a
				x=c*1.0/a/y
			end
			C.printf("2 %.12f %.12f\n",x,y)
		end
	end
}
