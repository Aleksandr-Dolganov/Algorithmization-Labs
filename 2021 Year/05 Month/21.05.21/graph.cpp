#include "graph.h"

struct trailer {
	struct lider* id;
	struct trailer* next;
};
struct lider {
	int key;
	int count;
	struct lider* next;
	struct trailer* trail;
};

graph::graph() {
	headlider = nullptr;
	endlider = nullptr;
	N = 0;
	smeg = nullptr;
	C = nullptr;
}
graph::~graph() {}
void graph::readDataToList(std::string dir) {
	std::ifstream file;
	file.open(dir);
	int a, b, c, ** matr;
	file >> N;
	matr = new int* [N];
	for (int i = 0; i < N; i++) {
		matr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matr[i][j] = INT8_MAX;
		}
	}
	C = matr;
	while (!file.eof()) {
		file >> a >> b >> c;
		addtoc(a - 1, b - 1, c);
		add(a, b);
	}
	file.close();
}
bool graph::empty() {
	return headlider == nullptr;
}
lider* graph::createlider(int vert) {
	lider* tmp = new lider;
	tmp->key = vert;
	tmp->count = 0;
	tmp->next = nullptr;
	tmp->trail = nullptr;
	return tmp;
}
trailer* graph::createtrailer(lider* smeg) {
	trailer* tmp = new trailer;
	tmp->id = smeg;
	tmp->next = nullptr;
	return tmp;
}
lider* graph::search(int vert) {
	lider* cur = headlider;
	while (cur != nullptr and cur->key != vert) {
		cur = cur->next;
	}
	return cur;
}
void graph::add(int v, int w) {
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
void graph::printList(std::string dir) {
	lider* curlider;
	trailer* curtrailer;
	std::fstream file;
	file.open(dir, std::fstream::app);
	curlider = headlider;
	while (curlider != nullptr) {
		file << curlider->key << " -> " << curlider->count << " : ";
		curtrailer = curlider->trail;
		while (curtrailer != nullptr) {
			file << curtrailer->id->key << " ";
			curtrailer = curtrailer->next;
		}
		file << "null" << std::endl;
		curlider = curlider->next;
	}
	file << std::endl;
	file.close();
}
void graph::topSortList() {
	lider* curlider = headlider, * newhead = headlider, * newend = endlider;
	trailer* curtrail;
	int count = 0, VCount = 0, i = 0, inf = 0;
	while (curlider != nullptr) {
		VCount++;
		curlider = curlider->next;
	}
	curlider = headlider;
	lider** adres = new lider * [VCount];
	int o = 0, j = 0;
	while (curlider != nullptr) {
		adres[o] = curlider;
		curlider = curlider->next;
		adres[o]->next = nullptr;
		o++;
	}
	o = 0;
	int* vis = new int[VCount], tmp = 0, g = 0;
	for (int i = 0; i < VCount; i++) {
		vis[i] = 0;
	}
	while (i < VCount and inf < 50) {
		j = 0;
		while (j < VCount) {
			for (int l = 0; l < VCount; l++) {
				if (adres[j]->key == vis[l]) tmp++;
			}
			if (adres[j]->count == 0 and tmp == 0) {
				if (count == 0) {
					vis[g] = adres[j]->key;
					g++;
					newhead = adres[j];
					newend = adres[j];
					curtrail = newend->trail;
					while (curtrail != nullptr) {
						curtrail->id->count -= 1;
						curtrail = curtrail->next;
					}
					newend->trail = nullptr;
					i++;
					count++;
				}
				else {
					vis[g] = adres[j]->key;
					g++;
					newend->next = adres[j];
					newend = newend->next;
					curtrail = newend->trail;
					while (curtrail != nullptr) {
						curtrail->id->count -= 1;
						curtrail = curtrail->next;
					}
					newend->trail = nullptr;
					i++;
				}
			}
			tmp = 0;
			j++;
		}
		inf++;
	}
	if (inf >= 50) {
		std::cout << "ERROR 123: INFINITY LOOP";
	}
	else {
		headlider = newhead;
		endlider = newend;
	}
}
void graph::createSmeg(int a, int b) {
	smeg[a][b] = 1;
}
void graph::readDataToMatr(std::string dir) {
	std::ifstream file;
	int a, b, c, ** matr, ** matr2;
	file.open(dir);
	file >> N;
	matr = new int* [N];
	matr2 = new int* [N];
	for (int i = 0; i < N; i++) {
		matr[i] = new int[N];
		matr2[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matr[i][j] = 0;
			matr2[i][j] = INT8_MAX;
		}
	}
	C = matr2;
	smeg = matr;
	while (!file.eof()) {
		file >> a >> b >> c;
		addtoc(a - 1, b - 1, c);
		createSmeg(a - 1, b - 1);
	}
	file.close();
}
void graph::printMatr(std::string dir) {
	std::fstream file;
	file.open(dir, std::fstream::app);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			file << smeg[i][j] << "\t";
		}
		file << std::endl;
	}
	file << std::endl;
	file.close();
}
void graph::topSortMatr(std::string dir) {
	int col = 0;
	std::fstream file;
	file.open(dir, std::fstream::app);
	while (col < N) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
			{
				if (smeg[j][i] > 0) { tmp = 1; }
			}
			if (tmp == 0) {
				for (int j = 0; j < N; j++)
				{
					if (smeg[i][j] != 2) { smeg[i][j] = 0; }
				}
				smeg[0][i] = 2;
				col++;
				file << i + 1 << " ";
			}
			tmp = 0;
		}
	}
	file << std::endl << std::endl;
	file.close();
}
void graph::addtoc(int a, int b, int c) {
	C[a][b] = c;
}
void graph::printC(std::string dir) {
	std::fstream file;
	file.open(dir, std::fstream::app);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			file << C[i][j] << "\t";
		}
		file << std::endl;
	}
	file << std::endl;
	file.close();
}
void graph::diextra(int start, std::string dir) {
	int v0 = start - 1;
	int* S = new int[N];
	int* parent = new int[N];
	int* d = new int[N];
	for (int i = 0; i < N; i++) {
		d[i] = C[v0][i];
		S[i] = 0;
		parent[i] = -1;
	}
	while (!S[v0]) {
		S[v0] = 1;
		int min_d = INT8_MAX;
		for (int i = 0; i < N; i++) {
			if (!S[i] and d[i] < min_d) {
				v0 = i;
				min_d = d[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (!S[i] and smeg[v0][i]) {
				if (d[i] > d[v0] + C[v0][i]) {
					d[i] = d[v0] + C[v0][i];
					parent[i] = v0;
				}
			}
		}
	}
	printDiextra(d, dir);
}
void graph::printDiextra(int* d, std::string dir) {
	std::fstream file;
	file.open(dir, std::fstream::app);
	for (int i = 0; i < N; i++) {
		file << d[i] << "\t";
	}
	file << std::endl << std::endl;
	file.close();
}