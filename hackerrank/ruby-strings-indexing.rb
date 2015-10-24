def serial_average(s)
	s=~/^(\d+)-(.+)?-(.+)$/
	$1+'-'+'%.2f'%[($2.to_f+$3.to_f)/2]
end