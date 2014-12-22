#!/usr/bin/ruby
1.step(100){|n|n%3<1&&x=:Fizz;puts n%5<1?"#{x}Buzz":x||n}