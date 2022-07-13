#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "mystring.h"

using namespace std;

struct {
	char name[40];
	int age;
} person, person_copy;


int main() {
	puts("----------------------------------------");
	cout << "对cstring里面的基本功能进行测试：" << endl;
	//1.memcpy 内存拷贝
	cout << "1.memcpy 内存拷贝：" << endl;
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	mmemcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;
	/* using memcpy to copy structure: */
	mmemcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	//2.memmove 内存移动
	cout << "2.memmove 内存移动：" << endl;
	char str01[] = "memmove can be very useful......";
	mmemmove(str01 + 20, str01 + 15, 11);
	puts(str01);

	//3.strcpy 字符串拷贝
	cout << "3.strcpy 字符串拷贝：" << endl;
	char str001[] = "Sample string";
	char str002[40];
	char str003[40];
	mstrcpy(str002, str001);
	mstrcpy(str003, "copy successful");
	printf("str001: %s\nstr002: %s\nstr003: %s\n", str001, str002, str003);
	
	//4.strncpy 字符串拷贝，限制长度
	cout << "4.strncpy 字符串拷贝，限制长度：" << endl;
	char str11[] = "To be or not to be";
	char str12[40];
	char str13[40];
	/* copy to sized buffer: */
	mstrncpy(str12, str11, sizeof(str11));
	/* partial copy (only 5 chars): */
	mstrncpy(str13, str12, 5);
	str13[5] = '\0';   /* null character manually added */
	puts(str11);
	puts(str12);
	puts(str13);

	//5.strcat 字符串拼接
	cout << "5.strcat 字符串拼接：" << endl;
	char str20[80];
	mstrcpy(str20, "these ");
	mstrcat(str20, "strings ");
	mstrcat(str20, "are ");
	mstrcat(str20, "concatenated.");
	puts(str20);
	
	//6.strncat 字符串拼接，限制长度
	cout << "6.strncat 字符串拼接，限制长度：" << endl;
	char str21[20];
	char str22[20];
	mstrcpy(str21, "To be ");
	mstrcpy(str22, "or not to be");
	mstrncat(str21, str22, 6);
	puts(str21);

	//7.memcmp 比较内存区域
	cout << "7.memcmp 比较内存区域：" << endl;
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = mmemcmp(buffer1, buffer2, sizeof(buffer1));
	if (n > 0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n < 0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	
	//8.strcmp 比较字符串
	cout << "8.strcmp 比较字符串：" << endl;
	char key[] = "apple";
	char buffer0[80];
	mstrcpy(buffer0, "apple");
	if (mstrcmp(key, buffer0) == 0) printf("%s is the same as %s.\n", key, buffer0);
	else printf("%s is not the same as %s.\n", key, buffer0);
	
	//9.strcoll 比较字符串，根据locale
	cout << "9.strcoll 比较字符串，根据locale：" << endl;
	char str31[] = "apple";
	char str32[] = "banana";
	int nn;
	nn = mstrcoll(str31, str32);
	if (nn > 0) printf("'%s' is greater than '%s'.\n", str31, str32);
	else if (nn < 0) printf("'%s' is less than '%s'.\n", str31, str32);
	else printf("'%s' is the same as '%s'.\n", str31, str32);
	
	//10.strncmp 比较字符串，限制长度
	cout << "10.strncmp 比较字符串，限制长度：" << endl;
	char str41[] = "apple";
	char str42[] = "banana";
	int n0;
	n0 = mstrncmp(str41, str42, 3);
	if (n0 > 0) printf("'%s' is greater than '%s'.\n", str41, str42);
	else if (n0 < 0) printf("'%s' is less than '%s'.\n", str41, str42);
	else printf("'%s' is the same as '%s'.\n", str41, str42);
	
	//11.strxfrm 转换字符串
	cout << "11.strxfrm 转换字符串：" << endl;
	char str51[] = "apple";
	char str52[80];
	mstrxfrm(str52, str51, sizeof(str52));
	puts(str52);
	
	//12.memchar 查找内存中的字符
	cout << "12.memchar 查找内存中的字符：" << endl;
	char* pch;
	char str38[] = "Example string";
	pch = (char*)mmemchr(str38, 'p', strlen(str38));
	if (pch != NULL)
		printf("'p' found at position %d.\n", pch - str38 + 1);
	else
		printf("'p' not found.\n");
	
	//13.strchr 查找字符串中的字符
	cout << "13.strchr 查找字符串中的字符：" << endl;
	char str37[] = "This is a sample string";
	char* pch0;
	printf("Looking for the 's' character in \"%s\"...\n", str37);
	pch0 = strchr(str37, 's');
	while (pch0 != NULL)
	{
		printf("found at %d\n", pch0 - str37 + 1);
		pch0 = mstrchr(pch0 + 1, 's');
	}
	
	// 14.strcspn 查找字符串中包含在keys里的第一个字符
	cout << "14.strcspn 查找字符串中包含在keys里的第一个字符：" << endl;
	char str27[] = "fcba73";
	char keys[] = "1234567890";
	int i = mstrcspn(str27, keys);
	printf("The first number in str is at position %d.\n", i + 1);
	
	// 15.strpbrk 查找字符串中包含在keys里的字符
	cout << "15.strpbrk 查找字符串中包含在keys里的字符：" << endl;
	char str28[] = "This is a sample string";
	char key1[] = "aeiou";
	char* pch1;
	printf("Vowels in '%s': ", str28);
	pch1 = mstrpbrk(str28, key1);
	while (pch1 != NULL)
	{
		printf("%c ", *pch1);
		pch1 = mstrpbrk(pch1 + 1, key1);
	}
	printf("\n");
	
	// 16.strrchr 查找字符串中的字符最后出现的位置
	cout << "16.strrchr 查找字符串中的字符最后出现的位置：" << endl;
	char str24[] = "This is a sample string";
	char* pch2;
	pch2 = mstrrchr(str24, 's');
	printf("Last occurence of 's' found at %d \n", pch2 - str24 + 1);

	// 17.strspn 查找字符串中包含在keys里的字符数
	cout << "17.strspn 查找字符串中包含在keys里的字符数：" << endl;

	char strtext[] = "129th";
	char cset[] = "1234567890";
	i = mstrspn(strtext, cset);
	printf("The initial number has %d digits.\n", i);
	
	// 18.strstr 查找字符串中的子串
	cout << "18.strstr 查找字符串中的子串：" << endl;
	char str35[] = "This is a simple string";
	char* pch3;
	pch3 = mstrstr(str35, "simple");
	if (pch3 != NULL)
		strncpy(pch3, "sample", 6);
	puts(str35);
	
	// 19.strtok 分割字符串
	cout << "19.strtok 分割字符串：" << endl;
	char str36[] = "This, a sample string.";
	char* pch4;
	printf("Splitting string \"%s\" into tokens:\n", str36);
	pch4 = mstrtok(str36, ",");
	while (pch4 != NULL)
	{
		printf("%s\n", pch4);
		pch4 = mstrtok(NULL, ",");
	}

	// 20.memset 将内存中的字符设置为指定值
	cout << "20.memset 将内存中的字符设置为指定值：" << endl;
	char str44[] = "almost every programmer should know memset!";
	mmemset(str44, '-', 6);
	puts(str44);
	
	// 21.strerror 返回错误信息
	cout << "21.strerror 返回错误信息：" << endl;
	FILE* pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error opening file unexist.ent: %s\n", mstrerror(errno));
	
	// 22.strlen 返回字符串的长度
	cout << "22.strlen 返回字符串的长度：" << endl;
	char str45[] = "This is a sample string";
	printf("The length of \"%s\" is %d.\n", str45, mstrlen(str45));
	
	puts("----------------------------------------");
	cout << "对常用string库函数实现的测试：" << endl;
	//1.stoi
	char str1[] = "123";
	i = stoi(str1);
	printf("The integer value of \"%s\" is %d.\n", str1, i);
	
	//2.stol
	long l;
	l = stol(str1);
	printf("The long value of \"%s\" is %ld.\n", str1, l);
	
	//3.stoul
	unsigned long ul;
	ul = stoul(str1);
	printf("The unsigned long value of \"%s\" is %lu.\n", str1, ul);
	
	//4.stoll
	long long ll;
	ll = stoll(str1);
	printf("The long long value of \"%s\" is %lld.\n", str1, ll);
	
	//5.stoull
	unsigned long long ull;
	ull = stoull(str1);
	printf("The unsigned long long value of \"%s\" is %llu.\n", str1, ull);
	
	//6.stof
	char str2[] = "123.456";
	float f;
	f = stof(str2);
	printf("The float value of \"%s\" is %f.\n", str2, f);
	
	//7.stod
	double d;
	d = stod(str2);
	printf("The double value of \"%s\" is %f.\n", str2, d);
	
	//8.stold
	long double ld;
	ld = stold(str2);
	printf("The long double value of \"%s\" is %Lf.\n", str2, ld);
		
	//9.to_string
	int x = 123;
	mystring s = to_mstring(x);
	cout << "The string value of " << x << " is " << s << endl;
	puts("----------------------------------------");
	//mystring 类
	cout << "对mystring类的属性函数的实现进行测试：" << endl;
	
	//(1) empty string constructor (default constructor)
	char str[] = "123";
	mystring s1;
	s1 = str;
	//	(2) copy constructor
	mystring s2(s1);
	//	(3) substring constructor
	mystring s3(s1, 1, 2);
	//	(4) from c - string
	mystring s4 (str);
	//	(5) from buffer
	char buf[] = "123";
	mystring s5( buf, strlen(buf) );
	//	(6) fill constructor
	mystring s6(10, 'a');
	//size
	printf("s1 size is %d.\n", s1.size());
	//	length
	printf("s1 length is %d.\n", s1.length());
	//	max_size
	printf("s1 max_size is %d.\n", s1.max_size());
	//	resize
	s1.resize(10);
	//	capacity
	printf("s1 capacity is %d.\n", s1.capacity());
	//	reserve
	s1.reserve(10);
	//	clear
	s1.clear();
	//	empty
	printf("s1 empty is %d.\n", s1.empty());
	//	shrink_to_fit
	s1.shrink_to_fit();
	//	Element access :
	cout << "对mystring中元素访问的测试：" << endl;
	//operator[]
	s1 = (char*)"abcdefg";
	cout << "s1[0] is " << s1[0] << endl;
	//	at
	cout << "s1.at(0) is " << s1.at(0) << endl;
	//	back
	cout << "s1.back() is " << s1.back() << endl;
	//	front
	cout << "s1.front() is " << s1.front() << endl;

	puts("----------------------------------------");
	//Modifiers:
	cout << "对mystring中操作函数的测试：" << endl;
	//operator+=
	s1 += s2;
	cout << "s1 += s2 is " << s1 << endl;
	//	append
	s1.append(str);
	cout << "s1.append(str) is " << s1 << endl;
	//	push_back
	//	Append character to string(public member function)
	s1.push_back('a');
	cout << "s1.push_back('a') is " << s1 << endl;
	//	assign
	//	Assign content to string(public member function)
	s1.assign(str);
	cout << "s1.assign(str) is " << s1 << endl;
	
	//	insert
	//	Insert into string(public member function)
	s1.insert(0, str);
	cout << "s1.insert(0, str) is " << s1 << endl;
	
	//	erase
	//	Erase characters from string(public member function)
	s1.erase(0, 2);
	cout << "s1.erase(0, 2) is " << s1 << endl;
	//	replace
	//	Replace portion of string(public member function)

	s1.replace(0, 2, s2);
	cout << "s1.replace(0, 2, str) is " << s1 << endl;
	//	swap
	//	Swap string values(public member function)
	s1.swap(s2);
	cout << "s1.swap(s2) is " << s1 << endl;
	//	pop_back
	//	Delete last character(public member function)
	s1.pop_back();
	cout << "s1.pop_back() is " << s1 << endl;
	puts("----------------------------------------");
	//	String operations :
	cout << "对mystring中字符串操作函数的测试：" << endl;
	//data
	//	Get string data(public member function)
	cout << "s1.data() is " << s1.data() << endl;
	//	copy
	//	Copy sequence of characters from string(public member function)
	char buf1[10] = "abc";
	mystring s7(buf1, strlen(buf1));
	s1.copy(s7);
	cout << "s1.copy(s7) is " << s1 << endl;
	cout << "s1 is " << s1 << " s7 is " << s7 << endl;
	//	find
	//	Find content in string(public member function)
	cout << "s1.find(s7) is " << s1.find(s7) << endl;
	//	rfind
	//	Find last occurrence of content in string(public member function)
	cout << "s1.rfind(s7) is " << s1.rfind(s7) << endl;
	//	find_first_of
	//	Find character in string(public member function)
	cout << "s1.find_first_of(s7) is " << s1.find_first_of(s7) << endl;
	//	find_last_of
	//	Find character in string from the end(public member function)
	cout << "s1.find_last_of(s7) is " << s1.find_last_of(s7) << endl;
	//	find_first_not_of
	//	Find absence of character in string(public member function)
	cout << "s1.find_first_not_of(s7) is " << s1.find_first_not_of(s7) << endl;
	//	find_last_not_of
	//	Find non - matching character in string from the end(public member function)
	cout << "s1.find_last_not_of(s7) is " << s1.find_last_not_of(s7) << endl;
	//	substr
	//	Generate substring(public member function)
	mystring s8 = s1.substr(0, 2);
	cout << "s1.substr(0, 2) is " << s8 << endl;
	//	compare
	//	Compare strings(public member function)
	cout << "s1.compare(s7) is " << s1.compare(s7) << endl;
	puts("----------------------------------------");
	cout << "对非成员函数的测试：" << endl;
	//	Non - member function overloads
	//	operator+
	//	Concatenate strings(function)
	mystring s9 = s1 + s2;
	cout << "s1 + s2 is " << s9 << endl;
	//	relational operators
	cout << "s1 == s2" << (s1 == s2) << endl;
	//	swap
	//	Exchanges the values of two strings(function)
	s1.swap( s2 );
	cout << "s1 is " << s1 << endl;

	//	operator<<
	//	Insert string into stream(function)
	cout << s1 << endl;
	
	//	getline
	//	Get line from stream into string(function)
	mystring s11;
	getline(cin, s11);
	cout << "s11 is " << s11 << endl;
	
	//	operator>>
	//	Extract string from stream(function)
	mystring s10;
	cin >> s10;
	cout << "s10 is " << s10 << endl;
}