<?php
class Calculator {
	// m_history of $results
	private $m_history = array();
	
	// Constructor for loading results from file
	public function __construct($file_name = '') {
		$this->load_history_from_file($file_name);
		$this->f_print("Calculator was created");
	}
	
	// Prints text with current date
	public function f_print($text) {
		$date = date('m/d/Y h:i:s a', time());
	    echo "# " . $date . " # "  . $text;
	}
	
	// Adds two numbers
	public function f_addition($number_1, $number_2) {
		$result = $number_1 + $number_2;
		$this->f_print("Result od f_addition is " . $result);
		$this->add_to_history($result);
		return $result;
	}
	
	// Subtracts two numbers
	public function f_substraction( $number_1, $number_2) {
		$result = $number_1 - $number_2;
		$this->f_print("Result od f_substraction is " . $result);
		$this->add_to_history($result);
		return $result;
	}
	
	
	// Multiplies two numbers
	public function f_multiplication( $number_1, $number_2) {
		$result = $number_1 * $number_2;
		$this->f_print("Result od f_multiplication is " . $result);
		$this->add_to_history($result);
		return $result;
	}
	
	// Divides two numbers
	public function f_division( $number_1, $number_2) {
		$result = $number_1 / $number_2;
		$this->f_print("Result od f_division is " . $result);
		$this->add_to_history($result);
		return $result;
	}
	
	// Adds $result to m_history array
	private function add_to_history($l_item) {
        array_push($this->m_history, $l_item);
	}
	
	// f_print the whole m_history
	public function print_history() {
		foreach ( $this->m_history as $result) {
			$this->f_print($result);
		}
	}
	
	// Compare two numbers
	public function compare_numbers( $number_1, $number_2) {
		if ($number_1 > $number_2) {
			$this->f_print($number_1 . " is bigger than " . $number_2);
		} else if ($number_2 > $number_1) {
			$this->f_print($number_1 . " is smaller than " . $number_2);
		} else {
			$this->f_print($number_1 . " is the same as " . $number_2);
		}
	}
	
	// Adds $results to m_history
	public function load_history_from_file($file_name) {
        if($file_name !== '')
        try {
			$l_file = fopen($file_name, "r");
            $read_line = "";
            while (($readLine = fgets($l_file)) !== false) {
                $this->add_to_history($read_line);
            }
            fclose($l_file);
            $this->f_print("m_history form file was loaded!");
		} catch (Exception $e) {
			$this->f_print("File could not be loaded! Because:" . $e);
		}
	}
	
	// Returns if l_number is odd
	public function is_odd( $l_number) {
		$bool_is_odd = ($l_number/2) != 0;
		switch ($bool_is_odd) {
			case true:
				$this->f_print($l_number . " is odd!");
				return true;
			case false: 
				$this->f_print($l_number . " is not odd!");
				return false;
		}
	}
}