#include <cctype>
#include <iostream>
#include <stack>
#include <string>

int main(void)
{
    char             c;
    int              num_case;
    std::string      buffer, merge;
    std::stack<char> op;

    getline(std::cin, buffer);
    num_case = std::stoi(buffer);
    getline(std::cin, buffer);
    while (num_case--) {
        while (1) {
            getline(std::cin, buffer);
            if (!buffer.size()) break;

            c = buffer[0];
            if (isdigit(c)) {
                std::cout << c;
            }
            else if (c == '*' || c == '/') {
                if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    std::cout << op.top();
                    op.pop();
                }
                op.push(c);
            }
            else if (c == '+' || c == '-') {
                while (!op.empty() && op.top() != '(') {
                    std::cout << op.top();
                    op.pop();
                }
                op.push(c);
            }
            else if (c == '(') {
                op.push(c);
            }
            else if (c == ')') {
                while (op.top() != '(') {
                    std::cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }

        while (!op.empty()) {
            std::cout << op.top();
            op.pop();
        }
        std::cout << std::endl;
        if (num_case) std::cout << std::endl;
    }

    return 0;
}
