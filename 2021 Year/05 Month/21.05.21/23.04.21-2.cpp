#include "graph.h"

/*	Граф - класс. Список/матрица смежности.
	Топологическая сортировка на списке/матрице смежности
	Алгоритм Диекстры	*/

int main()
{
	graph G;
	G.readDataToList("dataTopSort.txt");
	G.printList("outL.txt");
	G.topSortList();
	G.printList("outL.txt");
	G.readDataToMatr("dataTopSort.txt");
	G.printMatr("outM.txt");
	G.topSortMatr("outM.txt");
	G.printMatr("outM.txt");
	G.readDataToMatr("dataDiextra.txt");
	G.printC("outM.txt");
	G.diextra(1, "outM.txt");
	return 0;
}