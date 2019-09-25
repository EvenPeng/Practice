#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> table;
bool                check[8];

void generate(vector<int> &vec, int col)
{
    for (int i = 0; i < 8; ++i)
        if (!check[i]) {
            bool pass = true;
            for (int j = 0, diff = col; pass && j < col; j++, diff--)
                pass &= (vec[j] != i && vec[j] != i + diff && vec[j] != i - diff);
            if (pass) {
                vec[col] = i;
                if (col < 7) {
                    check[i] = true;
                    generate(vec, col + 1);
                    check[i] = false;
                }
                else {
                    table.push_back(vec);
                }
            }
        }
}

int main(void)
{
    int T, x, y, n;

    memset(check, false, sizeof(check));
    vector<int> vec(8);
    generate(vec, 0);

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        n = 0;
        for (int i = 0; i < table.size(); ++i)
            if (table[i][y - 1] == x - 1) {
                printf("%2d     ", ++n);
                for (int j = 0; j < 8; ++j)
                    printf(" %d", table[i][j] + 1);
                printf("\n");
            }
        if (T) printf("\n");
    }

    return 0;
}
