#include <cstdio>

using namespace std;

bool global;
int  target;

void travel(int x)
{
    char c;
    int  curr, s, child;

    child = 0;
    do
        scanf("%c", &c);
    while (c != '(' && c != ')');
    if (c == '(') {
        s = scanf("%d", &curr);
        if (s < 1) do
                scanf("%c", &c);
            while (c != ')');
        else {
            travel(x + curr);
            child++;
        }
    }
    else
        return;

    do
        scanf("%c", &c);
    while (c != '(');
    s = scanf("%d", &curr);
    if (s < 1) do
            scanf("%c", &c);
        while (c != ')');
    else {
        travel(x + curr);
        child++;
    }

    if (child < 1) global |= x == target;

    do
        scanf("%c", &c);
    while (c != ')');
}

int main(void)
{
    char c;
    int  curr, s;

    while (scanf("%d", &target) != EOF) {
        global = false;
        do
            scanf("%c", &c);
        while (c != '(');
        s = scanf("%d", &curr);
        if (s == 1)
            travel(curr);
        else
            do
                scanf("%c", &c);
            while (c != ')');
        if (global)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
