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
private:
	bool empty();
	lider* createlider(int);
	trailer* createtrailer(lider*);
	lider* search(int);
	void add(int, int);
	void createSmeg(int, int);
	void addtoc(int, int, int);
	void printDiextra(int*, std::string);
public:
	graph();
	~graph();
	void readDataToMatr(std::string);
	void readDataToList(std::string);
	void printMatr(std::string);
	void printList(std::string);
	void topSortMatr(std::string);
	void topSortList();
	void printC(std::string);
	void diextra(int, std::string);
};