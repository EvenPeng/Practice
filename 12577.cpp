#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char tmp[5];
    int  index = 0;

    while (1) {
        cin >> tmp;
        if (tmp[0] == '*') break;
        cout << "Case " << ++index << ": Hajj-e-";
        if (tmp[0] == 'H')
            cout << "Akbar" << endl;
        else
            cout << "Asghar" << endl;
    }

    return 0;
}
