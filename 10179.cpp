#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> prime({2, 3, 5, 7});
int         seen = 9;

void explore(int x)
{
    int sq = sqrt(seen);
    int pw = sq * sq;
    while (seen <= x) {
        if (pw == seen) {
            sq++;
            pw = sq * sq;
        }
        else {
            if (pw < seen) {
                sq++;
                pw = sq * sq;
            }
            bool pass = true;
            for (int i = 1; pass && prime[i] < sq; i++) {
                pass = seen % prime[i] != 0;
            }
            if (pass) prime.push_back(seen);
        }
        seen += 2;
    }
}

int main(void)
{
    int n, cnt, sq, frac;

    explore(31623);

    while (1) {
        scanf("%d", &n);
        if (!n) break;

        sq   = sqrt(n);
        cnt  = n;
        frac = n;
        for (int i = 0; i < int(prime.size()) && prime[i] <= sq; ++i)
            if (n % prime[i] == 0) {
                cnt = (cnt / prime[i]) * (prime[i] - 1);
                while (frac > 1 && frac % prime[i] == 0) 
                    frac /= prime[i];
            }
        if (frac > 1) cnt = cnt / frac * (frac - 1);

        if (n == 1)
            printf("1\n");
        else if (cnt == n)
            printf("%d\n", cnt - 1);
        else
            printf("%d\n", cnt);
    }

    return 0;
}
