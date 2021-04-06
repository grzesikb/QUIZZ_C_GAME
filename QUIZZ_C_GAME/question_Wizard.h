#pragma once
#include "STATUS.h"
#include "Settings_file_handler.h"
void q_wizard(unsigned int );
void ch_category(bool cat_was_empty)
{
	if(cat_was_empty)
	{
		char* name;
		name = (char*)malloc(sizeof(char)*10);
		int buffer = 0;
		must_init_exit(name, "CH_CATEGORY NAME VARIABLE MEM ALLOCATION");
		printf("ENTER NAME OF %d CATEGORY: ", noc_struct.the_number_of_categories);
		while (((*name) = (char)getchar())!='\n')
		{
			if(!(buffer%10))
			{
				name = (char*)realloc(name, buffer + 10);
				must_init_exit(name, "CH_CATEGORY NAME RELOCATION");
				buffer++;
			}
			else buffer++;
		}
		printf("%s", name);
		
	}else
	{
		unsigned int option;
		printf("CHOOSE CATEGORY TO ADD QUESTION OR CLICK NEW\n");
		for(unsigned int i=0; i<noc_struct.the_number_of_categories; i++)
		{
			printf("%d. %s\n", i, tab_of_cats[i].name);
		}
		printf("\n\n");
		printf("ENTER NUMBER: ");
		scanf("%d", &option);
		q_wizard(option);// twożymy kolejne pytanie i dołączmy do listy 
	}
}

void q_wizard(unsigned int nof_category)
{
	
}