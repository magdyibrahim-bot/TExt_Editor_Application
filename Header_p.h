#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void search_word(fstream& file, char name[100]);
//--------------------------------------------------------------
void number_of_word(fstream& file, char name[100]);
//--------------------------------------------------------------
void upper_case(fstream& file, char name[100]);
//--------------------------------------------------------------
void lower_case(fstream& file, char name[100]);
//--------------------------------------------------------------
void first_caps(fstream& file, char name[100]);
//--------------------------------------------------------------
void save(fstream& file, char name[100]);
//--------------------------------------------------------------
void add (fstream& file, char name[100]);
//--------------------------------------------------------------
void display (fstream& file, char name[100]);
//--------------------------------------------------------------
void empty_the_file(fstream& file, char name[100]);
//--------------------------------------------------------------
void encrypt (fstream& file, char name[100]);
//--------------------------------------------------------------
void decrypt(fstream& file, char name[100]);
//--------------------------------------------------------------
void merge_file(fstream& file, char name[100]);
//--------------------------------------------------------------
void count_characters(fstream& file, char name[100]);
//--------------------------------------------------------------
void count_lines(fstream& file, char name[100]);
//--------------------------------------------------------------
void count_words(fstream& file, char name[100]);


