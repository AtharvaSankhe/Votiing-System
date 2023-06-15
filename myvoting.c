#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>

#define party_no_1 "A"
#define party_no_2 "B"
int vote_count1, vote_count2 = 0;

int flag_sap[100];
int l = 0;

typedef struct
{
    char name[100];
    int sap_id;
    char dept[100];
    /* data */
} Student;

typedef struct
{
    char pass1[9];
    char pass2[5];

} Password;

Student students[100];
Password password[100];

void castVote()
{

    int temp, k, flag = 0, flag1 = 0;
    int choice;
    char pass[9];
    printf("\nEnter you sap id\n");
    scanf("%d", &temp);
    for (int j = 0; j < 66; j++)
    {
        if (flag_sap[j] == temp)
        {
            flag++;
        }
    }
    for (int j = 0; j < 66; j++)
    {
        if (temp != students[j].sap_id) // error tha
        {
            flag1++;
        }
        else if (temp == students[j].sap_id)
        {

            k = j;
            flag1 = 0;
            break;
        }
    }
    //   printf("%d-%d-%d",k,flag1,flag) ; correct

    if (flag != 0)
    {
        printf("You have already voted\n");
    }
    else if (flag1 != 0)
    {
        printf("Invalid sap id\n");
    }
    if (flag == 0 && flag1 == 0)
    {
        printf("Enter Password to vote: %s", password[k].pass1);
        scanf("%s", &pass);
        printf("\nVerifying Information . . . .\n");
        Sleep(5);
        int a = strcmp(pass, password[k].pass1);
      //  printf("%d", a);
        if (a == 0)
        {
            flag_sap[l] = temp;
            do
            {

                printf("\n1.A\n2.B\n0.Exit");
                printf("\nCast your vote\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    vote_count1++;
                    break;
                case 2:
                    vote_count2++;
                    break;
                default:
                    printf("Enter valid choice");
                }
            } while (choice == 1 && choice == 2);

            l++;
        }
        else
        {
            printf("Incorrect password\n");
        }
    }
}

void votesCount()
{
    printf("__________________________________________\n\n") ;
    printf("Number of people voted: %d", l);
    printf("\n\n__________________________________________") ;
}

void getLeadingCandiate()
{
     printf("_____________________________________________________________\n\n") ;
    printf("Votes :\nA:%d\nB:%d", vote_count1++, vote_count2++);
    if (vote_count1++ > vote_count2++)
    {
        printf("\nA is winning by %d votes.", (vote_count1++) - (vote_count2++));
    }
    else if (vote_count1++ == vote_count2++)
    {
       printf("\nVotes of A and B are equal.") ;
    }
    
    else
    {
        printf("\nB is winning by %d votes.", (vote_count2++) - (vote_count1++));
    }
     printf("\n\n_____________________________________________________________") ;
}

int main()
{
    FILE *fp;
    fp = fopen("test.csv", "r");

    if (fp == NULL)
    {
        printf("Error");
        exit(0);
    }

    char line[100];

    char *sp;
    int i = 0;
    int sap;
    char name1[100];
    char name2[100];

    while (fgets(line, 100, fp) != NULL)
    {
        sp = strtok(line, ",");
        sap = atoi(sp);

        sp = strtok(NULL, ",");
        strcpy(name1, sp);

        sp = strtok(NULL, ",");
        strcpy(name2, sp);

        // printf("%d %s %s", sap, name1, name2);

        students[i].sap_id = sap;
        strcpy(students[i].name, name1);
        strcpy(students[i].dept, name2);
        strncpy(password[i].pass1, students[i].name, 3);
        password[i].pass1[3] = '\0';
        strcpy(password[i].pass2, name2);
    /*    int length = 0;                           // setting password
        while (password[i].pass1[length] != '\0') // setting password
        {                                         // setting password
            ++length;
        }
        for (int m = 0; password[i].pass2[m] != '0'; m++, ++length)
        {
            password[i].pass1[length] = password[i].pass2[m];
        }
        password[i].pass1[length] = '\0';
        puts(password[i].pass1); // setting password */

        //    password[i] = password[i].pass1 + password[i].pass2 ;
        /*     printf("SAP ID: %d\nNAME: %s\nDEPARTMENT: %sPASSWORD: %s%s\n-------------------------\n", students[i].sap_id, students[i].name,students[i].dept,password[i].pass1,password[i].pass2); */
        i++;
    }
    char choice;
    do
    {

        printf("\n \n #_#_#_#_#_# WELCOME TO ELECTION / VOTING 2022 A.D #_#_#_#_#_#");
        printf("\n \n 1. Cast the Vote.");
        printf("\n \n 2. Number of people voted");
        printf("\n \n 3. Find the result");
        printf("\n \n 0. Exit.");

        printf("\n \n Please Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            castVote();
            break;
        case 2:
            votesCount();
            break;
        case 3:
            getLeadingCandiate();
            break;
        default:
            printf("\n Error: Invalid Choice !!!");
        }

    } while (choice != 0);

    getchar();

    return 0;
}