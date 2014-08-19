#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/ebd8a56b41711ba459f9
#STDOUT.sync=true
def solve(l)
	r=[]
	a=[0,0,0]
	l.chars{|e|
		a[1]+=1 if e=='s'
		a[2]+=1 if e=='b'
		a[1]+=1 if e=='f'&&a[1]<2
		(a[0]+=1;a[1]=a[2]=0) if e=='p'||a[1]>2
		a[1]=a[2]=0 if e=='h'||a[2]>3
		a[0]=a[1]=a[2]=0 if a[0]>2
		r<<a*''
	}
	r*','
end
DATA.each_with_index{|e,i|
	input,expect=e.chomp.split(' -> ')
	puts 'Case '+(i+1).to_s+': '+(expect==solve(input)?'OK':'NG')
}
__END__
s -> 010
sss -> 010,020,100
bbbb -> 001,002,003,000
ssbbbb -> 010,020,021,022,023,000
hsbhfhbh -> 000,010,011,000,010,000,001,000
psbpfpbp -> 100,110,111,200,210,000,001,100
ppp -> 100,200,000
ffffs -> 010,020,020,020,100
ssspfffs -> 010,020,100,200,210,220,220,000
bbbsfbppp -> 001,002,003,013,023,000,100,200,000
sssbbbbsbhsbppp -> 010,020,100,101,102,103,100,110,111,100,110,111,200,000,100
ssffpffssp -> 010,020,020,020,100,110,120,200,210,000