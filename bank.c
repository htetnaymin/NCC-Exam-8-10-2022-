#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<conio.h>
#include <unistd.h>
int main();
void Login();
char reg();
int checker();
int Menu();
int append();
void begin();
void unameread();
void unamewrite();
void bread();
void bwrite();
int random(int *lucknumber);
int passbyrefernce(int *sender,int *receiver,int amount);
void pass();
void print();
void passwrite();
int transfer();
void upassread();
char upass[100][100];
int balance[100];
char uname[100][100];
char username[100];
char password[100];
int cuindex=0;
int count=0;
int count1=0;
int num=0;
int lnum=0;
int pmoney=0;
int money=0;
int tindex=0;
char tusername[100];
int tmoney=0;
FILE *f;
FILE *g;
int main()
{
    printf("This program is created by HNM.");
    char condition;
    begin();
//     print();
    printf("Welcom to lottery game.\n");
    while(1==1)
    {
        printf("Enter 'l' to login.\nEnter 'r' to register.\nEnter 'e' to exit : ");
        scanf(" %c",&condition);
//        printf("condition=%c\n",condition);
        if(condition=='l'|| condition=='L')
        {
            Login();
//            printf("Test");
            return 0;
        }
        else if(condition=='R'||condition=='r')
        {
            printf("Enter Your Username To Register: ");
            fflush(stdin);
            fgets(username,sizeof(username),stdin);
            reg();
            return 0;
        }
        else if(condition=='E',condition=='e')
        {
            printf("Bye!");
            exit(0);
        }
        else
        {
            printf("Error!\nTry Again!");
        }

    }
    return 0;
}
char reg()
{
    printf("Enter Your password : ");
    fflush(stdin);
    fgets(password,sizeof(password),stdin);
    int m;
    printf("Enter money amount : ");
    append(username);
    scanf("%d",&balance[cuindex]);
//    printf("Username = %s",uname[cuindex]);
    bwrite();
    Login();
    exit(0);
    return 0;

}
int checker(char input[], char check[])
{
//    printf("Input : %s",input);
//    printf("Check : %s",check);
    int i, result = 1;
    for (i = 0; i< 100; i++)
    {
//        printf("Input[%d] : %c\n",i,input[i]);
//        printf("Check : %c\n",check[i]);
//        input[3]='\0';
        if(input[i]=='\n' && check[i]=='\0')
        {
            if(strlen(check)==0)
            {
                return 0;
            }
//            printf("i=%d",i);
            return result;
        }
        if (input[i] != check[i])
        {
//            printf("i : %d",i);
            result = 0;
            return result;
        }
    }
    return result;
}
int Menu()
{
    char condition;
    printf("Welcom back.\n");
    printf("Your balance = %d\n",balance[cuindex]);

    while(1==1)
    {
        printf("Enter 'a' to add money.\nEnter 'c' to get cash.\n Enter 't' to transfer money to others.\nEnter 'e' to Exit.\n:");
        scanf(" %c",&condition);
//        printf("condition=%c\n",condition);
        if(condition=='a'|| condition=='A')
        {
            printf("Enter your money amount to add : ");
            scanf("%d",&money);
            balance[cuindex]=balance[cuindex]+money;
            printf("Your balance is = %d\n",balance[cuindex]);
            printf("Press Enter to continue.");
            bwrite();
            getch();
            Menu();
            return 0;
        }
        else if(condition=='C'||condition=='c')
        {
            printf("Enter money amount to cash out : ");
            scanf("%d",&money);
            balance[cuindex]=balance[cuindex]-money;
            printf("Your balance is = %d\n",balance[cuindex]);
            bwrite();
            printf("Press Enter to continue.");
            getch();
            Menu();
            return 0;
        }
        else if(condition=='t'||condition=='T')
        {
            transfer();
            return 0;
        }
        else if(condition=='E',condition=='e')
        {
            printf("Bye!");
            exit(0);
        }
        else
        {
            printf("Error!\nTry Again!");
        }

    }
}
int append(char username[])
{
    int condition=0;
    int i=0;
    for (i = 0; i < 100; ++i)
    {
//        printf("%d",strlen(uname[i]));
        if(strlen(uname[i])==0)
        {
//            printf("uname[%d]=%s",i,uname[i]);
            strcpy(uname[i], username);
            strcpy(upass[i],password);
            cuindex=i;
            for (int j = 0; j < 100; ++j)
            {
                if(uname[i][j]=='\n')
                {
                    uname[i][j]='\0';
                    condition=condition+1;
                }
                if(upass[i][j]=='\n')
                {
                    upass[i][j]='\0';
                    condition=condition+1;
                }
                if(condition==2)
                {
                    goto Here;
                }
            }
            Here:
            unamewrite();
            passwrite();
            return i;
        }
    }
    return i;
}
void Login()
{
    printf("Enter Your Username : ");
    fflush(stdin);
    fgets(username,sizeof(username),stdin);
    int condition=0;
    char condition1;
//    printf("Your username is : %s\n", username);
    strcpy(uname[0], "Htet Nay Min");
    for (int i = 0; i < 100; ++i)
    {
        if (checker(username,uname[i]) == 1)
        {
            cuindex=i;
            condition = 1;
            pass();
            Menu();
            exit(0);
        }
        else
        {
            condition=0;
        }
    }
    if(condition==0)
    {
        printf("You haven't registered yet.\n");
        printf("Do you want to register (Y/N) : ");
        scanf("%c",&condition1);
        if(condition1=='N')
        {
            printf("Okay Bye.");
            exit(0);
        }
        reg();
    }
}
void begin()
{
    for (int i = 0; i < 100; ++i)
    {
//        strcpy(uname[i],"");
        username[i]='\0';
    }
    printf("Program is starting please wait ...\n");
    bread();
    unameread();
    upassread();
//    print();
}
void unameread()
{
    count=0;count1=0;
    if(fopen("uname.txt","r")==NULL)
    {
        fopen("uname.txt","w");
    }
    else
    {
        char cache[10000];
        char temp[100];
        f=fopen("uname.txt","r");
//        fscanf(f,"%s",cache);
        fgets(cache,10000,f);
        int sizeofcache=sizeof(cache)/sizeof(cache[0]);
        for (int i = 0; i < sizeofcache; ++i)
        {
            if(cache[i]=='\0')
            {
//                print();
                fclose(f);
                return;
            }
            if (cache[i]=='|')
            {
                for (int j = 0; j < 100; ++j)
                {
                    uname[count][j]= temp[j];
//                    sleep(0.01);
                }
                count=count+1;
                for (int j = 0; j <100; ++j)
                {
                    temp[j]='\0';
                }
                count1=0;
            }
            else
            {

                temp[count1] = cache[i];
                count1=count1+1;
            }
        }
    }
    fclose(f);
}
void unamewrite()
{
    int size=sizeof(uname)/sizeof(uname[0]);
    fopen("uname.txt","w");
    f=fopen("uname.txt","a");
    for (int i = 0; i < size ; ++i)
    {
        fprintf(f,"%s|",uname[i]);
    }
}
void bread()
{
    char pointer;
    int count2=0,count3=0;
    if(fopen("balance.txt","r")==NULL)
    {
        fopen("balance.txt","w");
    }
    else
    {
        char cache1[10000];
        char temp1[100];
        g=fopen("balance.txt","r");
        fscanf(g,"%s",&cache1);
//        fgets(cache1,10000,g);
//        printf("%s",cache1);
        int sizeofcache1=sizeof(cache1)/sizeof(cache1[0]);
        for (int i = 0; i < sizeofcache1; ++i)
        {
//            if(i==200)
            // {
            //     print();
            // }
            if(cache1[i]=='\0' && isdigit(cache1)==0)
            {
//                print();
                fclose(g);
                return;
            }
            if (cache1[i]=='|')
            {
                balance[count2]=atoi(temp1);
//                balance[count2]=strtol(temp1,&pointer,10);
//                getch();
//                printf("temp1=%s\n",temp1);
//                printf("balance=%d\n",balance[count2]);
                count2=count2+1;
                for (int j = 0; j <100; ++j)
                {
                    temp1[j]='\0';
//                    sleep(0.01);
                }
                count3=0;
//                if(i>200)
//                    printf("%d\n",i);
            }
            else
            {

                temp1[count3] = cache1[i];
                count3=count3+1;
            }
        }
    }
//    printf("Test");
    fclose(g);
}
void bwrite()
{
    int size=sizeof(balance)/sizeof(balance[0]);
    fopen("balance.txt","w");
    f=fopen("balance.txt","a");
    for (int i = 0; i < size ; ++i)
    {
        fprintf(f,"%d|",balance[i]);
    }
}
void print()/*Used for debugging*/
{
    for (int i = 0; i < 100; ++i)
    {
        printf("uname[%d]=%s\n",i,uname[i]);
        printf("balance[%d]=%d\n",i,balance[i]);
        printf("password[%d]=%s\n",i,upass[i]);
    }
}
int random(int *lucknumber)
{
    srand(time(NULL));   // Initialization, should only be called once.
    *lucknumber = rand();
    *lucknumber=((*lucknumber)*65*65)%1000;
}
int transfer()
{
    int condition;
    printf("Enter Acc name to transfer : ");
    fflush(stdin);
    fgets(tusername,sizeof(tusername),stdin);
    for (int i = 0; i < 100; ++i)
    {
        if (checker(tusername,uname[i]) == 1)
        {
            tindex=i;
            condition = 1;
            goto Found;
//            Menu();
//            exit(0);
        }
        else
        {
            condition=0;
        }
    }
    if(condition==0)
    {
        printf("There's not Acc name %s\n",tusername);
        printf("Try again.\n");
        transfer();
    }
    Found:
    printf("Found Acc name %s",tusername);
    printf("Enter money amount to transfer:");
    scanf("%d",&tmoney);
//    balance[tindex]=balance[tindex]+tmoney;
//    balance[cuindex]=balance[cuindex]-tmoney;
    passbyrefernce(&balance[cuindex],&balance[tindex],tmoney);
    bwrite();
    printf("%d transferred to %s\n",tmoney,uname[tindex]);
    printf("Your account balance is now : %d\n",balance[cuindex]);
    printf("Press Enter to continue.\n");
    getch();
    Menu();
    return 0;
}
int passbyrefernce(int *sender,int *receiver,int amount)
{
    *sender=*sender-amount;
    *receiver=*receiver+amount;
    return 0;
}
void pass()
{
    int condition = 0;
    printf("Enter Your Password : ");
    fflush(stdin);
    fgets(password,sizeof(password),stdin);
//    printf("%s",password);
    if (checker(password,upass[cuindex]) == 1)
    {
//      cuindex=i;
        condition = 1;
//      Menu();
        return;
    }
    else
    {
        condition=0;
    }
    if(condition==0)
    {
        printf("Password is worng!\nPlease try again.\n  ");
        pass();
    }
}
void upassread()
{
    count=0;count1=0;
    if(fopen("upass.txt","r")==NULL)
    {
        fopen("upass.txt","w");
    }
    else
    {
        char cache[10000];
        char temp[100];
        f=fopen("upass.txt","r");
//        fscanf(f,"%s",cache);
        fgets(cache,10000,f);
        int sizeofcache=sizeof(cache)/sizeof(cache[0]);
        for (int i = 0; i < sizeofcache; ++i)
        {
            if(cache[i]=='\0')
            {
//                print();
                fclose(f);
                return;
            }
            if (cache[i]=='|')
            {
                for (int j = 0; j < 100; ++j)
                {
                    upass[count][j]= temp[j];
//                    sleep(0.01);
                }
                count=count+1;
                for (int j = 0; j <100; ++j)
                {
                    temp[j]='\0';
                }
                count1=0;
            }
            else
            {

                temp[count1] = cache[i];
                count1=count1+1;
            }
        }
    }
    fclose(f);
}
void passwrite()
{
    int size=sizeof(upass)/sizeof(upass[0]);
    fopen("upass.txt","w");
    f=fopen("upass.txt","a");
    for (int i = 0; i < size ; ++i)
    {
        fprintf(f,"%s|",upass[i]);
    }
}