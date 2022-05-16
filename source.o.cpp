#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <regex>
#include <fstream>
#include "Header_p.h"
#include<vector>
using namespace std;


 // the text file to store and read from it
fstream dataFile;

// name of the file
char name[100];

// take the text file name and try to open it
void openDataFile() {

	cout << "Enter an exist data file name:\n";
	cin >> name;
	strcat_s(name, ".txt");

	// open in read mode and don't create new files if doesn't exist
	dataFile.open(name, ios_base::binary | ios_base::out | ios_base::in);

	// handle any wrong names or files doesn't exist
	while (!dataFile.is_open())
	{
		cout << "----Couldn't open the file. try again----\n";
		cout << "Do you want to create new file ?  \n(y) to create new one.  (n) to try opening file again. \n";
		char choice;
		cin >> choice;
		// create a new file and open it in write mode
		if (choice == 'y')
		{
			cout << "Enter the new file name:\n";
			cin >> name;
			strcat_s(name, ".txt");
			dataFile.open(name, ios::app);
		}
		else
		{	// try to open exist file again
			cout << "Enter an exist data file name:\n";
			cin >> name;
			strcat_s(name, ".txt");
			dataFile.open(name, ios_base::binary | ios_base::out | ios_base::in);
		}
	}

	cout << "Opened file succesfully.\n";
}

//--------------------------------------------------------------
void show_menu()
{
    cout<<
    "1.  Add new text to the end of the file\n" <<
    "2.  Display the content of the file\n" <<
    "3.  Empty the file\n" <<
    "4.  Encrypt the file content\n" <<
    "5.  Decrypt the file content\n" <<
    "6.  Merge another file\n" <<
    "7.  Count the number of words in the file\n" <<
    "8.  Count the number of characters in the file\n" <<
    "9.  Count the number of lines in the file\n" <<
    "10. Search for a word in the file\n" <<
    "11. Count the number of times a word exists in the file\n" <<
    "12. Turn the file content to upper case\n" <<
    "13. Turn the file content to lower case\n" <<
    "14. Turn file content to 1st caps (1st char of each word is capital)\n"<<
    "15. Save\n" <<
    "16. Exit\n" << endl;
}

//_____________________________________________________________________________

bool take_input()
{
    cout << "enter an option: \n";
    int option;

    cin >> option;
    // handle any non integer inputs
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "----Wrong input! enter numbers only. try again----\n";
        cin >> option;
    }
    if (option == 1)
    {
        add(dataFile , name);
    }
    else if (option == 2)
    {
        display(dataFile , name);
    }
    else if (option == 3)
    {
        empty_the_file(dataFile , name);
    }
    else if (option == 4)
    {
        encrypt(dataFile , name);
    }
    else if (option == 5)
    {
        decrypt(dataFile , name);
    }
    else if (option == 6)
    {
        merge_file(dataFile , name);
    }
    else if (option == 7)
    {
        count_words(dataFile , name);
    }
    else if ( option== 8)
    {
        count_characters(dataFile , name);
    }
    else if (option == 9)
    {
        count_lines(dataFile , name);
    }
    else if (option == 10)
    {
        search_word(dataFile , name);
    }
    else if (option == 11)
    {
        number_of_word(dataFile , name);
    }
    else if (option == 12)
    {
        upper_case(dataFile , name);
    }
    else if (option == 13)
    {
        lower_case(dataFile , name);
    }
    else if (option == 14)
    {
        first_caps(dataFile , name);
    }
    else if (option == 15)
    {
        save(dataFile , name);
    }
    else if (option == 16) return 0;
    else
    {
        cout << "----Wrong input! try again----\n";
    }

    return 1;
}

//______________________________________________________________________________________

int main()
{
    openDataFile();

    show_menu();
    take_input();
	// close the text file
	dataFile.close();
}
