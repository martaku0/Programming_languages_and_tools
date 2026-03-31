#include "../include/commands.hpp"

std::vector<std::string> grep(const std::vector<std::string>& lines, const std::vector<std::string>& args){
    bool opt_i = false; // Ignore case
    bool opt_n = false; // Line numbers
    bool opt_w = false; // Whole word
    bool opt_c = false; // Count only
    std::string pattern_str = "";

    for (int i = 0; i < args.size(); ++i) {
        if (args[i] == "-i") opt_i = true;
        else if (args[i] == "-n") opt_n = true;
        else if (args[i] == "-w") opt_w = true;
        else if (args[i] == "-c") opt_c = true;
        else if (pattern_str.empty()) {
            pattern_str = args[i]; // First non-option argument is the pattern
        }
    }

    std::vector<std::string> result;
    if (pattern_str.empty()) return result;

    if (opt_w) {
        pattern_str = "\\b" + pattern_str + "\\b";
    }

    auto flags = std::regex::ECMAScript; // Use ECMAScript syntax for regex
    
    if (opt_i) {
        flags |= std::regex::icase; // Add case-insensitive flag
    }

    std::regex re(pattern_str, flags);
    int match_count = 0;

    for (int i = 0; i < lines.size(); ++i) {
        
        if (std::regex_search(lines[i], re)) { // auto-detect if the pattern matches the line
            match_count++;
            
            if (!opt_c) {
                std::string output_line = "";
                if (opt_n) {
                    output_line += std::to_string(i + 1) + ":";
                }
                output_line += lines[i];
                result.push_back(output_line);
                // if (opt_n) {
                //     std::cout << (i + 1) << ":";
                // }
                // std::cout << lines[i] << "\n";
            }
        }
    }

    if (opt_c) {
        // std::cout << match_count << "\n";
        result.push_back(std::to_string(match_count));
    }

    return result;
}