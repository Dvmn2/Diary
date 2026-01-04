#include "cwuser.h"

std::string CWUser::inp_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string line;
    std::getline(std::cin, line);

    return line;
}

std::vector<int> CWUser::inp_array(int n) {
    std::vector<int> Data = {};
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        Data.push_back(a);
    }

    return Data;
}

void CWUser::output(std::string line) { std::cout << line; }
