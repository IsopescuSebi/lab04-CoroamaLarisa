#include <ctime>
#include "Service.h"

int Service::getCurrentDay() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_mday;
}


/*
ex. adaugă 10 internet - adaugă pentru ziua curentă o cheltuială de 10 RON
pentru internet

*/

void Service::addCurrentDayCheltuiala(int suma, char* tip) {

	int currentDay = getCurrentDay();
	Cheltuieli_familie newCheltuiala(currentDay, suma, tip);
	this->repoCheltuialaFamilie.addElem(newCheltuiala);

}



/*ex. inserează 25 100 mâncare - inserează pentru ziua 25 a lunii curente o
cheltuială de 100 RON pentru mâncare
*/

void Service::addCheltuiala(int zi, int suma, char* tip) {

	Cheltuieli_familie newCheltuiala(zi, suma, tip);
	this->repoCheltuialaFamilie.addElem(newCheltuiala);
}

/*get All cheltuieli*/

Cheltuieli_familie* Service::getAll() {

	return this->repoCheltuialaFamilie.getAll();
}

/*ex. elimină 15 - elimină toate cheltuielile din ziua 15
*/

void Service::deleteElemByDay(int day) {


	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {

		if (this->getAll()[i].get_zi() == day) {
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
			i--;
		}
	}
}

/*ex. elimină 2 la 9 - elimină toate cheltuielile pentru zilele 2,3, ..., 9*/

void Service::deleteElemByDayInterval(int day1, int day2) {

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {

		if (this->getAll()[i].get_zi() >= day1 && this->getAll()[i].get_zi() <= day2) {
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
			i--;
		}
	}

}

/*ex. elimină mâncare - elimină totate cheltuielile pentru mâncare din luna
curentă.*/

void Service::deleteElemByType(char* tip) {

	int i = 0;

	while (i < this->repoCheltuialaFamilie.getSize()) {

		if (strcmp(this->getAll()[i].get_tip(), tip) == 0) {
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);

		}
		else
			i++;
	}
}

/*
ex. listează mancare - afi?area tuturor cheltuielilor pentru mâncare
*/

void Service::getElemByType(char* tip, Cheltuieli_familie cheltuieli[], int& resultlen) {

	resultlen = 0;
	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0) {
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

/*
ex. listează mâncare > 5 - afi?area tuturor cheltuielilor pentru mâncare mai
mari de 5 RON
*/

void Service::getElemByCondAndType(int nr, char* tip, Cheltuieli_familie cheltuieli[], int& resultlen) {

	resultlen = 0;
	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0 && this->getAll()[i].get_suma_bani() > nr) {
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

/*ex. listează internet = 44 - afi?area tuturor cheltuielilor pentru internet în
valoare de 44 RON */


void Service::getElemByCond2AndType(int nr, char* tip, Cheltuieli_familie cheltuieli[], int& resultlen) {

	resultlen = 0;
	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0 && this->getAll()[i].get_suma_bani() == nr) {
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

/* ex. suma mâncare - suma tuturor cheltuielilor din categoria mâncare*/

int Service::sumElemByType(char* tip) {
	int sum = 0;

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0) {
			sum += this->getAll()[i].get_suma_bani();
		}
	}

	return sum;

}

/*ex. max zi - afișarea zilei cu cele mai mari cheltuieli */


int Service::maxDayBySum() {
	int v[32] = { 0 };
	int max = -1;
	int max_zi = -1;
	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {

		v[this->getAll()[i].get_zi()] += this->getAll()[i].get_suma_bani();

		if (v[this->getAll()[i].get_zi()] > max) {
			max = v[this->getAll()[i].get_zi()];
			max_zi = this->getAll()[i].get_zi();

		}

	}

	return max_zi;

}

/* ex. sortare zi - afișarea sumelor cheltuite zilnic în ordine descrescătoare
*/

void Service::sortBySumDesc(Cheltuieli_familie cheltuieli[], int& resultlen) {

	int done = 1;
	resultlen = 0;

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++)
		cheltuieli[resultlen++] = this->getAll()[i];

	while (done == 1) {
		done = 0;
		for (int i = 0; i < resultlen - 1; i++)
			if (cheltuieli[i].get_suma_bani() < cheltuieli[i + 1].get_suma_bani())
			{
				Cheltuieli_familie aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;

				done = 1;
			}
	}

}


/*ex. sortează mâncare - afișarea sumelor cheltuite zilnic pentru mâncare,
ordonate crescător */

void Service::sortBySumAndType(char* tip, Cheltuieli_familie cheltuieli[], int& resultlen) {

	int done = 1;
	resultlen = 0;

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++)
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0)
			cheltuieli[resultlen++] = this->getAll()[i];

	while (done == 1) {
		done = 0;
		for (int i = 0; i < resultlen - 1; i++)
			if (cheltuieli[i].get_suma_bani() > cheltuieli[i + 1].get_suma_bani())
			{
				Cheltuieli_familie aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;

				done = 1;
			}

	}

}

/*ex. filtrare mâncare - păstrează doar cheltuielile pentru mâncare
*/

void Service::filterByType(char* tip) {

	int i = 0;

	while (i < this->repoCheltuialaFamilie.getSize()) {
		if (strcmp(this->getAll()[i].get_tip(), tip) != 0)
		{
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);

		}
		else
			i++;
	}

}

/*lungimea lui repo*/


int Service::getBuget() {

	return this->repoCheltuialaFamilie.getBuget();
}

int Service::getSizeRepo() {
	return this->repoCheltuialaFamilie.getSize();
}

/*ex. filtrare haine = 59 - păstrează doar cheltuielile pentru haine egale cu 59
RON */



void Service::filterByTypeAndCondEq(int nr, char* tip) {

	int i = 0;

	while (i < this->repoCheltuialaFamilie.getSize()) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0 && this->getAll()[i].get_suma_bani() != nr)
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
		else if (strcmp(this->getAll()[i].get_tip(), tip) != 0)
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
		else
			i++;

	}

}

/*filtrare dupa tip si conditie cum ar fi >50 RON */

void Service::filterByTypeAndCond(int nr, char* tip) {

	int i = 0;

	while (i < this->repoCheltuialaFamilie.getSize()) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0 && this->getAll()[i].get_suma_bani() >= nr)
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
		else if (strcmp(this->getAll()[i].get_tip(), tip) != 0)
			this->repoCheltuialaFamilie.stergere(this->getAll()[i]);
		else
			i++;

	}
}

/*update la o cheltuiala*/

void Service::update(int day1, int sum1, char* tip1, int day2, int sum2, char* tip2) {
	Cheltuieli_familie c1(day1, sum1, tip1);
	Cheltuieli_familie c2(day2, sum2, tip2);

	this->repoCheltuialaFamilie.update(c1, c2);
}