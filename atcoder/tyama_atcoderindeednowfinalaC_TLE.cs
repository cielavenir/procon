using System;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Collections.Generic;

class IndeedNowFinalaC{
	const int SIZE=9999999;
	static byte[] _z=new byte[SIZE];
	static int input_count=0;

	static int get(){
		int r=0;
		for(;'0'<=_z[input_count]&&_z[input_count]<='9';)r=r*10+_z[input_count++]-'0';
		input_count++;
		return r;
	}

	static List<Tuple<int,int,int,int>>v;
	static List<Tuple<int,int,int>>z;
	static int[] r;
	static int N;

	static void fun(object _i){
		int i=(int)_i;
		for(int j=N;j>=0;j--)if(z[i].Item1>=v[j].Item2&&z[i].Item2>=v[j].Item3&&z[i].Item3>=v[j].Item4){
			r[i]=v[j].Item1;
			break;
		}
	}

	static void Main(){
		Console.OpenStandardInput().Read(_z,0,SIZE);
		N=get();
		int M=get();
		v=new List<Tuple<int,int,int,int>>(N+1);
		z=new List<Tuple<int,int,int>>(M);
		r=new int[M];
		for(int i=0;i<N;i++){
			int a=get(),b=get(),c=get(),d=get();
			v.Add(new Tuple<int,int,int,int>(d,a,b,c));
		}
		v.Add(new Tuple<int,int,int,int>(0,0,0,0));
		v.Sort();

		for(int i=0;i<M;i++){
			int a=get(),b=get(),c=get();
			z.Add(new Tuple<int,int,int>(a,b,c));
		}
		if(true){
			/*
			{
				int a,b;
				ThreadPool.GetAvailableThreads(out a,out b);
				ThreadPool.SetMinThreads(1,b);
				ThreadPool.SetMaxThreads(2,b);
			}
			List<Thread> threads=new List<Thread>();
			for(int i=0;i<M;i++){
				Thread t=new Thread(new ParameterizedThreadStart(fun));
				t.Start(i);
				threads.Add(t);
			}
			foreach(var t in threads)t.Join();
			*/
			ParallelOptions option=new ParallelOptions();
			option.MaxDegreeOfParallelism=4;
			Parallel.For(0,M,option,i=>fun(i));
		}else{
			//for(int i=0;i<M;i++)fun(i);
		}
		for(int i=0;i<M;i++)Console.WriteLine(r[i]);

	}
}

/*
2 1
0 200 200 5000
100 100 100 10000
100 100 100
*/