#include "Repo.h"
#include <cstddef>

Repo::Repo() {
	this->n = 0;
}


Repo::~Repo() {
	this->n = 0;
}

int Repo::getSize() {
	return this->n;
}

void Repo::addElem(Cheltuieli_familie c) {
	this->cheltuieli[this->n++] = c;
}

Cheltuieli_familie* Repo::getAll() {
	return this->cheltuieli;
}
