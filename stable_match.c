#include <stdio.h>
#include <stdlib.h>
void print_matrix(int *one,int size);
int *shuffle(int *one,int size);
int *shuffle(int *one,int size)
{
    int i;
    for (i = size - 1; i > 1; --i)
    {
        // generate random index
        int w = (rand() % i) + 1;
        // swap items
        int t = *(one+i);
        *(one+i) = *(one+w);
        *(one+w) = t;
    }
    return one;
}

// void print_matrix(int *one,int size)
// {
//     int i,j ;
//     for(i = 1; i < size; i++)
//     {
//         for(j = 1; j < size; j++)
//         {
//             printf("%d  ",*(one[i]+j));
//         }
//         printf("\n");
//     }
// }
void main()
{
    int n;
    printf("enter the number of men or women : ");
    scanf("%d", &n);
    // int **men_preferences = malloc(n*sizeof(int))
    int m_pre[n + 1][n+1];
    int w_pre[n+1][n+1];
    int i, j;
    for(i = 0; i < n + 1; i++)
    {
        m_pre[0][i] = 0;
        w_pre[0][i] = 0;
        m_pre[i][0] = 0;
        w_pre[i][0] = 0;
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            m_pre[i][j] = j;
            w_pre[i][j] = j;
            
        }
         shuffle(&m_pre[i][0],n+1);
         shuffle(&w_pre[i][0],n+1);
    }
    i = 0;
    for(i = 1; i < n+1; i++)
    {
        for(j= 1; j < n+1; j++)
        {
            printf("%d ",m_pre[i][j]);
        }
        printf("\n");
    }

    for(i = 1; i < n+1; i++)
    {
        for(j= 1; j < n+1; j++)
        {
            printf("%d ",w_pre[i][j]);
        }
        printf("\n");
    }


    int en_men[n+1];
    int en_wmn[n+1];
    for(i=0; i < n+1; i++)
    {
        en_men[i] = 0;
        en_wmn[i] = 0;
    }
    int temp = 0;
    int count = 0;
    i = 1;
    while(i < n+1)
    {
        if(en_men[i] == 0)
        {
            if(en_wmn[m_pre[i][m_pre[i][0]+1]] == 0)
            {
                en_men[i] = m_pre[i][0]+1;
                
                en_wmn[m_pre[i][m_pre[i][0]+1]] = i;
                int k;
                for(k = 1; k < n+1; k++)
                {
                    if(w_pre[m_pre[i][m_pre[i][0]+1]][k] == i)
                    {
                        w_pre[m_pre[i][m_pre[i][0]+1]][0] = k;
                        break;
                    }
                }
                m_pre[i][0] = m_pre[i][0] + 1;
                i = i+1;
                
                // if(count != 0)
                // {
                //     count = count - 1;
                // }
            } 
            else
            {
                int k = 1;
                // int ch = en_wmn[m_pre[i][0] + 1];

                for(k = 1; k < w_pre[m_pre[i][m_pre[i][0]+1]][0];k++)
                {
                    if(w_pre[m_pre[i][m_pre[i][0]+1]][k] == i)
                    {
                        temp = en_wmn[m_pre[i][m_pre[i][0]+1]];
                        count = 1;
                        en_wmn[m_pre[i][m_pre[i][0]+1]] = i;
                        w_pre[m_pre[i][m_pre[i][0]+1]][0] = k;
                        m_pre[i][0] = m_pre[i][0] + 1;
                        i = i +1;
                        break;

                    }
                    
                }
                if(temp == 0)
                {
                    m_pre[i][0] = m_pre[i][0] + 1;
                }
                else if(count == 1)
                {
                    int x = i;
                    i = temp;
                    temp = x;


                }
                else
                {
                    i = temp;
                    temp = 0;
                    count = 0;
                }
                
                
            }
            
        }
    }



    // print_matrix(&m_pre[0][0],n+1);
    printf("\n");
    for(i = 1; i < n + 1; i++)
    {
        printf("%d->",en_men[i]);
    }


}
