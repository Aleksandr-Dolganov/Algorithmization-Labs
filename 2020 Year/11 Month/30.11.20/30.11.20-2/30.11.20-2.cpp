#include <iostream>
#include <fstream>
using namespace std;

/*2.  Дан файл input.txt содержащий целые числа. Записать в файл  output.txt
компоненты исходного файла, являющиеся простыми числами.*/

int main()
{
	ifstream file("E:\\file\\2\\input.txt");
	ofstream output("E:\\file\\2\\output.txt");
	int a[99], j = 0;
	bool flag = false;
	for(int i = 0; i < 99 and !file.eof(); i++)
	{
		file >> a[i];
		j++;
	}
	for(int k = 0, n = 0; k < j; k++)
	{
		for(int i = 1; i * i <= a[k]; i++)
		{
			if(a[k] % i == 0)
			{
				n++;
			}
			if(n > 1)
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
		if(flag and a[k] != 1)
		{
			output << a[k] << " ";
			cout << a[k] << " ";
		}
		flag = true;
		n = 0;
	}

	file.close();
	output.close();
}