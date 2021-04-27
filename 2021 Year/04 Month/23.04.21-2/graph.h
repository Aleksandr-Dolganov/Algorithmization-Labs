#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct trailer {
	struct lider* id;
	struct trailer* next;
}; trailer;

struct lider {
	int key;
	int count;
	struct lider* next;
	struct trailer* trail;
}; lider;

class graph {
	lider* headlider;
	lider* endlider;
private:
	bool empty() {
		return headlider == nullptr;
	}

	lider* createlider(int vert) {
		lider* tmp = new lider;
		tmp->key = vert;
		tmp->count = 0;
		tmp->next = nullptr;
		tmp->trail = nullptr;
		return tmp;
	}

	trailer* createtrailer(lider* smeg) {
		trailer* tmp = new trailer;
		tmp->id = smeg;
		tmp->next = nullptr;
		return tmp;
	}

	lider* search(int vert) {
		lider* cur = headlider;
		while (cur != nullptr and cur->key != vert) {
			cur = cur->next;
		}
		return cur;
	}

public:
	graph()
		:headlider{ nullptr }
		, endlider{ nullptr }
	{}
	~graph() {}

	void add(int v, int w) {
		lider* curV, * curW;
		trailer* temptrailer, * curtrailer;
		if (empty()) {
			curV = createlider(v);
			curW = createlider(w);
			curV->next = curW;
			temptrailer = createtrailer(curW);
			curV->trail = temptrailer;
			curW->count++;
			headlider = curV;
			endlider = curW;
		}
		else {
			curV = search(v);
			curW = search(w);
			if (curV == nullptr) {
				curV = createlider(v);
				endlider->next = curV;
				endlider = curV;
			}
			if (curW == nullptr) {
				curW = createlider(w);
				endlider->next = curW;
				endlider = curW;
			}
			temptrailer = createtrailer(curW);
			curW->count++;
			if (curV->trail != nullptr) {
				curtrailer = curV->trail;
				while (curtrailer->next != nullptr) {
					curtrailer = curtrailer->next;
				}
				curtrailer->next = temptrailer;
			}
			else {
				curV->trail = temptrailer;
			}
		}
	}

	void print() {
		lider* curlider;
		trailer* curtrailer;
		std::ofstream file;
		file.open("out.txt");
		curlider = headlider;
		while (curlider != nullptr) {
			file << curlider->key << " : ";
			curtrailer = curlider->trail;
			while (curtrailer != nullptr) {
				file << curtrailer->id->key << " ";
				curtrailer = curtrailer->next;
			}
			file << "null" << std::endl;
			curlider = curlider->next;
		}
	}

};