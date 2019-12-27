#include <cctype>
#include <iostream>
#include <string>

long c2v(const char c)
{
    if (isdigit(c)) {
        return long(c - '0');
    }
    switch (c) {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return 16;
    }
}

std::string v2c(const long v)
{
    if (v < 10) {
        return std::to_string(v);
    }
    switch (v) {
    case 10:
        return "A";
    case 11:
        return "B";
    case 12:
        return "C";
    case 13:
        return "D";
    case 14:
        return "E";
    case 15:
        return "F";
    }
}

int main(void)
{
    bool        valid;
    long        old_base, new_base, value, d;
    std::string old_value, new_value;

    while (std::cin >> old_base >> new_base >> old_value) {
        valid = true;
        value = 0;
        for (int i = 0; valid && i < old_value.size(); ++i) {
            d     = c2v(old_value[i]);
            valid = d < old_base;
            value = value * old_base + d;
        }

        if (valid) {
            new_value = "";
            if (value) {
                while (value) {
                    d         = value % new_base;
                    new_value = v2c(d) + new_value;
                    value /= new_base;
                }
            }
            else {
                new_value = "0";
            }
            std::cout << old_value << " base " << old_base << " = " << new_value
                      << " base " << new_base << std::endl;
        }
        else {
            std::cout << old_value << " is an illegal base " << old_base
                      << " number" << std::endl;
        }
    }

    return 0;
}
