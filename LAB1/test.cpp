#include <iostream>
using namespace std;

int main()
{

    int a[10000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] * a[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n- 1 - i; j++)
        {

            if (a[j] > a[j + 1])
            {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

 for (int i = 0; i < n; i++)
    {
      cout<<a[i]<< " ";
    }

    return 0;
}