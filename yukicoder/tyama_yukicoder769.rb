#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a=[0]*n
k=draw=0
d=1
prev=''
m.times{|i|
    s=gets.chomp
    if prev!=s&&prev.start_with?('draw')
        a[k]-=draw
        k=(k+d)%n
        draw=0
    end
    a[k]+=1
    break if i==m-1
    if s=='drawtwo'
        draw+=2
    elsif s=='drawfour'
        draw+=4
    elsif s=='skip'
        k=(k+d)%n
    elsif s=='reverse'
        d=-d
    end
    prev=s
    k=(k+d)%n
}
puts [k+1,a[k]]*' '
