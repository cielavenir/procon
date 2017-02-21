#!/usr/bin/ruby
H=Hash.new{|h,k|h[k]=[]}
n=gets.to_i
roots=[*0...n]
n.times{
	x=gets.split.map(&:to_i)
	p=x.shift
	x.each{|e|
		H[p]<<e
		roots[e]=nil if e!=-1
	}
}
root=roots.find{|e|e}
def preorder(node)
	print " #{node}"
	H[node].each{|e|preorder(e) if e!=-1}
end
def inorder(node)
	children=H[node]
	inorder(children[0]) if children[0]&&children[0]!=-1
	print " #{node}"
	inorder(children[1]) if children[1]&&children[1]!=-1
end
def postorder(node)
	H[node].each{|e|postorder(e) if e!=-1}
	print " #{node}"
end
puts 'Preorder'
preorder(root);puts
puts 'Inorder'
inorder(root);puts
puts 'Postorder'
postorder(root);puts
