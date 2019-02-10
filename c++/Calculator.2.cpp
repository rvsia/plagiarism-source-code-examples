#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

// Calculator  class
class Calculator {
    // m_history of results
private: vector<float> m_history;

    // Constructor for loading results from file
    public: Calculator(string file_name) {
        load_history_from_file(file_name);
        f_print("Calculator was created");
    }
    
    Calculator() {
        f_print("Calculator was created");
    }

    // Prints text with current date
    public: void f_print(string text) {
        std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << "# " <<  std::ctime(&date) << " # " << text;
    }

    // Adds two numbers
    public: float f_addition(float number_1, float number_2) {
        float l_result = number_1 + number_2;
        f_print("Result od f_addition is " + to_string(l_result));
        add_to_history(l_result);
        return l_result;
    }

    // Subtracts two numbers
    public: float f_substraction(float number_1, float number_2) {
        float l_result = number_1 - number_2;
        f_print("Result od f_substraction is " + to_string(l_result));
        add_to_history(l_result);
        return l_result;
    }


    // Multiplies two numbers
    public: float f_multiplication(float number_1, float number_2) {
        float l_result = number_1 * number_2;
        f_print("Result od f_multiplication is " + to_string(l_result));
        add_to_history(l_result);
        return l_result;
    }

    // Divides two numbers
    public: float f_division(float number_1, float number_2) {
        float l_result = number_1 / number_2;
        f_print("Result od f_division is " + to_string(l_result));
        add_to_history(l_result);
        return l_result;
    }

    // Adds l_result to m_history array
    private: void add_to_history(float l_item) {
        m_history.push_back(l_item);
    }

    // f_print the whole m_history
    public: void print_history() {
        for (float l_result: m_history) {
            f_print(to_string(l_result));
        }
    }

    // Compare two numbers
    public: void compare_numbers(float number_1, float number_2) {
        if (number_1 > number_2) {
            f_print(to_string(number_1) + " is bigger than " + to_string(number_2));
        } else if (number_2 > number_1) {
            f_print(to_string(number_1) + " is smaller than " + to_string(number_2));
        } else {
            f_print(to_string(number_1) + " is the same as " + to_string(number_2));
        }
    }

    // Adds results to m_history
    public: void load_history_from_file(string file_name) {
        try {
            std::ifstream file(file_name);
            string read_line = "";
            while (getline(file, read_line)) {
                add_to_history(stof(read_line));
            }
            file.close();
            f_print("m_history form file was loaded!");
        } catch (const std::exception& e) {
            f_print("File could not be loaded! Because:" + std::string(e.what()));
        }
    }

    // Returns if l_number is odd
    public: bool is_odd(float l_number) {
        bool bool_is_odd = (l_number/2) != 0;
        switch (bool_is_odd) {
            case true:
                f_print(to_string(l_number) + " is odd!");
                return true;
            case false:
                f_print(to_string(l_number) + " is not odd!");
                return false;
        }
    }
};