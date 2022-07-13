#pragma once
#define _CRT_SECURE_NO_WARNING
#include <iostream>
using namespace std;

//Copy block of memory
void* mmemcpy(void* dst, const void* src, size_t size);

//Move block of memory 
void* mmemmove(void* dst, const void* src, size_t size);


//Copy string
char* mstrcpy(char* dst, const char* src);


//Copy characters from string
char* mstrncpy(char* dst, const char* src, size_t size);


//Concatenate strings
char* mstrcat(char* dst, const char* src);


//Append characters from string
char* mstrncat(char* dst, const char* src, size_t size);


//Compare two blocks of memory
int mmemcmp(const void* dst, const void* src, size_t size);
//Compare two strings
int mstrcmp(const char* dst, const char* src);


//Compare two strings using locale
int mstrcoll(const char* dst, const char* src);


//Compare characters of two strings 
int mstrncmp(const char* dst, const char* src, size_t size);


//Transform string using locale
char* mstrxfrm(char* dst, const char* src, size_t size);

//Locate character in block of memory
void* mmemchr(const void* dst, int c, size_t size);


//Locate first occurrence of character in string
char* mstrchr(const char* dst, int c);


//Get span until character in string
size_t mstrcspn(const char* str1, const char* str2);

//Locate characters in string 
char* mstrpbrk(const char* dst, const char* src);


//Locate last occurrence of character in string
char* mstrrchr(const char*, int);


//Get span of character set in string
size_t mstrspn(const char* str1, const char* str2);


//Locate substring
char* mstrstr(const char* dst, const char* src);


//Split string into tokens
char* mstrtok(char* str, const char* delimiters);


//Fill block of memory
void* mmemset(void* dst, int c, size_t size);

//Get pointer to error message string
char* mstrerror(int errnum);


//Get string length
size_t mstrlen(const char* dst);



class mystring
{
private:
	char* str;
	int len;
	int capa;
	const int MAX_LEN = 100;



public:
	//(1) empty string constructor(default constructor)
	mystring();
	//(2) copy constructor
	mystring(const mystring& s);
	//(3) substring constructor
	mystring(const mystring& s, int start, int end);
	//(4)Copies the null-terminated character sequence (C-string) pointed by s.
	mystring(char* s);
	//Copies the first n characters from the array of characters pointed by s.
	mystring(char* s, int n);
	//(6) fill constructor
	mystring(int n, char c);
	//(destructor)  String destructor 
	~mystring();



	//operator=   String assignment 
	mystring& operator=(const mystring& s);
	mystring& operator=(char* s);
	
	//size  Return length of string 
	int size() const;
	//length  Return length of string
	int length() const;
	//max_size
	int max_size() const;
	//resize
	void resize(int n);
	//capacity  Return capacity of string
	int capacity() const;
	//reserve  Reserve capacity of string
	void reserve(int n);
	//clear  Clear string
	void clear();
	//empty  Return true if string is empty
	bool empty();
	//shrink_to_fit 
	void shrink_to_fit();
	//operator[]  Return character at index i
	char operator[](int i) const;
	//at
	char at(int i);
	//front  Return first character of string
	char front();
	//back  Return last character of string
	char back();
	//operator +=
	mystring& operator+=(const mystring& s);

	//append
	void append(const mystring& s);

	//push_bac00k
	void push_back(char c);

	
	//assign
	void assign(const mystring& s);

	//insert
	void insert(int pos, const mystring& s);

	//erase
	void erase(int pos, int n);

	//replace
	void replace(int pos, int n, const mystring& s);

	//swap
	void swap(mystring& s);

	//pop_back
	void pop_back();

	//data
	char* data() const;

	//copy
	void copy(const mystring& s);
	//find
	int find(const mystring& s, int pos = 0);
	//rfind
	int rfind(const mystring& s, int pos = 0);
	//find_first_of
	int find_first_of(const mystring& s, int pos = 0);
	//find_last_of
	int find_last_of(const mystring& s, int pos = 0);
	//find_first_not_of
	int find_first_not_of(const mystring& s, int pos = 0);
	//find_last_not_of
	int find_last_not_of(const mystring& s, int pos = 0);
	//substr
	mystring substr(int pos, int n = -1);

	//compare
	int compare(const mystring& s) const;
	
	friend mystring operator+(const mystring& s1, const mystring& s2);
	friend bool operator==(const mystring& s1, const mystring& s2);
	friend ostream& operator<<(ostream& os, const mystring& s);
	friend istream& operator>>(istream& is, mystring& s);
	friend void swap(mystring& s1, mystring& s2);
	friend istream& getline(istream& is, mystring& s);
};

//stoi
int stoi(const mystring& s);
//stol
long stol(const mystring& s);
//stoul
unsigned long stoul(const mystring& s);
//stoll
long long stoll(const mystring& s);
//stoull
unsigned long long stoull(const mystring& s);
//stof
float stof(const mystring& s);
//stod
double stod(const mystring& s);
//stold
long double stold(const mystring& s);
//to_string
mystring to_mstring(int i);



