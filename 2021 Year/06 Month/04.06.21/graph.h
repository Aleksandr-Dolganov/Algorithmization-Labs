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
	/// ������ ������ �� ����� � ������ � ������� ���������.
	/// </summary>
	/// <param name="dir">���� � ����� � �������.</param>
	void readDataToMatr(std::string dir);
	/// <summary>
	/// ������ ������ �� ����� � ������ � ������ ���������.
	/// </summary>
	/// <param name="dir">���� � ����� � �������.</param>
	void readDataToList(std::string dir);
	/// <summary>
	/// ����� ������� ��������� � ����.
	/// </summary>
	/// <param name="dir">���� � ����� ������.</param>
	void printMatr(std::string dir);
	/// <summary>
	/// ����� ������ ��������� � ����.
	/// </summary>
	/// <param name="dir">���� � ����� ������.</param>
	void printList(std::string dir);
	/// <summary>
	/// �������������� ���������� ������� ��������� � ����� � ����.
	/// </summary>
	/// <param name="dir">���� � ����� ������.</param>
	void topSortMatr(std::string dir);
	/// <summary>
	/// �������������� ���������� ������ ���������.
	/// </summary>
	void topSortList();
	/// <summary>
	/// ����� ������� ��� � ����.
	/// </summary>
	/// <param name="dir">���� � ����� ������.</param> 
	void printC(std::string dir);
	/// <summary>
	/// �������� ��������.
	/// </summary>
	/// <param name="dir">���� � ����� ������.</param>
	/// <param name="start">����� �� ������� ������ ����.</param>
	void diextra(int start, std::string dir);
	/// <summary>
	/// �������� ������ � �������.
	/// </summary>
	/// <param name="v1">������� ������ ������.</param>
	void depthSort(int v1);
};