#include <iostream>
using namespace std;
int main()
{
    long double v1, v2, H;
    int k = 0;
    cin >> H >> v1 >> v2;
    if (v1 <= (v2 * 0.25))
    {
        cout << "-1";
        return 0;
    }
    if (H >= (v1 - (v2 * 0.25)) * 1000000000)
    {
        k = 1000000000;
        H -= (v1 - (v2 * 0.25)) * 1000000000;
    }
    while (H > v1)
    {
        k++;
        H -= (v1 - (v2 * 0.25));
    }
    cout << k;
    return 0;
}