#include <iostream>

/* 1. Дана строка. Подсчитать, сколько в ней букв y, x, z */

int main()
{
	char a[40];
	gets_s(a);
	int county = 0, countx = 0, countz = 0, size = strlen(a);
	for(int i = 0; i < size; i++)
	{
		if(a[i] == 'y')
		{
			county++;
		}
		if(a[i] == 'z')
		{
			countz++;
		}
		if(a[i] == 'x')
		{
			countx++;
		}
	}
	std::cout << "x=" << countx << "\ny=" << county << "\nz=" << countz;
	return 0;
}