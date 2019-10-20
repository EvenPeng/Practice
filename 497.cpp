#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define Height int
#define Best int
#define Previous int

struct Missle {
    Height   h;
    Previous p;
    Best     b;
};

std::vector<Missle> missles(100000);
int                 num_missles;

void print_sequence(int i)
{
    if (missles[i].p != i) print_sequence(missles[i].p);
    std::cout << missles[i].h << std::endl;
}

int main(void)
{
    int         num_cases, max_index;
    std::string buffer;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer, nullptr);
    getline(std::cin, buffer);
    while (num_cases--) {
        int n = 0;
        while (1) {
            getline(std::cin, buffer);
            if (buffer.size() < 1) break;
            missles[n].h = std::stoi(buffer);
            if (!n || missles[n - 1].h != missles[n].h) {
                missles[n].p = n;
                missles[n].b = 1;
                ++n;
            }
        }
        num_missles = n;

        max_index = 0;
        for (int i = 1; i < num_missles; ++i) {
            for (int j = 0; j < i; ++j) {
                if (missles[i].h > missles[j].h &&
                    missles[i].b < missles[j].b + 1) {
                    missles[i].b = missles[j].b + 1;
                    missles[i].p = j;
                }
            }
            if (missles[i].b > missles[max_index].b) max_index = i;
        }

        std::cout << "Max hits: " << missles[max_index].b << std::endl;
        print_sequence(max_index);
        if (num_cases) std::cout << std::endl;
    }

    return 0;
}
