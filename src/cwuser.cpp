#include "cwuser.h"

static std::string filter_allowed(const std::string& input) {
    static const std::regex allowed(
        R"([^A-Za-z0-9{} \[\] :";'<>,.\?\/\\|\+\-\*_=()&\^%$#№@!~])");
    return std::regex_replace(input, allowed, "");
}

std::string CWUser::db_filter(const std::string& input) {
    const std::regex forbidden(R"([\/\*\?":<>|])");
    return std::regex_replace(input, forbidden, "");
}

std::string CWUser::inp_line() {
    std::string line;
    std::getline(std::cin, line);
    line = filter_allowed(line);
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
    word = filter_allowed(word);
    return word;
}

void CWUser::out_line(const std::string& line) { std::cout << line; }
