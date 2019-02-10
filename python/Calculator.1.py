import datetime

class Computer:
    # records of results
    records = []

    # Constructor for loading results from file
    def __init__(self, path):
        self.pushResultsData(path)
        self.log("Computer was created")

    # Prints content with current time
    def log(self, content):
        time = datetime.datetime.now()
        print("# " + str(time) + " # " + content)

    # Add two numbers
    def plus(self, numeral1, numeral2):
        outcome = numeral1 + numeral2
        self.log('outcome of plus is ' + str(outcome))
        self.pushResult(outcome)
        return outcome

    # Substracts two numbers
    def minus(self, numeral1, numeral2):
        outcome = numeral1 - numeral2
        self.log('outcome of minus is ' + str(outcome))
        self.pushResult(outcome)
        return outcome

    # Multiplies two numbers
    def multiply(self, numeral1, numeral2):
        outcome = numeral1 * numeral2
        self.log('outcome of multiply is ' + str(outcome))
        self.pushResult(outcome)
        return outcome

    # Divides two numbers
    def divide(self, numeral1, numeral2):
        outcome = numeral1 / numeral2
        self.log('outcome of divide is ' + str(outcome))
        self.pushResult(outcome)
        return outcome

    # Adds outcome to records array
    def pushResult(self, element):
        self.records.append(element)

    # log the whole records
    def logResults(self):
        for outcome in self.records:
            self.log(str(outcome))

    # Compare two numbers
    def comparisonNumerals(self, numeral1,  numeral2):
        if numeral1 > numeral2:
            self.log(str(numeral1) + " is bigger than " + str(numeral2))
        elif numeral2 > numeral1:
            self.log(str(numeral1) + " is smaller than " + str(numeral2))
        else:
            self.log(str(numeral1) + " is the same as " + str(numeral2))

    # Adds  results  to records
    def pushResultsData(self, path):
        try:
            file = open(path)
            row = file.row()
            while row != None:
                self.pushResult(row)
                row = file.row()
            file.close()
            self.log("records from file was loaded!")
        except Exception:
            self.log("File could not be loaded! Because:" + str(Exception))

    # Returns if numeral is odd
    def uneven(self, numeral):
        booleanUneven = numeral / 2 != 0
        if booleanUneven:
            self.log(str(numeral) + " is odd!")
            return True
        if not booleanUneven:
            self.log(str(numeral) + " is not odd!")
            return False
