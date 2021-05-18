#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long N = 0;
    unsigned long long counter = 0;
    cin >> N;
    long long a[N];   
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    bool signOfDerivative = 1;
    long long lastMax = a[0];
    long long globMax = a[0];
    for(int i = 0; i < N;)
    {
        if(a[i + 1] > a[i]) 
        {   
            if(!signOfDerivative) //нашли минимум 
            {
                signOfDerivative = !signOfDerivative;
                counter = counter + (lastMax - a[i]);
            } 
            i++;
        }
        else 
        {   
            if(a[i + 1] < a[i]) 
            {
               if(signOfDerivative) //нашли максимум
               {
                  signOfDerivative = !signOfDerivative;
                  if(a[i] > globMax)
                  {
                    counter = counter + (a[i] - globMax);
                    globMax = a[i];
                  }
                  lastMax = a[i];
               }
               i++;
            }
            else
            {
                i++;
            }
        }
    }
    if(signOfDerivative == 1 && (a[N - 1] > globMax))
    {
        //cout << "case1" << "\n";
        counter = counter + (a[N - 1] - globMax);
    }
    if(signOfDerivative == 0 && (a[N - 1] < lastMax))
    {
        //cout << "case2" << "\n";
        counter = counter + (lastMax - a[N - 1]);
    }
    //cout <<"globMax: "<< globMax << "\n"; 
    //cout <<"lastMax: "<< lastMax << "\n";
    cout << counter;
    return 0;
}