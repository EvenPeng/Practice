#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

double Cal(char c, int v)
{
    switch (c) {
    case 'C':
        return 12.01 * v;
    case 'H':
        return 1.008 * v;
    case 'O':
        return 16.00 * v;
    case 'N':
        return 14.01 * v;
    }
}

int main(void)
{
    int    T, v;
    double ans;
    char   formula[100];

    scanf("%d", &T);
    while (T--) {
        scanf("%s", formula);
        ans = 0;

        int i = 0, j;
        while (formula[i] != '\0') {
            j = i + 1;
            v = isdigit(formula[j]) ? 0 : 1;
            while (isdigit(formula[j])) {
                v = v * 10 + int(formula[j] - '0');
                j++;
            }
            ans += Cal(formula[i], v);
            i = j;
        }

        printf("%.3lf\n", ans);
    }

    return 0;
}
