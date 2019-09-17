#include <cmath>
#include <iostream>

using namespace std;

int main(void)
{
    double p, n;

    while (cin >> n >> p)
        cout << (int)(pow(p, 1.0 / n) + 0.5) << endl;

    return 0;
}
