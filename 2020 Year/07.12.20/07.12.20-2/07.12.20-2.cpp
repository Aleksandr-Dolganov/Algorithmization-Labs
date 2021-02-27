#include <iostream>
#include <string>

/*2. Дана строка, содержащая английский текст. 
	Найти количество слов, начинающихся с буквы f.*/

int main()
{
	char a[99];
	gets_s(a);
	int i = 1, fword = 0, size = strlen(a);
	if(a[0] == 'f' or a[i] == 'F')
	{
		fword++;
	}
	for(; i < size; i++)
	{
		if((a[i] == 'f' or a[i] == 'F') and (a[i - 1] == ' '))
		{
			fword++;
		}
	}
	std::cout << "Count of fwords=" << fword;
	return 0;
}