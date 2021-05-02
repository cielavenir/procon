#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
ch=Hash.new{|h,k|h[k]=Hash.new 0};cnt=1
dfs=->x,d{x>0?dfs[ch[x][0],d-1]^dfs[ch[x][1],d-1]:d&-d}
n,m=gets.split.map &:to_i
n.times{
    s=gets.chomp
    q=1
    s.bytes{|b|c=b-48;ch[q][c]<1&&ch[q][c]=cnt+=1;q=ch[q][c]}
}
puts dfs[1,m+1]!=0 ? :Alice : :Bob
