#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int    T, m, n, score[21], lam;
    char   tmp[21];
    string keys[21], lines[21], org[21];

    T = 0;
    while (scanf("%d %d\n", &m, &n) != EOF) {
        for (int i = 0; i < m; ++i) {
            scanf("%s\n", tmp);
            keys[i] = string(tmp);
        }

        for (int i = 0; i < n; ++i) {
            getline(cin, org[i]);
            lines[i] = org[i];
            for (int j = 0; j < lines[i].size(); ++j)
                lines[i][j] = tolower(lines[i][j]);
        }

        lam = 0;
        for (int i = 0; i < n; ++i) {
            score[i] = 0;
            for (int j = 0; j < m; ++j) {
                size_t idx = lines[i].find(keys[j]);
                while (idx != string::npos) {
                    if ((idx == 0 || !isalpha(lines[i][idx - 1])) &&
                        (idx + keys[j].size() == lines[i].size() || !isalpha(lines[i][idx + keys[j].size()])))
                        score[i]++;
                    idx = lines[i].find(keys[j], idx + keys[j].size() + 1);
                }
            }
            lam = max(lam, score[i]);
        }

        printf("Excuse Set #%d\n", ++T);
        for (int i = 0; i < n; ++i)
            if (score[i] == lam) printf("%s\n", org[i].c_str());
        printf("\n");
    }

    return 0;
}
