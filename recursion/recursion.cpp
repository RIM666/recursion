﻿/*
Программа с рекурсией v 1.0
2020 год
Разработал: Рафиков И.М.
Задание:
Даны a1=b1=1
ak=3b(k-1)+2a(k-1)
bk=2a(k-1)+b(k-1)
k = 2,3...
И натуральное N
Найти сумму
2^k/(1-ak^2+bk^2)k!
*/

#include "Header.h"

int main()
{
	SetConsoleCP(1251);			// Ввод и вывод
	SetConsoleOutputCP(1251);	// русских символов
	Menu();						// Вызов функции меню
}