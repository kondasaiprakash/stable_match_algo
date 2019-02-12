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
    int power_front = 0;
    i = 1;
    while(i < n+1)
    {
    	
        if(en_men[i] == 0 && m_pre[i][0] <= n/2)
        {
        
            if(en_wmn[m_pre[i][m_pre[i][0]+1]] == 0)
            {
                en_men[i] = m_pre[i][0]+1;
                
                en_wmn[m_pre[i][m_pre[i][0]+1]] = i;
                int k;
                int women_matched = 0;
                for(k = 1; k < n/2; k++)
                {
                    if(w_pre[m_pre[i][m_pre[i][0]+1]][k] == i)
                    {
                        w_pre[m_pre[i][m_pre[i][0]+1]][0] = k;
                        women_matched = 1;
                        break;
                    }
                }
                if(women_matched == 0)
                {
                	en_men[i] = 0;
                	en_wmn[m_pre[i][m_pre[i][0]+1]] = 0;
                	m_pre[i][0] = m_pre[i][0] + 1;
                }
                else
                {
                
                	m_pre[i][0] = m_pre[i][0] + 1;
                	i = i+1;
            	}
                
                // if(count != 0)
                // {
                //     count = count - 1;
                // }cl
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
                        en_men[temp] = 0;
                        // count = 1;
                        en_wmn[m_pre[i][m_pre[i][0]+1]] = i;
                        w_pre[m_pre[i][m_pre[i][0]+1]][0] = k;
                        m_pre[i][0] = m_pre[i][0] + 1;
                        en_men[i] = m_pre[i][0];
                        i = i +1;
                        break;

                    }
                    
                }
                if(temp == 0)
                {
                    m_pre[i][0] = m_pre[i][0] + 1;
                    if(count == 1)
                    {
                        continue;
                    }
                }
                else if(count == 0){
                    int x = i;
                    i = temp;
                    temp = 0;
                    power_front = x;
                    count = 1;
                    continue;

                }
                else
                {
                    i= temp; 
                    temp = 0;
                    continue;
                }
                
    
                
                
            }
            if(count == 1)
            {
                i = power_front;
                temp = 0;
                count = 0;
            }
            
        }
        else
        {
        	if(count == 1)
        	{
        	
        		i = power_front;
        		temp = 0;
        		count = 0;
        	}
        	else
        	{
        		i = i + 1;
        	}
        }
    }
    int counter = 0;
    for(i = 1; i < n+1; i++)
    {
    	if(en_men[i] != 0)
    	{
    	
    		printf("\n %d mathced",i);
    		counter++;
    	}
    }
    printf(" \n %d",counter);



    // print_matrix(&m_pre[0][0],n+1);
//    printf("\n");
//    for(i = 1; i < n + 1; i++)
//    {
//        printf("%d->",en_men[i]);
//
//    }
//    printf("\n");
//    for(i = 1; i < n + 1; i++)
//    {
//        printf(" %d -> %d\n",i,en_wmn[i]);
//        
//    }
//    printf("\n printing avg : ");
//    float men_avg = 0;
//    float wmen_avg = 0;
//    for(i = 1; i < n + 1; i++)
//    {
//
//        men_avg += m_pre[i][0];
//        // w_pre[i][0] = 0;
//        wmen_avg += w_pre[i][0];
//    }
//    printf("\n men_avg : %f",men_avg/n);
//    printf("\n women_avg : %f",wmen_avg/n);

}
