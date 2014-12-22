#!/usr/bin/ruby
N=10
if N%2==1
	puts 'N must be even'
	exit
end
BLK=N/2
start=[*1..N]
goal=start.reverse
back={start=>nil}
queue=[start]
while !queue.empty?
	a=queue[0]
	break if a==goal
	queue.shift
	(1..BLK).each{|i|
		b=a[i,BLK]+a[0,i]+a[BLK+i..-1]
		if !back.has_key?(b)
			back[b]=a
			queue.push(b)
		end
	}
end
if queue.empty?
	puts 'Fail'
end
n=0
while back[goal]
	n+=1
	p goal
	goal=back[goal]
end
p n

__END__
[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
[5, 4, 3, 2, 10, 9, 8, 7, 6, 1]
[9, 5, 4, 3, 2, 10, 8, 7, 6, 1]
[10, 8, 7, 6, 1, 9, 5, 4, 3, 2]
[9, 5, 10, 8, 7, 6, 1, 4, 3, 2]
[6, 1, 4, 3, 9, 5, 10, 8, 7, 2]
[5, 6, 1, 4, 3, 9, 10, 8, 7, 2]
[9, 10, 5, 6, 1, 4, 3, 8, 7, 2]
[4, 3, 8, 9, 10, 5, 6, 1, 7, 2]
[5, 6, 1, 7, 2, 4, 3, 8, 9, 10]
[4, 5, 6, 1, 7, 2, 3, 8, 9, 10]
[2, 3, 4, 5, 6, 1, 7, 8, 9, 10]
12