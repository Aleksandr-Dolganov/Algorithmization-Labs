#include "graph.h"

// Граф - класс. Список смежности.

int main()
{
	graph G;
	std::ifstream file;
	file.open("data.txt");
	int a, b;
	while (!file.eof()) {
		file >> a >> b;
		G.add(a, b);
	}
	G.print();
}