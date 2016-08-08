#!/usr/bin/ruby
T=%w(I II III IIII V VI VII VIII IX X XI XII);x,y=gets.split;$><<T[(T.index(x)+y.to_i)%12]