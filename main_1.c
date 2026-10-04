#include <stdio.h>
#include <string.h>
#include <windows.h> // for mechanism to detect text files in folder

// Structures :

// Defining a structure named students :
struct students
{
    int roll_number;
    char name[50];
};

// Defining a structure named studnets :
struct subject
{
    char subject_name[50]; // Method to define a string .
};

int main()
{
    int file_counter = 0;
    int month;
    int year;
    int date;

    printf("\n");
    printf("************************************** \n");
    printf("**** ATTENDANCE MANAGEMENT SYSTEM **** \n");
    printf("************************************** \n");

    printf("\n");

    int option;

    while (option != 0)
    {
        printf("Add Student : Enter 1 \n");
        printf("View Students Name and Roll Number : Enter 2 \n");
        printf("Update Attendence : Enter 3 \n");
        printf("View Attendence : Enter 4 \n");
        printf("Exit the Program : Enter 0 \n");
        printf("\n");
        printf("\n") ;

        printf("Enter your option : \n");
        scanf("%d", &option);

        printf("\n");

        // Defining variables related to student data under scope of main :
        int n;
        // Defining variables related to subject attendence under scope of main :
        int n_sub;

        if (option == 1)
        {
            printf("Enter 1 to completely make a new student list : \n");
            printf("Enter 2 to add new students to existing list  : \n");

            int sub_option_first;
            scanf("%d", &sub_option_first);
            printf("\n");

            if (sub_option_first == 1)
            {
                // int n; -> Defined under global scope now

                printf("Enter number of students whose data you want to enter : \n");
                scanf("%d", &n);
                struct students s[n];

                char temp_name[50]; // To take input of name(string)

                // Mechanism to take student Input :
                FILE *ptr;
                ptr = fopen("Students_list.txt", "w");

                // Taking input from the user :
                for (int i = 0; i < n; i++)
                {
                    printf("Enter the ROLL NUMBER of student :\n ");
                    scanf("%d", &s[i].roll_number);
                    printf("Enter the NAME of the student : \n");
                    scanf("%s", &temp_name);
                    printf("\n");
                    strcpy(s[i].name, temp_name); // data of temp_name copied to struct variable .
                }
                // Entering the data into the file :

                // Entering roll numbers and names into the file :
                for (int i = 0; i < n; i++)
                {
                    // fprintf(ptr, " %d) ", i + 1);
                    fprintf(ptr, " %d ", s[i].roll_number);
                    fprintf(ptr, "  %s \n", s[i].name);
                }
                // Closing the file :
                fclose(ptr);
            }

            if (sub_option_first == 2)
            {
                // int n; -> Defined under global scope now

                printf("Enter number of students whose data you want to enter : \n");
                scanf("%d", &n);
                struct students s[n];

                char temp_name[50]; // To take input of name(string)

                // Mechanism to take student Input :
                FILE *ptr;
                ptr = fopen("Students_list.txt", "a");

                // Taking input from the user :
                for (int i = 0; i < n; i++)
                {
                    printf("Enter the ROLL NUMBER of student :\n ");
                    scanf("%d", &s[i].roll_number);
                    printf("Enter the NAME of the student : \n");
                    scanf("%s", &temp_name);
                    printf("\n");
                    strcpy(s[i].name, temp_name); // data of temp_name copied to struct variable .
                }
                // Entering the data into the file :

                // Entering roll numbers and names into the file :
                for (int i = 0; i < n; i++)
                {
                    // fprintf(ptr, " %d) ", i + 1);
                    fprintf(ptr, " %d ", s[i].roll_number);
                    fprintf(ptr, "  %s \n", s[i].name);
                }
                // Closing the file :
                fclose(ptr);
            }
        }

        else if (option == 2)
        {
            // Mechanism that reads the file and prints it content into the terminal : .
            FILE *ptr_1;
            ptr_1 = fopen("Students_list.txt", "r");

            if (ptr_1 == NULL)
            {
                printf("File does not contain any data .");
            }
            else
            {
                char character;

                while ((character = fgetc(ptr_1)) != EOF)
                {
                    printf("%c", character);
                }
            }
            printf("\n") ;
            fclose(ptr_1);
        }

        else if (option == 3)
        {
            int sub_option;
            printf("Enter 1 to make a attendence sheet for new subject .\n");
            printf("Enter 2 to update the attendence of existing subject .\n");
            printf("\n");
            scanf("%d", &sub_option);
            printf("\n");

            if (sub_option == 1)
            {

                printf("Enter number of subjects whose attendence1 file you want to make : \n");
                scanf("%d", &n_sub);
                struct subject sub[n_sub]; // struct variable which is actually a array

                // Mechanism to take names of subject, date and year:
                char temp_subject_name[50];
                char file_name[100];
                // int month; -> Making them a global variable
                // int year;
                // int date ;
                /*
                -> Going to use the sprintf() function :
                sprintf(file_name ,"%s_%d_%d.txt" , temp_subject_name , month , year ) ;

                -> sprintf() : puts the formatted result inside the character array filename.
                */
                for (int i = 0; i < n_sub; i++)
                {
                    printf("%d) Enter the name of subject %d : \n ", i + 1, i + 1);
                    scanf("%s", &temp_subject_name);
                    printf("Enter Date , month and year in number format (example :Date = 1 , July = 7 , Year = 2026): \n");
                    scanf("%d", &date);
                    scanf("%d", &month);
                    scanf("%d", &year);
                    sprintf(file_name, "%s_%d_%d_%d.txt", temp_subject_name, date, month, year);
                    strcpy(sub[i].subject_name, file_name);
                }
                printf("\n") ;
                // Mechansism to make the text files which will have name same as object :
                FILE *ptr_3;
                for (int i = 0; i < n_sub; i++)
                {
                    ptr_3 = fopen(sub[i].subject_name, "w"); // ptr will be pointing at different file every time .
                    fclose(ptr_3);                           // Closing the opened file immediatly , before opening the next file .
                }
            }
            if (sub_option == 2)
            {
                // Code to detect the text files present in the folder :
                char file_names[100][100] = {}; // array that will store text file names that will be detected by system.

                char name[500][500];
                int roll_num[500];
                char attendance[500];

                // Putting the roll number and attendacne in the arrays :

                FILE *data_into_array;
                data_into_array = fopen("Students_list.txt", "r");

                int i = 0;

                while (fscanf(data_into_array, "%d %s", &roll_num[i], name[i]) == 2)
                {
                    i++;
                }
                fclose(data_into_array);
                int num = i;

                i = 0;

                // Putting P or A in attendance array :
                while (i < num)
                {
                    printf("%d  %s \n", roll_num[i], name[i]);
                    printf("Mark attendance : Present(P) or Absent(A) \n");
                    scanf(" %c", &attendance[i]);
                    printf("\n") ;
                    i++;
                }

                // Mechanism to mark attendence in chosen file :
                WIN32_FIND_DATA fileData;

                HANDLE hFind = FindFirstFile("*.txt", &fileData);

                if (hFind == INVALID_HANDLE_VALUE)
                {
                    printf("No text files found.\n");
                    return 1;
                }
                int file_counter = 0;

                do
                {
                    if (strcmp(fileData.cFileName, "Students_list.txt") != 0)
                    {
                        strcpy(file_names[file_counter], fileData.cFileName);
                        printf("Choose %d to select file %s \n", file_counter + 1, file_names[file_counter]);
                        file_counter++;
                    }
                } while (FindNextFile(hFind, &fileData));

                FindClose(hFind);
                printf("\n");

                int file_chosen;
                scanf("%d", &file_chosen);

                FILE *file_ptr_write;
                file_ptr_write = fopen(file_names[file_chosen - 1], "w");

                //  Mechanism to add Date and Subject Name as heading of File :
                printf("Enter Date , month and year in number format (example :Date = 1 , July = 7 , Year = 2026): \n");
                scanf("%d", &date);
                scanf("%d", &month);
                scanf("%d", &year);
                fprintf(file_ptr_write, "========================================\n");
                fprintf(file_ptr_write, "          ATTENDANCE RECORD\n");
                fprintf(file_ptr_write, "\n");
                fprintf(file_ptr_write, "          DATE : %d/%d/%d \n", date, month, year);
                fprintf(file_ptr_write, "========================================\n\n");
                fprintf(file_ptr_write, "\n");
                fprintf(file_ptr_write, "%-15s %-15s %s\n", "Roll No.", "Name", "Status");
                fprintf(file_ptr_write, "----------------------------------------\n");

                i = 0;

                while (i < num)
                {
                    fprintf(file_ptr_write, "%-15d  %-15s  %c\n", roll_num[i], name[i], attendance[i]);

                    i++;
                }

                fclose(file_ptr_write);
            }
        }
        else if (option == 4)
        {
            char file_names[100][100];

            WIN32_FIND_DATA fileData;

            HANDLE hFind = FindFirstFile("*.txt", &fileData);

            if (hFind == INVALID_HANDLE_VALUE)
            {
                printf("No text files found.\n");
                return 1;
            }
            int file_counter = 0;

            do
            {
                if (strcmp(fileData.cFileName, "Students_list.txt") != 0)
                {
                    strcpy(file_names[file_counter], fileData.cFileName);
                    printf("Choose %d to select file %s \n", file_counter + 1, file_names[file_counter]);
                    file_counter++;
                }
            } while (FindNextFile(hFind, &fileData));

            FindClose(hFind);
            printf("\n");

            int file_chosen;
            scanf("%d", &file_chosen);

            FILE *show_attendace;
            show_attendace = fopen(file_names[file_chosen - 1], "r");

            char character;
            while ((character = fgetc(show_attendace)) != EOF)
            {
                printf("%c", character);
            }
            printf("\n");
        }
    }
    return 0;
}
