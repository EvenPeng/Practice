#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ctoi(char c) { return c == ' ' ? 0 : int(c - '0'); }

void resolve(string s)
{
    // parse numbers
    int r = 0, p = 0;

    for (int i = 0; i < 6; ++i) {
        if (s[i] == '.') {
            p = 5 - i;
        }
        else {
            r = r * 10 + ctoi(s[i]);
        }
    }

    int n = ctoi(s[7]) * 10 + ctoi(s[8]);
    p *= n;

    // calculate
    vector<long> v(1);
    v[0] = r;

    for (int i = 1; i < n; ++i) {
        int l = v.size();
        v[0] *= r;

        for (int j = 1; j < l; ++j) {
            v[j] *= r;
            v[j] += v[j - 1] / 100000;
            v[j - 1] %= 100000;
        }

        if (v[l - 1] >= 100000) {
            v.push_back(v[l - 1] / 100000);
            v[l - 1] %= 100000;
        }
    }

    // generate output
    int l = v.size() - 1;

    char out[150];
    int  i = 0;
    sprintf(out, "%5ld", v[l]);
    while (l-- > 0) {
        i += 5;
        sprintf(out + i, "%05ld", v[l]);
    }
    i += 4;

    // remove zero at tail
    while (out[i] == '0') {
        i--;
        p--;
    }
    i++;

    // print result
    int head = 0;
    while (out[head] == ' ')
        ++head;

    if (i - p < 1) {
        printf(".0");
        while (p >= i) {
            printf("0");
            p--;
        }
        while (head < i)
            printf("%c", out[head++]);
    }
    else {
        while (head < i - p)
            printf("%c", out[head++]);
        if (head < i) printf(".");
        while (head < i)
            printf("%c", out[head++]);
    }
    printf("\n");
}

int main(void)
{
    string s;
    while (getline(cin, s)) {
        resolve(s);
    }

    return 0;
}
