#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
	// traverse through the file linked list
	while (f_head)
	{
		read_datafile(f_head, head, f_head->file_name);
		f_head = f_head->link;
	}
}

// read content of file
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
	// open the file in read mode

	FILE *fptr = fopen(filename, " r ");
	fname = filename;
	int flag = 1;

	// declare an array to store words

	char word[WORD_SIZE];

	while (fscanf(fptr, "%s", word) != EOF)
	{
		// index
		int index = tolower(word[0]) % 97;

		// other than alphabet
		if (!(index >= 0 && index <= 25))
			index = 26;

		// check words are repeated or not
		if (head[index] != NULL)
		{
			Wlist *temp = head[index];
			// compare the words at each node with new word

			while (temp)
			{
				if (!strcmp(temp->word, word))
				{
					update_word_count(&temp, filename);
					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}
		if (flag == 1)
		{
			// words are not repeated
			insert_at_last(&head[index], word);
		}
	}
}

int update_word_count(Wlist **head, char *file_name)
{
	// check whether the filenames are same or not
	// if filenames are same -> word_count incremented
	// if filenames are different -> increment file_count , create new Ltable node

	if (!strcmp(file_name, (*head)->Tlink->file_name))
	{
		(*head)->Tlink->word_count = (*head)->Tlink->word_count + 1;
	}
	else
	{
		(*head)->file_count = (*head)->file_count + 1;

		Ltable *new = malloc(sizeof(Ltable));
		if (new == NULL)
		{
			return FAILURE;
		}

		strcpy(new->file_name, file_name);
		new->word_count = 1;
		new->table_link = NULL;

		Ltable *current = (*head)->Tlink;

		while (current->table_link != NULL)
		{
			current = current->table_link;
		}
		current->table_link = new;
	}
	return 0;
}
