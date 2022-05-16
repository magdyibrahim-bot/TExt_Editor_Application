#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header_p.h"
#include <conio.h>
#include <cctype>

using namespace std;



void add (fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void display (fstream& file, char name[100])
{


}
//--------------------------------------------------------------
void empty_the_file(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void encrypt (fstream& file, char name[100])
{


}
//--------------------------------------------------------------
void decrypt(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void merge_file(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void count_words(fstream& file, char name[100])
{
     string word ;
    int count = 0;
    while(!file.eof()){
        file >> word;
        count++;
    }
    cout<< count << endl;
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
    cout<< count << endl;
}
//--------------------------------------------------------------
void count_lines(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void search_word(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void number_of_word(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void upper_case(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void lower_case(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void first_caps(fstream& file, char name[100])
{

}
//--------------------------------------------------------------
void save(fstream& file, char name[100])
{

}





