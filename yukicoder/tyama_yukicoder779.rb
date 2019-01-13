#!/usr/bin/ruby
T=Time;t=T.new *gets.split;puts T.new(1989,1,7)<t&&t<T.new(2019,5,1)?:Yes: :No
