#!/usr/bin/ruby
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
n,m,k=gets.split.map &:to_i
d=gets.chomp
st=nil
go=nil
s=n.times.map{|i|
	line=gets.chomp
	if j=line.index('S')
		st=[i,j]
	end
	if j=line.index('G')
		go=[i,j]
	end
	line
}

#calculate cost table
costs=k.times.map{{}}
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
depth={}
q=[[0,*st]]
while !q.empty?
	curcost,*cur=heappop(q)
	next if depth[cur]
	depth[cur]=curcost
	if cur==go
		p curcost
		exit
	end
	D.each{|_d,(dx,dy)|
		next if !costs[curcost%k].has_key?(_d)
		ncost=costs[curcost%k][_d]+curcost+1
		nx=cur[1]+dx
		ny=cur[0]+dy
		if 0<=nx&&nx<m && 0<=ny&&ny<n && s[ny][nx]!='#' && !ncost.to_f.infinite?
			heappush(q,[ncost,ny,nx])
		end
	}
end
p -1
