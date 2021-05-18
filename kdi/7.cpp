#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    short N, M, X1, Y1, X2, Y2;
    cin >> N;
    cin >> M;
    cin >> X1;
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    if(abs(Y2 - Y1) != abs(X2 - X1))
    cout << "YES";
    else 
    cout << "NO";
    return 0;
}