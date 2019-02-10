#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

// Calculator  class
class Calculator {
    // History of results
private: vector<float> history;

    // Constructor for loading results from file
    public: Calculator(string fileName) {
        loadHistoryFromFile(fileName);
        print("Calculator was created");
    }
    
    Calculator() {
        print("Calculator was created");
    }

    // Returns if number is odd
    public: bool isOdd(float number) {
        bool boolIsOdd = (number/2) != 0;
        switch (boolIsOdd) {
            case true:
                print(to_string(number) + " is odd!");
                return true;
            case false:
                print(to_string(number) + " is not odd!");
                return false;
        }
    }

    // Adds two numbers
    public: float addition(float number1, float number2) {
        float result = number1 + number2;
        print("Result od addition is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Compare two numbers
    public: void compareNumbers(float number1, float number2) {
        if (number1 > number2) {
            print(to_string(number1) + " is bigger than " + to_string(number2));
        } else if (number2 > number1) {
            print(to_string(number1) + " is smaller than " + to_string(number2));
        } else {
            print(to_string(number1) + " is the same as " + to_string(number2));
        }
    }

    // Subtracts two numbers
    public: float substraction(float number1, float number2) {
        float result = number1 - number2;
        print("Result od substraction is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Print the whole history
    public: void printHistory() {
        for (float result: history) {
            print(to_string(result));
        }
    }

    // Multiplies two numbers
    public: float multiplication(float number1, float number2) {
        float result = number1 * number2;
        print("Result od multiplication is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Adds result to history array
    private: void addToHistory(float item) {
        history.push_back(item);
    }

    // Divides two numbers
    public: float division(float number1, float number2) {
        float result = number1 / number2;
        print("Result od division is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Prints text with current date
    public: void print(string text) {
        std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << "# " <<  std::ctime(&date) << " # " << text;
    }

    // Adds results to history
    public: void loadHistoryFromFile(string fileName) {
        try {
            std::ifstream file(fileName);
            string readLine = "";
            while (getline(file, readLine)) {
                addToHistory(stof(readLine));
            }
            file.close();
            print("History form file was loaded!");
        } catch (const std::exception& e) {
            print("File could not be loaded! Because:" + std::string(e.what()));
        }
    }
};