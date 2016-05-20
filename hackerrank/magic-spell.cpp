#include <iostream>
#include <vector>
using namespace std;

class Spell { 
	private:
		string scrollName;
	public:
		Spell(): scrollName("") { }
		Spell(string name): scrollName(name) { }
		virtual ~Spell() { }
		string revealScrollName() {
			return scrollName;
		}
};

class Fireball : public Spell { 
	private: int power;
	public:
		Fireball(int power): power(power) { }
		void revealFirepower(){
			cout << "Fireball: " << power << endl;
		}
};

class Frostbite : public Spell {
	private: int power;
	public:
		Frostbite(int power): power(power) { }
		void revealFrostpower(){
			cout << "Frostbite: " << power << endl;
		}
};

class Thunderstorm : public Spell { 
	private: int power;
	public:
		Thunderstorm(int power): power(power) { }
		void revealThunderpower(){
			cout << "Thunderstorm: " << power << endl;
		}
};

class Waterbolt : public Spell { 
	private: int power;
	public:
		Waterbolt(int power): power(power) { }
		void revealWaterpower(){
			cout << "Waterbolt: " << power << endl;
		}
};

class SpellJournal {
	public:
		static string journal;
		static string read() {
			return journal;
		}
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	if(Fireball *p=dynamic_cast<Fireball*>(spell))p->revealFirepower();
	else if(Frostbite *p=dynamic_cast<Frostbite*>(spell))p->revealFrostpower();
	else if(Thunderstorm *p=dynamic_cast<Thunderstorm*>(spell))p->revealThunderpower();
	else if(Waterbolt *p=dynamic_cast<Waterbolt*>(spell))p->revealWaterpower();
	else{
		string a=SpellJournal::journal,b=spell->revealScrollName();
		void LCS(const string &a,const string &b);
		LCS(a,b);
	}
}

#include <cstring>
short lcs[2001][2001];
void LCS(const string &a,const string &b){
	memset(lcs,0,sizeof(lcs));
	int m=0,i=1,j,_a=a.size(),_b=b.size();
	for(;i<=_a;i++)
		for(j=1;j<=_b;j++){
			lcs[i][j]=max(a[i-1]==b[j-1]?lcs[i-1][j-1]+1:0,max<int>(lcs[i-1][j],lcs[i][j-1]));
			if(m<lcs[i][j])m=lcs[i][j];
		}
	cout<<m<<endl;
}

class Wizard {
	public:
		Spell *cast() {
			Spell *spell;
			string s; cin >> s;
			int power; cin >> power;
			if(s == "fire") {
				spell = new Fireball(power);
			}
			else if(s == "frost") {
				spell = new Frostbite(power);
			}
			else if(s == "water") {
				spell = new Waterbolt(power);
			}
			else if(s == "thunder") {
				spell = new Thunderstorm(power);
			} 
			else {
				spell = new Spell(s);
				cin >> SpellJournal::journal;
			}
			return spell;
		}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while(T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}