#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

// Computer  class
class Computer {
    // records of results
private: vector<float> records;

    // Constructor for loading results from file
    public: Computer(string path) {
        pushResultsData(path);
        log("Computer was created");
    }
    
    Computer() {
        log("Computer was created");
    }

    // Prints content with current time
    public: void log(string content) {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << "# " <<  std::ctime(&time) << " # " << content;
    }

    // Adds two numbers
    public: float plus(float numeral1, float numeral2) {
        float outcome = numeral1 + numeral2;
        log("outcome od plus is " + to_string(outcome));
        pushResult(outcome);
        return outcome;
    }

    // Subtracts two numbers
    public: float minus(float numeral1, float numeral2) {
        float outcome = numeral1 - numeral2;
        log("outcome od minus is " + to_string(outcome));
        pushResult(outcome);
        return outcome;
    }


    // Multiplies two numbers
    public: float multiply(float numeral1, float numeral2) {
        float outcome = numeral1 * numeral2;
        log("outcome od multiply is " + to_string(outcome));
        pushResult(outcome);
        return outcome;
    }

    // Divides two numbers
    public: float divide(float numeral1, float numeral2) {
        float outcome = numeral1 / numeral2;
        log("outcome od divide is " + to_string(outcome));
        pushResult(outcome);
        return outcome;
    }

    // Adds outcome to records array
    private: void pushResult(float element) {
        records.push_back(element);
    }

    // log the whole records
    public: void logResults() {
        for (float outcome: records) {
            log(to_string(outcome));
        }
    }

    // Compare two numbers
    public: void comparisonNumerals(float numeral1, float numeral2) {
        if (numeral1 > numeral2) {
            log(to_string(numeral1) + " is bigger than " + to_string(numeral2));
        } else if (numeral2 > numeral1) {
            log(to_string(numeral1) + " is smaller than " + to_string(numeral2));
        } else {
            log(to_string(numeral1) + " is the same as " + to_string(numeral2));
        }
    }

    // Adds results to records
    public: void pushResultsData(string path) {
        try {
            std::ifstream data(path);
            string row = "";
            while (getline(data, row)) {
                pushResult(stof(row));
            }
            data.close();
            log("records form file was loaded!");
        } catch (const std::exception& error) {
            log("File could not be loaded! Because:" + std::string(error.what()));
        }
    }

    // Returns if numeral is odd
    public: bool uneven(float numeral) {
        bool booleanUneven = (numeral/2) != 0;
        switch (booleanUneven) {
            case true:
                log(to_string(numeral) + " is odd!");
                return true;
            case false:
                log(to_string(numeral) + " is not odd!");
                return false;
        }
    }
};