#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "STATUS.h"

struct number_of_categories
{
	unsigned int the_number_of_categories;
	
};
typedef struct number_of_categories S_Noc;
typedef struct number_of_categories* P_Noc;
P_Noc noc_ptr;
S_Noc noc_struct;
typedef struct number_of_categories** Ref_Noc;
struct category_cpy
{
	unsigned int category_id;
	const char name;
	unsigned int number_of_questions;
};
typedef struct category_cpy* P_c_cpy;
P_c_cpy c_cpy_ptr;
typedef struct category_cpy** ref_c_cpy;

struct category
{
	unsigned int category_id;
	const char name;
	unsigned int number_of_questions;
	struct category_list* ptr_category_list;
};
typedef struct category* P_cat;
P_cat cat_ptr;
P_cat tab_of_cats;
typedef struct category** Ref_cat;

struct  settings
{
	unsigned int nr_of_ctgs;
};

void init_tab_of_structure_of_categories()
{
	tab_of_cats = (P_cat)malloc(sizeof(struct category) * noc_struct.the_number_of_categories);
	must_init_exit(tab_of_cats, "ALLOCATION MEMORY FOR TAB OF CATS STRUCTURES");
}

void init_all_settings_ptrs()
{
	noc_ptr = (P_Noc)malloc(sizeof(struct number_of_categories));
	c_cpy_ptr = (P_c_cpy)malloc(sizeof(struct category_cpy));
	cat_ptr = (P_cat)malloc(sizeof(struct category));
	must_init_exit(noc_ptr, "ALLOCATION MEMORY FOR NOC STRUCTURE");
	must_init_exit(c_cpy_ptr, "ALLOCATION MEMORY FOR CATEGORY_CPY STRUCTURE");
	must_init_exit(cat_ptr, "ALLOCATION MEMORY FOR CATEGORY STRUCTURE");
}
void kill_all_settings_ptrs()
{
	free(noc_ptr);
	noc_ptr = NULL;
	free(c_cpy_ptr);
	c_cpy_ptr = NULL;
	free(cat_ptr);
	cat_ptr = NULL;
	free(tab_of_cats);
	tab_of_cats = NULL;
	must_init_get_info(!(noc_ptr && c_cpy_ptr && cat_ptr && tab_of_cats), 
		"IF ALL SETTINGS PTR WAS DELETED");
}