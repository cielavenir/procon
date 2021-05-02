#!/usr/bin/ruby
x=$<.map &:to_i
n=x[0]
h={}
begin
    i=1;while i<=n
    raise if (x[i]^i)%2>0
    u=x[i];v=i;h[u]=1
    while i<u
        i+=1
        raise if x[i]!=i
        i+=1
        raise if (x[i]^i)%2>0
        if u<x[i];u=x[i];h[u]=1
        elsif v==x[i];v+=2;v+=2 while h[v]
        else;raise
        end
    end
    i+=1;end
    puts :Yes
rescue
    puts :No
end
