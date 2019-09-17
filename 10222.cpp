#include <cstdio>

using namespace std;

int main(void)
{
    char c;

    while (scanf("%c", &c) != EOF) {
        if ('A' <= c && c <= 'Z') c -= 'A' - 'a';
        switch (c) {
        case 'e':
            c = 'q';
            break;
        case 'd':
            c = 'a';
            break;
        case 'c':
            c = 'z';
            break;
        case 'r':
            c = 'w';
            break;
        case 'f':
            c = 's';
            break;
        case 'v':
            c = 'x';
            break;
        case 't':
            c = 'e';
            break;
        case 'g':
            c = 'd';
            break;
        case 'b':
            c = 'c';
            break;
        case 'y':
            c = 'r';
            break;
        case 'h':
            c = 'f';
            break;
        case 'n':
            c = 'v';
            break;
        case 'u':
            c = 't';
            break;
        case 'j':
            c = 'g';
            break;
        case 'm':
            c = 'b';
            break;
        case 'i':
            c = 'y';
            break;
        case 'k':
            c = 'h';
            break;
        case ',':
            c = 'n';
            break;
        case 'o':
            c = 'u';
            break;
        case 'l':
            c = 'j';
            break;
        case '.':
            c = 'm';
            break;
        case 'p':
            c = 'i';
            break;
        case ';':
            c = 'k';
            break;
        case '[':
            c = 'o';
            break;
        case '\'':
            c = 'l';
            break;
        case ']':
            c = 'p';
            break;
        default:
            break;
        }
        printf("%c", c);
    }

    return 0;
}
