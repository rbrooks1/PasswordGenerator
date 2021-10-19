#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	string size;
	cout << "pick a password length: ";
	getline(cin, size);
	while (size.find_first_not_of("0123456789") != string::npos) {
		size = "";
		cout << "Not a number, pick again: ";
		cin >> size;
	}
	if (size.empty()) {
		size = "26";
	}

	char buffer[50];
	string pass = "";
	srand(time(NULL));
	for (int i = 0; i < stoi(size); i++) {
		sprintf(buffer, "%c", rand() % 93 + 33);
		pass += buffer;
	}

	cout << "Your new password is: " << pass << endl;

	return 1;
}