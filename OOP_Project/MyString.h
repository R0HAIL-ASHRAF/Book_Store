#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
#include <fstream>
#include <wx/wx.h>
#include <wx/string.h>
using namespace std;

class MyString {
private:
	int length;
	int capacity;
	char* charString;
	int ArrLength(const char* Arr);
public:
	//----------------Constructors-------------------------------------
		//Defalt Constructor
	MyString();
	// coverstion Constructor
	MyString(const char* Arr);

	MyString(const wxString& arr);
    // MyString to wxString
	operator wxString() const;
	// Parameterized Constructor 1;
	MyString(char* _Mystring);
	// Parameterized Constructor 2
	MyString(int size, int _capacity);
	MyString(const MyString& _str);
	// int to string constructor
	MyString(char a, int size);
	// itos Constructor
	MyString(int num);


	//----------------------Operators---------------------------
	// Assignment Operator
	MyString& operator=(const MyString& right);
	//index Operators
	const char operator [] (int index) const;
	char& operator [] (int index);
	//Eqaulity Operator
	bool operator==(const char* str)const;
	bool operator!=(const char* str)const;
	bool operator!=(const MyString& str) const;
	bool operator == (const MyString& str) const;
	char* ToCharArray() const;
	//less then check Operator
	bool operator<(const MyString& str) const;
	//Greater then check Operator
	bool operator>(const MyString& str) const;

	//----------------------------Functions--------------------------

	//              ---Searching Functions---

	int FindFirst(const char& a)const;
	int FindLast(const char& a)const;
	int* FindAll(const char& a, int& size);
	int* SearchAllSubstrings(const char* subStr, int& count);
	int SubStrSearchFirst(const char* subStr);
	int SubStrSearchLast(const char* subStr);

	//              ---Removing Functions---

	MyString& removeCharFirst(const char& a);
	MyString& removeCharLast(const char& a);
	MyString& removeAllChar(const char& a);
	//              ---String Concatenation---

	friend MyString operator + (MyString s1, MyString s2);
	MyString& AppendArray(const MyString& str);

	//              ---Inserting Functions---

	MyString& InsertChar(const char& a, const int& index);
	MyString& InsertCharString(const char* arr, const int& index);
	//              ---Special Functions---

	MyString& toLower();
	MyString& toUpper();
	//              ---Trim Functions---

	 // function with the prototype
	MyString& Trimm();


	//              ---Splitting Functions---
	bool isPresent(const char& ch, const char* chArr) const;
	MyString* split(const char& ch, int& count);
	MyString* Tokenize(const char* chArr, int& count);

	//              ---Regrow Functions---
	MyString RegrowArr();
	int* regrowInt(int* arr, int& size);
	//              ---Friend Functions---
	friend ostream& operator << (ostream& os, const MyString& _str);
	friend istream& operator >> (istream& os, MyString& str);



	//              ---Other Functions---

	void clear();
	bool isAvail(const char& ch) const;
	int StringToInt();
	MyString IntToString(int num);
	void ReplaceFirst(char c);
	const char charstring(int i);
	MyString& operator=(const char* right);
	void WriteToStream(std::ofstream& out) const;
	void ReadFromStream(std::ifstream& in);
	void convertionToChar(const int num, char arr[]);
	bool IsEmpty() const;
	void display() const;
	// Destructor
	~MyString();
	
};



#endif

