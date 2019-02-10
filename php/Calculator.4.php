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

	public function voidsomething() {
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		$s = "hello";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
		echo $s . " literal" . "\n";
		$s1 = $s . " literal";
		echo $s1 . "\n";
	}
}