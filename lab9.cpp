// lab9.cpp 
// Nico Shober
//got help from jerimiah Vaskis

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

string getFileName() {
	string name;
	cout << "Enter filename: ";
	cin >> name;
	return name;
}



bool checkOpeness(string file, ifstream& inFile) {
	inFile.open(file); // Try to Open File
	if (!inFile.is_open()) {
		cout << "File: " << file << " cant be opened" << endl;
		inFile.close();
		inFile.clear();
		return false;
	}
	else {
		cout << "File: " << file << " was able to open." << endl;
		return true;
	}
}



int main() {

	string fileName, input_string;
	ifstream InFile;
	ofstream OutFile;
	map <string, int> map_object;
	fileName = getFileName();
	if (checkOpeness(fileName, InFile)) {
		while (!InFile.eof()) {
			InFile >> input_string;
			++map_object[input_string];
		}
		InFile.close();
		OutFile.open("output.txt");
		for (map<string, int>::iterator it = map_object.begin(); it != map_object.end(); ++it) {
			for (int i = 0; i < it->second; i++) {
				OutFile << it->first;
			}
		}
		// Closes the file
		OutFile.close();
	}
	return 0;
}