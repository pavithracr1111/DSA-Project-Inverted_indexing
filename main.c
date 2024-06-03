#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

    // validate CLA
    if (argc <= 1)
    {
        printf("Enter the valid no. arguments\n");
        printf("./Slist.exe file1.txt file2.txt.......\n");
        return 0;
    }

    // create the file linked list

    // declare a head pointer
    Flist *f_head = NULL;

    // validate the files
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No file are available in the file LL\n");
        printf("Hence the process is terminated\n");
        return 0;
    }
    
    int y = 1;
    while (y)
    {
        printf("Select your choice among the following options:\n");
        printf("1. Create DATABASE\n");
        printf("2. Display Database\n");
        printf("3. Update DATABASE\n");
        printf("4. Search\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            create_database(f_head, head);
            break;
        case 2:
            displayDatabase();
            break;
        case 3:
            updateDatabase();
            break;
        case 4:
            searchDatabase();
            break;
        case 5:
            saveDatabase();
            break;
        case 6:
            printf("Exiting...\n");
            y = 0; // Set y to 0 to exit the loop
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
        }
    }

    return 0;
}
