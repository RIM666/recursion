#include "Header.h"

double Check(int n) // ����� ����� ����� ����
{
	double a = 1, b = 1; // ���������
	int k = 1; // ������� ����������
	int two = 2, kFactor = 1;
	double Sum = 0; // ����� � ��������
	double Temp_a; // �(�-1)
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

double Recursion(int n) // ����� ����� ����� ��������
{
	static double a = 1, b = 1; // ���������
	static int k = 1; // ������� ����������
	static int two = 2, kFactor = 1;
	static double Sum = 0; // ����� � ��������
	static double Temp_a; // �(�-1)
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
		return Recursion(n); // ��������
	}
	else
	{
		k = 1;
		//system("pause");
		return Sum;
	}
}

using namespace std; // ����� ������������ ����

void Menu() // ������� ����
{
	static int n; // ����� ���������� � ���� �����
	static double SumRec, SumFor;
	char nString[4] = ""; // ����� ���������� � ���� ������
	static int flag_input = 0, flag_rec = 0, flag_for = 0; // ����� ��� ����
	char MenuNum = '\0'; // ���������� ��� ������
	do // ������ �� ������������� ����� ������ ����
	{
		system("cls");
		cout << "1. ������ ����� ����������" << endl <<
			"2. ����� ����� ����� ��������" << endl <<
			"3. ����� ����� ����� ����" << endl <<
			"4. �������� ����������" << endl <<
			"5. � ���������" << endl <<
			"6. ������" << endl <<
			"7. �����" << endl <<
			"������� ����� �� 1 �� 7: ";
		MenuNum = _getch();
	} while (MenuNum != '1' && MenuNum != '7' && MenuNum != '2' &&
		MenuNum != '3' && MenuNum != '4' && MenuNum != '5' && MenuNum != '6'); // �������� ������������ ����� ������ ������� ����
	switch (MenuNum) // ������������� �����
	{
	case '1':
	{
		flag_input = 1; // ��������� ������
		flag_for = 0;
		flag_rec = 0;
		int i = 0;
		system("cls");
		cout << "������� ����������� �����, �� ������� 50: ";
		for (int i = 0; i < 2; i++)
			nString[i] = _getche();
		n = atoi(nString); // ������� ������ � �����
		if (n == 0 || n > 50) // �������� �������� ���������� �����
			do
			{
				system("cls");
				cout << "�� ����� ������������ ����� ���� ������, ������� ����������� �����, �� ������� 50: ";
				for (int i = 0; i < 2; i++)
					nString[i] = _getche();
				n = atoi(nString);
			} while (n == 0 || n > 50);
			system("cls");
			cout << "�� ����� �����: " << n << endl;
			system("pause");
			return Menu(); // ������� � ����
	}
	case '2':
	{
		system("cls");
		if (flag_input == 1) // �������� �������� ����� ���������� 
		{
			SumRec = Recursion(n);
			cout << "����� ������������������ ����� ����������� N = " << n << ": " << SumRec << endl;
			flag_rec = 1; // ��������� ����� ���������� ����� ����� ��������
		}
		else cout << "�� �� ����� ����� ����������. �������� ����� 1" << endl;
		system("pause");
		return Menu();
	}
	case '3':
	{
		system("cls");
		if (flag_input == 1) // �������� �������� ����� ���������� 
		{
			SumFor = Check(n);
			cout << "����� ������������������ ����� ���� ��� N = " << n << ": " << SumFor << endl;
			flag_for = 1; // ��������� ����� ���������� ����� ����� ����
		}
		else cout << "�� �� ����� ����� ����������. �������� ����� 1" << endl;
		system("pause");
		return Menu();
	}
	case '4':
	{
		system("cls");
		if (flag_for != 0 && flag_rec != 0) // �������� ������ ����� � ��������
			if (SumFor == SumRec) // ���������
				cout << "����� ��������� � �����: " << SumRec << endl;
			else cout << "����� �� �������" << endl;
		else cout << "������� ������� ����� � ������� 2 � 3" << endl;
		system("pause");
		return Menu();
	}
	case '5': // ��
	{
		system("cls");
		cout << "\"��������� � ���������\"\n���: 2020\t������ 1.0\t����������: ������� �.�.\n\n\n"
			<< "����:\n1) a1=b1=1\n2) ak = 3b(k - 1) + 2a(k - 1)\n3) bk = 2a(k - 1) + b(k - 1)\n" <<
			"4) k = 2, 3...\n5) ����������� N\n��������� ������� ����� 2^k / (1 - ak^2 + bk^2) * k!\n\n\n";
		system("pause");
		return Menu();
	}
	case '6': // ������� �� ����
	{
		system("cls");
		cout << "�������� 1 ��� ������ ����� ����������\n�������� 2 ��� ���������� ����� ����� ��������\n" <<
			"�������� 3 ��� ���������� ����� ����� ��������\n�������� 4 ��� ��������� �����������\n�������� 5 ��� ������ �������\n" <<
			"�������� 6 ��� ������ ������\n�������� 7 ��� ������\n\n\n";
		system("pause");
		return Menu();
	}
	case '7': // �����
		break;
	}
}