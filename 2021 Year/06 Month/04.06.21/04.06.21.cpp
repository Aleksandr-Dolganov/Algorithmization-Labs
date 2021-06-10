#include "graph.h"

int main()
{
	graph G;
	G.readDataToMatr("data.txt");
	//G.printMatr("out.txt");
	int a;
	std::cin >> a;
	G.depthSort(a);
	G.topSortMatr("out.txt");
}