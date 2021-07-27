#include<iostream>
#include<Windows.h>
using namespace std;
char mat[3][3]; // Наше поле.
int check(int choice) // Функция проверяющая ввёл ли пользователь любой символ, кроме цифры.
{
	while (true)
	{
		if (cin.fail()) // если предыдущее извлечение было неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Нельзя вводить буквы!\nПопробуйте выбрать значение ещё раз: ";
			cin >> choice;
		}
		else
			return choice;
	}
}
void check_cell(char cell, int& res, char value) // Функция для проверки пустоты клетки
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cell == mat[i][j]) {
				mat[i][j] = value;
				res = 0;
			}
		}
	}
}
void check_pos(int& result) // Функция для проверки победной комбинации
{
	if ((mat[0][0] == mat[0][1] && mat[0][0] == mat[0][2]) ||
		(mat[0][0] == mat[1][0] && mat[0][0] == mat[2][0]) ||
		(mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2]) || 
		(mat[1][0] == mat[1][1] && mat[1][0] == mat[1][2]) ||
		(mat[2][0] == mat[2][1] && mat[2][0] == mat[2][2]) ||
		(mat[0][1] == mat[1][1] && mat[0][1] == mat[2][1]) ||
		(mat[0][2] == mat[1][2] && mat[0][2] == mat[2][2]) ||
		(mat[2][0] == mat[1][1] && mat[2][0] == mat[0][2]))
		{
		result = 1;
}
}
int game(char &value) // Функция начала нашей игры
{
	char cell; // Номер клетки
	int result = 0; // Для проверки победной комбинации
	for (int i = 0; i < 9; i++)
	{
		int pos = 1; // Переменная для определения занятости клетки
		if (i % 2 == 0)
			cout << "Ходит игрок №1: ";
		else
			cout << "Ходит игрок №2: ";
		while (pos > 0)
		{
			cin >> cell;
			check_cell(cell, pos, value);
			if (pos > 0)
				cout << "Данная позиция уже занята. Попробуйте выбрать клетку ещё раз: ";
		}
		system("cls");
		cout << "\n\n\n";
		for (int i = 0; i < 3; i++) {
			cout << "\t\t\t|  ";
			for (int j = 0; j < 3; j++) {
				cout << mat[i][j] << "  |  ";
			}
			cout << endl;
		}
		check_pos(result);
		if (result == 1)
			return result;
		if (value == 'X')
			value = '0';
		else
			value = 'X';
	}
	result = 2;
	return result;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t\t\tЗдравствуйте!\n\t\tЭто игра крестики нолики.\nПравила:\n\n1) Поле состоит из 9 клеток (матрица 3 на 3), один игрок ходит крестиками - это символ X, второй игрок ходит ноликами - это символ 0."
		<< "\n\n2)Каждый игрок ходит по очереди начиная с крестиков.\n\n3)Побеждает тот, кто собрал комбинацию из 3 крестиков или ноликов, по горизонтали, либо по вертикали, либо по диагонали.";
	int k = 0; // Переменная для заполнения матрицы чилами от 1 до 9
	int result; //Переменная для определения победы или ничьи
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat[i][j] = '1' + (char)k;
			k++;
		}
	}
	int choice;
	char value = 'X'; // Чем будет ходить первый игрок.
	cout << "\n\nВыберите, чем будет ходить первый игрок:\n\n1 - X\n2 - 0" << endl;
	cin >> choice;
	choice = check(choice);
	while (choice > 2 || choice < 1)
	{
		cout << "Такого значения нет, попробуйте ещё раз: ";
		cin >> choice;
		choice = check(choice);
	}
	if (choice == 2)
	{
		value = '0';
		cout << "\nПервый игрок ходит ноликами (0), второй игрок ходит крестиками (X)" << endl << endl;
	}
	else
	{
		cout << "\nПервый игрок ходит крестиками (X), второй игрок ходит ноликами (0)" << endl << endl;
	}
	cout << "\nЭто вид поля, цифра соответствует клетке, чтобы выбрать клетку для хода, нажмите соответствующую ей цифру." << endl;
	cout << "\t\t\t  1  |  2  |  3  \n";
	cout << "\t\t\t-----|-----|-----\n";
	cout << "\t\t\t  4  |  5  |  6  \n";
	cout << "\t\t\t-----|-----|-----\n";
	cout << "\t\t\t  7  |  8  |  9  \n";
	result = game(value);
	if (result == 2)
		cout << "\t\t\t\tНичья!" << endl;
	else
	{
		if (value == 'X')
			cout << "\n\n\t\tПоздравляем, победили крестики!" << endl;
		else
			cout << "\n\n\t\tПоздравляем, победили нолики!" << endl;
	}
	return 0;
}