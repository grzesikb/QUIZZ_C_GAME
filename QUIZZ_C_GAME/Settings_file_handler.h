#pragma once
#include "Settings_Structures.h"
#include "STATUS.h"
#include "question_Wizard.h"
FILE* settings_file_ptr;

bool Settings_load_file()
{
	bool all_correct;
	must_init_exit(settings_file_ptr = fopen("SETTINGS.bin", "wb+"),
		"LOAD STATUS FILE");
	all_correct = must_init_get_info(fread(noc_ptr, 
		sizeof(struct number_of_categories),
		1, settings_file_ptr), 
		"IF SETTINGS FILE IS EMPTY (FAILURE)");
	
	if(all_correct)
	{
		// czytaj kolejne struktury tj tablica struct category
		
	}else
	{
		noc_struct.the_number_of_categories=1;
		init_tab_of_structure_of_categories();
		ch_category(true);
		// dokonać allokacji na reszte struct i  wywołać kreator kategori
	}
}