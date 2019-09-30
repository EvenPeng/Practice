#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    char op[20];
    int  T, t, n, x, id;

    bool               inqueue[1000];
    map<int, int>      tid;
    queue<int>         gqueue;
    vector<queue<int>> tqueue(1000, queue<int>());

    T = 0;
    while (1) {
        scanf("%d", &t);
        if (!t) break;

        memset(inqueue, false, sizeof(inqueue));
        queue<int>().swap(gqueue);
        for (int i = 0; i < t; ++i) {
            queue<int>().swap(tqueue[i]);
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                tid[x] = i;
            }
        }

        printf("Scenario #%d\n", ++T);
        while (1) {
            scanf("%s", op);
            if (op[0] == 'E') {
                scanf("%d", &x);
                id = tid[x];
                tqueue[id].push(x);
                if (!inqueue[id]) {
                    gqueue.push(id);
                    inqueue[id] = true;
                }
            }
            else if (op[0] == 'D') {
                id = gqueue.front();
                x  = tqueue[id].front();
                tqueue[id].pop();
                if (tqueue[id].empty()) {
                    gqueue.pop();
                    inqueue[id] = false;
                }
                printf("%d\n", x);
            }
            else if (op[0] == 'S')
                break;
        }
        printf("\n");
    }

    return 0;
}
