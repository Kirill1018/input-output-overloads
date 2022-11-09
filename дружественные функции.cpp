#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
#include <stdio.h>
/*0 Ч черный
1 Ч синий
2 Ч зеленый
3 Ч голубой
4 Ч красный
5 Ч лиловый
6 Ч желтый
7 Ч белый
8 Ч серый
9 Ч свело - синий
A Ч светло - зеленый
B Ч светло - голубой
— Ч светло - красный
E Ч светло - желтый
F Ч €рко - белый
system("color F0");*/  // ”становка белого фона и черного текста
class rectangle_2;
class rectangle_1
{
	int size_1, size_2;
public:
	rectangle_1()
	{
		size_1 = 0;//исходное значение первой стороны пр€моугольника
		size_2 = 0;//исходное значение второй стороны пр€моугольника
	}
	void build();
	void symb_change_by_user_choice();
	void perim_outp_of_rect();
	void user_choice_of_rect_size();
};
class rectangle_2
{
	int size, _size;
	friend void symb_change_by_user_choice();
	friend void perim_outp_of_rect();
	friend void user_choice_of_rect_size();
public:
	rectangle_2()
	{
		size = 0;//исходное значение первой стороны
		_size = 0;//исходное значение второй стороны
	}
	int gets()
	{
		return size;
	}
	int get_size()
	{
		return _size;
	}
};
void rectangle_1::build()
{
	const int side_1 = 3;
	const int side_2 = 6;
	char symbol_1 = '*';
	int _rectangle_1[side_1][side_2] = { symbol_1 };
	for (int x = 0; x < side_1; x++)
	{
		SetColor(1, 0);
		for (int y = 0; y < side_2; y++) cout << symbol_1;
		SetColor(2, 0);
		cout << symbol_1 << endl;
	}
}
void rectangle_1::symb_change_by_user_choice()
{
	const int side_1 = 3;
	const int side_2 = 6;
	char symbol_2;
	SetColor(3, 0);
	cout << "символ: ";
	cin >> symbol_2;
	int _rectangle_2[side_1][side_2] = { symbol_2 };
	for (int x = 0; x < side_1; x++)
	{
		SetColor(4, 0);
		for (int y = 0; y < side_2; y++) cout << symbol_2;
		SetColor(5, 0);
		cout << symbol_2 << endl;
	}
}
void rectangle_1::perim_outp_of_rect()
{
	const int side_1 = 3;
	const int side_2 = 6;
	char symbol_1 = '*';
	int _rectangle_2[side_1][side_2] = {};
	for (int x = 0; x < side_1; x++)
	{
		for (int y = 0; y < side_2; y++)
		{
			SetColor(6, 0);
			if (x == 0) cout << symbol_1;
			SetColor(7, 0);
			if (x == 0 && y == side_2 - 1) cout << endl;
			SetColor(8, 0);
			if (x == 1 && y == 0) cout << symbol_1 << setw(5) << symbol_1 << endl;
			SetColor(9, 0);
			if (x == 2 && y == 0) cout << symbol_1 << setw(5) << symbol_1 << endl;
			SetColor(10, 0);
			if (x == side_1 - 1) cout << symbol_1;
		}
	}
	cout << endl;
}
void rectangle_1::user_choice_of_rect_size()
{
	const int side_1 = 6, side_2 = 6;
	char symbol_1 = '*';
	int _rectangle_2[side_1][side_2] = { symbol_1 };
	for (int x = 0; x < side_1; x++)
	{
		SetColor(11, 0);
		for (int y = 0; y < side_2; y++) cout << symbol_1;
		SetColor(12, 0);
		cout << symbol_1 << endl;
	}
}
void main()
{
	setlocale(LC_ALL, "ru");
	rectangle_1 first_rect, sec_rect;
	first_rect.build();
	sec_rect.symb_change_by_user_choice();
	sec_rect.perim_outp_of_rect();
	sec_rect.user_choice_of_rect_size();
}