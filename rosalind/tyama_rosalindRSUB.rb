#!/usr/bin/ruby
require 'bio'
require 'stringio'
def dfs(v,s1,s2)
	c=$seqs[v.name]
	t1={};t2={}
	c.each_with_index{|e,i|
		t2[[i,e]]=s2[[i,e]]||v
	}
	s1.each_key{|k|
		i,s,t=k
		if c[i]==s
			puts '%s %s %d %s->%s->%s'%[s1[k].name.tr(' ','_'),v.name.tr(' ','_'),i+1,s,t,s]
		elsif c[i]==t
			t1[k]=s1[k]
		end
	}
	s2.each_key{|k|
		i,s=k
		if c[i]!=s
			t1[[i,s,c[i]]]=v;
		end
	}
	$tree.children(v).each{|w|
		dfs(w,t1,t2)
	}
end

$tree = Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
$seqs={}
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
dfs($tree.root,{},{})