#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long max1pos = 0, max2pos = 0;
    long long min1neg = 0, min2neg = 0;
    long long max = -1;
    long long* a = new long long[N];
    for (int i = 0; i < N; i++) {


        cin >> a[i];

    }

    if (N > 3) {
        for (int i = 0; i < N; i++) {
            if (a[i] > 0)
            {
                if (a[i] >= max1pos)
                {
                    max2pos = max1pos;
                    max1pos = a[i];
                }
                else if (a[i] >= max2pos)
                {
                    max2pos = a[i];
                }
            }
            if (a[i] < 0)
            {
                if (a[i] <= min1neg)
                {
                    min2neg = min1neg;
                    min1neg = a[i];
                }
                else if (a[i] <= min2neg)
                {
                    min2neg = a[i];
                }
            }
        }
        max = (min2neg * min1neg >= max1pos * max2pos ? min2neg * min1neg : max1pos * max2pos); 
    
    }

    else if (N == 3)
    {
        if(a[0] > a[1])
        {
            long long tmp = a[0];
            a[0] = a[1];
            a[1] = tmp;
        }
        if (a[1] > a[2])
        {
            long long tmp = a[1];
            a[1] = a[2];
            a[2] = tmp;
        }
        if (a[0] > a[1])
        {
            long long tmp = a[0];
            a[0] = a[1];
            a[1] = tmp; 
        }
    
        long long ab = a[0] * a[1];
        long long ac = a[0] * a[2];
        long long bc = a[1] * a[2];
        if (ab > ac)
        {
            if (ab > bc)
            {
                max = ab;
            }
            else
            { 
                max = bc;
            }
            if (ac > bc)
            {
                max = ac;
            }
        }
        else
        {
            if (ac > bc)
            {
                max = ac;
            }
            else
            {
                max = bc;
            }
        }

    }

    if (N == 2) {
        max = a[0] * a[1];
    }
    cout <<max;
    
    return 0;
}