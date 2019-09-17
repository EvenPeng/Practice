#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int    times, count, moves[101], postition, index;
    string op;

    cin >> times;

    for (int i = 0; i < times; ++i) {
        cin >> count;
        postition = 0;
        for (int j = 0; j < count; ++j) {
            cin >> op;
            if (op.compare("LEFT") == 0)
                moves[j + 1] = -1;
            else if (op.compare("RIGHT") == 0)
                moves[j + 1] = 1;
            else {
                cin >> op >> index;
                moves[j + 1] = moves[index];
            }
            postition += moves[j + 1];
        }
        cout << postition << endl;
    }

    return 0;
}
