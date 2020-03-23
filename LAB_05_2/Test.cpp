#include "Test.h"
#include <string.h>
#include <cassert>
#include "Service.h"

void test_cheltuieli_familie() {
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Cheltuieli_familie c1(3, 25, tip_1);
	Cheltuieli_familie c2(3, 25, tip_1);

	assert(c1.get_zi() == 3);
	assert(c1.get_suma_bani() == 25);
	assert(strcmp(c1.get_tip(), "haine") == 0);

	assert(c1 == c2);

	c1.set_zi(9);
	c1.set_suma_bani(200);
	c1.set_tip(tip_2);
	assert(c1.get_zi() == 9);
	assert(c1.get_suma_bani() == 200);
	assert(strcmp(c1.get_tip(), "mancare") == 0);

	delete[] tip_1;
	delete[] tip_2;

}

void test_repo_cheltuieli_familie() {

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Cheltuieli_familie c1(3, 50, tip_1);
	Cheltuieli_familie c2(6, 60, tip_2);

	Repo repository_cheltuieli_familie;
	repository_cheltuieli_familie.addElem(c1);
	repository_cheltuieli_familie.addElem(c2);
	assert(repository_cheltuieli_familie.getSize() == 2);

	assert(repository_cheltuieli_familie.getAll()[0] == c1);
	assert(repository_cheltuieli_familie.getAll()[1] == c2);

	assert(repository_cheltuieli_familie.getBuget() == 9890);

	delete[] tip_1;
	delete[] tip_2;


}

void test_eliminate_by_day_interval();
void test_get_by_condition();
void test_prop_based_on_sublist();
void test_sort_by_cond();
void test_filter_by_cond();

void test_service_cheltuieli_familie() {

	test_eliminate_by_day_interval();
	test_get_by_condition();
	test_prop_based_on_sublist();
	test_sort_by_cond();
	test_filter_by_cond();

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCurrentDayCheltuiala(100, tip_1);
	service_cheltuieli_familie.addCheltuiala(11, 100, tip_2);

	int currentDay = service_cheltuieli_familie.getCurrentDay();

	assert(service_cheltuieli_familie.getAll()[0].get_zi() == currentDay);
	assert(service_cheltuieli_familie.getAll()[1].get_zi() == 11);
	assert(service_cheltuieli_familie.getAll()[0].get_suma_bani() == 100);
	assert(service_cheltuieli_familie.getAll()[1].get_suma_bani() == 100);
	assert(strcmp(service_cheltuieli_familie.getAll()[0].get_tip(), "haine") == 0);
	assert(strcmp(service_cheltuieli_familie.getAll()[1].get_tip(), "mancare") == 0);

	service_cheltuieli_familie.deleteElemByDay(currentDay);
	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 11);
	assert(strcmp(service_cheltuieli_familie.getAll()[0].get_tip(), "mancare") == 0);

	delete[] tip_1;
	delete[] tip_2;
}


void test_eliminate_by_day_interval() {

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCurrentDayCheltuiala(100, tip_1);
	service_cheltuieli_familie.addCheltuiala(11, 100, tip_1);
	service_cheltuieli_familie.addCheltuiala(12, 100, tip_2);
	service_cheltuieli_familie.addCheltuiala(13, 100, tip_2);
	service_cheltuieli_familie.addCheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.addCheltuiala(40, 100, tip_2);

	service_cheltuieli_familie.deleteElemByDayInterval(12, 30);

	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 11);
	assert(service_cheltuieli_familie.getAll()[1].get_zi() == 40);

	service_cheltuieli_familie.deleteElemByType(tip_1);
	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 40);

	delete[] tip_1;
	delete[] tip_2;

}


void test_get_by_condition() {

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCurrentDayCheltuiala(100, tip_1);
	service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.addCheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.addCheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.addCheltuiala(30, 100, tip_2);

	Cheltuieli_familie rezultat[100];
	int resultlen = 0;

	service_cheltuieli_familie.getElemByType(tip_1, rezultat, resultlen);

	assert(resultlen == 3);
	assert(rezultat[1].get_zi() == 11);
	assert(rezultat[2].get_zi() == 13);

	service_cheltuieli_familie.getElemByCondAndType(120, tip_1, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].get_zi() == 11);
	assert(rezultat[1].get_zi() == 13);

	service_cheltuieli_familie.getElemByCond2AndType(100, tip_2, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].get_zi() == 14);
	assert(rezultat[1].get_zi() == 30);

	delete[] tip_1;
	delete[] tip_2;
}


void test_prop_based_on_sublist() {

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCurrentDayCheltuiala(100, tip_1);
	service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.addCheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.addCheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.addCheltuiala(30, 100, tip_2);

	int sum = service_cheltuieli_familie.sumElemByType(tip_1);
	assert(sum == 500);

	int max_zi = service_cheltuieli_familie.maxDayBySum();
	assert(max_zi == 13);

	delete[] tip_1;
	delete[] tip_2;

}

void test_sort_by_cond() {
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.addCheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.addCheltuiala(14, 100, tip_3);
	service_cheltuieli_familie.addCheltuiala(30, 120, tip_3);

	Cheltuieli_familie rezultat[100];
	int resultlen;

	service_cheltuieli_familie.sortBySumDesc(rezultat, resultlen);

	assert(resultlen == 5);
	assert(rezultat[0].get_zi() == 13);
	assert(rezultat[1].get_zi() == 12);
	assert(rezultat[4].get_zi() == 14);


	service_cheltuieli_familie.sortBySumAndType(tip_3, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].get_zi() == 14);
	assert(rezultat[0].get_suma_bani() == 100);
	assert(rezultat[1].get_zi() == 30);
	assert(rezultat[1].get_suma_bani() == 120);


	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;
}

void test_filter_by_cond() {
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");

	Service service_cheltuieli_familie;

	service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.addCheltuiala(13, 250, tip_3);
	service_cheltuieli_familie.addCheltuiala(14, 100, tip_3);
	service_cheltuieli_familie.addCheltuiala(30, 120, tip_2);

	service_cheltuieli_familie.filterByType(tip_2);

	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 12);
	assert(service_cheltuieli_familie.getAll()[1].get_zi() == 30);
	assert(service_cheltuieli_familie.getSizeRepo() == 2);

	service_cheltuieli_familie.filterByTypeAndCond(150, tip_2);
	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 30);
	assert(service_cheltuieli_familie.getAll()[0].get_suma_bani() == 120);

	service_cheltuieli_familie.addCheltuiala(11, 140, tip_2);
	service_cheltuieli_familie.addCheltuiala(12, 150, tip_2);

	service_cheltuieli_familie.filterByTypeAndCondEq(120, tip_2);

	assert(service_cheltuieli_familie.getAll()[0].get_zi() == 30);
	assert(service_cheltuieli_familie.getAll()[0].get_suma_bani() == 120);


	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;


}


