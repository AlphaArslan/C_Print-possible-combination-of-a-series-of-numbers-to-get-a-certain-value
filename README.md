# C_Print-possible-combination-of-a-series-of-numbers-to-get-a-certain-value
Input: Series Start, Series End, required value. Output:  All possible combination (addition - subtraction - concatenation)

This C code enables you to find out all possible combination of addition, subtraction, and concatenation aprations applied on a a series of numbers
in order to get a certain value out of this math. 

you enter:			<<In the control panel section in the code (HARDCODED) >>
	series_start
	series_end
	required_outcome
you get: 
	all possible combinations

Example:
	say you want to know how to get 100 (required_outcome) by manipulating the series  1 2 3 4 5 6 7 8 9
		1 	 is the series_start
		9	 is the series_end
		100	 is the required_outcome
	
	and you get:
		12+3-4+5+67+8+9                                                                                                                                
		12-3-4+5-6+7+89                                                                                                                                
		123+4-5+67-89                                                                                                                                  
		123+45-67+8-9                                                                                                                                  
		123-4-5-6-7+8-9                                                                                                                                
		123-45-67+89
