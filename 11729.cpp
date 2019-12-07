#include <algorithm>
#include <array>
#include <iostream>

struct Task {
    int p, e;
};

bool sort_task(const Task &x, const Task &y)
{
    return x.e == y.e ? x.p > y.p : x.e > y.e;
}

int main(void)
{
    int num_task, idx = 0;
    int prepare_time, finish_time;

    std::array<Task, 1000> task;

    while (1) {
        std::cin >> num_task;
        if (!num_task) break;

        for (int i = 0; i < num_task; ++i) {
            std::cin >> task[i].p >> task[i].e;
        }
        std::sort(task.begin(), task.begin() + num_task, sort_task);

        prepare_time = 0;
        finish_time  = 0;
        for (int i = 0; i < num_task; ++i) {
            prepare_time += task[i].p;
            finish_time = std::max(finish_time, prepare_time + task[i].e);
        }

        std::cout << "Case " << ++idx << ": " << finish_time << std::endl;
    }

    return 0;
}
