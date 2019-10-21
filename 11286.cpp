#include <algorithm>
#include <cstring>
#include <iostream>

#define Course int

struct Frosh {
    Course c[5];
};

bool compare_frosh(const Frosh &x, const Frosh &y)
{
    return x.c[0] == y.c[0]
               ? (x.c[1] == y.c[1]
                      ? (x.c[2] == y.c[2] ? (x.c[3] == y.c[3] ? x.c[4] < y.c[4]
                                                              : x.c[3] < y.c[3])
                                          : x.c[2] < y.c[2])
                      : x.c[1] < y.c[1])
               : x.c[0] < y.c[0];
}

bool same_frosh(const Frosh &x, const Frosh &y)
{
    return x.c[0] == y.c[0] && x.c[1] == y.c[1] && x.c[2] == y.c[2] &&
           x.c[3] == y.c[3] && x.c[4] == y.c[4];
}

int main(void)
{
    int   num_frosh, count, max_popularity, num_group;
    Frosh forshes[10000];

    while (1) {
        std::cin >> num_frosh;
        if (!num_frosh) break;
        for (int i = 0; i < num_frosh; ++i) {
            std::cin >> forshes[i].c[0] >> forshes[i].c[1] >> forshes[i].c[2] >>
                forshes[i].c[3] >> forshes[i].c[4];
            std::sort(forshes[i].c, forshes[i].c + 5);
        }
        std::sort(forshes, forshes + num_frosh, compare_frosh);

        count          = 0;
        max_popularity = 0;
        for (int i = 0; i < num_frosh;) {
            int j = i + 1;
            while (j < num_frosh) {
                if (same_frosh(forshes[i], forshes[j]))
                    ++j;
                else
                    break;
            }
            if (j - i > max_popularity) {
                max_popularity = j - i;
                count          = max_popularity;
            }
            else if (j - i == max_popularity) {
                count += max_popularity;
            }
            i = j;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
