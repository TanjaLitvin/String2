#include"String.h"

//class definition-определение класса:
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
void String::set_size(int size)
{
	if (size > 0)
	{
		this->size = size;
	}
	else
	{
		this->size = 80;
	}
}
//     Constructors
String::String(int size)
{
	set_size(size);//задаем размер строки
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[])
{
	//cout << StrLen(str) << endl;
	this->size = StrLen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}
void String::print()
{
	cout << "str:" << str << endl;
	cout << "size:" << size << endl;
}
//         Operators
String& String::operator=(const String& other)
{
	cout << "CopyAssignment:" << this << endl;
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];

	return *this;
}
String & String:: operator+=(const String& h)
{
	int size = StrLen(this->str) + StrLen(h.str);
	char* t = new char[size + 1];
	for (int i = 0; i < StrLen(this->str); i++)
		t[i] = this->str[i];
	for (int ii = StrLen(this->str), j = 0; ii <= size; ii++, j++)
		t[ii] = h.str[j];

	this->str = t;
	return *this;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)//i-index
{
	return str[i];
}
//         Metods
int String::StrLen(char const*  str)const
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

String& String::to_upper()
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я'

			)
			str[i] -= 32;
	}
	return *this;
}
String& String::to_lower()
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
	return *this;
}

String& String::shrink()
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
	}
	return *this;
}
String& String::remove_spaces()
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ')
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
	}
	return *this;
}
bool String::is_palindrome()const
{

	String buffer = *this;
	buffer.to_lower().remove_spaces();
	int size = buffer.StrLen(buffer.get_str());
	cout << buffer << endl;

	for (int i = 0; i < size / 2; i++)
	{
		if (buffer.str[i] != buffer.str[size - 1 - i])
		{
			return false;
		}
	}
	return true;
}
bool String::is_number()const
{
	/*int i = 0;
	if (str[0] == '+' || str[0] == '-')i = 1;*/
	//Ternary conditional operator:
	//(condition)?expression1:expression2;
	//если условие вернуло true,то оператор вернет expression1,
	//если условие вернуло false,то оператор вернет expression2.
	for (int i = (str[0] == '+' || str[0] == '-') ? 1 : 0; str[i]; i++)
	{

		if (str[i]<'0' || str[i]>'9')return false;
	}
	return true;
}
int String::to_int()const
{

	int number = 0;
	if (this->is_number())
	{
		bool minus = str[0] == '-' ? true : false;
		for (int i = minus ? 1 : 0; str[i]; i++)
		{
			number *= 10;//сдвигаем число для того что бы освободить место для следующего разряда

			number += str[i] - 48;//записываем в число значение следующего разряда
		}
		if (minus)number = -number;
	}
	return number;
}
bool String::is_bin()//const
{
	String str = *this;
	str.remove_spaces();

	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0'&& str[i] != '1')
		{
			return false;
		}
	}
	return true;
}
int String::bin_to_dec()
{
	if (!is_bin())return 0;
	int dec = 0;        //десятичное число
	int weight = 1;     //весовой коэффициент разряда
	for (int i = StrLen(str) - 1; i >= 0; i--)
	{
		dec += (str[i] - 48)*weight;
		weight *= 2;
	}
	return dec;
}
bool String::is_hex()
{
	String str = *this;
	for (int i = 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			)
		{
			return false;
		}
	}
	return true;

}
int String::hex_to_dec()
{
	if (!is_hex())return false;
	int dec = 0;
	int weight = 1;
	for (int i = StrLen(str) - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')dec += (str[i] - '0')*weight;
		if (str[i] >= 'A' && str[i] <= 'F')dec += (str[i] - 'A' + 10)*weight;
		if (str[i] >= 'a' && str[i] <= 'f')dec += (str[i] - 'a' + 10)*weight;
		weight *= 16;
	}
	return dec;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();

}
istream& operator>>(istream& is, String& obj)
{
	return is >> obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String res = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size() - 1; i++)
		//res.get_str()[i] = left.get_str()[i];
		res[i] = left[i];
	for (int i = 0; i < right.get_size() - 1; i++)
		//res.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		res[i + left.get_size() - 1] = right.operator[](i);
	return res;
}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}