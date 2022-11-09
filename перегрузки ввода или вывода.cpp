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
class Time
{
public:
	Time(int quantity)
	{
		hour = quantity;
		minute = quantity;
		second = quantity;
	}
	Time()
	{
		hour = 0;//исходное значение часа
		minute = 0;//исходное значение минуты
		second = 0;//исходное значение секунды
	}
	static void change_1(static bool afternoon, static bool am);
	static void change_2(static bool afternoon, static bool am);
	int hour, minute, second, day_half = 43200, h = 3600, min = 60, sec = 1;
	string daytime;
	friend ostream& operator<< (ostream& out, const Time& time);
	friend istream& operator>> (istream& in, Time& time);
};
ostream& operator<< (ostream& out, const Time& time)
{
	out << "time(" << time.daytime << ", " << time.hour << ":" << time.minute << ":" << time.second << ")" << endl;
	return out;
}
istream& operator>> (istream& in, Time& time)
{
	in >> time.daytime;
	in >> time.hour;
	in >> time.minute;
	in >> time.second;
	return in;
}
Time operator - (Time subtraction_1, Time subtraction_2)
{
	return Time(subtraction_1.day_half - subtraction_2.h);
}
Time operator + (Time sum_1, Time sum_2)
{
	return Time(sum_1.second + sum_2.sec);
}
Time operator * (Time multiplication_1, Time multiplication_2)
{
	return Time(multiplication_1.min * multiplication_2.h);
}
Time operator / (Time dividing_1, Time dividing_2)
{
	return Time(dividing_1.h / dividing_2.min);
}
Time operator % (Time transf_to_int_1, Time transf_to_int_2)
{
	return Time(transf_to_int_1.min / transf_to_int_2.h * 100);
}
Time operator ^ (Time multiplier_1, Time multiplier_2)
{
	return Time(multiplier_1.min * multiplier_2.h * 3);
}
bool operator > (Time value_1, Time value_2)
{
	return value_1.h > value_2.min;
}
bool operator < (Time value_1, Time value_2)
{
	return value_1.min < value_2.h;
}
bool operator == (Time value_1, Time value_2)
{
	return value_1.h == value_2.h;
}
bool operator != (Time value_1, Time value_2)
{
	return value_1.min != value_2.h;
}
Time operator += (Time value_1, Time value_2)
{
	return value_1.h++;
	return value_2.min++;
}
Time operator -= (Time value_1, Time value_2)
{
	return value_1.h--;
	return value_2.min--;
}
static void change_1(static bool afternoon, static bool am)
{
	afternoon = 1;
	am = 0;//втора€ половина дн€
	SetColor(1, 0);
	cout << "pm ";
}
static void change_2(static bool afternoon, static bool am)
{
	afternoon = 0;//перва€ половина дн€
	am = 1;
	SetColor(2, 0);
	cout << "am ";
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	SetColor(3, 0);
	cout << "врем€" << endl;
	SetColor(4, 0);
	cout << "до полудн€=1" << endl;
	SetColor(5, 0);
	cout << "после полудн€=2" << endl;
	int date;
	static bool afternoon, am;
	cin >> date;
	switch (date)
	{
	case 1:
	{
		SetColor(6, 0);
		cout << "am" << endl;
		afternoon = 0;//перва€ половина дн€
		am = 1;
		break;
	}
	case 2:
	{
		SetColor(7, 0);
		cout << "pm" << endl;
		afternoon = 1;
		am = 0;//втора€ половина дн€
		break;
	}
	}
	istream& operator>> (istream & in, Time & time);
	ostream& operator<< (ostream & out, const Time & time);
	Time period;
	cin >> period.hour;
	SetColor(8, 0);
	cout << ":";
	cin >> period.minute;
	SetColor(9, 0);
	cout << ":";
	cin >> period.second;
	SetColor(10, 0);
	if (period.hour == 0 || period.hour == 13) cout << "ошибка" << endl;
	SetColor(11, 0);
	if (period.hour < 10) cout << "0" << period.hour;
	else period.hour;
	SetColor(12, 0);
	cout << ":";
	SetColor(13, 0);
	if (period.minute < 0 || period.minute == 60) cout << "ошибка" << endl;
	SetColor(14, 0);
	if (period.minute < 10) cout << "0" << period.minute;
	else period.minute;
	SetColor(15, 0);
	cout << ":";
	if (period.second < 0 || period.second == 60) cout << "ошибка" << endl;
	if (period.second < 10) cout << "0" << period.second << endl;
	else period.second;
	bool log_val = 1;
	while (log_val == 1)
	{
		Sleep(1000);
		system("clear");
		period.second++;
		if (period.second == 60)
		{
			period.second = 0;//сброс счЄтчика секунд
			period.minute++;
			if (period.minute == 60)
			{
				period.minute = 0;//сброс счЄтчика минут
				period.hour++;
				if (period.hour == 13)
				{
					period.hour = 1;
					if (afternoon == 0) change_1(afternoon, am);
					else change_2(afternoon, am);
				}
			}
		}
		if (period.hour < 10) cout << "0" << period.hour;
		else cout << period.hour;
		cout << ":";
		if (period.minute < 10) cout << "0" << period.minute;
		else cout << period.minute;
		cout << ":";
		if (period.second < 10) cout << "0" << period.second << endl;
		else cout << period.second << endl;
	}
}