#define _CRT_SECURE_NO_WARNINGS
#include "mystring.h"
#include <iostream>
using namespace std;

//stoi
int stoi(const mystring& s) {
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
};

long stol(const mystring& s) {
	long result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
};

unsigned long stoul(const mystring& s) {
	unsigned long result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
};

long long stoll(const mystring& s) {
	long long result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
};

unsigned long long stoull(const mystring& s) {
	unsigned long long result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
};

float stof(const mystring& s) {
	float result = 0;
	int i = 0;
	while (s[i] != '.') {
		result = result * 10 + (s[i] - '0');
		i++;
	}
	float d = 0.1;
	for (int j = i + 1; j < s.length(); j++) {
		result = result + d * (s[j] - '0');
		d /= 10;
	}
	return result;
};

double stod(const mystring& s) {
	double result = 0;
	int i = 0;
	while (s[i] != '.' && i < s.length()) {
		result = result * 10 + (s[i] - '0');
		i++;
	}
	double d = 0.1;
	for (int j = i + 1; j < s.length(); j++) {
		result = result + d * (s[j] - '0');
		d /= 10;
	}
	return result;
};

long double stold(const mystring& s) {
	long double result = 0;
	int i = 0;
	while (s[i] != '.') {
		result = result * 10 + (s[i] - '0');
		i++;
	}
	long double d = 0.1;
	for (int j = i + 1; j < s.length(); j++) {
		result = result + d * (s[j] - '0');
		d /= 10;
	}
	return result;
};

mystring to_mstring(int i) {
	mystring result;
	if (i == 0) {
		char c[] = "0";
		result = c;
	}
	else {
		while (i > 0) {
			char t = (char)((i % 10) + '0');
			mystring temp = mystring(1, t);
			result = temp + result;
			i /= 10;
		}
	}
	return result;
};

void* mmemcpy(void* dst, const void* src, size_t size)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < size; i++)
	{
		d[i] = s[i];
	}
	return dst;
}

void* mmemmove(void* dst, const void* src, size_t num) 
{
	char* d = (char*)dst;
	char* s = (char*)src;
	if (d < s) {
		for (size_t i = 0; i < num; i++)
		{
			d[i] = s[i];
		}
	}
	else {
		for (size_t i = num; i > 0; i--)
		{
			d[i - 1] = s[i - 1];
		}
	}
	return dst;
};



char* mstrcpy(char* dst, const char* src) {
	char* d = dst;
	char* s = (char*)src;
	while (*s != '\0') {
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return dst;
};

char* mstrncpy(char* dst, const char* src, size_t num) {
	char* d = dst;
	char* s = (char*)src;
	for (size_t i = 0; i < num; i++) {
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return dst;
};


char* mstrcat(char* dst, const char* src)
{
	char* d = dst;
	while (*d != '\0') {
		d++;
	}
	char* s = (char*)src;
	for (size_t i = 0; i < strlen(dst); i++)
	{
		*d = *s;
		d++;
		s++;
	}
	return dst;
}

char* mstrncat(char* dst, const char* src, size_t size)
{
	char* d = dst;
	while (*d != '\0') {
		d++;
	}
	char* s = (char*)src;
	for (size_t i = 0; i < size; i++)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return dst;
}
int mmemcmp(const void* dst, const void* src, size_t size)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < size; i++)
	{
		if (d[i] != s[i])
		{
			return d[i] - s[i];
		}
	}
	return 0;
}
int mstrcmp(const char* dst, const char* src)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < strlen(dst); i++)
	{
		if (d[i] != s[i])
		{
			return d[i] - s[i];
		}
	}
	return 0;
}
int mstrcoll(const char* dst, const char* src)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < strlen(dst); i++)
	{
		if (d[i] != s[i])
		{
			return d[i] - s[i];
		}
	}
	return 0;
}
int mstrncmp(const char* dst, const char* src, size_t size)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < size; i++)
	{
		if (d[i] != s[i])
		{
			return d[i] - s[i];
		}
	}
	return 0;
}
char* mstrxfrm(char* dst, const char* src, size_t size)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < size; i++)
	{
		d[i] = s[i];
	}
	return dst;
}

void* mmemchr(const void* dst, int c, size_t size)
{
	char* d = (char*)dst;
	for (size_t i = 0; i < size; i++)
	{
		if (d[i] == c)
		{
			return d + i;
		}
	}
	return nullptr;
}
char* mstrchr(const char* dst, int c)
{
	char* d = (char*)dst;
	for (size_t i = 0; i < strlen(dst); i++)
	{
		if (d[i] == c)
		{
			return d + i;
		}
	}
	return nullptr;
}

size_t mstrcspn(const char* str1, const char* str2) {
	size_t i = 0;
	size_t j = 0;
	size_t result = 0;
	while (str1[i] != '\0') {
		j = 0;
		while (str2[j] != '\0') {
			if (str1[i] == str2[j]) {
				result = i;
				return result;
			}
			j++;
		}
		i++;
	}
	return result;
};

char* mstrpbrk(const char* dst, const char* src)
{
	size_t i = 0;
	size_t j = 0;
	while (dst[i] != '\0') {
		j = 0;
		while (src[j] != '\0') {
			if (dst[i] == src[j]) {
				return (char*)(dst + i);
			}
			j++;
		}
		i++;
	}
	return nullptr;
}
char* mstrrchr(const char* str, int character) {
	char* d = (char*)str;
	for (size_t i = strlen(str); i > 0; i--)
	{
		if (d[i] == character)
		{
			return d + i;
		}
	}
	return nullptr;
};

size_t mstrspn(const char* str1, const char* str2) {
	size_t i = 0;
	size_t j = 0;
	size_t result = 0;
	while (str1[i] != '\0') {
		j = 0;
		while (str2[j] != '\0') {
			if (str1[i] == str2[j]) {
				result ++;
			}
			j++;
		}
		i++;
	}
	return result;
};

char* mstrstr(const char* dst, const char* src)
{
	char* d = (char*)dst;
	char* s = (char*)src;
	for (size_t i = 0; i < strlen(dst); i++)
	{
		if (d[i] == s[0])
		{
			size_t j = 0;
			for (size_t k = i; k < strlen(dst); k++)
			{
				if (d[k] == s[j])
				{
					j++;
					if (s[j] == '\0')
					{
						return d + i;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	return nullptr;
}
char* mstrtok(char* str, const char* delimiters) {
	static char* next = nullptr;
	if (str != nullptr)
	{
		next = str;
	}
	if (next == nullptr)
	{
		return nullptr;
	}
	char* token = next;
	next = mstrpbrk(next, delimiters);
	if (next != nullptr)
	{
		*next = '\0';
		next++;
	}
	return token;
};
void* mmemset(void* dst, int c, size_t size)
{
	char* d = (char*)dst;
	for (size_t i = 0; i < size; i++)
	{
		d[i] = c;
	}
	return dst;
}
char* mstrerror(int errnum)
{
	return strerror(errnum);
}
size_t mstrlen(const char* dst)
{
	char* d = (char*)dst;
	size_t i = 0;
	while (d[i] != '\0')
	{
		i++;
	}
	return i;
}


//(1) empty string constructor(default constructor)
mystring::mystring() {
	str = NULL;
	len = 0;
};


//(2) copy constructor
mystring::mystring(const mystring& s) {
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
};
//(3) substring constructor
mystring::mystring(const mystring& s, int start, int end) {
	len = end - start;
	str = new char[len + 1];
	for (int i = 0; i < len; i++) {
		str[i] = s.str[start + i];
	}
	str[len] = '\0';
};
//(4)Copies the null-terminated character sequence (C-string) pointed by s.
mystring::mystring(char* s) {
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
};
//Copies the first n characters from the array of characters pointed by s.
mystring::mystring(char* s, int n) {
	len = n;
	str = new char[n + 1];
	for (int i = 0; i < n; i++) {
		str[i] = s[i];
	}
	str[n] = '\0';

};

//(6) fill constructor
mystring::mystring(int n, char c) {
	str = new char[n + 1];
	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
	str[n] = '\0';
	len = n;
};

//(destructor)  String destructor 
mystring::~mystring() {
	delete[] str;
};

	
	
//operator=   String assignment 
mystring& mystring::operator=(const mystring& s) {
	if (this != &s) {
		delete[] str;
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	return *this;
};

mystring& mystring::operator=(char* s) {
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
};

//size  Return length of string 
int mystring::size() const {
	return len;
};
//length  Return length of string
int mystring::length() const {
	return len;
};
//max_size
int mystring::max_size() const {
	return MAX_LEN;
};
	
//resize
void mystring::resize(int n) {
	if (n > len) {
		char* temp = new char[n + 1];
		for (int i = 0; i < len; i++) {
			temp[i] = str[i];
		}
		delete[] str;
		str = temp;
		len = n;
		str[n] = '\0';
	}
	else if (n < len) {
		char* temp = new char[n + 1];
		for (int i = 0; i < n; i++) {
			temp[i] = str[i];
		}
		delete[] str;
		str = temp;
		len = n;
		str[n] = '\0';
	}
};

//capacity  Return capacity of string
int mystring::capacity() const {
	return capa;
};


	
//reserve  Reserve capacity of string
void mystring::reserve(int n) {
	capa = n;
};
//clear  Clear string
void mystring::clear() {
	delete[] str;
	str = NULL;
	len = 0;
};
//empty  Return true if string is empty
bool mystring::empty() {
	if (len == 0) {
		return true;
	}
	else {
		return false;
	}
};
//shrink_to_fit 
void mystring::shrink_to_fit() {
	capa = len;
};

	
//operator[]  Return character at index i
char mystring::operator[](int i) const{
	return str[i];
};
//at
char mystring::at(int i) {
	return str[i];
};
//front  Return first character of string
char mystring::front() {
	return str[0];
};
//back  Return last character of string
char mystring::back() {
	return str[len - 1];
};

//operator +=
mystring& mystring::operator+=(const mystring& s) {
	char* temp = new char[len + s.len + 1];
	for (int i = 0; i < len; i++) {
		temp[i] = str[i];
	}
	for (int i = 0; i < s.len; i++) {
		temp[i + len] = s.str[i];
	}
	temp[len + s.len] = '\0';
	delete[] str;
	str = temp;
	len = len + s.len;
	return *this;
};

//append
void mystring::append(const mystring& s) {
	char* temp = new char[len + s.len + 1];
	for (int i = 0; i < len; i++) {
		temp[i] = str[i];
	}
	for (int i = 0; i < s.len; i++) {
		temp[i + len] = s.str[i];
	}
	temp[len + s.len] = '\0';
	delete[] str;
	str = temp;
	len = len + s.len;
};

//push_back
void mystring::push_back(char c) {
	char* temp = new char[len + 2];
	for (int i = 0; i < len; i++) {
		temp[i] = str[i];
	}
	temp[len] = c;
	temp[len + 1] = '\0';
	delete[] str;
	str = temp;
	len++;
};

//assign
void mystring::assign(const mystring& s) {
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
};

//insert
void mystring::insert(int pos, const mystring& s) {
	char* temp = new char[len + s.len + 1];
	for (int i = 0; i < pos; i++) {
		temp[i] = str[i];
	}
	for (int i = 0; i < s.len; i++) {
		temp[i + pos] = s.str[i];
	}
	for (int i = pos; i < len; i++) {
		temp[i + s.len] = str[i];
	}
	temp[len + s.len] = '\0';
	delete[] str;
	str = temp;
	len = len + s.len;
};
	
//erase
void mystring::erase(int pos, int n) {
	char* temp = new char[len - n + 1];
	for (int i = 0; i < pos; i++) {
		temp[i] = str[i];
	}
	for (int i = pos + n; i < len; i++) {
		temp[i - n] = str[i];
	}
	temp[len - n] = '\0';
	delete[] str;
	str = temp;
	len = len - n;
};
	
//replace
void mystring::replace(int pos, int n, const mystring& s) {
	char* temp = new char[len + s.len - n + 1];
	char* p = temp;
	for (int i = 0; i < pos; i++) {
		*p = str[i];
		p++;
	}
	for (int i = 0; i < s.len; i++) {
		*p = s.str[i];
		p++;
	}
	for (int i = pos + n; i < len; i++) {
		*p = str[i];
		p++;
	}
	*p = '\0';
	delete[] str;
	str = temp;
	len = len + s.len - n;
};
	
//swap
void mystring::swap(mystring& s) {
	char* temp = str;
	str = s.str;
	s.str = temp;
	int temp2 = len;
	len = s.len;
	s.len = temp2;
};
	
//pop_back
void mystring::pop_back() {
	char* temp = new char[len];
	for (int i = 0; i < len - 1; i++) {
		temp[i] = str[i];
	}
	temp[len - 1] = '\0';
	delete[] str;
	str = temp;
	len--;
};

//data
char* mystring::data() const{
	return str;
};
	
//copy
void mystring::copy(const mystring& s) {
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
};
//find
int mystring::find(const mystring& s, int pos) {
	for (int i = pos; i < len; i++) {
		if (str[i] == s.str[0]) {
			for (int j = 1; j < s.len; j++) {
				if (str[i + j] != s.str[j]) {
					break;
				}
				if (j == s.len - 1) {
					return i;
				}
			}
		}
	}
	return -1;
};
//rfind
int mystring::rfind(const mystring& s, int pos) {
	for (int i = len - 1; i >= pos; i--) {
		for (int j = 0; j < s.len; j++) {
			if (str[i - j] != s.str[s.len - 1 - j]) {
				break;
			}
			if (j == s.len - 1) {
				return i - s.len + 1;
			}
		}
	}
	return -1;
};
//find_first_of
int mystring::find_first_of(const mystring& s, int pos) {
	for (int i = pos; i < len; i++) {
		for (int j = 0; j < s.len; j++) {
			if (str[i] == s.str[j]) {
				return i;
			}
		}
	}
	return -1;
};
//find_last_of
int mystring::find_last_of(const mystring& s, int pos) {
	for (int i = len - 1; i >= pos; i--) {
		for (int j = 0; j < s.len; j++) {
			if (str[i] == s.str[j]) {
				return i;
			}
		}
	}
	return -1;
};
//find_first_not_of
int mystring::find_first_not_of(const mystring& s, int pos) {
	for (int i = pos; i < len; i++) {
		for (int j = 0; j < s.len; j++) {
			if (str[i] == s.str[j]) {
				break;
			}
			if (j == s.len - 1) {
				return i;
			}
		}
	}
	return -1;
};
//find_last_not_of
int mystring::find_last_not_of(const mystring& s, int pos) {
	for (int i = len - 1; i >= pos; i--) {
		for (int j = 0; j < s.len; j++) {
			if (str[i] == s.str[j]) {
				break;
			}
			if (j == s.len - 1) {
				return i;
			}
		}
	}
	return -1;
};
//substr
mystring mystring::substr(int pos, int n) {
	if (n == -1) {
		n = len - pos;
	}
	mystring s;
	s.len = n;
	s.str = new char[n + 1];
	for (int i = 0; i < n; i++) {
		s.str[i] = str[i + pos];
	}
	s.str[n] = '\0';
	return s;
};

//compare
int mystring::compare (const mystring& s) const {
	if (len < s.len) {
		return -1;
	}
	else if (len > s.len) {
		return 1;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (str[i] < s.str[i]) {
				return -1;
			}
			else if (str[i] > s.str[i]) {
				return 1;
			}
		}
		return 0;
	}
};		



	
//Non - member function overloads
//operator+
mystring operator+(const mystring& s1, const mystring& s2) {
	mystring s;
	s.len = s1.len + s2.len;
	s.str = new char[s.len + 1];
	for (int i = 0; i < s1.len; i++) {
		s.str[i] = s1.str[i];
	}
	for (int i = 0; i < s2.len; i++) {
		s.str[i + s1.len] = s2.str[i];
	}
	s.str[s.len] = '\0';
	return s;
}

//relational operators
bool operator==(const mystring& s1, const mystring& s2) {
	return s1.compare(s2) == 0;
}

//swap
void swap(mystring& s1, mystring& s2) {
	mystring temp = s1;
	s1 = s2;
	s2 = temp;
}

//operator>>
istream& operator>>(istream& is, mystring& s) {
	char temp[100];
	is >> temp;
	s.assign(temp);
	return is;
}

//operator <<
ostream& operator<<(ostream& os, const mystring& s) {
	os << s.data();
	return os;
}

//getline
istream& getline(istream& is, mystring& s) {
	char temp[100];
	is.getline(temp, 100);
	s.assign(temp);
	return is;
}
