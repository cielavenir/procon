#!/usr/bin/ruby
T={'Tetrahedron'=>4,'Cube'=>6,'Octahedron'=>8,'Dodecahedron'=>12,'Icosahedron'=>20}
s=0;gets.to_i.times{s+=T[gets.chomp]};p s
