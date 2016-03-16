#!/usr/bin/env crystal
gets.not_nil!.to_i.times{
	a,b,c=gets.not_nil!.split.map(&.to_i64)
	if a==0
		if b==0
			puts(c==0 ? 3 : 0)
		else
			printf("1 %.12f\n",-c/1.0/b)
		end
	else
		if a<0
			a,b,c=-a,-b,-c
		end
		d=b*b-4.0*a*c
		if d.abs<1e-9
			printf("1 %.12f\n",-b/2.0/a)
		elsif d<0
			puts(0)
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
			printf("2 %.12f %.12f\n",x,y)
		end
	end
}