import datetime

class Calculator:
    # History of results
    history = []

    # Constructor for loading results from file
    def __init__(self, fileName):
        self.loadHistoryFromFile(fileName)
        self.print("Calculator was created")

    # Prints text with current date
    def print(self, text):
        date = datetime.datetime.now()
        print("# " + str(date) + " # " + text)

    # Add two numbers
    def addition(self, number1, number2):
        result = number1 + number2
        self.print('Result of addition is ' + str(result))
        self.addToHistory(result)
        return result

    # Divides two numbers
    def division(self, number1, number2):
        result = number1 / number2
        self.print('Result of division is ' + str(result))
        self.addToHistory(result)
        return result

    # Adds result to history array
    def addToHistory(self, item):
        self.history.append(item)

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

    def something(self):
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)
        s = "12345678"
        s = "0" + s  
        print(s)