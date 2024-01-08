#include<stdio.h>
int function(int y,int m,int q)
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

    int h=(q+y+term1+term2+term3+term4)%7;
    printf(" \n");
    return h;

}

int main()
{
    int y,m,q;
    printf("Enter year:  ");
    scanf("%d",&y);
    printf("Enter month(1-12):");
    scanf("%d",&m);
    printf("Enter day  :   ");
    scanf("%d",&q);

    int h=function(y,m,q);
    if (m==1)
        printf("January");
    else if (m==2)
        printf("February");
    else if (m==3)
        printf("March");
    else if (m==4)
        printf("April");
    else if (m==5)
        printf("May");
    else  if (m==6)
        printf("June");
    else if (m==7)
        printf("July");
    else if (m==8)
        printf("August");
    else if (m==9)
        printf("September");
    else if (m==10)
        printf("October");
    else if (m==11)
        printf("November");
    else if (m==12)
        printf("December");

    switch(h)
    {
    case 0:
        printf(" %d ,%d  is Saturday ",q,y);
        break;
    case 1:
        printf(" %d ,%d is Sunday",q,y);
        break;
    case 2:
        printf("  %d ,%d is Monday",q,y);
        break;
    case 3:
        printf(" %d ,%d is Tuesday",q,y);
        break;
    case 4:
        printf("  %d ,%d is Wednesday",q,y);
        break;
    case 5:
        printf("  %d ,%d is Thursday",q,y);
        break;
    case 6:
        printf("  %d ,%d is Friday",q,y);
        break;

    }
    return 0;
}


