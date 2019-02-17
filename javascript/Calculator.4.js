// Calculator  class

class Calculator {
	// History of results
    history = [];
	
	// Constructor for loading results from file
	constructor(fileName) {
		this.loadHistoryFromFile(fileName);
		this.print("Calculator was created");
	}
	
	// Prints text with current date
	print(text) {
		date = new Date();
	    console.log("# " + date.toString() + " # " + text );
	}
	
	// Adds two numbers
	addition(number1, number2) {
		const result = number1 + number2;
		this.print("Result od addition is " + result);
		this.addToHistory(result);
		return result;
	}

	// Divides two numbers
	division(number1, number2) {
		const result = number1 / number2;
		this.print("Result od division is " + result);
		this.addToHistory(result);
		return result;
	}
	
	// Adds result to history array
	addToHistory(item) {
		this.history.append(item);
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

	something(){
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
		print(s);
		var s=", World";
		s = "Hello" + s;
	}
}