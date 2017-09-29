#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string s = "fuck you";
	string r;
	r = s;
	cout<<"s: "<<s<<endl;
	cout<<"r: "<<r<<endl;
	s = "new";
	cout<<"s: "<<s<<endl;
	cout<<"r: "<<r<<endl;
	r = s;
	cout<<"r: "<<r<<endl;
	return 0;
}