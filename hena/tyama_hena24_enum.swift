//usr/bin/env swift $0 $@;exit

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

precedencegroup PowerPrecedence {
	associativity: right
	higherThan: MultiplicationPrecedence
}
infix operator <>: ComparisonPrecedence
infix operator ≠: ComparisonPrecedence
infix operator ≤: ComparisonPrecedence
infix operator ≥: ComparisonPrecedence
infix operator **: PowerPrecedence
public func <> <T: Equatable>(lhs: T, rhs: T) -> Bool{return lhs != rhs}
public func ≠ <T: Equatable>(lhs: T, rhs: T) -> Bool{return lhs != rhs}
public func ≤ <T: Comparable>(lhs: T, rhs: T) -> Bool{return lhs <= rhs}
public func ≥ <T: Comparable>(lhs: T, rhs: T) -> Bool{return lhs >= rhs}
public func ** <T: Numeric>(lhs: T, rhs: Int64) -> T{
	var x = lhs
	var k = rhs
	var e = 1 as T
	while k>0{
		if k%2>0 {e*=x}
		x*=x
		k/=2
	}
	return e
}

func isqrt(_ n: Int64) -> Int64{
	if n<=0 {return 0}
	if n<4 {return 1}
	var x: Int64 = 0
	var y: Int64 = n
	while x<>y && x+1<>y {
		x = y
		y = (n/y+y)/2
	}
	return x
}
func icbrt(_ n: Int64) -> Int64{
	if n<0 {return icbrt(-n)}
	if n==0 {return 0}
	if n<8 {return 1}
	var x: Int64 = 0
	var y: Int64 = n
	while x<>y && x+1<>y {
		x = y
		y = (n/y/y+y*2)/3
	}
	return x
}

class generate: Sequence, IteratorProtocol{
	var i: Int64 = 0
	func next() -> Int64?{
		i += 1
		return i
	}
}
class drop_prev: Sequence, IteratorProtocol{
	var prev: AnyIterator<Int64>
	var check: (Int64) -> Bool
	var a: Int64 = 0
	var b: Int64 = 0
	init(_ check_: @escaping (Int64) -> Bool, _ prev_: AnyIterator<Int64>){
		check = check_
		prev = prev_
		b = prev.next()!
	}
	func next() -> Int64?{
		while true{
			a = b
			b = prev.next()!
			if !check(b){
				return a
			}
		}
	}
}
class drop_next: Sequence, IteratorProtocol{
	var prev: AnyIterator<Int64>
	var check: (Int64) -> Bool
	var first: Bool = true
	var a: Int64 = 0
	var b: Int64 = 0
	init(_ check_: @escaping (Int64) -> Bool, _ prev_: AnyIterator<Int64>){
		check = check_
		prev = prev_
	}
	func next() -> Int64?{
		while true{
			a = b
			b = prev.next()!
			if first || !check(a){
				first = false
				return b
			}
		}
	}
}
class drop_n: Sequence, IteratorProtocol{
	var prev: AnyIterator<Int64>
	var check: (Int64,Int64) -> Bool
	var n: Int64
	var i: Int64 = 0
	init(_ check_: @escaping (Int64,Int64) -> Bool, _ n_: Int64, _ prev_: AnyIterator<Int64>){
		check = check_
		prev = prev_
		n = n_
	}
	func next() -> Int64?{
		while true{
			i += 1
			let a = prev.next()!
			if !check(i,n){
				return a
			}
		}
	}
}
	
func is_sq(_ n: Int64) -> Bool{return isqrt(n)**2==n}
func is_cb(_ n: Int64) -> Bool{return icbrt(n)**3==n}
func is_multiple(_ i: Int64, _ n: Int64) -> Bool{return i%n==0}
func is_le(_ i: Int64, _ n: Int64) -> Bool{return i<=n}
var f: [Character: (AnyIterator<Int64>) -> AnyIterator<Int64>] = [:]
f["S"]={AnyIterator(drop_next(is_sq,$0))}
f["s"]={AnyIterator(drop_prev(is_sq,$0))}
f["C"]={AnyIterator(drop_next(is_cb,$0))}
f["c"]={AnyIterator(drop_prev(is_cb,$0))}
f["h"]={AnyIterator(drop_n(is_le,100,$0))}
for i in 2...9{f[Character(String(i))]={AnyIterator(drop_n(is_multiple,Int64(i),$0))}}

while true{
	let s = readLine()
	if s==nil{break}
	var g: AnyIterator<Int64> = AnyIterator(generate())
	for c in s!{
		g = f[c]!(g)
	}
	var c = 0
	for e in g{
		c += 1
		print(e,terminator:c==10 ? "\n" : ",")
		if c==10{break}
	}
}