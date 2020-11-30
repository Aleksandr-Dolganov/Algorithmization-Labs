#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*1.  Имеется текстовый файл input.txt Сформировать новый файл, содержащий слова,
сформированные из первых букв слов каждой строки исходного файла.
Результат работы программы (вывод) поместить в отдельный текстовый файл
(например, output.txt ), продублировав на экране.*/

int main()
{
	ifstream file;
	file.open("E:\\file\\1\\input.txt");
	string s[99];
	int i = 0, j = 0;
	while(!file.eof())
	{
		file >> s[i];
		j++;
		i++;
	}
	for(int i = 0; i < j; i++)
	{
		cout << s[i][0, 0];
	}
	ofstream output;
	output.open("E:\\file\\1\\output.txt");
	for(int i = 0; i < j; i++)
	{
		output << s[i][0, 0];
	}
	file.close();
	output.close();
}