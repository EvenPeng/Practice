#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string       buffer;
int               width, height;
std::vector<char> canvas;

void create()
{
    for (int i = 2; i < buffer.size(); ++i) {
        if (buffer[i] == ' ') {
            width  = std::stoi(buffer.substr(2, i - 2));
            height = std::stoi(buffer.substr(i + 1));
            break;
        }
    }
    canvas.resize(width * height);
    std::fill(canvas.begin(), canvas.end(), 'O');
}

void draw_pixel()
{
    int i = 2, x = 0, y = 0;
    while (buffer[i] != ' ')
        x = x * 10 + int(buffer[i++] - '0');
    --x;
    ++i;
    while (buffer[i] != ' ')
        y = y * 10 + int(buffer[i++] - '0');
    --y;
    ++i;

    canvas[y * width + x] = buffer[i];
}

void draw_vertical()
{
    int i = 2, x = 0, y1 = 0, y2 = 0;
    while (buffer[i] != ' ')
        x = x * 10 + int(buffer[i++] - '0');
    --x;
    ++i;
    while (buffer[i] != ' ')
        y1 = y1 * 10 + int(buffer[i++] - '0');
    --y1;
    ++i;
    while (buffer[i] != ' ')
        y2 = y2 * 10 + int(buffer[i++] - '0');
    --y2;
    ++i;
    if (y1 > y2) std::swap(y1, y2);

    while (y1 <= y2) {
        canvas[y1 * width + x] = buffer[i];
        ++y1;
    }
}

void draw_horizontal()
{
    int i = 2, x1 = 0, x2 = 0, y = 0;
    while (buffer[i] != ' ')
        x1 = x1 * 10 + int(buffer[i++] - '0');
    --x1;
    ++i;
    while (buffer[i] != ' ')
        x2 = x2 * 10 + int(buffer[i++] - '0');
    --x2;
    ++i;
    while (buffer[i] != ' ')
        y = y * 10 + int(buffer[i++] - '0');
    --y;
    ++i;
    if (x1 > x2) std::swap(x1, x2);

    while (x1 <= x2) {
        canvas[y * width + x1] = buffer[i];
        ++x1;
    }
}

void draw_rectangle()
{
    int i = 2, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    while (buffer[i] != ' ')
        x1 = x1 * 10 + int(buffer[i++] - '0');
    --x1;
    ++i;
    while (buffer[i] != ' ')
        y1 = y1 * 10 + int(buffer[i++] - '0');
    --y1;
    ++i;
    while (buffer[i] != ' ')
        x2 = x2 * 10 + int(buffer[i++] - '0');
    --x2;
    ++i;
    while (buffer[i] != ' ')
        y2 = y2 * 10 + int(buffer[i++] - '0');
    --y2;
    ++i;

    for (int j = x1; j <= x2; ++j) {
        for (int k = y1; k <= y2; ++k) {
            canvas[k * width + j] = buffer[i];
        }
    }
}

void expand(const int x, const int y, const char org, const char rep)
{
    if (canvas[y * width + x] == org) {
        canvas[y * width + x] = rep;
        if (x - 1 > -1) expand(x - 1, y, org, rep);
        if (x + 1 < width) expand(x + 1, y, org, rep);
        if (y - 1 > -1) expand(x, y - 1, org, rep);
        if (y + 1 < height) expand(x, y + 1, org, rep);
    }
}

void fill_area()
{
    int i = 2, x = 0, y = 0;
    while (buffer[i] != ' ')
        x = x * 10 + int(buffer[i++] - '0');
    --x;
    ++i;
    while (buffer[i] != ' ')
        y = y * 10 + int(buffer[i++] - '0');
    --y;
    ++i;

    if (canvas[y * width + x] != buffer[i]) {
        expand(x, y, canvas[y * width + x], buffer[i]);
    }
}

void show()
{
    std::cout << buffer.substr(2) << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << canvas[i * width + j];
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    bool done = false;

    while (!done) {
        getline(std::cin, buffer);
        switch (buffer[0]) {
        case 'I':
            create();
            break;
        case 'C':
            std::fill(canvas.begin(), canvas.end(), 'O');
            break;
        case 'L':
            draw_pixel();
            break;
        case 'V':
            draw_vertical();
            break;
        case 'H':
            draw_horizontal();
            break;
        case 'K':
            draw_rectangle();
            break;
        case 'F':
            fill_area();
            break;
        case 'S':
            show();
            break;
        case 'X':
            done = true;
            break;
        }
    }
    return 0;
}
