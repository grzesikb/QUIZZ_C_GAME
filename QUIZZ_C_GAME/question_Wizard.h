#pragma once
#include "STATUS.h"
#include "Settings_file_handler.h"
#include <string.h>
void q_wizard(unsigned int );
void ch_category(bool cat_was_empty)
{
	if(cat_was_empty)
	{
		char name[300];
		char c;
		printf("ENTER NAME OF %d CATEGORY: ", noc_struct.the_number_of_categories);
		while(((c)=getchar())!='\n')
		{
			strcat(name, &c);
		}
		printf("\n%s", name);
		
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
	5 4 3 
}