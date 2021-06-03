#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string text = "Litera H: \x48";
	string text2 = "Litera l: \154";
	string text3 = "Litera a: \x61";
	string text4 = "Litera 4: \x34";
	cout << text << endl;
	cout << text2 << endl;
	cout << text3 << endl;
	cout << text4 << endl;
	cout << "=======" << endl;
	string asd = "Litera P: \180";
	cout << asd << endl;
	cout << "Enter a char: ";
	char c;
	cin >> c;
	cout << "ASCII Value of " << c << " is " << int(c);
	cout << "ASCII hex value of " << c << " is " << hex << (int)c;

	stringstream ss;
	ss << hex << (int)c;
	string mystring = ss.str();
	cout << "w mystring jest: " << mystring << endl;
	cout << " Dlugosc mystring jest : " << mystring.size() << endl;
	cout << "Ostatni test: " << "\x61\x63" << endl;

	cout << "Test cudzyslowu: " << endl;
	string cudz = "123\"4";
	cout << cudz << endl;
	cout << cudz.size() << endl;
	
	return 0;
}
