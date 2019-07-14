#include"String.h"

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRING_BASICS
	/*char str[] = { 'H','e','l','l','o','\0' };
	cout << str << endl;*/
	/*char str[] = "Hello";
	cout << str << endl;*/
	const int n = 20;
	char str[n] = {};
	cout << "Input line:";
	//cin >> str;
	InputLine(str, n);
	cout << str << endl;
#endif // STRING_BASICS
#ifdef CONSTRUCTOR_CHECK

	String str; //Default Constructor

	str.print();
	cout << str << endl;

	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = str1;//CopyConstructor
	cout << str2 << endl;

	str1 = str1;//CopyAssignment 
	cout << str1 << endl;
#endif // CONSTRUCTOR_CHECK
#ifdef OPERATORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << "Operator '+'\t" << str3 << endl;
	str3 = str1;
	str1 += str2;
	cout << "Operator '+='\t" << str1 << endl;


#endif // OPERATORS_CHECK
#ifdef  METODS_PALINDROME_SHRINK_NUMBER


	/*for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}*/
	/*cout <<(int) 'A' <<"\t"<<(int)'a'<< endl;
	cout << 'A' - 'a' << endl;*/
	String str1 = "Привет(Hello)";
	String str2 = "Мир(World)";
	String str3 = str1 + " " + str2;
	cout << str3 << endl;
	str3.to_upper();
	cout << str3.to_upper() << endl;
	//str3.to_lower();
	cout << str3.to_lower() << endl;
	String str = "Аргентина манит негра";
	/*cout << "Vvedite stroky:\t";
	SetConsoleCP(1251);
	cin.getline(str.get_str(), str.get_size());
	SetConsoleCP(866);
	cout << str << endl;
	cout << str.shrink() << endl;
	cout << str.remove_spaces() << endl;
	cout << str.is_palindrome()<<endl;
	cout << str.is_number() << endl;
	cout << str.to_int() << endl;*/
	str[5] = '@';
	cout << str << endl;
#endif //  METODS_PALINDROME_SHRINK_NUMBER
#ifdef HEX_DEC_BIN
	String str;

	/*cout << "Vvedite chislo(0 and 1):";
	cin >> str;
	cout << str << endl;

cout << str.is_bin() << endl;
	cout << str.bin_to_dec() << endl;*/
	cout << "Vvedite\t";
	cin >> str;
	cout << str << endl;
	cout << str.is_hex() << endl;
	cout << str.hex_to_dec() << endl;

#endif // #define HEX_DEC_BIN


	



}