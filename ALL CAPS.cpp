//Robert Colburn
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string fileName, choice;
	char character;
	int nameLength;
	//Creates a new file for writing the converted text into.
	outputFile.open("temp.txt");
	cout << "==================================================================================\n";
	cout << "Welcome to the ALL CAPS program.\n";
	cout << "This program will read a text file, convert all letters to capital letters,\n";
	cout << "and will display the results.\n";
	cout << "This process involves duplicating a text file and deleting the original.\n";
	cout << "==================================================================================\n";
	cout << "Are you sure you want to proceed?\n";
	cout << "Type 'Y' for YES or 'N' for NO.\n";
	cin >> choice;
	cin.ignore();
	if (choice == "N" || choice == "n" || choice == "no" || choice == "NO" || choice == "No")
		exit(0);
	do
	{
		cout << endl;
		cout << "Enter the file name:\n";
		getline(cin, fileName);
		//If the user does not include the file extension, it is appended.
		if (fileName.find(".txt") == string::npos)
		{
			fileName.append(".txt");
		}
		inputFile.open(fileName);
		if (!inputFile)
		{
			cout << "Invalid file name.\n";
		}
		//Loops if the file name is invalid.
	} while (!inputFile);
	cout << endl;
	cout << "Results:\n";
	cout << "==================================================================================\n";
	//Displays the results of the case conversions.
	while (inputFile.get(character))
	{
		//Only displays the letters that were read, excludes any punctuation or whitespace characters.
		/*
		The static cast was included in the if statement because 
		of a bug I was having when I copied and pasted text into the file.
		*/
		if (isalpha(static_cast<char>(character)) == true)
		{
			cout << "Letter " << character << " has been converted to " <<
				static_cast<char>(toupper(character)) << endl;
		}
		character = toupper(character);
		outputFile << character;
	}
	cout << "==================================================================================\n";
	cout << endl;
	inputFile.close();
	nameLength = fileName.length();
	const char* oldFile = new char[nameLength + 1];
	//Converts the file name string object into a C-string.
	oldFile = fileName.c_str();
	remove(oldFile);
	outputFile.close();
	//Attempts to rename the new file that was created.
	if (rename("temp.txt", oldFile) == false)
	{
		cout << "The file was successfully renamed.\n";
		cout << "The ALL CAPS operation was a success!\n";
	}
	else
		cout << "The was an error with renaming the temporary file.\n";
	cin.get();
	return 0;
}