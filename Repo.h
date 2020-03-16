#pragma once
#include "Cheltuieli_familie.h"

class Repo {
private:
	Cheltuieli_familie cheltuieli[100];
	int n;
public:

	Repo();
	~Repo();
	void addElem(Cheltuieli_familie c);
	Cheltuieli_familie* getAll();
	int getSize();



};
