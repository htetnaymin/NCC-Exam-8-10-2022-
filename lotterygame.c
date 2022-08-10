#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int main();
void game();
char reg();
int checker();
int ingame();
int append();
void begin();
void unameread();
void unamewrite();
void bread();
void bwrite();
int random(int *lucknumber);
void print();
int balance[100];
char uname[100][100];
char username[100];
int cuindex=0;
int count=0;
int count1=0;
int num=0;
int lnum=0;
int pmoney=0;
int money=0;
FILE *f;
FILE *g;
int main()
{
    printf("This program is created by HNM.");
    begin();
//     print();
    printf("Welcom to lottery game.\n");
    game();
    return 0;
}
char reg()
{
    int m;
    printf("Enter money amount : ");
    append(username);
    scanf("%d",&balance[cuindex]);
//    printf("Username = %s",uname[cuindex]);
    bwrite();
    game();
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
int ingame()
{
    char condition;
    printf("Welcom back.\n");
    printf("Your balance = %d\n",balance[cuindex]);
    if(balance[cuindex]<1000)
    {
        printf("You don't have enough money to play.\nYou need to add money.\n");
        printf("Do you want to add more money?(Y/N)");
        getchar();
        scanf("%c",&condition);
        if(condition=='N'||condition=='n')
        {
//            main();
            return 0;
        }
        printf("Enter your money amount to add : ");
        scanf("%d",&money);
        balance[cuindex]=balance[cuindex]+money;
        printf("You can start play now.\n");
    }
    while(0==0)
    {
        printf("Enter your lucky number : ");
        scanf("%d",&num);
        printf("Enter your money amount to play :");
        scanf("%d",&pmoney);
        balance[cuindex]-pmoney;
        int lucknumber;
        random(&lucknumber);
        printf("LuckNumber is %d\n",lucknumber);
        if(num==lucknumber)
        {
            balance[cuindex]=balance[cuindex]+(pmoney*10);
            bwrite();
            printf("You win the lottery!\n");
            printf("Your balance is %d\n",balance[cuindex]);
        }
        else
        {
            balance[cuindex]=balance[cuindex]-pmoney;
            printf("You lose the lottery.\n");
            printf("Your balance is %d\n",balance[cuindex]);
            bwrite();
        }

        printf("Do you want to play again(Y/N):");
        getchar();
        scanf("%c",&condition);
        if(condition=='N'|| condition=='n')
        {
//            main();
            return 0;
        }
    }
    return 0;
}
int append(char username[])
{
    int i=0;
    for (i = 0; i < 100; ++i)
    {
//        printf("%d",strlen(uname[i]));
        if(strlen(uname[i])==0)
        {
//            printf("uname[%d]=%s",i,uname[i]);
            strcpy(uname[i], username);
            cuindex=i;
            for (int j = 0; j < 100; ++j)
            {
                if(uname[i][j]=='\n')
                {
                    uname[i][j]='\0';
                    goto Here;
                }
            }
            Here:
            unamewrite();
            return i;
        }
    }
    return i;
}
void game()
{
    printf("Enter Your Username : ");
    fflush(stdin);
    fgets(username,sizeof(username),stdin);
    int condition=0;
    char condition1;
    printf("You username is : %s\n", username);
    strcpy(uname[0], "Htet Nay Min");
    for (int i = 0; i < 100; ++i)
    {
        if (checker(username,uname[i]) == 1)
        {
            cuindex=i;
            condition = 1;
            ingame();
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
        strcpy(uname[i],"");
//        username[i]='\0';
    }

    bread();
    unameread();
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
    }
}
int random(int *lucknumber)
{
    srand(time(NULL));   // Initialization, should only be called once.
    *lucknumber = rand();
    *lucknumber=((*lucknumber)*65*65)%1000;
}
