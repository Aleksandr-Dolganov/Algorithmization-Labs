#include<iostream>
#include<Windows.h>
#include<string.h>
#include<time.h>
/*  Создайте структуру персонажа (Hero). Задайте имя персонажу – поле name, уровень развитие 1 – поле level,
сгенерируйте случайным образом вид  персонажа (от 0 до 2, пусть роли распределятся так: 0 – воин, 1 – маг, 2 – лучник) – поле kind.
В зависимости от вида персонажа задайте здоровье – поле health. Пусть здоровье воина будет 100, мага – 50, лучника – 75.
Сгенерируйте случайным образом 5 предметов персонажа – массив из 5 элементов поле items. Напишите функцию вывода информации о персонаже на экран.
Выведите информацию о персонажах согласно критерию:
1.	вывести только лучников
2.	вывести воинов или магов со здоровьем менее 50
3.	вывести героев у которых есть предмет равный 3
4.	вывести героев у которых есть предмет 2 или 4 */

using namespace std;

struct hero
{
	char name[20];
	int health;
	int level;
	int kind; // 0 воин 1 маг, 2 лучник
	int items[5];
};

void createhero(hero *heroes, int count);
void outhero(hero* heroes, int number);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	time((unsigned)NULL);
	int n;
	hero* heroes;
	cout << "Введите количество героев: ";
	cin >> n;
	heroes = (hero*)malloc(sizeof(hero) * n);
	for (int i = 0; i < n; i++) {
		createhero(heroes, i);
	}
	system("cls");
	for (int i = 0; i < n; i++) {
		outhero(heroes, i);
	}
	system("PAUSE");
	system("cls");
	cout << "Только лучники:\n";
	for (int i = 0; i < n; i++) {
		if (heroes[i].kind == 2) {
			outhero(heroes, i);
		}
	}
	system("PAUSE");
	system("cls");
	cout << "Воины или маги со здоровьем менее 50\n";
	for (int i = 0; i < n; i++) {
		if (heroes[i].kind == 0 or heroes[i].kind == 1) {
			if (heroes[i].health < 50) {
				outhero(heroes, i);
			}
		}
	}
	system("PAUSE");
	system("cls");
	cout << "Герои у которых есть предмет равный 3\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) { 
			if (heroes[i].items[j] == 3) {
				outhero(heroes, i);
				break;
			}
		}
	}
	system("PAUSE");
	system("cls");
	cout << "Герои у которых есть предмет равный 2 или 4\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (heroes[i].items[j] == 2 or heroes[i].items[j]==4) {
				outhero(heroes, i);
				break;
			}
		}
	}
	system("PAUSE");
	return 0;
}

void createhero(hero* heroes, int count)
{
	system("cls");
	cout << "Введите имя персонажа " << count+1 << " персонажа: ";
	cin >> heroes[count].name;
	heroes[count].level = 1;
	heroes[count].kind = rand() % 3;
	switch (heroes[count].kind) 
	{
		case 0:heroes[count].health = rand() % 101; break;
		case 1:heroes[count].health = rand() % 51; break;
		case 2:heroes[count].health = rand() % 76; break;
	}
	for (int i = 0; i < 5; i++) 
	{
		heroes[count].items[i] = rand() % 6;
	}
	count++;
}

void outhero(hero* heroes, int number) {
	cout << "Имя: " << heroes[number].name << "\nУровень: " << heroes[number].level << "\nЗдоровье: " << heroes[number].health;
	switch (heroes[number].kind) {
	case 0: cout << "\nТип: Воин" << "\n\n"; break;
	case 1: cout << "\nТип: Маг" << "\n\n"; break;
	case 2: cout << "\nТип: Лучник" << "\n\n"; break;
	}
}