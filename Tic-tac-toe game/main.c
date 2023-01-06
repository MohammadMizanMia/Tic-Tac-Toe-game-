#include<stdio.h>
#include<stdbool.h>
void printc(int a[][4],int n);
int isWins(int a[][4],int n);

//main function;
int main()
{
    int n = 3;
    int a[4][4];

    for(int i = 1; i <=3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            a[i][j] = -1;
        }
    }

    bool player1 = true;
    bool player2 = false;
   while(true)
   {
       printc(a,n);
       if(player1)
       {
           int r,c;
           enter:
           printf("1st player(X) turn , enter row & column : ");
           scanf("%d %d",&r,&c);
           if(a[r][c] != -1)
           {
                printf("This box already fill!\n");
               goto enter;
           }
           a[r][c] = 1;
           player1 = false;
           player2 = true;
       }
       else
       {
            int r,c;
            enter2:
            printf("2nd player(O) turn , enter row & column : ");
           scanf("%d %d",&r,&c);
            if(a[r][c] != -1)
           {
               printf("This box already fill!\n");
               goto enter2;
           }
           a[r][c] = 2;
           player2 = false;
           player1 = true;
       }

       if(isWins(a,n)==1)
       {

           printf("Player 1 is win!\n");
           printc(a,n);
           break;
       }
      if(isWins(a,n)==2)
       {

           printf("Player 2 is win!\n");
           printc(a,n);
           break;
       }
   }
    return 0;
}


//user defined function;
void printc(int a[][4],int n)
{
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == -1)
            {
                printf(" ");
            }
            if(a[i][j] == 1)
            {
                printf("X");
            }
            if(a[i][j] == 2)
            {
                printf("O");
            }
            if(j<n)
                printf("\t | \t");
        }
        printf("\n");
        if(i<n)
            printf("__________________________________");
        printf("\n");
        printf("\n");
    }
}

int isWins(int a[][4],int n)
{
    int i,j;
    for(i = 1; i<=n; i++)
    {
        if(a[i][1]==a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1)
        {
            return a[i][1];
        }
    }
     for(j = 1; i<=n; i++)
    {
        if(a[1][j]==a[2][j] && a[2][j] == a[3][j] && a[1][j] != -1)
        {
            return a[j][1];
        }
    }

    if(a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != -1)
    {
        return a[1][1];
    }

     if(a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] != -1)
    {
        return a[1][1];
    }

    return -1;
}


