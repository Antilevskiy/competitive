#include <iostream>
using namespace std;
void merge(int*, int, int, int, long long &c);
void mSort(int* a, int, int, long long &c);
//используем сортировку слиянием. алгоритм становится тривиальным 

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long c = 0;
    mSort(a, 0, n, c);

    cout << c;
    return 0;
}

void merge(int* a, int left, int mid, int right, long long &c)
{
    int i1 = 0;
    int i2 = 0;
    long* res = new long[right - left]; 

    while ((left + i1 < mid) && (mid + i2 < right))
    {
        if (a[left + i1] < a[mid + i2])
        {
            res[i1 + i2] = a[left + i1];
            i1++;
        }
        else
        {
			c = c + (mid - left - i1);
            res[i1 + i2] = a[mid + i2];
            i2++;
        }
    }
    while (left + i1 < mid)
    {			
        res[i1 + i2] = a[left + i1];
        i1++;
    }
    while (mid + i2 < right)
    {
        res[i1 + i2] = a[mid + i2];
        i2++;
    }
    for (int i = 0; i < i1 + i2; i++)
    {
        a[left + i] = res[i]; 
    }
    delete (res);
}

void mSort(int* a, int left, int right, long long &c)
{
    if (left + 1 >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mSort(a, left, mid, c);
    mSort(a, mid, right, c);
    merge(a, left, mid, right, c);
}
