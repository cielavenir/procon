#!/usr/bin/ruby
require 'zlib'
require 'base64'
prog=gets.chomp
prog.each_char{|e|
	if e=='H'
		puts 'Hello, world!'
	elsif e=='Q'
		puts prog
	elsif e=='9'
		puts Zlib.inflate Zlib.inflate Base64.decode64 'eNqrmDN3lm/e5QQG1u+WR8sZRC7+/8byJqKw0cWQaeKxFZ6hhdWXunhfvT4z+brkeZXZ6rd/yskdK7Ob++1y4Zn7x8tmzTtWI7Fc/nLFzTff5x87vPv89dX5s+Mvz5x1LK/Osudsonldft/xj59NzPw/f04s3/dq3prXV7saVVZsKp/mqsC56s3aVEGPJq3q5EiWSQtOxUWLgaTCIVJLIVKJYKm6bTpMnhdS3he2nItkA/JveRlOYAm9FgY2a1sQj4rj1K1Tk4Da1qwVYfYMSM1dKgHUnK191EEoJDJaE67F99s5kvWgWDN5L+l6kK25kJKfQ6oeFGtMbmaTrActCE5RGgRbKAwCfcqCIOT4liVZ6VbTTb6uETGfPtdxwrK5DhGXrtR/27HzTe9Ok7e1PxdNF/22zikuVKfqywZ1/soPESXKid8Fi6Q3Zoj9i/1yUePA8ff6eU3tlTbn/Cf/ubLer3ZF1Pp9Zx6b7G88fln7wy/bbefrjxXWzbmn59l+9P9/tnpGnox6RQDjKmhx'
	end
}