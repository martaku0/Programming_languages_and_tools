#include "../include/komendy.hpp"

std::vector<std::string> tail(const std::vector<std::string>& lines, const std::vector<std::string>& args) {
    int n = 10; // num of lines (default)
    bool is_chars = false; // flag for -c option (we want to count chars instead of lines)
    bool from_start = false; // flag for + option (we want to count from the start of the file instead of the end)

    for(int i = 0; i < args.size(); ++i) {
       std::string arg = args[i]; // command arg

        if (arg == "-n" && i + 1 < args.size()) {
            std::string val = args[++i]; // next part of argument (number of lines)
            if (val[0] == '+') { 
                from_start = true; 
                n = std::stoi(val.substr(1)); 
            }
            else if (val[0] == '-') { 
                from_start = false; 
                n = std::stoi(val.substr(1)); 
            }
            else { 
                from_start = false; 
                n = std::stoi(val); 
            }
        }
        else if (arg == "-c" && i + 1 < args.size()) {
            is_chars = true;
            std::string val = args[++i]; // next part of argument (number of chars)
            if (val[0] == '+') { 
                from_start = true; 
                n = std::stoi(val.substr(1)); 
            }
            else if (val[0] == '-') { 
                from_start = false; 
                n = std::stoi(val.substr(1)); 
            }
            else { 
                from_start = false; 
                n = std::stoi(val); 
            }
        }
        else if (arg[0] == '+') { // option: +liczba
            from_start = true;
            n = std::stoi(arg.substr(1));
        }
        else if (arg[0] == '-' && arg.length() > 1 && isdigit(arg[1])) { // option: -liczba
            from_start = false;
            n = std::stoi(arg.substr(1));
        }
    }


    std::vector<std::string> result;
    
    if (is_chars) { // chars (-c option)
        std::string full_text = "";
        for (const auto& line : lines) {
            full_text += line + "\n"; // merge lines
        }
        
        int len = full_text.length();
        if (len == 0) return result;

        int start_idx = 0; // index to start printing from
        if (from_start) {
            start_idx = std::max(0, n - 1); // +1 is the first char (index 0)
        } else {
            start_idx = std::max(0, len - n); // count chars from the end, but not less than 0
        }
        
        if (start_idx < len) {
            // std::cout << full_text.substr(start_idx); // print the substring from start_idx to the end
            std::string sub = full_text.substr(start_idx);
            if (!sub.empty() && sub.back() == '\n') sub.pop_back(); // remove trailing newline if it exists
            result.push_back(sub);
        }
    } 
    else { // lines (default)
        int total_lines = lines.size();
        int start_idx = 0;
        
        if (from_start) {
            start_idx = std::max(0, n - 1); // +1 is the first line (index 0)
        } else {
            start_idx = std::max(0, total_lines - n); // count lines from the end, but not less than 0
        }

        for (int i = start_idx; i < total_lines; ++i) {
            // std::cout << lines[i] << "\n"; // print lines from start_idx to the end
            result.push_back(lines[i]);
        }
    }

    return result;
}