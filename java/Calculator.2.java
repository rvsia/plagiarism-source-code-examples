import java.util.*;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;

// Calculator  class
public class Calculator {
	// m_history of results
	private List<Float> m_history = new ArrayList<Float>();
	
	// Constructor for loading results from file
	public Calculator(String file_name) {
		this.load_history_from_file(file_name);
		this.f_print("Calculator was created");
	}
	
	// Prints text with current date
	public void f_print(String text) {
		java.util.Date date = new java.util.Date();
	    System.out.println("# " + date.toString() + " # " + text );
	}
	
	// Adds two numbers
	public float f_addition(float number_1, float number_2) {
		float l_result = number_1 + number_2;
		this.f_print("Result od f_addition is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Subtracts two numbers
	public float f_substraction(float number_1, float number_2) {
		float l_result = number_1 - number_2;
		this.f_print("Result od f_substraction is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	
	// Multiplies two numbers
	public float f_multiplication(float number_1, float number_2) {
		float l_result = number_1 * number_2;
		this.f_print("Result od f_multiplication is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Divides two numbers
	public float f_division(float number_1, float number_2) {
		float l_result = number_1 / number_2;
		this.f_print("Result od f_division is " + l_result);
		this.add_to_history(l_result);
		return l_result;
	}
	
	// Adds l_result to m_history array
	private void add_to_history(float l_item) {
		this.m_history.add(l_item);
	}
	
	// f_print the whole m_history
	public void print_history() {
		for (float l_result: this.m_history) {
			this.f_print(String.valueOf(l_result));
		}
	}
	
	// Compare two numbers
	public void compare_numbers(float number_1, float number_2) {
		if (number_1 > number_2) {
			this.f_print(number_1 + " is bigger than " + number_2);
		} else if (number_2 > number_1) {
			this.f_print(number_1 + " is smaller than " + number_2);
		} else {
			this.f_print(number_1 + " is the same as " + number_2);
		}
	}
	
	// Adds results to m_history
	public void load_history_from_file(String file_name) {
		try {
			File history_file = new File(file_name);
			BufferedReader l_reader = new BufferedReader(new FileReader(history_file));
            String read_line = "";
            while ((read_line = l_reader.readLine()) != null) {
                this.add_to_history(Float.parseFloat(read_line));
            }
            reader.close();
            this.f_print("m_history form file was loaded!");
		} catch (Exception e) {
			this.f_print("File could not be loaded! Because:" + e);
		}
	}
	
	// Returns if l_number is odd
	public boolean is_odd(float l_number) {
		boolean bool_is_odd = (l_number%2) != 0;
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