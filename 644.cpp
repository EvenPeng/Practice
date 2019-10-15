#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int    T = 0, st;
    bool   dup;
    size_t size = 100;
    char * buf  = (char *)malloc(sizeof(char) * size);

    map<string, int> check;

    st = 0;
    while (1) {
        dup = false;
        check.clear();
        while (1) {
            st = getline(&buf, &size, stdin);
            if (buf[0] == '9') break;

            if (!dup) {
                buf[strlen(buf) - 1] = '\0';
                if (check[string(buf)]) {
                    dup = true;
                }
                else {
                    check[string(buf)] = 1;
                    for (int i = strlen(buf) - 1; i > 0; --i) {
                        buf[i] = '\0';
                        if (check[string(buf)] == 1) {
                            dup = true;
                            break;
                        }
                        check[string(buf)] = 2;
                    }
                }
            }
        }
        if (st == -1) break;

        if (dup)
            printf("Set %d is not immediately decodable\n", ++T);
        else
            printf("Set %d is immediately decodable\n", ++T);
    }

    return 0;
}
