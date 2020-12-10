#include <iostream>
#include <Windows.h> // для SetConsoleCP(1251) и SetConsoleOutputCP(1251)

int menu_exit;

struct sportsmen
{
	char surname[20];
	int age;
	char sport[20];
};
void Menu(sportsmen*, int);
void data_input(sportsmen*, int);
void data_output(sportsmen*, int);
void data_sort(sportsmen*, int);
void data_find(sportsmen*, int);

/*  Информация о спортсменах: Ф.И.О., возраст и вид спорта хранится в динамическом массиве.
	Реализовать: 1. Ввод данных, 2. Вывод данных, 3. Сортировка по алфавиту, 4.
	Вывод информации о спортсменах заданного вида спорта с клавиатуры.*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Ввод/вывод русского языка (setlocale не поддерживает ввод русских букв с клавиатуры)
	int size;
	std::cout << "Введите количество студентов: ";
	std::cin >> size;
	system("cls");
	sportsmen* stud;
	stud = (sportsmen*)malloc(size * sizeof(sportsmen));
	do
	{
		Menu(stud, size);
	}
	while(menu_exit != 5);
}

void Menu(sportsmen* stud, int size)
{
	system("cls");
	int menu;
	std::cout << "1) Ввод данных." << "\n2) Вывод данных." << "\n3) Сортировка по алфавиту." << "\n4) Поиск." << "\n5) Выход из программы.\n" << "Действие: ";
	std::cin >> menu;
	switch(menu)
	{
		case 1: data_input(stud, size); break;
		case 2: data_output(stud, size); break;
		case 3: data_sort(stud, size); break;
		case 4: data_find(stud, size); break;
		case 5: menu_exit = 5; break;
	}
}

void data_input(sportsmen* stud, int size)
{
	system("cls");
	int n;
	std::cout << "Введите номер студента: \n";
	std::cin >> n;
	std::cout << "Введите фамилию студента:\n";
	std::cin >> stud[n - 1].surname;
	std::cout << "Введите возраст студента:\n";
	std::cin >> stud[n - 1].age;
	std::cout << "Каким видом спортом занимается студент:\n";
	std::cin >> stud[n - 1].sport;
}

void data_output(sportsmen* stud, int size)
{
	system("cls");
	int n;
	std::cout << "Введите номер студента: \n";
	std::cin >> n;
	std::cout << "Фамилия студента: " << stud[n - 1].surname << "\nВозраст студента: " << stud[n - 1].age << "\nВид спорта: " << stud[n - 1].sport << "\n";
	system("PAUSE");
}

void data_sort(sportsmen* stud, int size)
{
	for(int q = 0; q < size - 1; q++)
	{
		for(int w = 0; w < size - q - 1; w++)
		{
			if(stud[w].surname[1] < stud[w + 1].surname[1])
			{
				char tmpsurname[20], tmpsport[20];
				int tmpage;
				strcpy_s(tmpsurname, stud[w].surname);
				tmpage = (int)stud[w].age;
				strcpy_s(tmpsport, stud[w].sport);

				strcpy_s(stud[w].surname, "");
				strcpy_s(stud[w].surname, stud[w + 1].surname);
				stud[w].age = stud[w + 1].age;
				strcpy_s(stud[w].sport, "");
				strcpy_s(stud[w].sport, stud[w + 1].sport);

				strcpy_s(stud[w + 1].surname, "");
				strcpy_s(stud[w + 1].surname, tmpsurname);
				stud[w + 1].age = tmpage;
				strcpy_s(stud[w + 1].sport, "");
				strcpy_s(stud[w + 1].sport, tmpsport);
			}
		}
	}
}

void data_find(sportsmen* stud, int size)
{
	system("cls");
	char surfind[20];
	int flag = 0;
	std::cout << "Введите фамилию студента которого хотите найти: ";
	std::cin >> surfind;
	for(int i = 0; i < size; i++)
	{
		if(!strcmp(surfind, stud[i].surname))
		{
			std::cout << "Номер студента: " << i + 1 << "\nФамилия: " << stud[i].surname << "\nВозраст: " << stud[i].age << "\nВид спорта: " << stud[i].sport << "\n";
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		std::cout << "Студента с такой фамилией нет в базе.\n";
	}
	system("PAUSE");
}