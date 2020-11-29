//usr/bin/env vala --pkg gee-0.8 --pkg gio-2.0 "$0" "$@";exit

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

using Gee;

abstract class Generator<G> {
	// http://valajournal.blogspot.com/2011/07/generators-in-vala.html
	private bool consumed;
	private G value;
	private SourceFunc callback;

	protected async void helper () {
		yield generate ();
		consumed = true;
	}

	protected abstract async void generate ();

	protected async void feed (G value) {
		this.value = value;
		this.callback = feed.callback;
		yield;
	}

	public bool next () {
		return !consumed;
	}

	public G get () {
		var result = value;
		callback ();
		return result;
	}

	public Generator<G> iterator () {
		return this;
	}
}

int isqrt(int n){
	if(n<=0)return 0;
	if(n<4)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;){x=y;y=(n/y+y)/2;}
	return x;
}
int icbrt(int n){
	if(n<0)return icbrt(-n);
	if(n==0)return 0;
	if(n<8)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;){x=y;y=(n/y/y+y*2)/3;}
	return x;
}

class mygenerate_impl:Generator<int>{
	public mygenerate_impl(){
		helper();
	}
	protected override async void generate(){
		for(int i=1;;i++){
			yield feed(i);
		}
	}
}
Generator<int> mygenerate(){return new mygenerate_impl();}

static delegate bool dbi(int a);
class drop_prev_impl:Generator<int>{
	dbi check;
	Generator<int> prev;
	public drop_prev_impl(dbi _check, Generator<int> _prev){
		check=_check;
		prev=_prev;
		helper();
	}
	protected override async void generate(){
		int a=prev.get();
		int b=prev.get();
		for(;;){
			if(!check(b))yield feed(a);
			a=b;
			b=prev.get();
		}
	}
}
Generator<int> drop_prev(dbi check,Generator<int> prev){return new drop_prev_impl(check,prev);}

class drop_next_impl:Generator<int>{
	dbi check;
	Generator<int> prev;
	public drop_next_impl(dbi _check, Generator<int> _prev){
		check=_check;
		prev=_prev;
		helper();
	}
	protected override async void generate(){
		int a=prev.get();
		int b=prev.get();
		yield feed(a);
		for(;;){
			if(!check(a))yield feed(b);
			a=b;
			b=prev.get();
		}
	}
}
Generator<int> drop_next(dbi check,Generator<int> prev){return new drop_next_impl(check,prev);}

static delegate bool dbii(int a,int b);
class drop_n_impl:Generator<int>{
	dbii check;
	int n;
	Generator<int> prev;
	public drop_n_impl(dbii _check, int _n, Generator<int> _prev){
		check=_check;
		n=_n;
		prev=_prev;
		helper();
	}
	protected override async void generate(){
		int i=0;
		for(;;){
			i++;
			int a=prev.get();
			if(!check(i,n))yield feed(a);
		}
	}
}
Generator<int> drop_n(dbii check,int n,Generator<int> prev){return new drop_n_impl(check,n,prev);}

bool is_sq(int n){
	int x=isqrt(n);
	return x*x==n;
}
bool is_cb(int n){
	int x=icbrt(n);
	return x*x*x==n;
}
bool is_multiple(int i,int n){return i%n==0;}
bool is_le(int i,int n){return i<=n;}

static delegate Generator<int> dgg(Generator<int> a);
void main(){
	var f=new HashMap<char,dgg>();
	f.set('S',(e)=>{return drop_next(is_sq,e);});
	f.set('s',(e)=>{return drop_prev(is_sq,e);});
	f.set('C',(e)=>{return drop_next(is_cb,e);});
	f.set('c',(e)=>{return drop_prev(is_cb,e);});
	f.set('h',(e)=>{return drop_n(is_le,100,e);});
	f.set('2',(e)=>{return drop_n(is_multiple,2,e);});
	f.set('3',(e)=>{return drop_n(is_multiple,3,e);});
	f.set('4',(e)=>{return drop_n(is_multiple,4,e);});
	f.set('5',(e)=>{return drop_n(is_multiple,5,e);});
	f.set('6',(e)=>{return drop_n(is_multiple,6,e);});
	f.set('7',(e)=>{return drop_n(is_multiple,7,e);});
	f.set('8',(e)=>{return drop_n(is_multiple,8,e);});
	f.set('9',(e)=>{return drop_n(is_multiple,9,e);});

	for(string line;(line = stdin.read_line())!=null;){
		bool first=true;
		//cS => f['S'](f['c'](generate()))
		//auto z=reduce!((s,e)=>f[e](s))(generate(),line);

		var z=mygenerate();
		foreach(uint8 e in line.data){
			// called object type 'gpointer' (aka 'void *') is not a function or function pointer
			// z=f[(char)e](z);

			if(e=='S')z=drop_next(is_sq,z);
			if(e=='s')z=drop_prev(is_sq,z);
			if(e=='C')z=drop_next(is_cb,z);
			if(e=='c')z=drop_prev(is_cb,z);
			if(e=='h')z=drop_n(is_le,100,z);
			if(e=='2')z=drop_n(is_multiple,2,z);
			if(e=='3')z=drop_n(is_multiple,3,z);
			if(e=='4')z=drop_n(is_multiple,4,z);
			if(e=='5')z=drop_n(is_multiple,5,z);
			if(e=='6')z=drop_n(is_multiple,6,z);
			if(e=='7')z=drop_n(is_multiple,7,z);
			if(e=='8')z=drop_n(is_multiple,8,z);
			if(e=='9')z=drop_n(is_multiple,9,z);
		}
		for(int i=0;i<10;i++){
			int n=z.get();
			if(!first)stdout.printf("%c",',');
			first=false;
			stdout.printf("%d",n);
		}
		stdout.printf("\n");
		stdout.flush();
	}
}
