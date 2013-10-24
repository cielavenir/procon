object Solution {
//answer
def g(sum:Double,num:Double,num2:Double,i:Int,fact:Int):Double = if(i==10)sum else g(sum+num2/fact,num,num2*num,i+1,fact*(i+1))
def f(arr:Double):Double = g(1,arr,arr,1,1)
//until here
def main(args: Array[String]) {
	var n = readInt
	(1 to n) foreach(x=> println(f(readFloat())))
    }
}