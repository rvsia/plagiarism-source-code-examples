<?php
class Computer {
	// records of $results
	private $records = array();
	
	// Constructor for loading results from file
	public function __construct($path = '') {
		$this->pushResultsData($path);
		$this->log("Computer was created");
	}
	
	// Prints content with current time
	public function log($content) {
		$time = time('m/d/Y h:i:s a', time());
	    echo "# " . $time . " # "  . $content;
	}
	
	// Adds two numbers
	public function plus($numeral1, $numeral2) {
		$outcome = $numeral1 + $numeral2;
		$this->log("outcome od plus is " . $outcome);
		$this->pushResult($outcome);
		return $outcome;
	}
	
	// Subtracts two numbers
	public function minus( $numeral1, $numeral2) {
		$outcome = $numeral1 - $numeral2;
		$this->log("outcome od minus is " . $outcome);
		$this->pushResult($outcome);
		return $outcome;
	}
	
	
	// Multiplies two numbers
	public function multiply( $numeral1, $numeral2) {
		$outcome = $numeral1 * $numeral2;
		$this->log("outcome od multiply is " . $outcome);
		$this->pushResult($outcome);
		return $outcome;
	}
	
	// Divides two numbers
	public function divide( $numeral1, $numeral2) {
		$outcome = $numeral1 / $numeral2;
		$this->log("outcome od divide is " . $outcome);
		$this->pushResult($outcome);
		return $outcome;
	}
	
	// Adds $outcome to records array
	private function pushResult($element) {
        array_push($this->records, $element);
	}
	
	// log the whole records
	public function logResults() {
		foreach ( $this->records as $outcome) {
			$this->log($outcome);
		}
	}
	
	// Compare two numbers
	public function comparisonNumerals( $numeral1, $numeral2) {
		if ($numeral1 > $numeral2) {
			$this->log($numeral1 . " is bigger than " . $numeral2);
		} else if ($numeral2 > $numeral1) {
			$this->log($numeral1 . " is smaller than " . $numeral2);
		} else {
			$this->log($numeral1 . " is the same as " . $numeral2);
		}
	}
	
	// Adds $results to records
	public function pushResultsData($path) {
        if($path !== '')
        try {
			$data = fopen($path, "r");
            $row = "";
            while (($row = fgets($data)) !== false) {
                $this->pushResult($row);
            }
            fclose($data);
            $this->log("records form file was loaded!");
		} catch (Exception $error) {
			$this->log("File could not be loaded! Because:" . $error);
		}
	}
	
	// Returns if numeral is odd
	public function uneven( $numeral) {
		$booleanUneven = ($numeral/2) != 0;
		switch ($booleanUneven) {
			case true:
				$this->log($numeral . " is odd!");
				return true;
			case false: 
				$this->log($numeral . " is not odd!");
				return false;
		}
	}
}