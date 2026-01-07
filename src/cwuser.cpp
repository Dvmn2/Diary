#include "cwuser.h"

std::string CWUser::inp_line() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

std::string CWUser::inp_text() {
    std::string result;
    while (true) {
        std::string part = inp_line();
        if (part == "0") break;  // Читаем текст пока не 0
        result.append(part).append("\n");
    }
    return result;
}

std::string CWUser::inp_word() {
    std::string word;
    std::cin >> word;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return word;
}

void CWUser::out_line(const std::string& line) { std::cout << line; }
