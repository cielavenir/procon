#!/usr/bin/env crystal
def heappush(heap, item)
	heap.push(item)
	_siftdown(heap, 0, heap.size-1)
end

def heappop(heap)
	lastelt = heap.pop
	if !heap.empty?
		returnitem = heap[0]
		heap[0] = lastelt
		_siftup(heap, 0)
	else
		returnitem = lastelt
	end
	returnitem
end

def heappushpop(heap, item)
	if !heap.empty? && (heap[0]<=>item)<0
		item, heap[0] = heap[0], item
		_siftup(heap, 0)
	end
	item
end

def heapify(x)
	n = x.size
	(n/2-1).downto(0){|i|_siftup(x, i)}
end

def _siftdown(heap, startpos, pos)
	newitem = heap[pos]
	while pos > startpos
		parentpos = (pos - 1) >> 1
		parent = heap[parentpos]
		if (newitem<=>parent)<0
			heap[pos] = parent
			pos = parentpos
		else
			break
		end
	end
	heap[pos] = newitem
end

def _siftup(heap, pos)
	endpos = heap.size
	startpos = pos
	newitem = heap[pos]
	childpos = 2*pos + 1
	while childpos < endpos
		rightpos = childpos + 1
		if rightpos < endpos && (heap[childpos]<=>heap[rightpos])>=0
			childpos = rightpos
		end
		heap[pos] = heap[childpos]
		pos = childpos
		childpos = 2*pos + 1
	end
	heap[pos] = newitem
	_siftdown(heap, startpos, pos)
end

D={
'L'=>[-1,0],
'D'=>[0,1],
'R'=>[1,0],
'U'=>[0,-1],
}
n,m,k=gets.not_nil!.split.map &.to_i
d=gets.not_nil!.chomp
st={0,0}
go={0,0}
s=n.times.map{|i|
	line=gets.not_nil!.chomp
	if j=line.index('S')
		st={i,j}
	end
	if j=line.index('G')
		go={i,j}
	end
	line
}.to_a

#calculate cost table
costs=k.times.map{Hash(Char,Int32).new}.to_a
k.times{|i|
	o=i
	z=0
	costs[i][d[o]]=z
	i-=1
	i=k-1 if i==-1
	z+=1
	while d[o]!=d[i]
		costs[i][d[o]]=z
		i-=1
		i=k-1 if i==-1
		z+=1
	end
}

#bfs
depth=Hash(Tuple(Int32,Int32),Int64).new
q=[{0_i64,st[0],st[1]}]
while !q.empty?
	curcost,cury,curx=heappop(q)
	cur={cury,curx}
	next if depth.has_key?(cur)
	depth[cur]=curcost
	if cur==go
		puts curcost
		exit
	end
	D.each{|_d,(dx,dy)|
		next if !costs[curcost%k].has_key?(_d)
		ncost=curcost+1_i64+costs[curcost%k][_d]
		nx=cur[1]+dx
		ny=cur[0]+dy
		if 0<=nx&&nx<m && 0<=ny&&ny<n && s[ny][nx]!='#' && !ncost.to_f.infinite?
			heappush(q,{ncost,ny,nx})
		end
	}
end
p -1
