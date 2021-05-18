#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if(N == 1)
    {
        cout<< N;
        return 0;
    }
    
    int M = N;
    short counter  = 1;
    while (N / 10 != 0)
    {   
        N = N / 10;
        counter++;
    }
    
    int* a = new int[counter];
    for (short i = counter-1; i >= 0 ; i--)
    {
        a[i] = M % 10;
        M = M / 10;
    }
    
   /* for (int i = 0; i < counter ; i++)
    {
        cout << a[i] <<" ";   123  122384 -->  122483 --> 122438
    }*/
    short i = 0;
    M = 0;
    bool b = 0;
    for (i = counter - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        { 
            int x;
            for(short j = i+1; j <= counter - 1; j++)
            {   
                short min = 10;
                if (a[j] >  a[i])
                {
                    if(a[j] < min)
                    {
                       min = a[j];
                       x = j;
                    }
                }
            }
            short tmp = a[i];
            a[i] = a[x];
            a[x] =  tmp;
            b = 1;
            break;
        }
    }
    
    if (b == 1)
    {
        for (int k = 0; k <= i; k++)
        {
            M = 10 * M + a[k];
        }
        //cout << "M промежуточное:" << M << "\n";
        for (int k = counter - 1; k > i; k--)
        {
            M = 10*M + a[k];
        } 
       /* for (int i = 0; i < counter; i++)
        {
            cout << a[i];
        }*/
        cout << M;
    }
    else cout << -1;
    return 0;
}