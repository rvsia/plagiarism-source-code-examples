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
	
	// Prints text with current date
	public void print(String text) {
		java.util.Date date = new java.util.Date();
	    System.out.println("# " + date.toString() + " # " + text );
	}
	
	// Adds two numbers
	public float addition(float number1, float number2) {
		float result = number1 + number2;
		this.print("Result od addition is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Divides two numbers
	public float division(float number1, float number2) {
		float result = number1 / number2;
		this.print("Result od division is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Adds result to history array
	private void addToHistory(float item) {
		this.history.add(item);
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

	public void someThing(){
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		String s = "world!";
        System.out.println("Hello " + s);
		System.out.println("Hello " + s);
	}
}