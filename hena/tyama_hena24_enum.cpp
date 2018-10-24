// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/
// -fcoroutines-ts -stdlib=libc++

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
using namespace std;

#if defined(_MSC_VER)
#include <experimental/generator>
#else
//based on https://github.com/Microsoft/Range-V3-VS2015/issues/12#issuecomment-291325027
//modified by cielavenir
//(according to http://releases.llvm.org/5.0.0/tools/clang/docs/ReleaseNotes.html#major-new-features and https://wandbox.org/permlink/Dth1IO5q8Oe31ew2)

/***
*generator
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*       Purpose: Library support of coroutines. generator class
*       http://open-std.org/JTC1/SC22/WG21/docs/papers/2015/p0057r0.pdf
*
*       [Public]
*
****/
#pragma push_macro("new")
#undef new

#include <experimental/coroutine>

namespace std {

namespace experimental {

	template <typename _Ty, typename _Alloc = allocator<char>>
	struct generator
	{
		struct promise_type
		{
			_Ty const *_CurrentValue;
			auto get_return_object() { return generator{coroutine_handle<promise_type>::from_promise(*this)}; }
			auto initial_suspend() { return suspend_always{}; }
			auto final_suspend() { return suspend_always{}; }
			void unhandled_exception() { std::terminate(); }
			void return_void() {}

			auto yield_value(_Ty const &_Value)
			{
				_CurrentValue = addressof(_Value);
				return suspend_always{};
			}

			using _Alloc_traits = allocator_traits<_Alloc>;
			using _Alloc_of_char_type = typename _Alloc_traits::template rebind_alloc<char>;

			void *operator new(size_t _Size)
			{
				_Alloc_of_char_type _Al;
				return _Al.allocate(_Size);
			}

			void operator delete(void *_Ptr, size_t _Size) _NOEXCEPT
			{
				_Alloc_of_char_type _Al;
				return _Al.deallocate(static_cast<char *>(_Ptr), _Size);
			}
		};

		struct iterator
		{
			using iterator_category = input_iterator_tag;
			using difference_type = ptrdiff_t;
			using value_type = _Ty;
			using reference = _Ty const &;
			using pointer = _Ty const *;

			coroutine_handle<promise_type> _Coro = nullptr;

			iterator() = default;
			iterator(nullptr_t) : _Coro(nullptr) {}
			iterator(coroutine_handle<promise_type> _CoroArg) : _Coro(_CoroArg) {}

			iterator &operator++()
			{
				_Coro.resume();
				if (_Coro.done())
					_Coro = nullptr;
				return *this;
			}

			void operator++(int)
			{
				// This postincrement operator meets the requirements of the Ranges TS
				// InputIterator concept, but not those of Standard C++ InputIterator.
				++*this;
			}

			bool operator==(iterator const &_Right) const { return _Coro == _Right._Coro; }
			bool operator!=(iterator const &_Right) const { return !(*this == _Right); }
			reference operator*() const { return *_Coro.promise()._CurrentValue; }
			pointer operator->() const { return _Coro.promise()._CurrentValue; }
		};

		iterator begin()
		{
			if (_Coro) {
				_Coro.resume();
				if (_Coro.done())
					return {nullptr};
			}

			return {_Coro};
		}

		iterator end() { return {nullptr}; }
		explicit generator(coroutine_handle<promise_type> x) : _Coro(x) {}
		generator() = default;
		generator(generator const &) = delete;
		generator &operator=(generator const &) = delete;
		generator(generator &&_Right) : _Coro(_Right._Coro) { _Right._Coro = nullptr; }

		generator &operator=(generator &&_Right)
		{
			if (this != addressof(_Right)) {
				_Coro = _Right._Coro;
				_Right._Coro = nullptr;
			}
			return *this;
		}

		~generator()
		{
			if (_Coro) {
				_Coro.destroy();
			}
		}

	private:
		coroutine_handle<promise_type> _Coro = nullptr;
	};

} // namespace experimental

}

#pragma pop_macro("new")
#endif
using namespace std::experimental;

int isqrt(int n){
	if(n<=0)return 0;
	if(n<4)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
	return x;
}
int icbrt(int n){
	if(n<0)return icbrt(-n);
	if(n==0)return 0;
	if(n<8)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y/y+y*2)/3;
	return x;
}

generator<int> mygenerate(){
	int i=1;
	for(;;){
		co_yield i;
		i+=1;
	}
}
generator<int> drop_prev(bool(*check)(int),generator<int> _prev){
	auto prev=_prev.begin();
	int a=*prev;
	++prev;
	int b=*prev;
	for(;;){
		if(!check(b))co_yield a;
		a=b;
		++prev;
		b=*prev;
	}
}
generator<int> drop_next(bool(*check)(int),generator<int> _prev){
	auto prev=_prev.begin();
	int a=*prev;
	++prev;
	int b=*prev;
	co_yield a;
	for(;;){
		if(!check(a))co_yield b;
		a=b;
		++prev;
		b=*prev;
	}
}
generator<int> drop_n(bool(*check)(int,int),int n,generator<int> _prev){
	auto prev=_prev.begin();
	int i=0;
	for(;;){
		i++;
		int a=*prev;
		if(!check(i,n))co_yield a;
		++prev;
	}
}
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

int main(){
	map<char,function<generator<int>(generator<int>)>> f={
		{'S',[&](auto e){return drop_next(&is_sq,move(e));}},
		{'s',[&](auto e){return drop_prev(&is_sq,move(e));}},
		{'C',[&](auto e){return drop_next(&is_cb,move(e));}},
		{'c',[&](auto e){return drop_prev(&is_cb,move(e));}},
		{'h',[&](auto e){return drop_n(&is_le,100,move(e));}},
	};
	vector<int>v(8);
	iota(v.begin(),v.end(),2);
	for(auto &e:v)f[(char)('0'+e)] = [&](int &j){
		return [&](auto e){return drop_n(&is_multiple,j,move(e));};
	}(e);

	string line;
	for(;getline(cin,line);){
		bool first=true;
		//cS => f['S'](f['c'](generate()))
		//auto z=reduce!((s,e)=>f[e](s))(generate(),line);

		auto z=mygenerate();
		for(char e:line)z=f[e](move(z));
		auto it=z.begin();
		for(int i=0;i<10;i++){
			int n=*it;
			++it;
			if(!first)putchar(',');
			first=false;
			printf("%d",n);
		}
		puts("");
		fflush(stdout);
	}
}
