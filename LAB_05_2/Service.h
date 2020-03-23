#pragma once
#include "Repo.h"


class Service {
private:
	Repo repoCheltuialaFamilie;
public:


	int getCurrentDay();
	void addCurrentDayCheltuiala(int suma, char* tip);
	void addCheltuiala(int zi, int suma, char* tip);
	Cheltuieli_familie* getAll();
	void deleteElemByDay(int day);
	void deleteElemByDayInterval(int day1, int day2);
	void deleteElemByType(char* tip);
	void getElemByType(char* type, Cheltuieli_familie cheltuieli[], int& resultlen);
	void getElemByCondAndType(int nr, char* tip, Cheltuieli_familie cheltuieli[], int& resultlen);
	void getElemByCond2AndType(int nr, char* tip, Cheltuieli_familie cheltuieli[], int& resultlen);
	int sumElemByType(char* tip);
	int maxDayBySum();
	void sortBySumDesc(Cheltuieli_familie cheltuieli[], int& resultlen);
	void sortBySumAndType(char* tip, Cheltuieli_familie cheltuieli[], int& resultlen);
	void filterByType(char* tip);
	int getSizeRepo();
	void filterByTypeAndCond(int nr, char* tip);
	void filterByTypeAndCondEq(int nr, char* tip);
	int getBuget();
	void update(int day1, int sum1, char* tip1, int day2, int sum2, char* tip2);


};