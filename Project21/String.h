#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;


//#define STRING_BASICS
//#define CONSTRUCTOR_CHECK
#define OPERATORS_CHECK
//#define METODS_PALINDROME_SHRINK_NUMBER
//#define HEX_DEC_BIN

class String; //class declaration

ostream& operator<<(ostream& os, const String& obj);
istream& operator>>(istream& is, String& obj);
String operator+(const String& left, const String& right);

//class declaration-объявление класса
class String
{
	int size;//размер строки в байтах
	char* str;//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	void set_size(int size);
	//     Constructors
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();
	void print();
	//         Operators
	String& operator=(const String& other);
	String & operator+=(const String& h);

	const char& operator[](int i)const;
	char& operator[](int i);
	//         Metods
	int StrLen(char const*  str)const;

	String& to_upper();
	String& to_lower();

	String& shrink();
	String& remove_spaces();
	bool is_palindrome()const;
	bool is_number()const;
	int to_int()const;
	bool is_bin();
	int bin_to_dec();
	bool is_hex();
	int hex_to_dec();

};
