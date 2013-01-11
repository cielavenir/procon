using System;

class icpc2007dA{
  static void Main(){
    int i, n, s, ma, mi, sum;
    while(true){
      ma=0; mi=1000; sum=0;
      n=int.Parse(Console.ReadLine());
      if(n==0)return;
      for(i=0;i<n;i++){
        s=int.Parse(Console.ReadLine());
        ma=ma>s?ma:s;
        mi=mi<s?mi:s;
        sum+=s;
      }
      Console.WriteLine((sum-ma-mi)/(n-2));
    }
  }
}