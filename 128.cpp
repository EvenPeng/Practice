#include <iomanip>
#include <iostream>
#include <string>

#define GVAL 34943

int main(void)
{
    std::string  buffer;
    char         first, second;
    unsigned int crc;

    while (1) {
        std::getline(std::cin, buffer);
        if (buffer[0] == '#') break;

        crc = 0;
        for (int i = 0; i < buffer.size(); ++i) {
            crc = ((crc << 8) + (unsigned int)buffer[i]) % GVAL;
        }

        if (crc) crc = GVAL - (((crc << 8) % GVAL) << 8) % GVAL;

        std::cout << std::setfill('0') << std::setw(2) << std::hex
                  << std::uppercase << (crc >> 8) << " " << std::setfill('0')
                  << std::setw(2) << std::hex << std::uppercase << (crc & 0x0ff)
                  << std::endl;
    }

    return 0;
}
