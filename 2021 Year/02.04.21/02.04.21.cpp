#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Графы. Топографическая сортировка на матрице смежности

void showMatr(int**, int);
int** createZeroMatr(int);
void topogrSort(int**, int);

int main()
{
	ifstream in;
	in.open("data.txt");
	int size;
	in >> size;
	int** graph = createZeroMatr(size);
	int i = 0, lenght = 0;
	while (!in.eof())
	{
		int a, b;
		in >> a >> b;
		graph[a-1][b-1] = 1;
	}
	in.close();
	showMatr(graph, size);
	ofstream output;
	output.open("data_o.txt");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			output << graph[i][j] << " ";
		}
		output << endl;
	}
	output.close();
	cout << endl;
	topogrSort(graph, size);
	cout << endl << endl;
	showMatr(graph, size);
}

void showMatr(int** matr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}

int** createZeroMatr(int size) {
	int** graph;
	graph = new int* [size];
	for (int i = 0; i < size; i++) {
		graph[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			graph[i][j] = 0;
		}
	}
	return graph;
}

void topogrSort(int** graph, int size) {
	int col = 0;
	fstream out;
	out.open("data_o.txt", fstream::app);
	out << endl;
	while (col < size) {
		int tmp = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				if (graph[j][i] > 0) { tmp = 1;}
			}
			if (tmp == 0) {
				for (int j = 0; j < size; j++)
				{
					if (graph[i][j] != 2) { graph[i][j] = 0; }
				}
				graph[0][i] = 2;
				col++;
				cout << i+1 << " ";
				out << i + 1 << " ";
			}
			tmp = 0;
		}
	}
	out.close();
}