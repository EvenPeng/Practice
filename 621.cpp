#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int    count, len;
    string st;

    cin >> count;

    for (int i = 0; i < count; ++i) {
        cin >> st;
        len = st.size();
        if (len < 3) {
            cout << "+" << endl;
            continue;
        }

        if (st.at(len - 2) == '3' && st.at(len - 1) == '5')
            cout << "-" << endl;
        else if (st.at(0) == '1' && st.at(1) == '9' && st.at(2) == '0')
            cout << "?" << endl;
        else if (st.at(0) == '9')
            cout << "*" << endl;
        else
            cout << "+" << endl;
    }

    return 0;
}
