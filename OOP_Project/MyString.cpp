

#include<iostream>
#include"MyString.h"


int MyString::ArrLength(const char* Arr) {
	int i = 0;
	for (i = 0; Arr[i] != '\0'; i++) {}
	return i;
}

//----------------Constructors-------------------------------------
//Defalt Constructor
MyString::MyString() {
	this->capacity = 1;
	this->length = 0;
	this->charString = new char[this->capacity];
}
//conversition Constructor
MyString::MyString(const char* Arr) {
	this->capacity = ArrLength(Arr);
	this->length = ArrLength(Arr);
	this->charString = new char[this->capacity + 1];
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = Arr[i];
	}
}
MyString::MyString(const wxString& arr)
{
	this->capacity = ArrLength(arr);
	this->length = ArrLength(arr);
	this->charString = new char[this->capacity + 1];
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = arr[i];
	}
}
// Parameterized Constructor 1
MyString::MyString(char* _Mystring) {
	this->length = ArrLength(_Mystring);
	this->capacity = ArrLength(_Mystring);
	this->charString = new char[this->capacity] {'\0'};
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = _Mystring[i];
	}
	if (length == capacity)
		*this = RegrowArr();
	this->charString[length] = { '\0' };
}
// Parameterized Constructor 2
MyString::MyString(int size, int _capacity) {
	this->length = size;
	this->capacity = _capacity;
	this->charString = new char[this->capacity] {'\0'};
	this->charString[this->length] = '\0';
}
//Copy Constructor
MyString::MyString(const MyString& _str) {
	this->length = _str.length;
	this->capacity = _str.capacity;
	this->charString = new char[_str.capacity + 1] {'\0'};
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = _str.charString[i];
	}
	this->charString[this->length] = '\0';
}

// int to string constructor
MyString::MyString(char a, int size) {
	this->length = size;
	this->capacity = size;
	this->charString = new char[this->capacity] {'\0'};
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = a;
	}
}
// itos Constructor
MyString::MyString(int num) {
	this->length = 0;
	this->capacity = 0;
	this->charString = new char[this->capacity + 1] {'\0'};
	*this = IntToString(num);
}

//----------------------Operators---------------------------
// Assignment Operator
MyString& MyString::operator=(const MyString& right) {
	if (this == &right) {
		return *this;
	}
	delete[] this->charString;
	this->length = right.length;
	this->capacity = right.capacity;
	this->charString = new char[this->capacity + 1];
	for (int i = 0; i < this->length; i++) {
		this->charString[i] = right.charString[i];
	}
	this->charString[this->length] = '\0';
	return *this;
}

//index Operators
const char MyString::operator [] (int index) const {
	if (index > -1 && index < length)
		return *(this->charString + index);
	throw::out_of_range("invlaid data accez");
}
char& MyString::operator [] (int index) {
	if (index > -1 && index < length)
		return *(this->charString + index);
	throw::out_of_range("invlaid data accez");
}
//Eqaulity Operator
bool MyString::operator == (const MyString& str) const {
	if (this->length != str.length)
		return false;

	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] != str.charString[i])
			return false;
	}
	return true;
}
char* MyString::ToCharArray() const {
	char* result = new char[this->length + 1];
	for (size_t i = 0; i < this->length; i++) {
		result[i] = this->charString[i];
	}
	result[this->length] = '\0';
	return result;
}
bool MyString::operator==(const char* str) const {
	MyString tempStr = { str };
	if (tempStr == *this) {
		return true;
	}
	else
		return false;
}
bool MyString::operator!=(const char* str) const {
	MyString tempStr = { str };
	if (tempStr == *this) {
		return false;
	}
	else
		return true;
}
bool MyString::operator!=(const MyString& str) const {
	
	if (str == *this) {
		return false;
	}
	else
		return true;
}

//less then check Operator
bool MyString::operator<(const MyString& str) const {
	for (int i = 0; i < this->length && i < str.length; i++) {
		if (this->charString[i] < str.charString[i]) {
			return true;
		}
		if (this->charString[i] > str.charString[i]) {
			return false;
		}
	}
	if (this->length < str.length) {
		return true;
	}
	return false;
}
//Greater then check Operator
bool MyString::operator>(const MyString& str) const {
	for (int i = 0; i < this->length && i < str.length; i++) {
		if (this->charString[i] > str.charString[i]) {
			return true;
		}
		if (this->charString[i] < str.charString[i]) {
			return false;
		}
	}
	if (this->length > str.length) {
		return true;
	}
	return false;
}


//----------------------------Functions--------------------------

//              ---Searching Functions---

int MyString::FindFirst(const char& a)const {
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] == a) {
			return i;
		}
	}
	return -1;
}
int MyString::FindLast(const char& a)const {
	for (int i = length - 1; i > -1; i--) {
		if (charString[i] == a) {
			return i;
		}
	}
	return -1;
}
int* MyString::FindAll(const char& a, int& size) {
	size = 0;
	int* count = new int[size];
	for (int i = this->length - 1; i > -1; i--) {
		if (this->charString[i] == a) {
			count = regrowInt(count, size);
			count[size - 1] = i;
		}
	}
	return count;
}
int* MyString::SearchAllSubstrings(const char* subStr, int& count) {
	int sublen = ArrLength(subStr);
	count = 0;
	int* indices = new int [count] {};
	bool flag = false;
	int existence = 0;
	int k = 0;
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] == subStr[k]) {
			existence++;
			k++;
			if (existence == sublen) {
				indices = regrowInt(indices, count);
				indices[count - 1] = i - sublen + 1;
			}
		}
		else {
			k = 0;
			existence = 0;
		}
	}
	return indices;
}
int MyString::SubStrSearchFirst(const char* subStr) {
	int sublen = ArrLength(subStr);
	if (sublen > this->length)
		return -1;
	int existence = 0;
	int k = 0;
	for (int i = 0; i < this->length; i++) {
		if (charString[i] == subStr[k]) {
			existence++;
			k++;
			if (existence == sublen) {
				return i - sublen + 1;
			}
		}
		else {
			k = 0;
			existence = 0;
		}
	}
	return -1;
}
int MyString::SubStrSearchLast(const char* subStr) {
	int sublen = ArrLength(subStr);
	if (sublen > this->length)
		return -1;
	int existence = 0;
	int k = sublen - 1;
	for (int i = this->length - 1; i >= 0; i--) {
		if (charString[i] == subStr[k]) {
			existence++;
			k--;
			if (existence == sublen) {
				return i;
			}
		}
		else {
			k = sublen - 1;
			existence = 0;
		}
	}
	return -1;
}

//              ---Removing Functions---

MyString& MyString::removeCharFirst(const char& a) {
	int index;
	index = FindFirst(a);
	if (index == -1)
		return *this;
	for (int i = index; i < this->length - 1; i++) {
		this->charString[i] = this->charString[i + 1];
	}
	this->charString[this->length - 1] = '\0';
	this->length--;
	return *this;
}
MyString& MyString::removeCharLast(const char& a) {
	int index = FindLast(a);
	if (index == -1)
		return *this;
	for (int i = index; i < this->length - 1; i++) {
		this->charString[i] = this->charString[i + 1];
	}
	this->charString[this->length - 1] = '\0';
	this->length--;
	return *this;
}

MyString& MyString::removeAllChar(const char& a) {
	int size = 0;
	int* indexArr = FindAll(a, size);
	for (int i = 0; i < size; i++) {
		*this = removeCharFirst(a);
		this->length--;
	}
	return *this;
}

//              ---String Concatenation---

MyString operator+(MyString s1, MyString s2) {

	MyString concatArr(s1.length + s2.length, s1.length + s2.length + 1);
	int i = 0;
	for (i = 0; i < s1.length; i++)
		concatArr.charString[i] = s1.charString[i];
	for (int j = 0; j < s2.length; i++, j++)
		concatArr.charString[i] = s2.charString[j];
	return concatArr;
}
MyString& MyString::AppendArray(const MyString& str) {
	int i = 0;
	for (int j = 0; j < str.length; i++, j++) {
		if (this->length == capacity)
			*this = RegrowArr();
		charString[length] = str.charString[j];
		this->length++;
	}
	return *this;
}

//              ---Inserting Functions---

MyString& MyString::InsertChar(const char& a, const int& index) {
	if (this->capacity == this->length) {
		*this = RegrowArr();
		this->length++;
	}
	for (int i = this->length; i > index; i--) {
		this->charString[i + 1] = this->charString[i];
	}
	this->charString[index] = a;
	return *this;
}
MyString& MyString::InsertCharString(const char* arr, const int& index) {
	this->length = this->length + ArrLength(arr);
	while (this->capacity <= this->length) {
		*this = RegrowArr();
	}
	for (int i = this->length - ArrLength(arr); i >= index; i--) {

		this->charString[i + ArrLength(arr)] = charString[i];
	}
	int k = 0;
	for (int i = index; i < index + ArrLength(arr); i++) {
		this->charString[i] = arr[k];
		k++;
	}
	return *this;
}

//              ---Special Functions---

MyString& MyString::toLower() {
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] >= 'A' && this->charString[i] <= 'Z') {
			this->charString[i] = this->charString[i] + 32;
		}
	}
	return *this;
}
MyString& MyString::toUpper() {
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] >= 'a' && this->charString[i] <= 'z') {
			this->charString[i] = this->charString[i] - 32;
		}
	}
	return *this;
}

//              ---Trim Functions---

MyString& MyString::Trimm() {
	for (int i = 0; i < this->length; i++) {
		if ((this->charString[i] >= 'a' && this->charString[i] <= 'z') ||
			(this->charString[i] >= 'A' && this->charString[i] <= 'Z')) {
			break;
		}
		for (int j = i; j < this->length - 1; j++) {
			this->charString[j] = this->charString[j + 1];
		}
		this->length--;
		i--;
	}

	for (int i = this->length - 1; i >= 0; i--) {
		if ((this->charString[i] >= 'a' && this->charString[i] <= 'z') ||
			(this->charString[i] >= 'A' && this->charString[i] <= 'Z')) {
			break;
		}
		this->length--;
	}
	charString[this->length] = '\0';
	return *this;
}

//              ---Splitting Functions---

MyString* MyString::split(const char& ch, int& count) {
	count = 1;
	bool flag = false;
	int a = this->length;
	for (int i = 0; i < this->length; i++) {
		if (charString[i] == ch) {
			flag = false;
		}
		else if (!flag) {
			count++;
			flag = true;
		}
	}
	MyString* splitArr = new MyString[count];
	for (int i = 0; i < count; i++) {
		splitArr[i].charString = new char[100] {'\0'};
	}
	int index = 0;
	int k = 0;

	for (int i = 0; i < this->length; i++) {
		if (charString[i] != ch) {
			flag = false;
			splitArr[index].length++;
			splitArr[index].capacity++;
			splitArr[index].charString[k] = this->charString[i];
			splitArr[index].charString[k + 1] = '\0';
			k++;
		}
		else {
			k = 0;
			if (!flag) {
				index++;
				flag = true;
			}
		}
	}
	return splitArr;
}
MyString* MyString::Tokenize(const char* chArr, int& count) {
	count = 0;
	bool flag = false;

	for (int i = 0; i < this->length; i++) {
		if (isPresent(charString[i], chArr)) {
			flag = false;
		}
		else if (!flag) {
			count++;
			flag = true;
		}
	}
	MyString* splitArr = new MyString[count];
	for (int i = 0; i < count; i++) {
		splitArr[i].charString = new char[100] {'\0'};
	}
	int index = 0;
	int k = 0;
	for (int i = 0; i < this->length; i++) {
		if (isPresent(charString[i], chArr)) {
			if (k > 0) {
				splitArr[index].charString[k] = '\0';
				index++;
				k = 0;
			}
		}
		else {
			splitArr[index].length++;
			splitArr[index].capacity++;
			splitArr[index].charString[k] = charString[i];
			k++;
		}
	}
	return splitArr;
}
bool MyString::isPresent(const char& ch, const char* chArr) const {
	for (int i = 0; chArr[i] != '\0'; i++) {
		if (ch == chArr[i])
			return true;
	}
	return false;
}

//              ---Regrow Functions---
MyString MyString::RegrowArr() {
	MyString _str{ *this };
	_str.length = this->length;
	_str.capacity = 2 * (this->length) + 1;
	delete[] _str.charString;
	_str.charString = new char[_str.capacity + 1] {'\0'};
	for (int i = 0; i < this->length; i++) {
		_str.charString[i] = this->charString[i];
	}
	_str.charString[this->length] = '\0';
	return _str;
}
int* MyString::regrowInt(int* arr, int& size) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	size++;
	delete[] arr;
	return newArr;
}
void MyString::display() const {
	for (int i = 0; i < length; i++) {
		cout << charString[i];
	}
}

//              ---Friend Functions---
ostream& operator << (ostream& os, const MyString& _str) {
	for (int i = 0; i < _str.length; i++) {
		os << _str.charString[i];
	}
	return os;
}

//              ---Other Functions---

void MyString::clear() {

	delete[] this->charString;
	this->length = 0;
	this->capacity = 0;
	this->charString = nullptr;
}
bool MyString::isAvail(const char& ch) const {
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] == ch)
			return true;
	}
	return false;
}
int MyString::StringToInt() {
	int n = 0;
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < this->length; i++) {
		if (this->charString[i] == '-') {
			flag = true;
			i++;
		}
		n = this->charString[i] - '0';
		sum = sum * 10 + n;
	}
	if (flag) {
		sum = sum * -1;
	}
	return sum;
}
MyString MyString::IntToString(int num) {

	while (num != 0) {
		if (this->length == this->capacity) {
			*this = RegrowArr();
		}

		int n = num % 10;
		this->charString[length] = n + '0';
		num /= 10;
		this->length++;
	}
	int tempLength = this->length;
	for (int i = 0; i < tempLength; i++) {
		int temp = charString[i];
		charString[i] = charString[tempLength - 1];
		charString[tempLength - 1] = temp;
		tempLength--;
	}
	charString[this->length] = '\0';
	return *this;
}
void MyString::ReplaceFirst(char c) {
	this->charString[0] = c;
}


MyString::~MyString() {

	delete[] this->charString;
}
istream& operator >> (istream& os, MyString& str) {
	if (str.charString != nullptr) {
		delete[] str.charString;

	}
	str.charString = new char[50] {'\0'};
	os >> str.charString;
	str.length = str.ArrLength(str.charString);
	int a = str.length;
	str.capacity = str.length;
	return os;
}
void MyString::convertionToChar(const int num, char arr[]) {
	int temp = num;
	int digits = 0;

	if (temp == 0) {
		arr[0] = '0';
		arr[1] = '\0';
		return;
	}
	while (temp > 0) {
		temp /= 10;
		digits++;
	}
	arr[digits] = '\0';
	temp = num;
	while (temp > 0) {
		arr[--digits] = (temp % 10) + '0';
		temp /= 10;
	}
}

const char MyString::charstring(int i) {
	return charString[i];

}

MyString& MyString::operator=(const char* right) {
	if (this->charString == right) {
		return *this;
	}
	delete[] this->charString;
	this->length = ArrLength(right);
	this->capacity = this->length;
	this->charString = new char[this->capacity + 1];
	for (size_t i = 0; i < this->length; ++i) {
		this->charString[i] = right[i];
	}
	this->charString[this->length] = '\0';

	return *this;
}

void MyString::WriteToStream(ofstream& out) const {
	int len = length;
	out.write((char*)&len, sizeof(int));
	out.write(charString, len);
}

void MyString::ReadFromStream(std::ifstream& in) {
	int len;
	in.read((char*)&len, sizeof(int));
	if (len > 0 && in) {
		delete[] charString;
		charString = new char[len + 1];
		in.read(charString, len);
		charString[len] = '\0';
		length = len;
		capacity = len + 1;
	}
}

MyString::operator wxString() const {
	return wxString(charString);
}


bool MyString::IsEmpty() const {
	if (length == 0)
		return true;
	return false;
}