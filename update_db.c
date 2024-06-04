#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    // prompt the user for new file to update the database

    char file_name[FNAME_SIZE];
    printf("Enter the new file \n");
    scanf("%s", file_name);

    // validate the file

    int empty = isFileEmpty(file_name);

    if (empty == FILE_NOTAVAILABLE)
    {
        printf("\nFile : %s is not available\n", file_name);
        printf("Hence we are not adding that file\n");
    }
    else if (empty == FILE_EMPTY)
    {
        printf("\nFile : %s is not having any content \n", file_name);
        printf("Hence we are not adding that file\n");
    }
    else
    {
        // add files to file LL
        int ret_val = to_create_list_of_files(f_head, file_name);

        if (ret_val == SUCCESS)
        {
            printf("\nSuccessfull : Inserting the file : %s into file LL\n", file_name);
        }
        else if (ret_val == REPEATATION)
        {
            printf("This file name : %s is repeated. Hence we are not adding that file\n", file_name);
        }
        else
        {
            printf("Failure\n");
        }
    }

    while (*f_head)
    {
        if (!strcmp((*f_head)->file_name, file_name))
        {
            printf("Adding file to Database\n");

            create_database(*f_head, head);

            printf("Successfully added the file to Database\n\n");
        }
        *f_head = (*f_head)->link;
    }
}

