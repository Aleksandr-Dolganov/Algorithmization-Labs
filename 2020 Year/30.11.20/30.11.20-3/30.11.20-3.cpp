#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*3. Дан текстовый файл. Подсчитать количество строк в файле,
количество слов, количество чисел и найти самое длинное слово в файле.*/

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("E:\\file\\3\\input.txt");
	ofstream output("E:\\file\\3\\output.txt");
	int strcount = 0, words = 0, maxwordlenght = 0, maxwordposition = 0, numbers = 0;
	string s1, s2;
	while(!file.eof())
	{
		getline(file, s1);
		for(int i = 0; i < s1.length(); i++)
		{
			int p = i;
			if((s1[i] >= 'a' and s1[i] <= 'z') or (s1[i] >= 'A' and s1[i] <= 'Z'))
			{
				p++;
				words++;
				while((s1[p] >= 'a' and s1[p] <= 'z') or (s1[p] >= 'A' and s1[p] <= 'Z'))
				{
					p++;
				}
				if(p >= maxwordlenght)
				{
					maxwordlenght = p;
					maxwordposition = i;
					s2 = s1;
				}
				i = p;
				p = 0;
			}
			if(s1[i] >= '0' and s1[i] <= '9')
			{
				numbers++;
				while(s1[i] >= '0' and s1[i] <= '9')
				{
					i++;
				}
			}
		}
		strcount++; // Количество строк
	}
	output << "Количество цифр = " << numbers << "\nКоличество слов = " << words << "\nКоличество строк = " << strcount << "\nСамое длинное слово = " << s2.substr(maxwordposition, maxwordlenght);
	cout << "Количество цифр = " << numbers << "\nКоличество слов = " << words << "\nКоличество строк = " << strcount << "\nСамое длинное слово = " << s2.substr(maxwordposition, maxwordlenght);
	file.close();
	output.close();
}