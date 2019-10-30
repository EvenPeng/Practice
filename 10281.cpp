#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

struct Record {
    bool   no_speed;
    int    hour, minute, second, time;
    double speed, distance;
};

void parse_record(Record &r, const std::string s)
{
    r.hour     = std::stoi(s.substr(0, 2));
    r.minute   = std::stoi(s.substr(3, 2));
    r.second   = std::stoi(s.substr(6, 2));
    r.time     = r.hour * 3600 + r.minute * 60 + r.second;
    r.no_speed = s.size() < 9;
    r.speed    = r.no_speed ? 0 : double(std::stoi(s.substr(9))) / 3600;
    r.distance = 0;
}

void cal_distance(Record &curr, Record &next)
{
    int elapsed   = next.time - curr.time;
    next.distance = curr.distance + curr.speed * elapsed;
}

void show_record(const Record &r)
{
    std::cout << std::setfill('0') << std::setw(2) << r.hour << ":";
    std::cout << std::setfill('0') << std::setw(2) << r.minute << ":";
    std::cout << std::setfill('0') << std::setw(2) << r.second << " ";
    std::cout << std::fixed << std::setprecision(2) << r.distance << " km"
              << std::endl;
}

int main(void)
{
    std::string buffer;
    Record      curr, next;

    getline(std::cin, buffer);
    parse_record(curr, buffer);
    if (curr.speed == 0) show_record(curr);
    while (getline(std::cin, buffer)) {
        parse_record(next, buffer);
        cal_distance(curr, next);
        if (next.no_speed) {
            show_record(next);
            next.speed = curr.speed;
        }
        std::swap(curr, next);
    }

    return 0;
}
