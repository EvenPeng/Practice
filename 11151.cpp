#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int main(void)
{
    int         num_cases, len;
    std::string buffer;

    std::array<std::array<int, 1000>, 1000> dp;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    while (num_cases--) {
        getline(std::cin, buffer);
        len = buffer.size();
        if (len > 0) {
            // init
            dp[0][0] = 1;
            for (int i = 1; i < len; ++i) {
                dp[i - 1][i] = buffer[i - 1] == buffer[i] ? 2 : 1;
                dp[i][i]     = 1;
            }

            for (int l = 2; l < len; ++l) {
                for (int i = 0; i + l < len; ++i) {
                    dp[i][i + l] = std::max(dp[i + 1][i + l], dp[i][i + l - 1]);
                    if (buffer[i] == buffer[i + l]) {
                        dp[i][i + l] =
                            std::max(dp[i][i + l], dp[i + 1][i + l - 1] + 2);
                    }
                }
            }

            std::cout << dp[0][len - 1] << std::endl;
        }
        else {
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}
