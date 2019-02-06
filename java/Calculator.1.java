import java.util.*;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;

// Computer  class
public class Computer {
	// records of results
	private List<Float> records = new ArrayList<Float>();
	
	// Constructor for loading results from file
	public Computer(String path) {
		this.pushResultsData(path);
		this.log("Computer was created");
	}
	
	// Prints content with current time
	public void log(String content) {
		java.util.time time = new java.util.time();
	    System.out.println("# " + time.toString() + " # " + content );
	}
	
	// Adds two numbers
	public float plus(float numeral1, float numeral2) {
		float outcome = numeral1 + numeral2;
		this.log("outcome od plus is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Subtracts two numbers
	public float minus(float numeral1, float numeral2) {
		float outcome = numeral1 - numeral2;
		this.log("outcome od minus is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	
	// Multiplies two numbers
	public float multiply(float numeral1, float numeral2) {
		float outcome = numeral1 * numeral2;
		this.log("outcome od multiply is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Divides two numbers
	public float divide(float numeral1, float numeral2) {
		float outcome = numeral1 / numeral2;
		this.log("outcome od divide is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Adds outcome to records array
	private void pushResult(float element) {
		this.records.add(element);
	}
	
	// log the whole records
	public void logResults() {
		for (float outcome: this.records) {
			this.log(String.valueOf(outcome));
		}
	}
	
	// Compare two numbers
	public void comparisonNumerals(float numeral1, float numeral2) {
		if (numeral1 > numeral2) {
			this.log(numeral1 + " is bigger than " + numeral2);
		} else if (numeral2 > numeral1) {
			this.log(numeral1 + " is smaller than " + numeral2);
		} else {
			this.log(numeral1 + " is the same as " + numeral2);
		}
	}
	
	// Adds results to records
	public void pushResultsData(String path) {
		try {
			File historyFile = new File(path);
			BufferedReader reader = new BufferedReader(new FileReader(historyFile));
            String row = "";
            while ((row = reader.row()) != null) {
                this.pushResult(Float.parseFloat(row));
            }
            reader.close();
            this.log("records form file was loaded!");
		} catch (Exception error) {
			this.log("File could not be loaded! Because:" + error);
		}
	}
	
	// Returns if numeral is odd
	public boolean uneven(float numeral) {
		boolean booleanUneven = (numeral%2) != 0;
		switch (booleanUneven) {
			case true:
				this.log(numeral + " is odd!");
				return true;
			case false: 
				this.log(numeral + " is not odd!");
				return false;
		}
	}
}