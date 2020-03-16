#include "Test.h"
#include "Cheltuieli_familie.h"
#include <string.h>
#include <cassert>
#include "Repo.h"

void test_cheltuieli_familie() {
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Cheltuieli_familie c1(3,25,tip_1);
	Cheltuieli_familie c2(3, 25, tip_1);

	assert(c1.get_zi() == 3);
	assert(c1.get_suma_bani() == 25);
	assert( strcmp(c1.get_tip(),"haine")==0);

	assert(c1 == c2);

	c1.set_zi(9);
	c1.set_suma_bani(200);
	c1.set_tip(tip_2);
	assert(c1.get_zi() == 9);
	assert(c1.get_suma_bani() == 200);
	assert(strcmp(c1.get_tip(), "mancare") == 0);

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


}