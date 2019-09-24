#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define N 1000000
int         vv[N], pp[N], si[N], lenv, lens;
vector<int> ss(N);

inline void show(int i)
{
    if (pp[i] > -1) show(pp[i]);
    printf("%d\n", vv[i]);
}

int main(void)
{
    lenv = 0;
    while (scanf("%d", &vv[lenv++]) != EOF)
        ;

    lens = 0;
    for (int i = 0; i < lenv; ++i) {
        int idx = int(lower_bound(ss.begin(), ss.begin() + lens, vv[i]) - ss.begin());
        ss[idx] = vv[i];
        si[idx] = i;
        pp[i]   = idx > 0 ? si[idx - 1] : -1;
        lens    = max(lens, idx + 1);
    }

    printf("%d\n-\n", lens);
    show(si[lens - 1]);

    return 0;
}

