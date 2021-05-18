#include <iostream>
using namespace std;
/*Все делители числа 1 087 388 483:

1, 1 021, 1 031, 1 033, 1 052 651, 1 054 693, 1 065 023, 1 087 388 483

Всего делителей : 8 */
int main()
{
    int N;
    int x = 0;
    cin >> N;
    bool v1021 = false, v1031 = false, v1033 = false, v1021_1031 = false, v1021_1033 = false, v1031_1033 = false, v1 = false, vNumber = false;
    for (long i = 0; i < N; i++)
    {   
        cin >> x;
        if (x < 1087388484)
        {
            if (x == 1087388483)
            {
                vNumber = true;
            }
            if (x == 1)
            {
                v1 = true;
            }
            if (x == 1021)
            {
                v1021 = true;
            }
            if (x == 1031)
            {
                v1031 = true;
            }
            if (x == 1033)
            {
                v1033 = true;
            }
            if (x == 1052651)
            {
                v1021_1031 = true;
            }
            if (x == 1054693)
            {
                v1021_1033 = true;
            }
            if (x == 1065023)
            {
                v1031_1033 = true;
            }
        }
        else
            continue;
    }
    if ((vNumber) || (v1021_1031 && v1033) || (v1021_1033 && v1031) || (v1031_1033 && v1021) || (v1021 && v1031 && v1033))
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}
