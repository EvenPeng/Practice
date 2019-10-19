#include <iomanip>
#include <iostream>

#define Slope double
#define Coefficient double

struct Point {
    double x, y;
};

struct Line {
    Point p, q;
    // y = s * x + c
    Slope       s;
    Coefficient c;
    bool        is_vertical;
};

Slope slope(Line *line)
{
    return (line->p.y - line->q.y) / (line->p.x - line->q.x);
}

void read_line(Line *line)
{
    std::cin >> line->p.x >> line->p.y >> line->q.x >> line->q.y;
    line->s           = slope(line);
    line->c           = line->p.y - line->s * line->p.x;
    line->is_vertical = line->p.x == line->q.x;
}

Point intersection(Line *line1, Line *line2)
{
    Point p;
    if (line1->is_vertical) {
        p.x = line1->p.x;
        p.y = p.x * line2->s + line2->c;
    }
    else {
        if (line2->p.x == line2->q.x)
            p.x = line2->p.x;
        else
            p.x = (line2->c - line1->c) / (line1->s - line2->s);
        p.y = p.x * line1->s + line1->c;
    }
    return p;
}

void judge(Line *line1, Line *line2)
{
    if (line1->s != line2->s) {
        if (line1->is_vertical && line2->is_vertical) {
            if (line1->p.x == line2->p.x)
                std::cout << "LINE" << std::endl;
            else
                std::cout << "NONE" << std::endl;
        }
        else {
            Point p = intersection(line1, line2);
            std::cout << "POINT " << p.x << " " << p.y << std::endl;
        }
    }
    else if (line1->c == line2->c) {
        std::cout << "LINE" << std::endl;
    }
    else {
        std::cout << "NONE" << std::endl;
    }
}

int main(void)
{
    int  num_case;
    Line line1, line2;

    std::cin >> num_case;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "INTERSECTING LINES OUTPUT" << std::endl;
    while (num_case--) {
        read_line(&line1);
        read_line(&line2);
        judge(&line1, &line2);
    }
    std::cout << "END OF OUTPUT" << std::endl;

    return 0;
}
