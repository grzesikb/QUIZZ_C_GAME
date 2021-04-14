#pragma once
#include "init_structures.h"
FILE* file;

void scan_file();
void add_questions();
void get_quest_from_usr();
void write_to_file();
void read_from_file();

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
		read_from_file();
		fclose(file);
	}
	else 
	{
		add_questions();
		fclose(file);
	}
}

void get_quest_from_usr()
{
	
	// clears stdin buffer from \n char which has left 
	fseek(stdin, 0, SEEK_END);
	
	printf("Wprowadz pytanie: ");
	tmp_question.question = read_str();

	printf("%s\n", tmp_question.question);

	printf("Wprowadz odpowiedz A: ");
	tmp_question.answer_a = read_str();
	printf("%s\n", tmp_question.answer_a);

	printf("Wprowadz odpowiedz B: ");
	tmp_question.answer_b = read_str();
	printf("%s\n", tmp_question.answer_b);

	printf("Wprowadz odpowiedz C: ");
	tmp_question.answer_c = read_str();
	printf("%s\n", tmp_question.answer_c);

	printf("Wprowadz odpowiedz D: ");
	tmp_question.answer_d = read_str();
	printf("%s\n", tmp_question.answer_d);

	printf("Wprowadz oznaczenie poprawnej odpowiedzi: ");
	scanf("%c", tmp_question.correct);
}

void add_questions()
{
	int questions_number;
	printf(" Ile pytan chcesz dodac: ");
	scanf("%d", &questions_number);
	while(questions_number)
	{
		load_mem_for_questions_ptrs();
		get_quest_from_usr();
		write_to_file();
		questions_number--;
	}
}


void write_to_file()
{
	fwrite(&qt_w, sizeof(tmp_question), 1, file);
}
void read_from_file()
{
	while (fread(&tmp_question, sizeof(tmp_question), 1, file))
	{
		printf("%s\n", tmp_question.question);
		printf("%s\n", tmp_question.answer_a);
		printf("%s\n", tmp_question.answer_b);
		printf("%s\n", tmp_question.answer_c);
		printf("%s\n", tmp_question.answer_d);
		printf("%s\n", tmp_question.correct);
		printf("\n");
	}
}