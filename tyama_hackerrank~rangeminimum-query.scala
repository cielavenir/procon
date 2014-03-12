object Solution{
	def _query(a:Int,b:Int,k:Int,l:Int,r:Int,minval:Array[Int]):Int = {
		if(r<=a||b<=l)return 999999999
		if(a<=l&&r<=b)return minval(k)
		else{
			val vl=_query(a,b,k*2+1,l,(l+r)/2,minval)
			val vr=_query(a,b,k*2+2,(l+r)/2,r,minval)
			return List(vl,vr).min
		}
	}
	def query(a:Int,b:Int,siz:Int,minval:Array[Int]):Int = {
		return _query(a,b,0,0,siz,minval)
	}

	def _getSize(k:Int,siz:Int):Int = {
		if(k<=siz)return siz
		else return _getSize(k,siz*2)
	}
	def getSize(k:Int):Int = {
		return _getSize(k,1)
	}

	def _update(k:Int,minval:Array[Int]){
		minval(k)=List(minval(k*2+1),minval(k*2+2)).min
		if(k>0)_update((k-1)/2,minval)
	}
	def update(k:Int,t:Int,siz:Int,minval:Array[Int]){
		minval(k+siz-1)=t
		_update((k+siz-1-1)/2,minval)
	}

	def main(args:Array[String]){
		val a=readLine().split(' ').map(_.toInt)
		val siz=getSize(a(0))
		val minval=new Array[Int](2*siz-1)
		for(i<-0 to minval.length-1){
			minval(i)=999999999
		}
		val v=readLine().split(' ').map(_.toInt)
		for(i<-0 to v.length-1){
			update(i,v(i),siz,minval)
		}
		for(i<-0 to a(1)-1){
			val x=readLine().split(' ').map(_.toInt)
			println(query(x(0),x(1)+1,siz,minval))
		}
	}
}