#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node {
    int id, val;
} nodes[100000];
int len, ids[100000];

bool compareNode(const Node &x, const Node &y) { return x.id < y.id; };

int main(void)
{
    char c;
    bool valid;
    int  v, id;

    len = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == '(') {
            scanf("%c", &c);
            if (c == ')') {
                sort(nodes, nodes + len, compareNode);
                for (int i = 0; i < len; ++i)
                    ids[i] = nodes[i].id;

                valid = ids[0] == 1;
                for (int i = 1; i < len; ++i)
                    if (!binary_search(ids, ids + len, (ids[i] / 2)) || ids[i - 1] == ids[i]) valid = false;

                if (valid) {
                    printf("%d", nodes[0].val);
                    for (int i = 1; i < len; ++i)
                        printf(" %d", nodes[i].val);
                    printf("\n");
                }
                else
                    printf("not complete\n");

                len = 0;
                continue;
            }

            v = 0;
            while (isdigit(c)) {
                v = v * 10 + int(c - '0');
                scanf("%c", &c);
            }
            nodes[len].val = v;

            id = 1;
            while (c != ')') {
                if (c == 'L')
                    id = id * 2;
                else if (c == 'R')
                    id = id * 2 + 1;
                scanf("%c", &c);
            }
            nodes[len++].id = id;
        }
    }

    return 0;
}
