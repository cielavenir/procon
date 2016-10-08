#!/usr/bin/ruby
N=gets.to_i
X=N.times.map{gets.chomp}
Y=N.times.map{gets.chomp}
attackX=attackY=0
N.times{|i|
	foulX=foulY=false
	if X[i]=='kougekida'
		foulX=true if attackX==0
		if Y[i]=='kougekida'
			foulY=true if attackY==0
			next if foulX&&foulY
			if foulX
				puts 'Nakajima-kun'
				exit
			elsif foulY
				puts 'Isono-kun'
				exit
			elsif attackX>attackY
				puts 'Isono-kun'
				exit
			elsif attackY<attackX
				puts 'Nakajima-kun'
				exit
			end
			attackY=0
		elsif foulX
			puts 'Nakajima-kun'
			exit
		elsif Y[i]=='tameru'
			puts 'Isono-kun'
			exit
		elsif Y[i]=='mamoru' && attackX>=5
			puts 'Isono-kun'
			exit
		end
		attackX=0
	elsif X[i]=='tameru'
		if Y[i]=='kougekida'
			if attackY==0
				puts 'Isono-kun'
				exit
			else
				puts 'Nakajima-kun'
				exit
			end
			attackY=0
		elsif Y[i]=='tameru'
			attackY+=1
		elsif Y[i]=='mamoru'
		end
		attackX+=1
	elsif X[i]=='mamoru'
		if Y[i]=='kougekida'
			if attackY==0
				puts 'Isono-kun'
				exit
			elsif attackY>=5
				puts 'Nakajima-kun'
				exit
			end
			attackY=0
		elsif Y[i]=='tameru'
			attackY+=1
		elsif Y[i]=='mamoru'
		end
	end
}
puts 'Hikiwake-kun'