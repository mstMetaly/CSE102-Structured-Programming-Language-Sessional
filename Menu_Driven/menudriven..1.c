#include<stdio.h>
#include<windows.h>
#include<conio.h>


int position(int array[],int nmb,int size)
    {
    int i,index;
    for(i=0;i<size;i++)
    {
        if(array[i]<=nmb && nmb<array[i+1]){
        index=i+1;
        }
    }

    return index;

}

int check_sort(int array[],int size)
{
    int i,count=0,sorted;
    for(i=0;i<=(size-2);i++)
    {
        if(array[i]<array[i+1])
            count++;
    }
   if(count==(size-1))
    return 1;
    else return 2 ;


}


int main()
{   int ch;
    do{
    printf("    Choose-\n");
    printf("\t1 for taking input\n");
    printf("\t2 for display\n");
    printf("\t3 for sorting\n");
    printf("\t4 for inserting\n");
    printf("\t5 for appending\n");
    printf("\t6 for deleting\n");
    printf("\t7 for searching\n");
    printf("\t8 for exit\n\n");
    printf("     Enter your choice:");
    scanf("%d",&ch);


    switch(ch){

    case 1:
        system("cls");
        int array[100],i,size;
        printf("How many numbers do you want to take as input?");
        scanf("%d",&size);
        for(i=0;i<size;i++)
        {  printf("Enter data:");
            scanf("%d",&array[i]);
        }

        printf("\n\n\tPress any key to continue:");
        getch();
        system("cls");
        break;

    case 2:
        system("cls");
        for(i=0;i<size;i++)
        {
            printf("%d\n",array[i]);
        }
        printf("\n\n\tPress any key to continue:");
        getch();
        system("cls");
        break;

    case 3:
        system("cls");
        int j,temp,n;
        printf("To get ascending order press 1:\n");
        printf("to get descending order press 2:\n");
        scanf("%d",&n);

        if(n==1){
        for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
            {
                if(array[i]>array[j])
                { temp=array[j];
                array[j]=array[i];
                array[i]=temp;

                }
            }
        }
        printf("Sorting by ascending order:");
        for(i=0;i<size;i++)
        {
            printf("%d ",array[i]);
        }
        }

  else if(n==2){
        for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
            {
                if(array[i]<array[j])
                { temp=array[j];
                array[j]=array[i];
                array[i]=temp;

                }
            }
        }
         printf("Sorting by decending order:");

        for(i=0;i<size;i++)
        {
            printf("%d ",array[i]);
        }
        }

  printf("\n\n\tPress any key to continue:");
  getch();
  system("cls");
  break;

    case 4:
        system("cls");

        int nmb,index,pos;
        printf("Which data do you want to insert?");
        scanf("%d",&nmb);

        int sort=check_sort(array,size);

        if(sort==1){
        index=position(array,nmb,size);

    }
    if(sort==2)
    {
        printf("For which position want to insert value?");
        scanf("%d",&pos);
        index=pos-1;
    }

   for(i=size-1;i>=index;i--)
   {
       array[i+1]=array[i];
   }
   array[index]=nmb;
   size++;
   for(i=0;i<size;i++)
   {
       printf("%d",array[i]);
   }

printf("\n\n\tPress any key to continue:");
getch();
system("cls");
break;


    case 5:
        system("cls");
        int more;
        printf("How many more data do you want to append?");
        scanf("%d",&more);
        int m=more+size;
        for(i=size;i<m;i++)
        {  printf("Enter data:");
            scanf("%d",array[i]);
        }
        size=size+more;

/*  for(i=0;i<size;i++)
  {
      printf("%d",array[i]);
  }*/
  system("pause");
  printf("\n\n\tPress any key to continue:");
  getch();

  break;

    case 6:
        system("cls");
        int del_data,count=0;
        printf("Which data want to delete?");
        scanf("%d",&del_data);
          for(i=0;i<size;i++)
        {
            if(array[i]==del_data){
                index=i;
                count++;}

        }
        if(count==0)
            printf("%d is not found at array",del_data);
        else{
         temp=array[index];
        for(i=index;i<=size-2;i++)
        {
        array[i]=array[i+1];
        }
        size--;
        for(i=0;i<size;i++)
        {
            printf("%d",array[i]);
        }
        }

     printf("\n\n\tPress any key to continue:");
     getch();
     system("cls");
     break;

    case 7:
        system("cls");
        int search,counting=0;
        printf("Which data do you want to search?");
        scanf("%d",&search);
        for(i=0;i<size;i++)
        {
            if(array[i]==search)
                printf("%d is found at index %d,position %d \n",search,i,i+1);
            counting++;
        }

        if(counting==0)
          {
          printf("%d is not found",search);}

        printf("\n\n\tPress any key to continue:");
        getch();
        system("cls");
        break;


        }
    }
    while(ch!=8);









}
