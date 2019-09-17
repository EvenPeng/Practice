#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int n, q, p;

    scanf("%d", &n);
    vector<int> lady(1);
    scanf("%d", &lady[0]);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p);
        if (p != lady.back()) lady.push_back(p);
    }
    n = lady.size();

    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%d", &p);
        auto idx = lower_bound(lady.begin(), lady.end(), p);

        if (idx == lady.end()) {
            printf("%d X\n", *idx);
        }
        else {
            if (idx != lady.begin())
                printf("%d ", *(idx - 1));
            else
                printf("X ");

            if (*idx != p)
                printf("%d\n", *idx);
            else if (idx + 1 < lady.end())
                printf("%d\n", *(idx + 1));
            else
                printf("X\n");
        }
    }

    return 0;
}
