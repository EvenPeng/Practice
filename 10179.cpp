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
    int n, cnt;

    while (1) {
        scanf("%d", &n);
        if (!n) break;

        int p = 0;
        if (seen < n) {
            explore(n);
            if (prime.back() != n) p = int(prime.size()) - 1;
        }
        else {
            p = int(lower_bound(prime.begin(), prime.end(), n) - prime.begin());
        }

        if (!p || prime[p] == n)
            printf("%d\n", n - 1);
        else {
            vector<int> comb;
            int         i = 0, sq = sqrt(n);
            for (; prime[i] <= sq; ++i)
                if (n % prime[i]) comb.push_back(prime[i]);
            for (; i < p; ++i)
                comb.push_back(prime[i]);
            printf("%d\n", comb.size());
            for (int i = 0; i < 3; ++i)
                printf("%d ", comb[i]);
            printf("\n");
        }
    }

    return 0;
}
