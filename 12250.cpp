#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string in;
    int    index = 0;

    getline(cin, in);

    while (in.compare("#") != 0) {
        index++;
        cout << "Case " << index << ": ";
        if (in.compare("HELLO") == 0)
            cout << "ENGLISH" << endl;
        else if (in.compare("HOLA") == 0)
            cout << "SPANISH" << endl;
        else if (in.compare("HALLO") == 0)
            cout << "GERMAN" << endl;
        else if (in.compare("BONJOUR") == 0)
            cout << "FRENCH" << endl;
        else if (in.compare("CIAO") == 0)
            cout << "ITALIAN" << endl;
        else if (in.compare("ZDRAVSTVUJTE") == 0)
            cout << "RUSSIAN" << endl;
        else
            cout << "UNKNOWN" << endl;
        getline(cin, in);
    }

    return 0;
}
