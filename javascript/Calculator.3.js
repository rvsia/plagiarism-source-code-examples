// Calculator  class

class Calculator {
	// History of results
    history = [];
	
	// Constructor for loading results from file
	constructor(fileName) {
		this.loadHistoryFromFile(fileName);
		this.print("Calculator was created");
	}
	
	// Returns if number is odd
	isOdd(number) {
		boolIsOdd = (number%2) != 0;
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
	addition(number1, number2) {
		const result = number1 + number2;
		this.print("Result od addition is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Print the whole history
	printHistory() {
		this.history.forEach(function(result){
			this.print(result);
		})
	}
	// Subtracts two numbers
	substraction(number1, number2) {
		const result = number1 - number2;
		this.print("Result od substraction is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Compare two numbers
	compareNumbers(number1, number2) {
		if (number1 > number2) {
			this.print(number1 + " is bigger than " + number2);
		} else if (number2 > number1) {
			this.print(number1 + " is smaller than " + number2);
		} else {
			this.print(number1 + " is the same as " + number2);
		}
	}
	
	// Multiplies two numbers
	multiplication(number1, number2) {
		const result = number1 * number2;
		this.print("Result od multiplication is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Adds result to history array
	addToHistory(item) {
		this.history.append(item);
	}
	
	// Divides two numbers
	division(number1, number2) {
		const result = number1 / number2;
		this.print("Result od division is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Prints text with current date
	print(text) {
		date = new Date();
		console.log("# " + date.toString() + " # " + text );
	}
	
	// Adds results to history
	loadHistoryFromFile(fileName) {
		try {
			fileName = fileName.split('\n');
			const readLine = 0;
            while (readLine < fileName.length) {
				this.addToHistory(fileName[readLine]);
				readLine += 1;
            }
            this.print("History from file was loaded!");
		} catch (e) {
			this.print("File could not be loaded! Because:" + e);
		}
	}
}