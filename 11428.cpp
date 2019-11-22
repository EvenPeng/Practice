#include <array>
#include <iostream>

int main(void)
{
    int                   N, diff;
    std::array<int, 10001> tripple;
    std::array<int, 10001> x, y;
    x.fill(0);
    y.fill(0);

    tripple[0] = 0;
    for (int i = 1; ; ++i) {
        tripple[i] = i * i * i;
        if (tripple[i] - tripple[i-1] > 10000) break;
        for (int j = i-1; j > -1; --j){
            diff = tripple[i]-tripple[j];
            if (diff > 10000) break;
            if (!y[diff]) {
                x[diff] = i;
                y[diff] = j;
            }
        }
    }

    while(1) {
        std::cin >> N;
        if (!N) break;

        if (!x[N])
            std::cout << "No solution" << std::endl;
        else
            std::cout << x[N] << " " << y[N] << std::endl;
    }

    return 0;
}
