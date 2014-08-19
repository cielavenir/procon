#!/usr/bin/ruby
require 'bio'
require 'stringio'
$a=[[0],[0,1],[1]]
def dfs(t,n)
	_r=[0,0,0]
	if n.name
		_r[n.name.count 'a']+=1
	else
		l,r=t.descendents(n)
		l=dfs(t,l)
		r=dfs(t,r)
		l.size.times{|i|
			r.size.times{|j|
				$a[i].each{|ii|
					$a[j].each{|jj|
						_r[ii+jj]+=(l[i]*r[j]).to_f/($a[i].size*$a[j].size)
					}
				}
			}
		}
	end
	_r
end
tree=Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
puts dfs(tree,tree.root)*' '