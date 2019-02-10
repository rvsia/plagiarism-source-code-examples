import java.util.*;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;

// Calculator  class
public class Calculator {
	// History of results
	private List<Float> history = new ArrayList<Float>();
	
	// Constructor for loading results from file
	public Calculator(String fileName) {
		this.loadHistoryFromFile(fileName);
		this.print("Calculator was created");
	}
	
	// Returns if number is odd
	public boolean isOdd(float number) {
		boolean boolIsOdd = (number%2) != 0;
		switch (boolIsOdd) {
			case true:
				this.print(number + " is odd!");
				return true;
			case false: 
				this.print(number + " is not odd!");
				return false;
		}
	}
	
	// Adds two numbers
	public float addition(float number1, float number2) {
		float result = number1 + number2;
		this.print("Result od addition is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Compare two numbers
	public void compareNumbers(float number1, float number2) {
		if (number1 > number2) {
			this.print(number1 + " is bigger than " + number2);
		} else if (number2 > number1) {
			this.print(number1 + " is smaller than " + number2);
		} else {
			this.print(number1 + " is the same as " + number2);
		}
	}
	
	// Subtracts two numbers
	public float substraction(float number1, float number2) {
		float result = number1 - number2;
		this.print("Result od substraction is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Print the whole history
	public void printHistory() {
		for (float result: this.history) {
			this.print(String.valueOf(result));
		}
	}
	
	// Multiplies two numbers
	public float multiplication(float number1, float number2) {
		float result = number1 * number2;
		this.print("Result od multiplication is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Adds result to history array
	private void addToHistory(float item) {
		this.history.add(item);
	}
	
	// Divides two numbers
	public float division(float number1, float number2) {
		float result = number1 / number2;
		this.print("Result od division is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Prints text with current date
	public void print(String text) {
		java.util.Date date = new java.util.Date();
	    System.out.println("# " + date.toString() + " # " + text );
	}

	// Adds results to history
	public void loadHistoryFromFile(String fileName) {
		try {
			File historyFile = new File(fileName);
			BufferedReader reader = new BufferedReader(new FileReader(historyFile));
            String readLine = "";
            while ((readLine = reader.readLine()) != null) {
                this.addToHistory(Float.parseFloat(readLine));
            }
            reader.close();
            this.print("History form file was loaded!");
		} catch (Exception e) {
			this.print("File could not be loaded! Because:" + e);
		}
	}
}