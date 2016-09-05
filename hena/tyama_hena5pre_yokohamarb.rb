#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/yokohamarb/2016.07.ront/
#http://qiita.com/Nabetani/items/1234c313776b6588a9d8
D=[[1,0],[0,1],[-1,0],[0,-1]]
C=[
	[3,2,1,0],
	[1,0,3,2],
	[0,1,2,3],
]

def solve(s)
	res=''
	a=s.split('/').map{|e|e.chars.map(&:to_i)}
	d=1;x=1;y=0
	while 0<=x&&x<4&&0<=y&&y<4
		res+=(y*4+x+97).chr
		break if a[y][x]==3
		d=C[a[y][x]][d]
		x+=D[d][0];y+=D[d][1]
	end
	res
end

if !ENV['SELFTEST']
	while gets
		puts solve($_.chomp)
		STDOUT.flush
	end
else
	$case=0
	def test(s,t)
		puts 'Case '+$case.to_s+': '+(solve(s)==t ? 'OK' : 'NG')
		$case+=1
	end
test( "0113/1201/2201/2100", "bcgfeabfjnoklpo" ) # 0    
test( "2110/2013/2210/0122", "bcgh" ) # 1    
test( "2222/2130/2121/2002", "bfg" ) # 2    
test( "0021/2212/2102/1220", "baeimnoplhdcbfjkgfe" ) # 3    
test( "0213/1221/0220/1103", "bfjnokgcbaefghlkjimn" ) # 4    
test( "3201/3120/3333/3333", "bfghdcgk" ) # 5    
test( "3233/3233/3133/3333", "bfjk" ) # 6    
test( "3333/3333/3333/3333", "b" ) # 7    
test( "1212/1201/2123/2220", "bfjkl" ) # 8    
test( "2212/3102/1002/2100", "bfgcba" ) # 9    
test( "0023/2221/1102/0031", "baeijnm" ) # 10    
test( "1121/3120/0212/1120", "bcdhgfba" ) # 11    
test( "2202/3211/2120/1210", "bfjklhgcd" ) # 12    
test( "3201/3211/1111/0100", "bfjkonjie" ) # 13    
test( "0121/1120/1111/1211", "bcdhgfbaefjkop" ) # 14    
test( "1212/1213/2103/0213", "bfjkgfea" ) # 15    
test( "1121/2212/1323/3031", "bcdhl" ) # 16    
test( "0030/1230/1121/0031", "baefg" ) # 17    
test( "2223/1211/0002/1200", "bfjimnokl" ) # 18    
test( "3210/0033/0201/0130", "bfei" ) # 19    
test( "0213/2220/0021/3002", "bfjim" ) # 20    
test( "2121/2112/1110/1010", "bcdhlkgfba" ) # 21    
test( "0113/1003/2303/2220", "bcgfj" ) # 22    
test( "2202/1110/1302/0313", "bfgkj" ) # 23    
test( "1211/3202/2102/0222", "bfjkgh" ) # 24    
test( "3113/0002/0112/1022", "bcgfjko" ) # 25    
test( "1200/3000/0121/0121", "bfe" ) # 26    
test( "2221/1122/1031/2200", "bfgh" ) # 27    
test( "1202/0121/0222/1300", "bfghlpo" ) # 28    
test( "0002/1012/1021/3300", "baefbc" ) # 29    
test( "0211/1200/2220/2103", "bfjnokghdc" ) # 30
end