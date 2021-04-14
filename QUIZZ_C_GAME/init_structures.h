#pragma once

struct questions
{
	int id;
	char* question;
	char* answer_a;
	char* answer_b;
	char* answer_c;
	char* answer_d;
	char* correct;
	struct questions* next;
};

typedef struct questions* p_questions;
typedef struct questions** ref_questions;

struct questions_tmp
{
	int id;
	char* question;
	char* answer_a;
	char* answer_b;
	char* answer_c;
	char* answer_d;
	char* correct;
};

typedef struct questions_tmp* p_questions_tmp;
typedef struct questions_tmp** ref_questions_tmp;

struct questions_tmp tmp_question;

struct questions_tmp_to_write
{
	int id;
	char question;
	char answer_a;
	char answer_b;
	char answer_c;
	char answer_d;
	char correct;
};

typedef struct questions_tmp_to_write* p_questions_tmp_to_write;
typedef struct questions_tmp_to_write** ref_questions_tmp_to_write;


struct questions_tmp_to_write qt_w;



void load_mem_for_questions_ptrs()
{
	tmp_question.question = (const char*)malloc(1); 
	tmp_question.answer_a = (const char*)malloc(1); 
	tmp_question.answer_b = (const char*)malloc(1); 
	tmp_question.answer_c = (const char*)malloc(1); 
	tmp_question.answer_d = (const char*)malloc(1); 
	tmp_question.correct = (const char*)malloc(1); 
}
void kill_mem_for_questions_ptrs()
{
	free(tmp_question.question);
	tmp_question.question = NULL;
	free(tmp_question.answer_a);
	tmp_question.answer_a = NULL;
	free(tmp_question.answer_b);
	tmp_question.answer_b = NULL;
	free(tmp_question.answer_c);
	tmp_question.answer_c = NULL;
	free(tmp_question.answer_d);
	tmp_question.answer_d = NULL;
	free(tmp_question.correct);
	tmp_question.correct = NULL;
}