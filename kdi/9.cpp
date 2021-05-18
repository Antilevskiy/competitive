#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned long long q = 0;
    string s;
    cin >> s;
    cin >> q;
    bool change = false;
    bool izmProm[s.size() + 1] = { false };
    int l;
    int r;
    for (int i = 0; i < q; i++)
    {
        cin >> l;
        cin >> r;
        
        if (l != r)
        {
            if(l > r)
                swap(l,r);
            l--;    
            izmProm[l] = !izmProm[l];
            izmProm[r] = !izmProm[r];
        }
        else
        {
            l--;
          if (s[l]  < 95)
                {
                    s[l] += 32;
                }
                else
                {
                    s[l] -= 32;
                }
        }
    }
    for (int i = 0; i < s.size(); i++)
        {  
            if (izmProm[i])
                change = !change; 
            if (change)
            {
                if (s[i] < 95)
                {
                    s[i] += 32;
                }
                else
                {
                    s[i] -= 32;
                }
            }
        }
    cout << s;
    return 0;
}