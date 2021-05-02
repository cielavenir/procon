#!/usr/bin/ruby
L,X,Y,s,d=gets.split.map &:to_f;p [(d-=s)%L/(X+Y),Y>X ? -d%L/(Y-X):1e9].min