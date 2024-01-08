#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main()
{

    int array[100],total,count=2,nmb,i,ch;
    for(i=2; i<100; i++)
    {
        array[i]=(-1);
    }

    while(1)
    {
       if(i>=100)
        return -1;
       if(array[i]==(-1))
       {
           array[i]=nmb;
       }
       if(nmb>array[i])
           i=2*i+1;
       if(nmb<array[i])
        i=2*i;
    }



for(i=1;i<=100;i++)
{
    printf("%d",array[i]);
}






    printf("\n\n");
    printf("\tChoose:");
    printf("\n\t\t1.For inserting a new value into the tree");
    printf("\n\t\t2.For finding Height of a node ");
    printf("\n\t\t3.For displaying the listing value");
    printf("\n\t\t4.For deleting an element");
    printf("\n\t\t5.For finding maximum height of the tree\n");
    printf("\n\tEnter your choice:");
    scanf("%d",&ch);


    switch(ch)
    {
    case 1:
        system("cls");
        /* int array[100],total,count=2,nmb,i,nmb;
          for(i=2;i<100;i++)
         {
             array[i]=(-1);
         }
         printf("Enter total element of the tree:");
         scanf("%d",&total);

         printf("Enter the element of tree:");
         scanf("%d",&array[1]);


         while(count!=total)
         {   i=1;
             scanf("%d",&nmb);
            if(nmb>array[1])
            {
                while(array[i]!=(-1))
                {
                    i=2*i+1;
                }

                array[i]=nmb;
            }

               if(nmb<array[1])
            {
                while(array[i]!=(-1))
                {
                    i=2*i;
                }

                array[i]=nmb;
            }

           count++;
         }

         printf("\n");
         for(i=1;i<100;i++)
         {
             if(array[i]!=(-1))
                printf("%d ",array[i]);
         }





         */





    }















































}














