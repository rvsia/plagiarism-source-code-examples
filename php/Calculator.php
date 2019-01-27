<?php
class Calculator {
	// History of $results
	private $history = array();
	
	// Constructor for loading results from file
	public function __construct($fileName = '') {
		$this->loadHistoryFromFile($fileName);
		$this->print("Calculator was created");
	}
	
	// Prints text with current date
	public function print($text) {
		$date = date('m/d/Y h:i:s a', time());
	    echo "# " . $date . " # "  . $text;
	}
	
	// Adds two numbers
	public function addition($number1, $number2) {
		$result = $number1 + $number2;
		$this->print("Result od addition is " . $result);
		$this->addToHistory($result);
		return $result;
	}
	
	// Subtracts two numbers
	public function substraction( $number1, $number2) {
		$result = $number1 - $number2;
		$this->print("Result od substraction is " . $result);
		$this->addToHistory($result);
		return $result;
	}
	
	
	// Multiplies two numbers
	public function multiplication( $number1, $number2) {
		$result = $number1 * $number2;
		$this->print("Result od multiplication is " . $result);
		$this->addToHistory($result);
		return $result;
	}
	
	// Divides two numbers
	public function division( $number1, $number2) {
		$result = $number1 / $number2;
		$this->print("Result od division is " . $result);
		$this->addToHistory($result);
		return $result;
	}
	
	// Adds $result to history array
	private function addToHistory($item) {
        array_push($this->history, $item);
	}
	
	// Print the whole history
	public function printHistory() {
		foreach ( $this->history as $result) {
			$this->print($result);
		}
	}
	
	// Compare two numbers
	public function compareNumbers( $number1, $number2) {
		if ($number1 > $number2) {
			$this->print($number1 . " is bigger than " . $number2);
		} else if ($number2 > $number1) {
			$this->print($number1 . " is smaller than " . $number2);
		} else {
			$this->print($number1 . " is the same as " . $number2);
		}
	}
	
	// Adds $results to history
	public function loadHistoryFromFile($fileName) {
        if($fileName !== '')
        try {
			$file = fopen($fileName, "r");
            $readLine = "";
            while (($readLine = fgets($file)) !== false) {
                $this->addToHistory($readLine);
            }
            fclose($file);
            $this->print("History form file was loaded!");
		} catch (Exception $e) {
			$this->print("File could not be loaded! Because:" . $e);
		}
	}
	
	// Returns if number is odd
	public function isOdd( $number) {
		$boolIsOdd = ($number/2) != 0;
		switch ($boolIsOdd) {
			case true:
				$this->print($number . " is even!");
				return true;
			case false: 
				$this->print($number . " is not odd!");
				return false;
		}
	}
}