#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string str = "Now this is a new text";

	ofstream out;
	ifstream in;
	out.open("file.txt");
	out<<str<<endl;
	out.close();

	in.open("file.txt");
	getline(in,str);
	cout<<str<<endl;
	in.close();
	return 0;
}
