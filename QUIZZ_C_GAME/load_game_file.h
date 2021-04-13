#pragma once
#include "init_structures.h"
FILE* file;

void scan_file();
void add_questions();

void write_to_file();
void load_saved_info()
{
	file = fopen("database.bin", "wb+");
	must_init_exit(file, "FILE WITH SAVED QUESTIONS");
}

void scan_file()
{
	bool status;
	status = must_init_get_info(fread(&tmp_question, 
		sizeof(struct questions_tmp),  1, file),
		"If file is empty");
	if(status)
	{
		//read_questions();
	}
	else 
	{
		add_questions();
	}
}

void write_to_file()
{
	char str[50];
	int num_char = 0, i=0,j=0, count=0;
	char holder='s';
	char* string;
	getchar();
	printf("Wprowadz pytanie:");
	while(holder!='\n')
	{
		holder = 's';
		while (holder != ' ') {
			count++;
			if ((holder = getchar()) == '\n') break;
			str[num_char] = holder;
			num_char++;
		}
		if (holder == '\n') break;
		char* more = (char*)realloc(tmp_question.question, count+(sizeof(char)*num_char));
		must_init_exit(more, "mem relocation for string");
		tmp_question.question = more;
		while (num_char) {
			tmp_question.question[i] = str[j];
			tmp_question.question[i+1] = '\0';
			
			i++;
			j++;
			num_char--;
		}
		j = 0;
		num_char = 0;
	}
	printf("%s", tmp_question.question);


	printf("Podaj poprawna odpowiedz \n");
	scanf("%c", tmp_question.correct);

	must_init_get_info(fwrite(&tmp_question,
		sizeof(struct questions_tmp), 1, file),
		"If written correctly");
}

void add_questions()
{
	int questions_number;
	printf(" Ile pytan chcesz dodac: ");
	scanf("%d", &questions_number);
	while(questions_number)
	{
		load_mem_for_questions_ptrs();
		write_to_file();
		questions_number--;
	}
}


