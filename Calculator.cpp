// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Calculator  class
class Calculator {
    // History of results
private: vector<string> history;

    // Constructor for loading results from file
    public: Calculator(string fileName) {
        loadHistoryFromFile(fileName);
        print("Calculator was created");
    }

    // Prints text with current date
    public: void print(string text) {
        //java.util.Date date = new java.util.Date();
        std::cout << "# " << date.toString() << " # " << text;
    }

    // Adds two numbers
    public: float addition(float number1, float number2) {
        float result = number1 + number2;
        print("Result od addition is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Subtracts two numbers
    public: float substraction(float number1, float number2) {
        float result = number1 - number2;
        print("Result od substraction is " + to_string(result));
        addToHistory(result);
        return result;
    }


    // Multiplies two numbers
    public: float multiplication(float number1, float number2) {
        float result = number1 * number2;
        print("Result od multiplication is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Divides two numbers
    public: float division(float number1, float number2) {
        float result = number1 / number2;
        print("Result od division is " + to_string(result));
        addToHistory(result);
        return result;
    }

    // Adds result to history array
    private: void addToHistory(float item) {
        history.push_back(to_string(item));
    }

    // Print the whole history
    public: void printHistory() {
        for (float result: history) {
            print(result);
        }
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

    // Adds results to history
    public: void loadHistoryFromFile(string fileName) {
        try {
            File historyFile = new File(fileName);
            BufferedReader reader = new BufferedReader(new FileReader(historyFile));
            string readLine = "";
            while ((readLine = reader.readLine()) != null) {
                addToHistory(Float.parseFloat(readLine));
            }
            reader.close();
            print("History form file was loaded!");
        } catch (Exception e) {
            print("File could not be loaded! Because:" + e);
        }
    }

    // Returns if number is odd
    public: bool isOdd(float number) {
        bool boolIsOdd = (number%2) != 0;
        switch (boolIsOdd) {
            case true:
                print(number + " is odd!");
                return true;
            case false:
                print(number + " is not odd!");
                return false;
        }
    }
}

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
