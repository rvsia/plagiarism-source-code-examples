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

    // Prints text with current date
    public: void print(string text) {
        std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << "# " <<  std::ctime(&date) << " # " << text;
    }

    // Adds two numbers
    public: float addition(float number1, float number2) {
        float result = number1 + number2;
        print("Result od addition is " + to_string(result));
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
        history.push_back(item);
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

   public: void something(){
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
        std::vector<std::string> myStrings { "prepended to" , "my string" } ;
        std::string prepended = std::accumulate( myStrings.begin( ) , 
	    myStrings.end( ) , std::string( "" ) , []( std::string a , 
	    std::string b ) { return a + b ; } ) ;
        std::cout << prepended << std::endl ;
   }
};