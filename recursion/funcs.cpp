#include "Header.h"

double Check(int n) // Поиск суммы через цикл
{
	double a = 1, b = 1; // Переменые
	int k = 1; // Счетчик повторения
	int two = 2, kFactor = 1;
	double Sum = 0; // Сумма в рекурсии
	double Temp_a; // а(к-1)
	for (k; k <= n; k++)
	{
		Sum += two / (1. - a * a + b * b) / kFactor;
		Temp_a = a;
		a = 2 * a + b;
		b = 3 * b + 2 * Temp_a;
		two = two << 1;
		kFactor *= k + 1;
		//std::cout << Sum << std::endl;
	}
	//system("pause");
	return Sum;
}

double Recursion(int n) // Поиск суммы через рекурсию
{
	static double a = 1, b = 1; // Переменые
	static int k = 1; // Счетчик повторения
	static int two = 2, kFactor = 1;
	static double Sum = 0; // Сумма в рекурсии
	static double Temp_a; // а(к-1)
	if (k == 1) { Sum = 0; a = 1; b = 1; k = 1; kFactor = 1; two = 2; }
	if (k <= n)
	{
		Sum += two / (1. - a * a + b * b) / kFactor;
		Temp_a = a;
		a = 2 * a + b;
		b = 3 * b + 2 * Temp_a;
		two = two << 1;
		k++;
		kFactor *= k;
		//std::cout << Sum << std::endl;
		return Recursion(n); // Рекурсия
	}
	else
	{
		k = 1;
		//system("pause");
		return Sum;
	}
}

using namespace std; // Смена пространства имен

void Menu() // Функция меню
{
	static int n; // Число повторений в виде числа
	static double SumRec, SumFor;
	char nString[4] = ""; // Число повторений в виде строки
	static int flag_input = 0, flag_rec = 0, flag_for = 0; // Флаги для меню
	char MenuNum = '\0'; // Переменная для свитча
	do // Защита от некорректного ввода пункта меню
	{
		system("cls");
		cout << "1. Ввести число повторений" << endl <<
			"2. Найти сумму через рекурсию" << endl <<
			"3. Найти сумму через цикл" << endl <<
			"4. Сравнить результаты" << endl <<
			"5. О программе" << endl <<
			"6. Помощь" << endl <<
			"7. Выход" << endl <<
			"Введите число от 1 до 7: ";
		MenuNum = _getch();
	} while (MenuNum != '1' && MenuNum != '7' && MenuNum != '2' &&
		MenuNum != '3' && MenuNum != '4' && MenuNum != '5' && MenuNum != '6'); // Проверка соответствия числа номеру пункрта меню
	switch (MenuNum) // Переключатель свитч
	{
	case '1':
	{
		flag_input = 1; // Изменение флагов
		flag_for = 0;
		flag_rec = 0;
		int i = 0;
		system("cls");
		cout << "Введите натуральное число, не большее 50: ";
		for (int i = 0; i < 2; i++)
			nString[i] = _getche();
		n = atoi(nString); // Перевод строки в число
		if (n == 0 || n > 50) // Проверка верности введенного число
			do
			{
				system("cls");
				cout << "Вы ввели некорректное число либо символ, введите натуральное число, не большее 50: ";
				for (int i = 0; i < 2; i++)
					nString[i] = _getche();
				n = atoi(nString);
			} while (n == 0 || n > 50);
			system("cls");
			cout << "Вы ввели число: " << n << endl;
			system("pause");
			return Menu(); // Возврат в меню
	}
	case '2':
	{
		system("cls");
		if (flag_input == 1) // Проверка введения числа повторений 
		{
			SumRec = Recursion(n);
			cout << "Сумма последовательности через рекурсиюпри N = " << n << ": " << SumRec << endl;
			flag_rec = 1; // Изменение флага вычисления суммы через рекурсию
		}
		else cout << "Вы не ввели число потворений. Выберите пункт 1" << endl;
		system("pause");
		return Menu();
	}
	case '3':
	{
		system("cls");
		if (flag_input == 1) // Проверка введения числа повторений 
		{
			SumFor = Check(n);
			cout << "Сумма последовательности через цикл при N = " << n << ": " << SumFor << endl;
			flag_for = 1; // Изменение флага вычисления суммы через цикл
		}
		else cout << "Вы не ввели число потворений. Выберите пункт 1" << endl;
		system("pause");
		return Menu();
	}
	case '4':
	{
		system("cls");
		if (flag_for != 0 && flag_rec != 0) // Проверка флагов цикла и рекурсии
			if (SumFor == SumRec) // Сравнение
				cout << "Суммы совпадают и равны: " << SumRec << endl;
			else cout << "Суммы не совпали" << endl;
		else cout << "Сначала найдите суммы в пунктах 2 и 3" << endl;
		system("pause");
		return Menu();
	}
	case '5': // ТЗ
	{
		system("cls");
		cout << "\"Программа с рекурсией\"\nГод: 2020\tВерсия 1.0\tРазработал: Рафиков И.М.\n\n\n"
			<< "Дано:\n1) a1=b1=1\n2) ak = 3b(k - 1) + 2a(k - 1)\n3) bk = 2a(k - 1) + b(k - 1)\n" <<
			"4) k = 2, 3...\n5) натуральное N\nПрограмма находит сумму 2^k / (1 - ak^2 + bk^2) * k!\n\n\n";
		system("pause");
		return Menu();
	}
	case '6': // Справка по меню
	{
		system("cls");
		cout << "Выберите 1 для выбора числа повторений\nВыберите 2 для нахождения суммы через рекурсию\n" <<
			"Выберите 3 для нахождения суммы через рекурсию\nВыберите 4 для сравнения результатов\nВыберите 5 для вывода справки\n" <<
			"Выберите 6 для вывода помощи\nВыберите 7 для выхода\n\n\n";
		system("pause");
		return Menu();
	}
	case '7': // Выход
		break;
	}
}