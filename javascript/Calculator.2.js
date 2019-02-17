// Calculator  class

class Calculator {
	// m_history of results
    m_history = [];
	
	// Constructor for loading results from file
	constructor(file_name) {
		this.load_history_from_file(file_name);
		this.f_print("Calculator was created");
	}
	
	// Prints text with current date
	f_print(text) {
		date = new Date();
	    console.log("# " + date.toString() + " # " + text );
	}
	
	// Adds two numbers
	f_addition(number_1, number_2) {
		const l_result = number_1 + number_2;
		this.f_print("Result od f_addition is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Subtracts two numbers
	f_substraction(number_1, number_2) {
		const l_result = number_1 - number_2;
		this.f_print("Result od f_substraction is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	
	// Multiplies two numbers
	f_multiplication(number_1, number_2) {
		const l_result = number_1 * number_2;
		this.f_print("Result od f_multiplication is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Divides two numbers
	f_division(number_1, number_2) {
		const l_result = number_1 / number_2;
		this.f_print("Result od f_division is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Adds l_result to m_history array
	add_to_history(l_item) {
		this.m_history.append(l_item);
	}
	
	// f_print the whole m_history
	print_history() {
		this.m_history.forEach(function(l_result){
			this.f_print(l_result);
		})
	}
	
	// Compare two numbers
	compare_numbers(number_1, number_2) {
		if (number_1 > number_2) {
			this.f_print(number_1 + " is bigger than " + number_2);
		} else if (number_2 > number_1) {
			this.f_print(number_1 + " is smaller than " + number_2);
		} else {
			this.f_print(number_1 + " is the same as " + number_2);
		}
	}
	
	// Adds results to m_history
	load_history_from_file(file_name) {
		try {
			file_name = file_name.split('\n');
			const read_line = 0;
            while (read_line < file_name.length) {
				this.add_to_history(file_name[read_line]);
				read_line += 1;
            }
            this.f_print("m_history from file was loaded!");
		} catch (e) {
			this.f_print("File could not be loaded! Because:" + e);
		}
	}
	
	// Returns if l_number is odd
	is_odd(l_number) {
		bool_is_odd = (l_number%2) != 0;
		switch (bool_is_odd) {
			case true:
				this.f_print(l_number + " is odd!");
				return true;
			case false: 
				this.f_print(l_number + " is not odd!");
				return false;
		}
	}
}