#include <iomanip>
#include <iostream>

struct Point {
    double x, y;
};

bool same_point(const Point &p, const Point &q)
{
    return p.x == q.x && p.y == q.y;
}

int main(void)
{
    Point p, q, r, x;

    std::cout << std::fixed << std::setprecision(3);
    while (std::cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> x.x >> x.y) {
        if (same_point(p, r))
            std::cout << q.x + (x.x - p.x) << " " << q.y + (x.y - p.y)
                      << std::endl;
        else if (same_point(p, x))
            std::cout << q.x + (r.x - p.x) << " " << q.y + (r.y - p.y)
                      << std::endl;
        else if (same_point(q, r))
            std::cout << p.x + (x.x - q.x) << " " << p.y + (x.y - q.y)
                      << std::endl;
        else
            std::cout << p.x + (r.x - q.x) << " " << p.y + (r.y - q.y)
                      << std::endl;
    }

    return 0;
}
