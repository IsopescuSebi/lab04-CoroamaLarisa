#pragma once
#include "Cheltuieli_familie.h"

class Repo {
private:
	Cheltuieli_familie cheltuieli[100];
	int n;
	int buget;
public:

	Repo();
	~Repo();
	Repo(Cheltuieli_familie cheltuieli[], int n, int buget);
	void addElem(Cheltuieli_familie c);
	Cheltuieli_familie* getAll();
	int getSize();
	int getBuget();
	void stergere(Cheltuieli_familie c);
	int cautare(const Cheltuieli_familie& c);
	void setSize(int n);
	Repo& operator=(Repo& r);
	void setBuget(int n);
	void update(Cheltuieli_familie c1,Cheltuieli_familie c2);
};
