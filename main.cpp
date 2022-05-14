#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
void add ()
{

}
//--------------------------------------------------------------
void display ()
{

}
//--------------------------------------------------------------
void empty_the_file()
{

}
//--------------------------------------------------------------
void encrypt ()
{
    string word;
    const int letterCount = 'z' - 'a' + 1;
    for (auto &letter: word) {
        if (!isalpha(letter)) {
            continue;
        }
        const bool isUpper = isupper(letter);
        const char baseOffset = isUpper ? 'A' : 'a';
        const auto distanceFromAlphabetStart = letter - baseOffset;
        letter = (baseOffset + letterCount - 1) - distanceFromAlphabetStart;
    }
}
//--------------------------------------------------------------
void decrypt()
{
    string word;
    const int letterCount = 'z' - 'a' + 1;
    for (auto &letter: word) {
        if (!isalpha(letter)) {
            continue;
        }
        const bool isUpper = isupper(letter);
        const char baseOffset = isUpper ? 'A' : 'a';
        const auto distanceFromAlphabetStart = letter - baseOffset;
        letter = (baseOffset + letterCount - 1) - distanceFromAlphabetStart;
    }
}
//--------------------------------------------------------------
void merge_file()
{
    char fileone[30], filetwo[30], filetarget[30], ch;
    fstream fpsone, fpstwo, fptarget;
    cout<<"Enter the Name of First Source File: \n";
    cin >> fileone;
    cout<<"Enter the Name of Second Source File: \n";
    cin >> filetwo;
    fpsone.open(fileone, fstream::in);
    fpstwo.open(filetwo, fstream::in);
    if((!fpsone) || (!fpstwo))
    {
        cout<<"\nError Occurred (First Source File)!\n";
    }
    else
    {
        cout<<"\nEnter the Name of Target File: \n";
        cin >> filetarget;
        fptarget.open(filetarget, fstream::out);
        if(!fptarget)
            cout<<"\nError Occurred (Target File)!\n";
        else
        {
            while(fpsone>>noskipws>>ch)
                fptarget<<ch;
            fptarget<<"\n";
            while(fpstwo>>noskipws>>ch)
                fptarget<<ch;
            cout<<"\nContent of Two File Merged Successfully into Third!\n";
        }
    }
    fpsone.close();
    fpstwo.close();
    fptarget.close();
    cout<<endl;
}
//--------------------------------------------------------------
void count_words()
{
   char filename[30], ch, str[1000];
   int tot=0, i=0, tot_word=0;
   ifstream fp;
   fp.open(filename, ifstream::in);
   while(fp>>noskipws>>ch)
   {
      str[tot] = ch;
      tot++;
   }
   fp.close();
   str[tot]='\0';
   while(str[i]!='\0')
   {
      if(str[i]=='\n')
      {
         if(str[i+1]!='\0' && str[i+1]!=' ')
            tot_word++;
         i++;
      }
      else if(str[i]!=' ')
         i++;
      else
      {
         if(str[i+1]!='\0' && str[i+1]!=' ')
            tot_word++;
         i++;
      }
   }
   cout<<endl<<"Total Words = "<<tot_word<<"\n";
   cout<<endl;
}
//--------------------------------------------------------------
void count_characters()
{
   char filename[30], ch;
   int tot=0;
   ifstream fp;
   fp.open(filename, ifstream::in);
   if(!fp)
   {
      cout<<endl<<"File doesn't exist or Access denied!\n";
   }
   while(fp>>noskipws>>ch)
    {
        tot++;
    }
   fp.close();
   cout<<endl<<"Total Characters = "<<tot<<"\n";
   cout<<endl;
}
//--------------------------------------------------------------
void count_lines()
{
   char filename[30], ch, str[1000];
   int tot=0, i=0, tot_lines=0;
   ifstream fp;
   fp.open(filename, ifstream::in);
   while(fp>>noskipws>>ch)
   {
      str[tot] = ch;
      tot++;
   }
   fp.close();
   str[tot]='\0';
   while(str[i]!='\0')
   {
      if(str[i]=='\n')
         tot_lines++;
      i++;
   }
   tot_lines++;
   cout<<endl<<"Total Number of Lines = "<<tot_lines<<"\n";
   cout<<endl;
}
//--------------------------------------------------------------
void search_word()
{

}
//--------------------------------------------------------------
void number_of_word()
{

}
//--------------------------------------------------------------
void upper_case()
{

}
//--------------------------------------------------------------
void lower_case()
{

}
//--------------------------------------------------------------
void first_caps()
{

}
//--------------------------------------------------------------
void save()
{

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
//--------------------------------------------------------------------
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
        add();
    }
    else if (option == 2)
    {
        display();
    }
    else if (option == 3)
    {
        empty_the_file();
    }
    else if (option == 4)
    {
        encrypt();
    }
    else if (option == 5)
    {
        decrypt();
    }
    else if (option == 6)
    {
        merge_file();
    }
    else if (option == 7)
    {
        count_words();
    }
    else if ( option== 8)
    {
        count_characters();
    }
    else if (option == 9)
    {
        count_lines();
    }
    else if (option == 10)
    {
        search_word();
    }
    else if (option == 11)
    {
        number_of_word();
    }
    else if (option == 12)
    {
        upper_case();
    }
    else if (option == 13)
    {
        lower_case();
    }
    else if (option == 14)
    {
        first_caps();
    }
    else if (option == 15)
    {
        save();
    }
    else if (option == 16) return 0;
    else
    {
        cout << "----Wrong input! try again----\n";
    }

    return 1;
}

int main()
{
    openDataFile();
    bool run = true;
	do
	{
		show_menu();
		run = take_input();

	} while (run);

	// close the text file
	dataFile.close();
}
