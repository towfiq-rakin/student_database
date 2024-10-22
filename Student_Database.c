#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int i,j;
int main_exit;

void fordelay(int j); 
void heading();
void new_std();
void view_list();
void edit();
void cgpa();
void erase();
void see();
void menu();
void closing();

struct date
{
    int month,day,year;
};
struct student
{
    char name[60];
    long long int roll;
    int age;
    char email[60];
    char phone[12];
    char batch[10];
    float cgpa;
    struct date dob;
}add,upd,check,rem;

int main()
{   
    //system("color F0");  // Change console background to white and text color to black
    heading();
    char pass[10],password[10]="rakin";
    char username[10];
    int i=0;
    printf("\n\n\tEnter username: ");
    scanf("%s",username);
    printf("\n\tEnter the password to login: ");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {   
        printf("\n\n\tWrong password!!\a\a\a");
        login_try:
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
            system("cls");
            main();
        }
        else if (main_exit==2)
        {
            system("cls");
            closing();
        }
        else
        {   
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    return 0;
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void closing()
{   
    system("cls");
    heading();
    printf("\n\n\n\nThis C Project is developed by Team Resistors!\n\n");
    printf("Towfiq Omar Rakin \t   23524202131\n");
    printf("Shreya Sarker \t\t   23524202109\n");
    printf("Mushfiqur Rahman Sama      23524202117\n");
    printf("Md. Tahmidur Rahman Khan   23524202041\n");
    printf("Iftekhar Ahmed Sourav      23524202107\n\n");
    printf("BCSE-2023, BUP @ 2024\n\n\n");
    system("pause");
}
void heading()
{
    printf("\n\n\t\t\tBANGLADESH UNIVERSITY OF PROFESSIONALS");
    printf("\n\t\t\t    Faculty of Science & Technology");
    printf("\n\t\t     Department of Computer Science & Engineering");
}

void new_std()
{
    int choice;
    FILE *ptr;
    ptr=fopen("srecord.txt","a+");
    account_no:
    system("cls");
    heading();
    printf("\n\n\t\t\t   ========= ADD STUDENT =========");
    printf("\n\n\nEnter the ID : ");
    scanf("%lld",&check.roll);
    while(fscanf(ptr,"%lld %s %d/%d/%d %d %s %s %s %f\n",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
    {
        if (check.roll==add.roll)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }
    add.roll=check.roll;
    printf("\nEnter Nickname: ");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    printf("\nEnter the email: ");
    scanf("%s",add.email);
    printf("\nEnter the phone number: ");
    scanf("%s",add.phone);
    printf("\nEnter Batch: ");
    scanf("%s",add.batch);
    
    fprintf(ptr,"%lld %s %d/%d/%d %d %s %s %s %f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch,add.cgpa=0.00);
    
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\t1. Return to Menu");
    printf("\n\n\n\t\t2. Exit");
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d",&main_exit);
    fclose(ptr);
    system("cls");
    if (main_exit==1)
    {
        menu();
    }else if(main_exit==2)
    {
        closing();
    }else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void view_list()
{
    FILE *view;
    view=fopen("srecord.txt","r");
    int test=0;
    system("cls");
    heading();
    printf("\n\n\t\t\t========= LIST OF STUDENTS =========\n\n");
    printf("\n\n    ID. NO.\t\t    NAME\t\t\t\tEmail\t\t\t  PHONE\t\t    BATCH\n");

    while(fscanf(view,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
    {
        printf("\n%11lld %20s     %40s\t\t  %11s\t %10s\t",add.roll,add.name,add.email,add.phone,add.batch);
        test++;
    }

    fclose(view);
    if (test==0)
    {   
        printf("\nNO RECORDS!!\n");
    }

    view_list_invalid:
    printf("\n\n\n\t\t1. Return to Menu");
    printf("\n\t\t2. Exit");
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    menu();
    else if(main_exit==2)
    closing();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}
void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("srecord.txt","r");
    newrec=fopen("new.dat","w");

    heading();
    printf("\n\n\t\t\t========= UPDATE INFORMATION =========");

    printf("\n\n\nEnter the ID no. of the student whose info you want to change: ");
    scanf("%lld",&upd.roll);
    while(fscanf(old,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
    {
        if (add.roll==upd.roll)
        {   
            test=1;
            printf("\nWhich information do you want to change?\n1. Email\n2. Phone\n\nEnter your choice(1 for email and 2 for phone):");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\nEnter the new email:");
                scanf("%s",upd.email);
                fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,upd.email,add.phone,add.batch,add.cgpa);
                printf("\n\nChanges saved!");
            }
            else if(choice==2)
            {
                printf("\n\nEnter the new phone number:");
                scanf("%lld",&upd.phone);
                fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,upd.phone,add.batch,add.cgpa);
                
                printf("\n\nChanges saved!");
            }

        }
        else
        fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch,add.cgpa);
    }
    fclose(old);
    fclose(newrec);
    remove("srecord.txt");
    rename("new.dat","srecord.txt");

    if(test!=1)
    {   
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\t\t3. Edit");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)

        menu();
        else if (main_exit==2)
            closing();
        else if(main_exit==3)
            edit();
        else{
            printf("\nInvalid!\a");
        goto edit_invalid;}
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            closing();
    }
}

void cgpa()
{
    int n;
    FILE *old,*newrec;
    int test=0;
    old=fopen("srecord.txt","r");
    newrec=fopen("new.dat","w");
    heading();
    printf("\n\n\t\t\t========= CLCULATE CGPA =========");
    printf("\n\nEnter Student ID: ");
    scanf("%lld",&check.roll);
    while(fscanf(old,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
    {
        if (add.roll==check.roll)
        {   
            test=1;
            printf("\nEnter total courses: ");
            scanf("%d",&n);
            float marks[n],credit[n],grade[n],cgpa=0;
    
            for(int i=1;i<=n;i++)
            {
                printf("\nCourse %d \n\nMark   : ",i);
                scanf("%f",&marks[i]);
                printf("Credit : ");
                scanf("%f",&credit[i]);
            }
    
    
            for(int i=1;i<=n;i++)
            {
                if(marks[i]>=80)
                grade[i]=4.00;
                else if(marks[i]>=75)
                grade[i]=3.75;
                else if(marks[i]>=70)
                grade[i]=3.50;
                else if(marks[i]>=65)
                grade[i]=3.25;
                else if(marks[i]>=60)
                grade[i]=3.00;
                else if(marks[i]>=55)
                grade[i]=2.75;
                else if(marks[i]>=50)
                grade[i]=2.50;
                else if(marks[i]>=45)
                grade[i]=2.25;
                else if(marks[i]>=40)
                grade[i]=2.00;
                else
                grade[i]=0.00;
            }

    
            float total_grade=0,total_credit=0;
            for(int i=1;i<=n;i++)
            {
                total_grade=total_grade+credit[i]*grade[i];
                total_credit=total_credit+credit[i];
            }

            cgpa=total_grade/total_credit;
            printf("Total credit= %0.2f\n",total_credit);
            printf("Total grade= %0.2f\n",total_grade);
            printf("CGPA= %0.2f\n",cgpa);
            upd.cgpa=cgpa;
            fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch,upd.cgpa);
        }
        else
        {
            fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch,add.cgpa);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("srecord.txt");
    rename("new.dat","srecord.txt");

    if(test!=1)
    {   
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\t\t3. Edit");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)

        menu();
        else if (main_exit==2)
            closing();
        else if(main_exit==3)
            edit();
        else{
            printf("\nInvalid!\a");
        goto edit_invalid;}
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            closing();
    }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("srecord.txt","r");
    newrec=fopen("new.dat","w");
    heading();
    printf("\n\n\t\t\t========= DELETE INFORMATION =========");
    printf("\n\nEnter the ID no. of the Student you want to delete: ");
    scanf("%lld",&rem.roll);
    while (fscanf(old,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
   {
        if(add.roll!=rem.roll)
            fprintf(newrec,"%lld %s %d/%d/%d %d %s %s %s %.2f\n",add.roll,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch,add.cgpa);
        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("srecord.txt");
   rename("new.dat","srecord.txt");
   if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\t\t3. Try again");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closing();
        else if(main_exit==3)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            closing();
    }

}

void see()
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    ptr=fopen("srecord.txt","r");
    heading();
    printf("\n\n\t\t\t   ========= INFORMATION =========");
    printf("\n\nDo you want to check by\n1.ID no\n2.Name\n\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\nEnter the ID number: ");
        scanf("%lld",&check.roll);

        while (fscanf(ptr,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
        {
            if(add.roll==check.roll)
            {   
                test=1;
                printf("\n\nID NO.      : %lld\nName        : %s \nCGPA        : %.2f  \nDOB         : %d/%d/%d \nAge         : %d \nEmail       : %s\nPhone number: %s \nBatch       : %s\n\n",add.roll,add.name,add.cgpa,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch);
            }
        }
    }
    else if (choice==2)
    {   printf("\nEnter the name: ");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%lld %s %d/%d/%d %d %s %s %s %f",&add.roll,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.email,add.phone,add.batch,&add.cgpa)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   
                test=1;
                printf("\n\nID NO.      : %lld\nName        : %s \nCGPA        : %.2f \nDOB         : %d/%d/%d \nAge         : %d \nEmail       : %s\nPhone number: %s \nBatch       : %s\n\n",add.roll,add.name,add.cgpa,add.dob.day,add.dob.month,add.dob.year,add.age,add.email,add.phone,add.batch);
            }
        }
    }

    fclose(ptr);
    if(test!=1)
    {   
        printf("\n\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\n\n\n\t\t1. Return to Menu");
        printf("\n\t\t2. Exit");
        printf("\n\t\t3. Try Again");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&main_exit);
        system("cls");
            
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closing();
        else if(main_exit==3)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
    printf("\n\n\n\t\t1. Return to Menu");
    printf("\n\t\t2. Exit");
            
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d",&main_exit);
    }
    if (main_exit==1)
    {
        system("cls");
        menu();
    }
    else
    {
        system("cls");
        closing();
    }

}

void menu()
{   
    int choice;
    system("cls");
    heading();
    printf("\n\n\t\t\t      ========= MENU =========");
    printf("\n\n\n\t\t1.Add New Student\n\t\t2.Update information of existing student\n\t\t3.Calculate CGPA\n\t\t4.Check the details of existing student\n\t\t5.Remove information of existing student\n\t\t6.View student's list\n\t\t7.Exit\n\n");
    try_again:
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d",&choice);
    if((choice!=1)&&(choice!=2)&&(choice!=3)&&(choice!=4)&&(choice!=5)&&(choice!=6)&&(choice!=7))
    {
        printf("\n\n\t\tInvalid Choice!!!\a\a\a\n\t\tTry Again....");
        fordelay(1000000000);
        goto try_again;
    }
    system("cls");
    switch(choice)
    {
        case 1: new_std();
        break;
        case 2: edit();
        break;
        case 3: cgpa();
        break;
        case 4: see();
        break;
        case 5: erase();
        break;
        case 6: view_list();
        break;
        case 7: closing();
        break;

    }

}

