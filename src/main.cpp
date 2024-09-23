//******************************************************************************
// File name:   main.cpp
// Author:      Hazel Swafford
// Date:        9/23/2024
// Class:       CS200-01
// Assignment:  Hello World
// Purpose:     Convert a specieifed base to equivalent numbers in the other 
//              two bases
// Hours:       10.3
//******************************************************************************

#include <iostream>
#include <string>

using namespace std;

/**************************************************************************
 Function: 	 	hexCharToInt

 Input: 			hexadecimal character (0-9, A, B, C, D, E, or F)

 Returned:	 	equivalent decimal number (0-9, 10, 11, 12, 13, 14, 15)
 *************************************************************************/
int hexCharToInt (char hexDigit) {
	const int DECIMAL_BASE = 10;
	const char ZERO = '0', NINE = '9', A = 'A', F = 'F';
	const char a = 'a', f = 'f';

	if (hexDigit >= ZERO && hexDigit <= NINE ) {
		return hexDigit - ZERO;
	}

	else if (hexDigit >= A && hexDigit <= F) {
		return hexDigit - A + DECIMAL_BASE;

	}

	else if (hexDigit >= a && hexDigit <= f) {
		return hexDigit - a + DECIMAL_BASE;
	}

	return tolower (hexDigit) - a + DECIMAL_BASE;

}


/**************************************************************************
 Function: 	getBase

 Input:     string representing a decimal, hexadecimal, 
            or binary number

 Returns:		one of three characters:
            	• D if the number is a decimal
            	• H if the user number is a hexadecimal
           	  • B if the number is binary.
 *************************************************************************/
char getBase (const string& strNumber) {
	const string HEX_INDICATOR = "0x", BINARY_INDICATOR = "0b";
	const char HEX = 'H', BINARY = 'B', DECIMAL = 'D';
	const int FIND_TRUE = 0;

	if (strNumber.find (HEX_INDICATOR) == FIND_TRUE) {
		return HEX;
	}
	else if (strNumber.find (BINARY_INDICATOR) == FIND_TRUE) {
		return BINARY;
	}
	else {
		return DECIMAL;
	}

}

/**************************************************************************
 Function:	getNumber

 Input: 		user prompt

 Returns:		string representing a decimal, hexadecimal, or binary number.
 *************************************************************************/
string getNumber (const string& prompt) {
	string input;
	cout << prompt;
	cin >> input;

	return input;
}


/**************************************************************************
 Function: 	printTitle

 Input: 		Title to print
 Output:		printed title

 Returns: 	void
 *************************************************************************/
void printTitle (const string& myTitle) {
	cout << myTitle;

}


/**************************************************************************
 Function: 	binaryToDecimal

 Input: 		string representing a binary number

 Returns: 	string representing the decimal equivalent
 *************************************************************************/
string binaryToDecimal (const string& strNumber) {
	const int BINARY_BASE = 2, TWO = 2;
	const char ZERO = '0';
	int decimalResult = 0;

	for (char digit : strNumber.substr (TWO)) {
		decimalResult = decimalResult * BINARY_BASE + (digit - ZERO);
	}

	return to_string (decimalResult);
}



/**************************************************************************
 Function: 	decimalToBinary

 Input: 		string representing a decimal number

 Returns: 	string representing the binary equivalent
 *************************************************************************/
string decimalToBinary (const string& strNumber) {
	const int ZERO = 0, BINARY_BASE = 2;
	const string BINARY = "0b", BINARY_ZERO = "0b0";
	int stringDecimal = stoi (strNumber);
	string binaryResult = "";

	if (stringDecimal == ZERO) {

		return BINARY_ZERO;
	}

	while (stringDecimal > ZERO) {
		binaryResult = to_string (stringDecimal % BINARY_BASE) + binaryResult;
		stringDecimal /= BINARY_BASE;
	}

	return BINARY + binaryResult;

}


/**************************************************************************
 Function: 	decimalToHex

 Input: 		string representing a decimal number

 Returns: 	string representing the hexadecimal equivalent
 *************************************************************************/
string decimalToHex (const string& strNumber) {
	const int HEX_BASE = 16, ZERO = 0;
	const char hexArray [] = "0123456789ABCDEF";
	const string HEX = "0x", HEX_ZERO = "0x0";
	int stringDecimal = stoi (strNumber);
	string hexResult = "";

	stringDecimal = stoi (strNumber);

	if (stringDecimal == ZERO) {
		return HEX_ZERO;
	}

	while (stringDecimal > ZERO) {
	 hexResult = hexArray [stringDecimal % HEX_BASE] + hexResult;

	 stringDecimal /= HEX_BASE;

	}

	return HEX + hexResult;

}


/**************************************************************************
 Function: 	hexToDecimal

 Input: 		string representing a hexadecimal number

 Returns: 	string representing the decimal equivalent
 *************************************************************************/
string hexToDecimal (const string& strNumber) {
	const int HEX_BASE = 16, TWO = 2;
	int stringDecimal = stoi (strNumber.substr (TWO), nullptr, HEX_BASE);

	return to_string (stringDecimal);

}



/**************************************************************************
 Function:  hexToBinary

 Input: 		string representing a hexadecimal number

 Returns: 	string representing the binary equivalent
 *************************************************************************/
string hexToBinary (const string& strNumber) {

	return decimalToBinary (hexToDecimal (strNumber));

}



/**************************************************************************
 Function:  binaryToHex

 Input: 	 	string representing a binary number

 Returns:  	string representing the hexadecimal equivalent
 *************************************************************************/
string binaryToHex (const string& strNumber) {

	return decimalToHex (binaryToDecimal (strNumber));

}


/**************************************************************************
 Function:  main

 Purpose:  	main driver for reading a user inputed string and then 
						converting that string to a hex, binary, or decimal
						and displaying that to the user

 Returns:  	EXIT_SUCCESS
 *************************************************************************/
int main () {
 const int INF_LOOP = 1, FIND_TRUE = 0;
 const char QUIT = 'q', HEX = 'H', DECIMAL = 'D', BINARY = 'B';
 const string TITLE_BORDER = "**************************************\n", 
							TITLE_TEXT = "*****HEX-DECIMAL-BINARY CONVERTER*****\n", 
							FIRST_PROMPT = "Enter your string to convert (q to quit): ",
							PROMPT = "\nEnter your string to convert (q to quit): ";
 bool firstPrompt = true;

 printTitle (TITLE_BORDER);

 printTitle (TITLE_TEXT);

 printTitle (TITLE_BORDER);

 	while (INF_LOOP) {
	 string strUserInput;
	 char base;

	 if (firstPrompt) {
	 strUserInput = getNumber (FIRST_PROMPT);
	
	 }
	 else {
		strUserInput = getNumber (PROMPT);
	 }
	 
	 if (strUserInput.find (QUIT) == FIND_TRUE) {
		 break;
		}

	 base = getBase (strUserInput);

	 switch (base) {
		
		case BINARY: cout << "The decimal conversion is: " 
								 << binaryToDecimal (strUserInput) << endl;

		cout << "The hexadecimal conversion is: " << binaryToHex (strUserInput) 
				 << endl;
				 break;
	 
	 case DECIMAL: 
		cout << "The binary conversion is: " << decimalToBinary (strUserInput) 
				 << endl;

		cout << "The hexadecimal conversion is: " << decimalToHex (strUserInput) 
				 << endl;
				 break;

	 
	 case HEX:

		cout << "The decimal conversion is: " << hexToDecimal (strUserInput) 
				 << endl;

		cout << "The binary conversion is: " << hexToBinary (strUserInput) 
				 << endl;

				 break;
		
	 }

	 firstPrompt = false;

	}
  return EXIT_SUCCESS;
}


