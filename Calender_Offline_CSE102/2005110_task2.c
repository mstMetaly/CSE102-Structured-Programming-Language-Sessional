#include<stdio.h>

int function(int y,int m )
{
    if(m==1|| m==2)
    {
        m=m+12;
        y=y-1;
    }
    int term1=(26*(m+1))/10;
    int term2=y/4;
    int term_3=(y/100);
    int term3=6*term_3;
    int term4=y/400;

    int h=(1+y+term1+term2+term3+term4)%7;

    return h;
}

void calender(int y,int m)
{

    int month_days;

    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        month_days=31;
    if(m==2)
    {
        if((y%4==0 && y%100!=0)||(y%400==0))
            month_days=29;
        else month_days=28;
    }
    if(m==4||m==6||m==9||m==11) month_days=30;

    int weekday,date,starting_day;
    int month1st_day=function(y,m);
    if(month1st_day==0)
    {
        starting_day=7;
    }
    else starting_day=month1st_day;


    printf("  Calender For:\n");
    printf("\n");

    if(m==1) printf("  January, %d\n",y);
    else if(m==2) printf("  February, %d\n",y);
    else if (m==3) printf("  March, %d\n",y);
    else if(m==4) printf("  April, %d\n",y);
    else  if(m==5) printf("  May, %d\n",y);
    else  if(m==6) printf ("  June, %d\n",y);
    else  if(m==7) printf("  July, %d\n",y);
    else if(m==8) printf("  August, %d\n",y);
    else  if(m==9) printf("  September, %d\n",y);
    else if(m==10) printf("  October, %d\n",y);
    else  if(m==11) printf("  November, %d\n",y);
    else if(m==12) printf("  December, %d\n",y);
    printf("\n");

    printf("  Sun Mon Tue Wed Thu Fri Sat\n");

    for(weekday=1; weekday<starting_day; weekday++)
    {
        printf("    ");
    }
    for(date=1; date<=month_days; date++)
    {
        if(weekday>7)
        {
            printf("\n");
            weekday=1;
        }
        printf("%4d",date);
        weekday++;

    }

}

int main()
{
    int y,m;
    printf("  Enter year:  ");
    scanf("%d",&y);
    printf("  Enter month(1-12):");
    scanf("%d",&m);
    printf("\n");
    calender(y,m);

    return 0;
}







