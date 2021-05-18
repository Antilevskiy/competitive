#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    string rs = s;
    reverse(rs.begin(), rs.end());
    if (s != rs)
    {
        cout << l;
    }
    else
    {
        string tmp = rs;
        for (int i = 0; i < l; i++)
        {
            tmp.erase(tmp.length() - 1);
            if (s.find(tmp, i + 1) == -1)
            {
                cout << tmp.length();
                return 0;
            }
        }
        cout << -1;
    }
    return 0;
}