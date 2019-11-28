#include <iostream>
#include <queue>
#include <string>

struct Query {
    int id, step, next;
};

bool operator<(const Query &x, const Query &y)
{
    return x.next == y.next ? x.id > y.id : x.next > y.next;
}
bool operator>(const Query &x, const Query &y)
{
    return x.next == y.next ? x.id < y.id : x.next < y.next;
}

int main(void)
{
    int         count, x, y;
    std::string buffer;

    std::priority_queue<Query> q;

    while (1) {
        std::cin >> buffer;
        if (buffer[0] == '#') break;
        std::cin >> x >> y;
        q.push(Query{x, y, y});
    }

    std::cin >> count;
    while (count--) {
        auto top = q.top();
        q.pop();
        std::cout << top.id << std::endl;
        top.next += top.step;
        q.push(top);
    }

    return 0;
}
