#!/usr/bin/ruby
def place(m,a)
	m.size.times{|r|
		#m[r].size.times{|c|
		a[r].each{|c|
			next if r==m.size-1&&c==m[r].size-2
			next if r==m.size-2&&c==m[r].size-1
			if [[-1,0],[0,-1],[1,0],[0,1]].any?{|dr,dc|
				0<=r+dr&&r+dr<m.size && 0<=c+dc&&c+dc<m[r].size && m[r][c]==0
			}
				m[r][c]=1;a[r]-=[c]
				return [r,c]
			end
		}
	}
end
h,w=gets.split.map &:to_i
m=h.times.map{[0]*w}
a=h.times.map{[*0...w]}
m[0][0]=1;a[0]-=[0]
f=h==1||w==1?1:0
k=(h*w+f)%2
puts [:Second,:First][k]
if k==1
if w==1
	puts '2 1'
	m[1][0]=1;a[1]-=[0]
else
	puts '1 2'
	m[0][1]=1;a[0]-=[1]
end
end
STDOUT.flush
loop{
	r,c=gets.split.map &:to_i
	r-=1;c-=1
	m[r][c]=1;a[r]-=[c]
	if [r,c]==[h-1,w-2] || [r,c]==[h-2,w-1]
		puts '%d %d'%[h,w]
		exit
	end
	r,c=place(m,a)
	puts '%d %d'%[r+1,c+1]
	STDOUT.flush
}
