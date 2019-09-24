#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int groups[200000], size[200000];

int root(int x)
{
    while (x != groups[x])
        x = groups[x];
    return x;
}

int main(void)
{
    char             cA[21], cB[21];
    string           nameA, nameB;
    map<string, int> names;

    int T, n, gA, gB;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        names.clear();
        for (int c = 0; c < n; ++c) {
            scanf("%s %s", cA, cB);
            nameA    = string(cA);
            auto itA = names.find(nameA);

            if (itA == names.end()) {
                gA           = int(names.size());
                groups[gA]   = gA;
                size[gA]     = 1;
                names[nameA] = gA;
            }
            else {
                gA = root(itA->second);
            }

            nameB    = string(cB);
            auto itB = names.find(nameB);
            if (itB == names.end()) {
                gB           = int(names.size());
                groups[gB]   = gB;
                size[gB]     = 1;
                names[nameB] = gB;
            }
            else {
                gB = root(itB->second);
            }

            if (gA != gB) {
                if (gA > gB) swap(gA, gB);
                groups[gB] = gA;
                size[gA] += size[gB];
            }

            printf("%d\n", size[gA]);
        }
    }

    return 0;
}
