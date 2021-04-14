#pragma once
#include "init_structures.h"
FILE* file;
unsigned int id = 0;

void scan_file();
void add_questions();
void get_quest_from_usr();
void write_to_file();
void read_from_file();
void free_all_allocated_strings();


void load_saved_info()
{
	file = fopen("database.bin", "rb+");
	must_init_get_info(file, "FILE WITH SAVED QUESTIONS");
}

void scan_file()
{
	
	/*bool status;
	status = must_init_get_info(fread(&status, 
		sizeof(int),  1, file),
		"If file is empty");*/
	if(file)
	{
		read_from_file();
		fclose(file);
	}
	else 
	{
		file = fopen("database.bin", "wb+");
		must_init_get_info(file, "FILE WITH SAVED QUESTIONS");
		add_questions();
		fclose(file);
	}
}

void get_quest_from_usr()
{
	
	// clears stdin buffer from \n char which has left 
	fseek(stdin, 0, SEEK_END);
	
	printf("Wprowadz pytanie: \n\n");
	tmp_question.question = read_str();

	printf("\n");

	printf("Wprowadz odpowiedz A: ");
	tmp_question.answer_a = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz B: ");
	tmp_question.answer_b = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz C: ");
	tmp_question.answer_c = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz D: ");
	tmp_question.answer_d = read_str();
	
	printf("\n");

	printf("Wprowadz oznaczenie poprawnej odpowiedzi: ");
	scanf("%c", tmp_question.correct);

	printf("\n");
	
}

void add_questions()
{
	int questions_number;
	printf(" Ile pytan chcesz dodac: ");
	scanf("%d", &questions_number);
	while(questions_number)
	{
		load_mem_for_questions_ptrs();

		tmp_question.id = id;
		id++;
		
		get_quest_from_usr();
		write_to_file();
		free_all_allocated_strings();
		questions_number--;
	}
}

int get_str_len(char* string)
{
	int counter = 0;
	while (*string != '\0') {
		counter++; string++;
	}
	return counter+1;
}

void write_to_file()
{
	int struct_size;

	fwrite(&tmp_question.id, sizeof(int), 1, file);
	
	struct_size = get_str_len(tmp_question.question);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.question, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_a);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_a, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_b);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_b, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_c);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_c, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_d);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_d, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.correct);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.correct, 1, 1, file);
}
void read_from_file()
{
	int struct_size=0;
	while (fread(&struct_size, sizeof(int), 1, file))
	{
		fread(tmp_question.question, struct_size, 1, file);
		printf("%d\n", tmp_question.id);
		
		tmp_question.question = (char*)malloc(struct_size * sizeof(char));
		fread(tmp_question.question, struct_size, 1, file);
		printf("%s\n", tmp_question.question);
		
		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_a= (char*)malloc(struct_size );
		fread(tmp_question.answer_a, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_a);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_b = (char*)malloc(struct_size );
		fread(tmp_question.answer_b, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_b);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_c = (char*)malloc(struct_size );
		fread(tmp_question.answer_c, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_c);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_d = (char*)malloc(struct_size );
		fread(tmp_question.answer_d, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_d);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.correct = (char*)malloc(struct_size );
		fread(tmp_question.correct, 1, 1, file);
		printf("%c\n", tmp_question.correct[0]);
		printf("\n");
		
	}
}
void free_all_allocated_strings()
{
	free(tmp_question.question);
	tmp_question.question = NULL;
	must_init_get_info(!tmp_question.question, 
		"CORRECT IF ALLOCATED STR_question WAS KILLED");

	free(tmp_question.answer_a);
	tmp_question.answer_a = NULL;
	must_init_get_info(!tmp_question.answer_a,
		"CORRECT IF ALLOCATED STR_answer_a WAS KILLED");

	free(tmp_question.answer_b);
	tmp_question.answer_b = NULL;
	must_init_get_info(!tmp_question.answer_b,
		"CORRECT IF ALLOCATED STR_answer_b WAS KILLED");

	free(tmp_question.answer_c);
	tmp_question.answer_c = NULL;
	must_init_get_info(!tmp_question.answer_c,
		"CORRECT IF ALLOCATED STR_answer_c WAS KILLED");

	free(tmp_question.answer_d);
	tmp_question.answer_d = NULL;
	must_init_get_info(!tmp_question.answer_d,
		"CORRECT IF ALLOCATED STR_answer_d WAS KILLED");

	free(tmp_question.correct);
	tmp_question.correct = NULL;
	must_init_get_info(!tmp_question.correct,
		"CORRECT IF ALLOCATED STR_answer_d WAS KILLED");
}

