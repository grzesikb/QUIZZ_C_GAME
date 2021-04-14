#pragma once
char* read_str()
{
	char buffer[50];
	int num_char = 0, i = 0, j = 0, count = 0;
	char character = ' ';
	char* string=(char*)malloc(1);
	
	
	
	
	while (character != '\n')
	{
		// gets char from stdin
		do {
			count++;
			if ((character = getchar()) == '\n') break;
			buffer[num_char] = character;
			num_char++;
		}while (character != ' ');
		
		//if (character == '\n') break;
		// relocate new memory 
		char* more = (char*)realloc(string, count + (sizeof(char) * num_char + 1));
		// cheeks if memory has been allocated 
		must_init_exit(more, "mem relocation for string");
		
		string = more;
		// write from buffer to allocated mem
		while (num_char) {
			string[i] = buffer[j];
			string[i + 1] = '\0';
			i++;
			j++;
			num_char--;
		}
		// to start from zero in next while 
		j = 0;
		num_char = 0;
		
	}
	// clears stdin buffer from \n char which has left 
	fseek(stdin, 0, SEEK_END);
	// returns sentence
	return string;
}