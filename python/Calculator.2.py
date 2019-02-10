import datetime

class Calculator:
    # m_history of results
    m_history = []

    # Constructor for loading results from file
    def __init__(self, file_name):
        self.load_history_from_file(file_name)
        self.f_print("Calculator was created")

    # Prints text with current date
    def f_print(self, text):
        date = datetime.datetime.now()
        print("# " + str(date) + " # " + text)

    # Add two numbers
    def f_addition(self, number_1, number_2):
        l_result = number_1 + number_2
        self.f_print('Result of f_addition is ' + str(l_result))
        self.add_to_history(l_result)
        return l_result

    # Substracts two numbers
    def f_substraction(self, number_1, number_2):
        l_result = number_1 - number_2
        self.f_print('Result of f_substraction is ' + str(l_result))
        self.add_to_history(l_result)
        return l_result

    # Multiplies two numbers
    def f_multiplication(self, number_1, number_2):
        l_result = number_1 * number_2
        self.f_print('Result of f_multiplication is ' + str(l_result))
        self.add_to_history(l_result)
        return l_result

    # Divides two numbers
    def f_division(self, number_1, number_2):
        l_result = number_1 / number_2
        self.f_print('Result of f_division is ' + str(l_result))
        self.add_to_history(l_result)
        return l_result

    # Adds l_result to m_history array
    def add_to_history(self, l_item):
        self.m_history.append(l_item)

    # f_print the whole m_history
    def print_history(self):
        for l_result in self.m_history:
            self.f_print(str(l_result))

    # Compare two numbers
    def compare_numbers(self, number_1,  number_2):
        if number_1 > number_2:
            self.f_print(str(number_1) + " is bigger than " + str(number_2))
        elif number_2 > number_1:
            self.f_print(str(number_1) + " is smaller than " + str(number_2))
        else:
            self.f_print(str(number_1) + " is the same as " + str(number_2))

    # Adds  results  to m_history
    def load_history_from_file(self, file_name):
        try:
            l_file = open(file_name)
            read_line = l_file.readline()
            while read_line != None:
                self.add_to_history(read_line)
                read_line = l_file.read_line()
            file.close()
            self.f_print("m_history from file was loaded!")
        except Exception:
            self.f_print("File could not be loaded! Because:" + str(Exception))

    # Returns if l_number is odd
    def is_odd(self, l_number):
        bool_is_odd = l_number / 2 != 0
        if bool_is_odd:
            self.f_print(str(l_number) + " is odd!")
            return True
        if not bool_is_odd:
            self.f_print(str(l_number) + " is not odd!")
            return False
