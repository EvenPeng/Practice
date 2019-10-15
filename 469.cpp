#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int x, y;
};

int    T, n, m, x, y, s;
char   land[100][100];
bool   seen[100][100];
int *  cnt[100][100];
char * buf;
size_t buf_size = 100;

node        curr;
queue<node> q;

void Add(int xx, int yy)
{
    if (land[xx][yy] == 'W' && !seen[xx][yy]) {
        ++(*cnt[x][y]);
        cnt[xx][yy]  = cnt[x][y];
        seen[xx][yy] = true;
        q.push({xx, yy});
    }
}

int main(void)
{
    buf = (char *)malloc(sizeof(char) * buf_size);

    scanf("%d\n", &T);
    getline(&buf, &buf_size, stdin);
    while (T--) {
        while (isspace(buf[0])) {
            getline(&buf, &buf_size, stdin);
        }

        n = 0;
        while (isalpha(buf[0])) {
            memset(seen[n], false, sizeof(seen[0]));
            memcpy(land + n++, buf, sizeof(char) * buf_size);
            getline(&buf, &buf_size, stdin);
        }
        m = strlen(land[0]) - 1;

        s = 0;
        while (isdigit(buf[0]) && s != -1) {
            int si = 0;
            while (buf[si] != ' ')
                si++;
            buf[si] = '\n';

            x = atoi(buf) - 1;
            y = atoi(buf + si + 1) - 1;
            if (!seen[x][y]) {
                cnt[x][y] = (int *)malloc(sizeof(int));
                ++(*cnt[x][y]);
                seen[x][y] = true;
                q.push({x, y});
                while (q.size()) {
                    curr = q.front();
                    q.pop();
                    if (curr.x + 1 < n) {
                        if (curr.y + 1 < m) Add(curr.x + 1, curr.y + 1);
                        if (curr.y - 1 > -1) Add(curr.x + 1, curr.y - 1);
                        Add(curr.x + 1, curr.y);
                    }
                    if (curr.x - 1 > -1) {
                        if (curr.y + 1 < m) Add(curr.x - 1, curr.y + 1);
                        if (curr.y - 1 > -1) Add(curr.x - 1, curr.y - 1);
                        Add(curr.x - 1, curr.y);
                    }
                    if (curr.y + 1 < m) Add(curr.x, curr.y + 1);
                    if (curr.y - 1 > -1) Add(curr.x, curr.y - 1);
                }
            }
            printf("%d\n", *cnt[x][y]);
            s = getline(&buf, &buf_size, stdin);
        }

        if (T) printf("\n");
    }

    return 0;
}
