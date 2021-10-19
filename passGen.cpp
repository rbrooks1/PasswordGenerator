#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

// split function to remove all spaces from a string
string remSpaces(string s) {
	string newString = "";
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			newString = newString + s[i];
		}
	}

	return newString;
}

// main function
int main() {
	// get password length from user
	string size;
	cout << "pick a password length: ";
	getline(cin, size);
	size = remSpaces(size);
	
	// ensure password length is only digits
	while (size.find_first_not_of("0123456789") != string::npos) {
		size = "";
		cout << "Not a number, pick again: ";
		getline(cin, size);
		size = remSpaces(size);
	}
	// default to 26 if size is empty
	if (size.empty()) {
		size = "26";
	}

	// create password
	char buffer[50];
	string pass = "";
	srand(time(NULL));
	for (int i = 0; i < stoi(size); i++) {
		sprintf_s(buffer, "%c", rand() % 93 + 33);
		pass += buffer;
	}

	// show password to user and prompt for program end
	cout << "Your new password is: " << pass << endl;
	cout << endl << "Press any key to exit" << endl;
	getchar();
	return 1;
}