#include "../include/commands.hpp"

std::string get_column(const std::string& line, int column) { // helper function to extract the key for sorting based on the specified column
    if (column <= 0) {
        return line;
    }

    int current_word = 0;
    std::string word = "";
    bool in_word = false;

    for (int i = 0; i < line.length(); ++i) {
        if (line[i] != ' ' && line[i] != '\t') {
            if (!in_word) {
                in_word = true;
                current_word++;
            }
            
            if (current_word == column) { // if we are in the desired column, we build the word
                word += line[i];
            }
        } else {
            if (in_word) {
                in_word = false;
                if (current_word == column) { // if we just finished the desired column, we can return the word
                    return word; 
                }
            }
        }
    }
    
    return word;
}

bool should_swap(const std::string& line1, const std::string& line2, bool numeric, int column) { // helper function to determine if two lines should be swapped based on the sorting criteria
    std::string key1 = get_column(line1, column);
    std::string key2 = get_column(line2, column);

    if (numeric) {
        double num1 = 0.0;
        double num2 = 0.0;
        
        try { num1 = std::stod(key1); } catch (...) {} // try to convert the keys to numbers, if conversion fails, we keep them as 0
        try { num2 = std::stod(key2); } catch (...) {}
        
        return num1 > num2;
    }

    return key1 > key2;
}

std::vector<std::string> sort(const std::vector<std::string>& lines, const std::vector<std::string>& args){
    bool numeric_sort = false;
    int column = 0;

    for (int i = 0; i < args.size(); ++i) {
        if (args[i] == "-n") {
            numeric_sort = true;
        } 
        else if (args[i] == "-k" && i + 1 < args.size()) {
            column = std::stoi(args[++i]);
        }
    }

    std::vector<std::string> sorted_lines = lines; // copy of the original lines for sorting
    int n = sorted_lines.size();

    for (int i = 0; i < n - 1; ++i) { // bubble sort implementation
        for (int j = 0; j < n - i - 1; ++j) {
            if (should_swap(sorted_lines[j], sorted_lines[j + 1], numeric_sort, column)) {
                std::string temp = sorted_lines[j];
                sorted_lines[j] = sorted_lines[j + 1];
                sorted_lines[j + 1] = temp;
            }
        }
    }

    return sorted_lines;

    // for (int i = 0; i < n; ++i) {
    //     std::cout << sorted_lines[i] << "\n";
    // }
}