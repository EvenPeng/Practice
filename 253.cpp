#include <iostream>
#include <string>

int rotations[4][6] = {
    {0, 1, 2, 3, 4, 5},
    {0, 2, 4, 1, 3, 5},
    {0, 3, 1, 4, 2, 5},
    {0, 4, 3, 2, 1, 5},
};

int orientations[5][6] = {
    {1, 5, 2, 3, 0, 4}, {2, 5, 4, 1, 0, 3}, {3, 5, 1, 4, 0, 2},
    {4, 5, 3, 2, 0, 1}, {5, 3, 4, 1, 2, 0},
};

bool compare_sides(const std::string &sides, int rotation_id)
{
    for (int i = 0; i < 6; ++i)
        if (sides[i] != sides[6 + rotations[rotation_id][i]]) return false;
    return true;
}

bool try_rotation(const std::string &sides)
{
    for (int i = 0; i < 4; ++i)
        if (compare_sides(sides, i)) return true;
    return false;
}

bool try_orientation(const std::string &sides)
{
    std::string alias(sides);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j)
            alias[6 + j] = sides[6 + orientations[i][j]];
        if (try_rotation(alias)) return true;
    }
    return false;
}

int main(void)
{
    std::string sides;
    bool        match;
    while (std::cin >> sides) {
        match = try_rotation(sides) || try_orientation(sides);
        std::cout << (match ? "TRUE" : "FALSE") << std::endl;
    }

    return 0;
}
