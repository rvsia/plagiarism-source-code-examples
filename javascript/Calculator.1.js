// Computer  class

class Computer {
	// records of results
    records = [];
	
	// Constructor for loading results from file
	constructor(path) {
		this.pushResultsData(path);
		this.log("Computer was created");
	}
	
	// Prints content with current time
	log(content) {
		time = new time();
	    console.log("# " + time.toString() + " # " + content );
	}
	
	// Adds two numbers
	plus(numeral1, numeral2) {
		const outcome = numeral1 + numeral2;
		this.log("outcome od plus is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Subtracts two numbers
	minus(numeral1, numeral2) {
		const outcome = numeral1 - numeral2;
		this.log("outcome od minus is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	
	// Multiplies two numbers
	multiply(numeral1, numeral2) {
		const outcome = numeral1 * numeral2;
		this.log("outcome od multiply is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Divides two numbers
	divide(numeral1, numeral2) {
		const outcome = numeral1 / numeral2;
		this.log("outcome od divide is " + outcome);
		this.pushResult(outcome);
		return outcome;
	}
	
	// Adds outcome to records array
	pushResult(element) {
		this.records.append(element);
	}
	
	// log the whole records
	logResults() {
		this.records.forEach(function(outcome){
			this.log(outcome);
		})
	}
	
	// Compare two numbers
	comparisonNumerals(numeral1, numeral2) {
		if (numeral1 > numeral2) {
			this.log(numeral1 + " is bigger than " + numeral2);
		} else if (numeral2 > numeral1) {
			this.log(numeral1 + " is smaller than " + numeral2);
		} else {
			this.log(numeral1 + " is the same as " + numeral2);
		}
	}
	
	// Adds results to records
	pushResultsData(path) {
		try {
			data = path.split('\n');
			const row = 0;
            while (row < data.length) {
				this.pushResult(data[row]);
				row += 1;
            }
            this.log("records from file was loaded!");
		} catch (error) {
			this.log("File could not be loaded! Because:" + error);
		}
	}
	
	// Returns if numeral is odd
	uneven(numeral) {
		booleanUneven = (numeral%2) != 0;
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