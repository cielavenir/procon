#!/usr/bin/ruby
L,X,Y,S,D=gets.split.map &:to_f;p [(D-S)%L/(X+Y),Y>X ? (S-D)%L/(Y-X):1e9].min