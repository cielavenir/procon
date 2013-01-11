$peter=Hash.new{|h,k|h[k]=0}
def peter(depth,s)
	if depth==9 then $peter[s]+=1;return end
	(1..4).each{|i|peter(depth+1,s+i)}
end
peter(0,0)
$colin=Hash.new{|h,k|h[k]=0}
def colin(depth,s)
	if depth==6 then $colin[s]+=1;return end
	(1..6).each{|i|colin(depth+1,s+i)}
end
colin(0,0)

win=0
lose=0
draw=0
total=0
$peter.each{|kp,vp|
	$colin.each{|kc,vc|
		if kp>kc then win+=vp*vc end
		if kp<kc then lose+=vp*vc end
		if kp==kc then draw+=vp*vc end
		total+=vp*vc
	}
}
puts sprintf("%.7f",win/total.to_f)
#puts sprintf("%.7f",lose/total.to_f)
#puts sprintf("%.7f",draw/total.to_f)