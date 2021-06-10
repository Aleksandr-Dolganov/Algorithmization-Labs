 #pragma once
#include <iostream>
#include <fstream>
#include <string>

struct trailer;
struct lider;

class graph {
	lider* headlider;
	lider* endlider;
	int N;
	int** smeg;
	int** C;
	char* color;
private:
	bool empty();
	lider* createlider(int);
	trailer* createtrailer(lider*);
	lider* search(int);
	void add(int, int);
	void createSmeg(int, int);
	void addtoc(int, int, int);
	void printDiextra(int*, std::string);
	void depthSearch(int, int);
public:
	graph();
	~graph();
	/// <summary>
	/// Чтение данных из файла и запись в матрицу смежности.
	/// </summary>
	/// <param name="dir">Путь к файлу с данными.</param>
	void readDataToMatr(std::string dir);
	/// <summary>
	/// Чтение данных из файла и запись в список смежности.
	/// </summary>
	/// <param name="dir">Путь к файлу с данными.</param>
	void readDataToList(std::string dir);
	/// <summary>
	/// Вывод матрицы смежности в файл.
	/// </summary>
	/// <param name="dir">Путь к файлу вывода.</param>
	void printMatr(std::string dir);
	/// <summary>
	/// Вывод списка смежности в файл.
	/// </summary>
	/// <param name="dir">Путь к файлу вывода.</param>
	void printList(std::string dir);
	/// <summary>
	/// Топологическая сортировка матрицы смежности и вывод в файл.
	/// </summary>
	/// <param name="dir">Путь к файлу вывода.</param>
	void topSortMatr(std::string dir);
	/// <summary>
	/// Топологическая сортировка списка смежности.
	/// </summary>
	void topSortList();
	/// <summary>
	/// Вывод матрицы цен в файл.
	/// </summary>
	/// <param name="dir">Путь к файлу вывода.</param> 
	void printC(std::string dir);
	/// <summary>
	/// Алгоритм Диекстра.
	/// </summary>
	/// <param name="dir">Путь к файлу вывода.</param>
	/// <param name="start">Точка из которой ищутся пути.</param>
	void diextra(int start, std::string dir);
	/// <summary>
	/// Алгоритм поиска в глубину.
	/// </summary>
	/// <param name="v1">Вершина начала поиска.</param>
	void depthSort(int v1);
};