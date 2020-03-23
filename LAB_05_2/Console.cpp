#include "Console.h"
#include <iostream>
using namespace std;


void Console::meniu() {
	cout << "Cheltuieli de familie \n";
	cout << "a. Adaugarea unei cheltuieli in lista  \n";
	cout << "b. Modificarea cheltuielilor din lista \n";
	cout << "c. Stabilirea cheltuielilor cu anumite proprietati \n";
	cout << "d. Obtinerea unor proprietati a diferitelor subliste \n";
	cout << "e. Filtrarea listei de cheltuieli \n";
	cout << "f. Afisare \n";
	cout << "g. Afisare buget \n";
	cout << "x. Iesire \n";



}

int Console::console() {


	while (true)
	{
		meniu();
		char op = read_op();

		if (op == 'a') {

			cout << "1. Ex. Adauga 10 internet - adauga pentru ziua curenta o cheltuiala de 10 RON pentru internet \n";
			cout << "2. Ex. Insereaza 25 100 mancare - insereaza pentru ziua 25 a lunii curente o cheltuiala de 100 RON pentru mancare \n";


			char op2 = read_op();

			if (op2 == '1')
			{
				this->add_cheltuiala_without_day();
			}
			else if (op2 == '2')
			{
				this->add_cheltuiala_with_day();
			}
		}
		else if (op == 'b') {

			cout << "1. Ex. Elimina 15 - elimina toate cheltuielile din ziua 15 \n";
			cout << "2. Ex. Elimină 2 la 9 - elimină toate cheltuielile pentru zilele 2,3, ..., 9 \n";
			cout << "3. Ex. Elimina mancare - elimina totate cheltuielile pentru mancare din luna curenta. \n";
			cout << "4. Moficare cheltuiala total \n";

			char op2 = read_op();

			if (op2 == '1')
			{
				this->delete_cheltuiala_day();
			}
			else if (op2 == '2')
			{
				this->delete_cheltuiala_between_days();
			}
			else if (op2 == '3')
			{
				this->delete_cheltuiala_by_type();
			}
			else if (op2 == '4')
			{
				this->modify_cheltuiala();
			}
		}
		else if (op == 'c')
		{

			cout << "1. Ex. Listeaza mancare - afisarea tuturor cheltuielilor pentru mancare ";
			cout << "2. Ex. Listeaza mancare > 5 - afisarea tuturor cheltuielilor pentru mancare mai mari de 5 RON \n";
			cout << "3. Ex. Listeaza internet = 44 - afisarea tuturor cheltuielilor pentru internet in valoare de 44 RON \n";

			char op2 = read_op();

			if (op2 == '1')
			{
				this->show_cheltuiala_by_type();
			}
			else if (op2 == '2')
			{
				this->show_cheltuiala_by_type_and_cond();
			}
			else if (op2 == '3')
			{
				this->show_cheltuiala_by_type_and_cond_eq();
			}
		}
		else if (op == 'd') {

			cout << "1. Ex. Suma mancare - suma tuturor cheltuielilor din categoria mancare \n";
			cout << "2. Ex. Max zi - afisarea zilei cu cele mai mari cheltuieli \n";
			cout << "3. Ex. Sortare zi - afisarea sumelor cheltuite zilnic in ordine descrescatoare \n";
			cout << "4. Ex. Sorteaza mancare - afisarea sumelor cheltuite zilnic pentru mancare, ordonate crescator \n";


			char op2 = read_op();

			if (op2 == '1')
			{
				this->max_sum_type();
			}
			else if (op2 == '2')
			{
				this->max_day();
			}
			else if (op2 == '3')
			{
				this->sum_ord_desc();
			}
			else if (op2 == '4')
			{
				this->sum_type_cresc();
			}
		}
		else if (op == 'e') {

			cout << "1. Ex. Filtrare mancare - pastreaza doar cheltuielile pentru mancare \n";
			cout << "2. Ex. Filtrare menaj < 100 - pastreaza doar cheltuielile pentru menaj mai mici decat 100 RON \n";
			cout << "3. Ex. Filtrare haine = 59 - pastreaza doar cheltuielile pentru haine egale cu 59 RON  \n";

			char op2 = read_op();

			if (op2 == '1') {
				this->filter_by_type();
			}
			else if (op2 == '2') {
				this->filter_by_type_and_cond();
			}


			else if (op2 == '3')
			{
				this->filter_by_type_and_cond_eq();
			}

		}
		else if (op == 'f') {
			this->show_cheltuieli_familie();
		}
		else if (op == 'x')
			return 0;
		else if (op == 'g')
		{
			cout << "Bugetul a inceput de la 10000 si s-a redus din cauza cheltuielilor lunare la : " << this->service_cheltuieli.getBuget() << "\n";
		}


	}
}

int Console::read_int() {
	cout << "Introdu un numar: ";
	int a;
	cin >> a;
	return a;
}

char Console::read_op() {
	cout << "Introdu o optiune: ";
	char a;
	cin >> a;
	return a;
}

char* Console::read_p_char()
{
	cout << "Introdu un cuvant: ";
	char b[100];
	cin >> b;
	char* a = new char[strlen(b) + 1];
	strcpy_s(a, strlen(b) + 1, b);
	return a;
}

void Console::show_cheltuieli_familie()
{
	int size = this->service_cheltuieli.getSizeRepo();
	Cheltuieli_familie* cheltuieli_familie = this->service_cheltuieli.getAll();
	for (int i = 0; i < size; i++) {
		cout << cheltuieli_familie[i];

	}


}

void Console::add_cheltuiala_without_day() {
	int suma_bani = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.addCurrentDayCheltuiala(suma_bani, tip);
}

void Console::add_cheltuiala_with_day() {
	int zi = read_int();
	int suma_bani = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.addCheltuiala(zi, suma_bani, tip);
}

void Console::delete_cheltuiala_day() {
	int zi = read_int();

	this->service_cheltuieli.deleteElemByDay(zi);
}

void Console::delete_cheltuiala_between_days() {
	int zi_1 = read_int();
	int zi_2 = read_int();

	this->service_cheltuieli.deleteElemByDayInterval(zi_1, zi_2);
}

void Console::delete_cheltuiala_by_type() {
	char* tip = read_p_char();
	this->service_cheltuieli.deleteElemByType(tip);
	delete[] tip;
}

void Console::show_by_len(int n, Cheltuieli_familie cheltuieli[]) {
	for (int i = 0; i < n; i++) {
		cout << cheltuieli[i];
		cout << "\n";
	}
}

void Console::show_cheltuiala_by_type() {
	char* tip = read_p_char();

	Cheltuieli_familie de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByType(tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);
	delete[] tip;

}

void Console::show_cheltuiala_by_type_and_cond() {
	char* tip = read_p_char();
	int nr = read_int();
	Cheltuieli_familie de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByCondAndType(nr, tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);
	delete[] tip;

}

void Console::show_cheltuiala_by_type_and_cond_eq() {
	char* tip = read_p_char();
	int nr = read_int();
	Cheltuieli_familie de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByCond2AndType(nr, tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);
	delete[] tip;

}

void Console::max_sum_type() {

	char* tip = read_p_char();
	int sum = this->service_cheltuieli.sumElemByType(tip);

	cout << " Suma tuturor cheltuielilor din categoria " << tip << " este " << sum << "\n";

	delete[] tip;
}

void Console::max_day() {

	int day = this->service_cheltuieli.maxDayBySum();

	cout << " Ziua cu cele mai mari cheltuieli este: " << day << "\n";

}

void Console::sum_ord_desc() {

	Cheltuieli_familie de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.sortBySumDesc(de_afisat, resultlen);

	for (int i = 0; i < resultlen; i++) {
		cout << de_afisat[i].get_suma_bani() << " ";
	}

	cout << "\n";

}

void Console::sum_type_cresc() {

	char* tip = read_p_char();
	Cheltuieli_familie de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.sortBySumAndType(tip, de_afisat, resultlen);

	for (int i = 0; i < resultlen; i++) {
		cout << de_afisat[i].get_suma_bani() << " ";
	}

	cout << "\n";

	delete[] tip;

}

void Console::filter_by_type() {
	char* tip = read_p_char();

	this->service_cheltuieli.filterByType(tip);
	delete[] tip;
}

void Console::filter_by_type_and_cond() {
	int nr = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.filterByTypeAndCond(nr, tip);

	delete[] tip;
}

void Console::filter_by_type_and_cond_eq() {
	int nr = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.filterByTypeAndCondEq(nr, tip);
	delete[] tip;
}

void Console::modify_cheltuiala() {
	cout << "Cheltuiala pe care vrei sa o modifici are urmatoarele atribute: \n";
	cout << "Ziua: \n";
	int day1 = read_int();
	cout << "Suma de bani: \n";
	int sum1 = read_int();
	cout << "Tipul: \n";
	char* tip1 = read_p_char();

	cout << "Atributele schimbate sunt: \n";
	cout << "Ziua: \n";
	int day2 = read_int();
	cout << "Suma de bani: \n";
	int sum2 = read_int();
	cout << "Tipul: \n";
	char* tip2 = read_p_char();

	this->service_cheltuieli.update(day1, sum1, tip1, day2, sum2, tip2);

	delete[] tip1;
	delete[] tip2;

}