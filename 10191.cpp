#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <string>

struct Appointment {
    int beg, end;
};

bool sort_appointment(const Appointment &x, const Appointment &y)
{
    return x.beg == y.beg ? x.end < y.end : x.beg < y.beg;
}

int get_begin(const std::string &buffer)
{
    return 60 * std::stoi(buffer.substr(0, 2)) + std::stoi(buffer.substr(3, 2));
}

int get_end(const std::string &buffer)
{
    return 60 * std::stoi(buffer.substr(6, 2)) + std::stoi(buffer.substr(9, 2));
}

int main(void)
{
    int                          num_days = 0, num_appointment;
    std::string                  buffer;
    std::array<Appointment, 480> appointment;
    int latest_end, last_end, longest_beg, longest_elapsed;

    while (getline(std::cin, buffer)) {
        num_appointment = std::stoi(buffer);
        for (int i = 0; i < num_appointment; ++i) {
            getline(std::cin, buffer);
            appointment[i].beg = get_begin(buffer);
            appointment[i].end = get_end(buffer);
        }

        std::sort(appointment.begin(), appointment.begin() + num_appointment,
                  sort_appointment);

        longest_beg     = 600;
        longest_elapsed = appointment[0].beg - 600;

        int i = 0, j;
        while (i < num_appointment) {
            last_end = appointment[i].end;
            j        = i + 1;
            while (j < num_appointment && appointment[j].beg <= last_end) {
                if (last_end < appointment[j].end)
                    last_end = appointment[j].end;
                ++j;
            }

            if (j < num_appointment &&
                appointment[j].beg - last_end > longest_elapsed) {
                longest_beg     = last_end;
                longest_elapsed = appointment[j].beg - last_end;
            }

            i = j;
        }

        latest_end = appointment[0].end;
        for (int i = 1; i < num_appointment; ++i) {
            if (latest_end < appointment[i].end)
                latest_end = appointment[i].end;
        }
        if (1080 - latest_end > longest_elapsed) {
            longest_beg     = latest_end;
            longest_elapsed = 1080 - latest_end;
        }

        std::cout << "Day #" << ++num_days << ": the longest nap starts at "
                  << std::setfill('0') << std::setw(2) << longest_beg / 60
                  << ":" << std::setfill('0') << std::setw(2)
                  << longest_beg % 60 << " and will last for ";
        if (longest_elapsed / 60) {
            std::cout << longest_elapsed / 60 << " hours"
                      << " and " << longest_elapsed % 60 << " minutes."
                      << std::endl;
        }
        else {
            std::cout << longest_elapsed % 60 << " minutes." << std::endl;
        }
    }

    return 0;
}
