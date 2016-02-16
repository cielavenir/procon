#include <iostream>
using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box{
public:
	int l=0,b=0,h=0;
	Box(int _l,int _b,int _h):l(_l),b(_b),h(_h){++BoxesCreated;}
	Box(const Box &_b){l=_b.l,b=_b.b,h=_b.h;++BoxesCreated;}
	Box(){++BoxesCreated;}
	~Box(){++BoxesDestroyed;}
	int getLength(){return l;}
	int getBreadth(){return b;}
	int getHeight(){return h;}
	long long CalculateVolume(){return (long long)l*b*h;}
	bool operator<(const Box &_b){
		if(l<_b.l)return true;
		if(l>_b.l)return false;
		if(b<_b.b)return true;
		if(b>_b.b)return false;
		return h<_b.h;
	}
};
namespace std{
	ostream& operator<<(ostream& out, Box _b){
		return out<<_b.l<<' '<<_b.b<<' '<<_b.h;
	}
}


void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
	{
	int type;
	cin>>type;
	if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser"<<endl;
		}
			else
			{
				cout<<"Greater"<<endl;
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	BoxesCreated = 0;
	BoxesDestroyed = 0;
	check2();
	cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}