#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
	int age;
	string first_name;
	string last_name;
	int standard;
public:
	void set_age(int _){age=_;}
	void set_first_name(string _){first_name=_;}
	void set_last_name(string _){last_name=_;}
	void set_standard(int _){standard=_;}
	int get_age(){return age;}
	string get_first_name(){return first_name;}
	string get_last_name(){return last_name;}
	int get_standard(){return standard;}
	string to_string(){return ::to_string(age)+","+first_name+","+last_name+","+::to_string(standard);}
};

int main() {
	int age, standard;
	string first_name, last_name;

	cin >> age >> first_name >> last_name >> standard;

	Student st;
	st.set_age(age);
	st.set_standard(standard);
	st.set_first_name(first_name);
	st.set_last_name(last_name);

	cout << st.get_age() << "\n";
	cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
	cout << st.get_standard() << "\n";
	cout << "\n";
	cout << st.to_string();

	return 0;
}