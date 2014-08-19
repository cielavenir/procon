#!/usr/bin/ruby
require 'bio'
require 'stringio'
def dfs1(v)
	children=$tree.children(v)
	return if children.size==0
	cnt=Array.new(L){Hash.new(0)}
	children.each{|w|
		dfs1(w)
		$seqs[w.name].each_with_index{|e,i|
			e.chars{|f|cnt[i][f]+=1}
		}
	}
	$seqs[v.name]=cnt.map{|e|
		max=e.values.max
		e.keys.select{|f|e[f]==max}*''
	}
end
def dfs2(v)
	a=$seqs[v.name]
	b=$tree.parent(v) ? $seqs[$tree.parent(v).name] : ['?']*L
	ret=0
	L.times{|i|
		raise if b[i].size!=1
		if a[i].index(b[i])
			a[i]=b[i]
		else
			a[i]=a[i][0,1]
			ret+=1
		end
	}
	$seqs[v.name]=a
	$tree.children(v).each{|w|
		ret+=dfs2(w)
	}
	ret
end

$tree = Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
$seqs={} #$seqs.values are Array whose size is L
head=gets.chomp[1..-1].tr('_',' ')
seq=''
while gets
	if $_[0..0]=='>'
		$seqs[head]=seq.split('')
		head=$_.chomp[1..-1].tr('_',' ')
		seq=''
	else
		seq+=$_.chomp
	end
end
$seqs[head]=seq.split('')
L=$seqs.values[0].size
dfs1($tree.root)
p dfs2($tree.root)-L
$tree.nodes.each{|e|
	puts ">#{e.name.tr(' ','_')}\n#{$seqs[e.name]*''}" if $tree.children(e).size>0
}