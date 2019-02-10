import datetime

class Calculator:
    # History of results
    history = []

    # Constructor for loading results from file
    def __init__(self, fileName):
        self.loadHistoryFromFile(fileName)
        self.print("Calculator was created")

    # Returns if number is odd
    def isOdd(self, number):
        boolIsOdd = number / 2 != 0
        if boolIsOdd:
            self.print(str(number) + " is odd!")
            return True
        if not boolIsOdd:
            self.print(str(number) + " is not odd!")
            return False

    # Add two numbers
    def addition(self, number1, number2):
        result = number1 + number2
        self.print('Result of addition is ' + str(result))
        self.addToHistory(result)
        return result

    # Print the whole history
    def printHistory(self):
        for result in self.history:
            self.print(str(result))

    # Substracts two numbers
    def substraction(self, number1, number2):
        result = number1 - number2
        self.print('Result of substraction is ' + str(result))
        self.addToHistory(result)
        return result

    # Compare two numbers
    def compareNumbers(self, number1,  number2):
        if number1 > number2:
            self.print(str(number1) + " is bigger than " + str(number2))
        elif number2 > number1:
            self.print(str(number1) + " is smaller than " + str(number2))
        else:
            self.print(str(number1) + " is the same as " + str(number2))

    # Multiplies two numbers
    def multiplication(self, number1, number2):
        result = number1 * number2
        self.print('Result of multiplication is ' + str(result))
        self.addToHistory(result)
        return result

    # Adds result to history array
    def addToHistory(self, item):
        self.history.append(item)
 
    # Divides two numbers
    def division(self, number1, number2):
        result = number1 / number2
        self.print('Result of division is ' + str(result))
        self.addToHistory(result)
        return result

    # Prints text with current date
    def print(self, text):
        date = datetime.datetime.now()
        print("# " + str(date) + " # " + text)

    # Adds  results  to history
    def loadHistoryFromFile(self, fileName):
        try:
            file = open(fileName)
            readLine = file.readline()
            while readLine != None:
                self.addToHistory(readLine)
                readLine = file.readline()
            file.close()
            self.print("History from file was loaded!")
        except Exception:
            self.print("File could not be loaded! Because:" + str(Exception))

