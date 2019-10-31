#include <algorithm>
#include <iostream>

int main(void)
{
    int  length;
    long count;
    int  array[500000], tmp_array[500000];

    while (1) {
        std::cin >> length;
        if (!length) break;

        for (int i = 0; i < length; ++i) {
            std::cin >> array[i];
        }

        count = 0;
        for (int seg = 1; seg < length; seg <<= 1) {
            for (int i = 0; i < length; i += (seg << 1)) {
                int beg1 = i;
                int end1 = beg1 + seg > length ? length : beg1 + seg;
                int beg2 = end1 > length ? length : end1;
                int end2 = beg2 + seg > length ? length : beg2 + seg;
                int idx  = beg1;
                while (beg1 < end1 && beg2 < end2) {
                    if (array[beg1] <= array[beg2])
                        tmp_array[idx++] = array[beg1++];
                    else {
                        tmp_array[idx++] = array[beg2++];
                        count += end1 - beg1;
                    }
                }
                while (beg1 < end1) {
                    tmp_array[idx++] = array[beg1++];
                }
                while (beg2 < end2) {
                    tmp_array[idx++] = array[beg2++];
                }
            }
            std::swap(array, tmp_array);
        }
        std::cout << count << std::endl;
    }

    return 0;
}
