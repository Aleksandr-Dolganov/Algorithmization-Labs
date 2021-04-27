#include <iostream>
#include <string>

void matr_show(int** a, int x, int y);

/*3. Составить программу, которая по данной символьной строке формирует
	числовой двумерный массив размера 5 на 4, содержащий коды символов,
	составляющих строку. Строку записываем посимвольно змейкой, начиная слева на право.
	Если длина строки короче, чем количество элементов массива, то добавьте пробелы
	или удалите лишние символы.*/

int main()
{
	char str[99];
	gets_s(str);
	int h = 0;
	int** A = NULL;
	A = (int**)malloc(4 * sizeof(int*));
	for(int i = 0; i < 4; i++)
	{
		A[i] = (int*)malloc(5 * sizeof(int));
		if(i % 2 == 0)
		{
			for(int j = 0; j < 5; j++)
			{
				if((int)str[h] != -2)
				{
					A[i][j] = (int)str[h];
					h++;
				}
				else
				{
					A[i][j] = 0;
				}
			}
		}
		else
		{
			for(int g = 4; g >= 0; g--)
			{
				if((int)str[h] != -2)
				{
					A[i][g] = (int)str[h];
					h++;
				}
				else
				{
					A[i][g] = 0;
				}
			}
		}
	}
	matr_show(A, 4, 5);
	return 0;
}

void matr_show(int** a, int x, int y)
{
	std::cout << "\n";
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << "\n\n";
	}
}