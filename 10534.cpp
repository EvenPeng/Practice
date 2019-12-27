#include <array>
#include <cmath>
#include <iostream>

int main(void)
{
    int                    size, sub_size, ans;
    std::array<int, 10000> val, asc, dec, seq;

    while (std::cin >> size) {
        for (int i = 0; i < size; ++i) {
            std::cin >> val[i];
        }

        sub_size = 1;
        seq[0]   = val[0];
        asc[0]   = 1;
        for (int i = 1; i < size; ++i) {
            int k = sub_size;
            while (k > 0 && seq[k - 1] >= val[i]) {
                --k;
            }
            if (k == sub_size) {
                seq[sub_size++] = val[i];
            }
            else {
                seq[k] = std::min(seq[k], val[i]);
            }
            asc[i] = k + 1;
        }

        sub_size      = 1;
        seq[0]        = val[size - 1];
        dec[size - 1] = 1;
        for (int i = size - 2; i > -1; --i) {
            int k = sub_size;
            while (k > 0 && seq[k - 1] >= val[i]) {
                --k;
            }
            if (k == sub_size) {
                seq[sub_size++] = val[i];
            }
            else {
                seq[k] = std::min(seq[k], val[i]);
            }
            dec[i] = k + 1;
        }

        ans = 0;
        for (int i = 0; i < size; ++i) {
            ans = std::max(ans, std::min(asc[i], dec[i]));
        }
        ans = ans * 2 - 1;

        std::cout << ans << std::endl;
    }

    return 0;
}
