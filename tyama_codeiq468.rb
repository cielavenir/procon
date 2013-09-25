#!/usr/bin/ruby
def dfs(d,*a)d<5?0.step(a.max+1){|e|dfs(d+1,*a,e)}:puts(a.each.with_index(1).group_by{|e,i|e}.map{|k,v|v.map(&:last)*''}*'.')end;dfs(1,0)

__END__
ENV: Ruby (137bytes)
POINT: DFS
手計算しているうちに規則性が見えたので、DFSに落とし込んだ。
Rubyの可変長引数とeach_with_indexを効率よく使うことで138バイトまで短縮出来ました^^