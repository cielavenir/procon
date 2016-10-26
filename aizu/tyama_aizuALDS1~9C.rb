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

### main ###
q=[]
loop{
	a=gets.split
	break if a[0]=='end'
	if a[0]=='insert'
		heappush(q,-a[1].to_i)
	else
		p -heappop(q)
	end
}
