#pragma once
#include "Service.h"

class Console {
private:
	Service service_cheltuieli;
public:
	void meniu();
	int console();
	int read_int();
	char read_op();
	char* read_p_char();
	void show_cheltuieli_familie();
	void add_cheltuiala_without_day();
	void add_cheltuiala_with_day();
	void delete_cheltuiala_day();
	void delete_cheltuiala_between_days();
	void delete_cheltuiala_by_type();
	void show_cheltuiala_by_type();
	void show_cheltuiala_by_type_and_cond();
	void show_cheltuiala_by_type_and_cond_eq();
	void show_by_len(int n, Cheltuieli_familie cheltuieli[]);
	void max_sum_type();
	void max_day();
	void sum_ord_desc();
	void sum_type_cresc();
	void filter_by_type();
	void filter_by_type_and_cond();
	void filter_by_type_and_cond_eq();
	void modify_cheltuiala();

};