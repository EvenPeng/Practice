#include <iostream>
#include <string>

struct Digit {
    bool   is_end;
    Digit *next[10];
};

int main(void)
{
    bool        valid;
    int         num_case, num_phone, x;
    std::string buffer;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> num_phone;

        valid        = true;
        Digit *head  = new (Digit);
        head->is_end = false;
        for (int i = 0; i < 10; ++i)
            head->next[i] = NULL;

        Digit *curr;
        while (num_phone--) {
            std::cin >> buffer;
            if (valid) {
                curr = head;
                for (int i = 0; i < buffer.size(); ++i) {
                    x = int(buffer[i] - '0');
                    if (curr->next[x] == NULL) {
                        curr->next[x] = new (Digit);
                        curr          = curr->next[x];
                        curr->is_end  = i + 1 == buffer.size();
                        for (int i = 0; i < 10; ++i)
                            curr->next[i] = NULL;
                    }
                    else {
                        curr = curr->next[x];
                        if (curr->is_end || i + 1 == buffer.size())
                            valid = false;
                    }
                }
            }
        }

        if (valid)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}
