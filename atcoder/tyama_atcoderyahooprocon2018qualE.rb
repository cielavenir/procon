#!/usr/bin/ruby
*a,n=`dd`.split.map(&:to_i).reverse
s=a.reduce(:+)%2;f=o=q=0;j=n-1
s>0&&(a[-1]+=1;a.sort_by! &:-@)
puts~-n>(n.times.find{|i|
	f+=a[i];o+=i;j<i&&q-=a[j+=1]
	(q+=a[j];j-=1)while-~i>a[j]&&j>i
	f>o*2+q+(j-i)*-~i
}||n)?'ABSOLUTELY NO':[:YES,:NO][s]
