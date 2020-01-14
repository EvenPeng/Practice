#include <iostream>

struct Person {
    int     id;
    Person *prev, *next;
};

int main(void)
{
    std::ios::sync_with_stdio(false);

    int n, k;

    Person *head, *curr, *next;

    while (1) {
        std::cin >> n >> k;
        if (!n) break;

        head = new Person{0, nullptr, nullptr};
        curr = head;
        for (int i = 1; i < n; ++i) {
            curr->next = new Person{i, curr, nullptr};
            curr       = curr->next;
        }
        curr->next = head;
        head->prev = curr;

        curr = head;
        for (int i = 1; i < n; ++i) {
            for (int j = 2; j < k; ++j)
                curr = curr->next;
            curr->next = curr->next->next;
            next       = curr->next;
            next->prev = curr;
            for (int j = 1; j < k; ++j)
                next = next->next;
            if (curr != next && curr->next != next) {
                next->prev->next = next->next;
                next->next->prev = next->prev;
                next->next       = curr->next;
                next->next->prev = next;
                next->prev       = curr;
                curr->next       = next;
            }
            curr = next->next;
        }

        if (curr->id == 0)
            std::cout << 1 << std::endl;
        else
            std::cout << (n - curr->id) + 1 << std::endl;
    }

    return 0;
}
