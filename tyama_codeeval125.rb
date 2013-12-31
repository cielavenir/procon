#!/usr/bin/ruby
while gets
    n=$_.to_i.to_s(2).scan(/1/).size
    p n%3
end