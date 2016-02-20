#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("@echo off");
    system("cls");
    int m,n,x,y;
    scanf("%d %d",&m,&n);
    system("cls");
    int T=m;
    m=n;
    n=T;
    int f[m][n];

    for(int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            f[i][j]=0;
            printf("-");
        }
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        scanf("%d %d",&x,&y);
        x--; y--;
        int t=y;
        y=x;
        x=t;

        if(x<0 || y<0 || x>=m || y>=n)
            break;
        system("cls");
        f[x][y]=!(f[x][y]);
        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if(f[i][j])
                    printf("#");
                else
                    printf("-");
            }
            printf("\n");
        }
        printf("\n");
    }

    int ff[m][n];
    int c;
    system("pause");
    while(1)
    {
        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                ff[i][j]=f[i][j];
            }
        }
        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                c=0;
                if(i>0)            if(f [i-1][j] == 1)   c++;
                if(i>0 && j>0)     if(f [i-1][j-1] == 1) c++;
                if(j>0)            if(f [i][j-1] == 1)   c++;
                if(j>0 && i<m-1)   if(f [i+1][j-1] == 1) c++;
                if(i<m-1)          if(f [i+1][j] == 1)   c++;
                if(i<m-1 && j<n-1) if(f [i+1][j+1] == 1) c++;
                if(j<n-1)          if(f [i][j+1] == 1)   c++;
                if(i>0 && j<n-1)   if(f [i-1][j+1] == 1) c++;

                if(f[i][j] == 1 && (c<2 || c>3))
                    ff[i][j] = 0;
                else if(f[i][j] == 0 && c == 3)
                    ff[i][j] = 1;
            }
        }
        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                f[i][j]=ff[i][j];
            }
        }
        system("cls");
        printf("\n");
        char choice;

        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if(f[i][j])
                    printf("#");
                else
                    printf("-");
            }
            printf("\n");
        }
        scanf("%c", &choice);
        if(choice == 'q') break;
    }
    return 0;
}
