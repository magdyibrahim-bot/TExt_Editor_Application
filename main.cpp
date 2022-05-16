#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header_p.h"
#include <conio.h>
#include <cctype>
#include <vector>

using namespace std;

void add (fstream& file, char name[100])
{
    char token[101];
    file_file:
        if (file.fail())
        {
            cerr<<"wrong file enter an existing one\n";
            goto file_file;
        }
        else{
            cout<<"open good\n";
            string item;
            cout<<"enter what u want: ";
            while(item==""){
                getline(cin,item);
                file<<item;
            }
        }
    file.close();
}
//--------------------------------------------------------------
void display (fstream& file, char name[100])
{
    char token[101];
    file_file:
        if (file.fail()){
            cerr<<"wrong file enter an existing one\n";
            goto file_file;
        }else{
            cout<<"open good\n";
        }
    cout << "the Text is : \n" ;
    while(!file.eof()){
        file.getline(token,100,'\n');
        cout<<token<<endl;
    }
    file.close();
}
//--------------------------------------------------------------
void empty_the_file(fstream& file, char name[100])
{
    file_file:
        string file1;
        if (file.fail()){
            cerr<<"wrong file enter an existing one\n";
            goto file_file;
        }else{
            file.close();
            cout<<"open good\n";
            file.open(file1, std::ofstream::out | std::ofstream::trunc);
        }

    file.close();
}
//--------------------------------------------------------------
void encrypt (fstream& file, char name[100])
{
    char token;
    file_file:
        if (file.fail()){
            cerr<<"wrong file enter an existing one\n";
            goto file_file;
        }else{
            cout<<"open good\n";
        }
    fstream second;
    second_file:
        string file2;
        cout<<"enter target file name: ";
        cin>>file2;
        second.open(file2);
        if (second.fail()){
            cerr<<"wrong file enter an existing one\n";
            goto second_file;
        }else{
            cout<<"open good\n";
            while (!file.eof())
            {
                file>>token;
                token+=1;
                second<<token;
            }

        }
    file.close();
    second.close();

}
//--------------------------------------------------------------
void decrypt(fstream& file, char name[100])
{
    char token;
    file_file:
        if (file.fail()){
            cerr<<"wrong file enter an existing one\n";
            goto file_file;
        }
        else
        {
            cout<<"open good\n";
        }
    fstream second;
    second_file:
    string file2;
    cout<<"enter target file name: ";
    cin>>file2;
    second.open(file2);
    if (second.fail())
    {
        cerr<<"wrong file enter an existing one\n";
        goto second_file;
    }
    else
    {
        cout<<"open good\n";
        while (!file.eof())
        {
            file>>token;
            token-=1;
            second<<token;
        }

    }
    file.close();
    second.close();
}
//--------------------------------------------------------------
void merge_file(fstream& file, char name[100])
{
    char filetwo[30], filetarget[30], ch;
    fstream fpstwo, fptarget;
    cout<<"Enter the Name of Second Source File: \n";
    cin >> filetwo;
    strcat_s(filetwo , ".txt");
    fpstwo.open(filetwo, fstream::in);
    if((!file) || (!fpstwo))
    {
        cout<<"\nError Occurred (First Source File)!\n";
    }
    else
    {
        cout<<"\nEnter the Name of Target File: \n";
        cin >> filetarget;
        strcat_s(filetarget , ".txt");
        fptarget.open(filetarget, fstream::out);
        if(!fptarget)
            cout<<"\nError Occurred (Target File)!\n";
        else
        {
            while(file>>noskipws>>ch)
                fptarget<<ch;
            fptarget<<"\n";
            while(fpstwo>>noskipws>>ch)
                fptarget<<ch;
            cout<<"\nContent of Two File Merged Successfully into Third!\n";
        }
    }
    fpstwo.close();
    fptarget.close();
    cout<<endl;
}
//--------------------------------------------------------------
void count_words(fstream& file, char name[100])
{
     string word ;
    int count = 0;
    while(!file.eof()){
        file >> word;
        count ++ ;
    }
    cout<<"Total words = "<<count << endl;
    file.close();
}
//--------------------------------------------------------------
void count_characters(fstream& file, char name[100])
{
    char ch;
    int count =0;
    while(!file.eof()){
        file >> ch;
        count ++ ;
    }
    cout<<"Total characters = "<< count << endl;
    file.close();
}
//--------------------------------------------------------------
void count_lines(fstream& file, char name[100])
{
    char ch, str[1000];
    int tot=0, i=0, tot_lines=0;
    while(file>>noskipws>>ch)
    {
       str[tot] = ch;
       tot++;
    }
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
    file.close();
}
//--------------------------------------------------------------
void search_word(fstream& file, char name[100])
{
    string wordToFind, line,input_file;
    while (1)
    {
        cin.ignore();
        int line_Number = 0, found = 0;
        cout << "\nWord to find:\n "; getline(cin, wordToFind); //getting the word

        if (file)
        {
            while (getline(file, line)) //reading file lines
            {
                line_Number++;
                int position = 0;
                for (int i = line.find(wordToFind); i < line.length(); i = i + position)
                {
                    position = line.find(wordToFind, i);
                    if (position != string::npos)
                    {
                        cout << endl << wordToFind << " is at line " << line_Number << ":" <<"at position"<< position << endl; // print the position of word.
                        found = 1;
                        break;
                    }
                    else break;
                }
            }
            if (found == 0)
            {
                cout << endl << wordToFind << " not in file" << endl;
            }
        }
        else
        {
            cout << endl << input_file << " not found" << endl; //file not available
        }
    }
    file.close();
}
//--------------------------------------------------------------
void number_of_word(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void upper_case(fstream& file, char name[100])
{
    char ch;
    vector<char> container;
    while(!file.eof() && !file.fail()){
        file.get(ch);
        container.push_back(toupper(ch));
    }
    file.close();
    file.open(name,ios::out);
    for(int i=0 ; i<container.size()-1 ; ++i){
        file.put(container[i]);
    }
    file.close();
    return;
}
//--------------------------------------------------------------
void lower_case(fstream& file, char name[100])
{
    char ch;
    vector<char> container;
    while(!file.eof() && !file.fail()){
        file.get(ch);
        container.push_back(tolower(ch));
    }
    file.close();
    file.open(name,ios::out);
    for(int i=0 ; i<container.size()-1 ; ++i){
        file.put(container[i]);
    }
    file.close();
    return;
}
//--------------------------------------------------------------
void first_caps(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void save(fstream& file, char name[100])
{
    char new_file[100] , ch ;
    fstream fptarget;


    cout <<
            "1 - save file content again in the same file \n" <<
            "2 - save file content in new file \n";

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

    }
    else if (option == 2)
    {
        cout<< "Enter name of the new file : ";
        cin >> new_file;
        strcat_s(new_file, ".txt");
        fptarget.open(new_file , fstream::out );
         if(!fptarget)
            cout<<"\nError Occurred (Target File)!\n";
        else
        {

        while(file>>noskipws>>ch)
                fptarget<<ch;
                cout<<"new file has been created" ;

        }

    }
    fptarget.close();
    file.close();

}





