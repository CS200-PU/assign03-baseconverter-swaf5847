//******************************************************************************
// File name:   main.cpp
// Author:      Hazel Swafford
// Date:        9/17/2024
// Class:       CS200-01
// Assignment:  Hello World
// Purpose:     Convert a specieifed base to equivalent numbers in the other 
//              two bases
// Hours:       0.0
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

	if (hexDigit >= ZERO && hexDigit <= NINE ) {
		return hexDigit - ZERO;
	}
	else if (hexDigit >= A && hexDigit <= F) {
		return hexDigit - A + DECIMAL_BASE;
	}

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
	const int BINARY_BASE = 2;
	const char ZERO = '0';
	int decimal = 0;

	for (int i = 0; i < strNumber.length (); ++i) {
		decimal *= BINARY_BASE;

		decimal += static_cast<int> (strNumber[i] - ZERO);
	}

	return to_string(decimal);
}



/**************************************************************************
 Function: 	pqueueCreate

 Input: 		string representing a decimal number

 Returns: 	string representing the binary equivalent
 *************************************************************************/
string decimalToBinary (const string& strNumber) {
	const int ZERO = 0, BINARY_BASE = 2;
	int stringDecimal = stoi (strNumber);
	string binaryResult;

	while (stringDecimal > ZERO) {
		binaryResult = to_string (stringDecimal % BINARY_BASE) + binaryResult;
		stringDecimal /= BINARY_BASE;
	}

	return binaryResult;

}


/**************************************************************************
 Function: 	decimalToHex

 Input: 		string representing a decimal number

 Returns: 	string representing the hexadecimal equivalent
 *************************************************************************/
string decimalToHex (const string& strNumber) {
	const int DECIMAL_BASE = 10;
	const char A = 'A';
	int stringDecimal;

	stringDecimal = stoi(strNumber);

	if (stringDecimal < DECIMAL_BASE) {
		return to_string (stringDecimal);
	}
	else if {
		return A + decimalToHex (to_string (stringDecimal % DECIMAL_BASE));
	}

}


/**************************************************************************
 Function: 	hexToDecimal

 Input: 		string representing a hexadecimal number

 Returns: 	string representing the decimal equivalent
 *************************************************************************/
string hexToDecimal (const string& strNumber) {
	const int HEX_BASE = 16, TEN = 10;
	int stringDecimal = 0;
	char stringCharacter;

	for (int i = 0; i < strNumber.length(); ++i) {
		stringCharacter = toupper (strNumber[i]);
		if (!isdigit (stringCharacter)) {
			stringDecimal *= HEX_BASE;

			stringDecimal += hexCharToInt (stringCharacter);
		} 
		else {
			stringDecimal *= TEN;
		}

	}

	return to_string (stringDecimal);

}



/**************************************************************************
 Function:  hexToBinary

 Input: 		string representing a hexadecimal number

 Returns: 	string representing the binary equivalent
 *************************************************************************/
string hexToBinary (const string& strNumber) {
	const int HEX_BASE = 16;
	int stringNum;

	stringNum = stoi (strNumber, nullptr, HEX_BASE);

	return binaryToDecimal (hexToBinary ("" + to_string (stringNum)));

}



/**************************************************************************
 Function:  binaryToHex

 Input: 	 	string representing a binary number

 Returns:  	string representing the hexadecimal equivalent
 *************************************************************************/
string binaryToHex (const string& strNumber) {
	const int BASE_HEX = 16;
	int stringDecimal;

	stringDecimal = stoi (strNumber, nullptr, BASE_HEX);

	return (binaryToDecimal (hexToBinary ("" + to_string (stringDecimal))));

}


/**************************************************************************
 Function:  main

 Purpose:  	main driver for reading a user inputed string and then 
						converting that string to a hex, binary, or decimal
						and displaying that to the user

 Returns:  	EXIT_SUCCESS
 *************************************************************************/
int main () {
	const int INF_LOOP = 1;
	const char QUIT = 'q', HEX = 'H', DECIMAL = 'D', BINARY = 'B';
	const string TITLE_BORDER = "**************************************", 
							 TITLE_TEXT = "*****HEX-DECIMAL-BINARY CONVERTER*****", 
							 PROMPT = "Enter your string to convert (q to quit): ";

 printTitle (TITLE_BORDER);

 printTitle (TITLE_TEXT);

 printTitle (TITLE_BORDER);

 	while (INF_LOOP) {
	 string strUserInput;
	 char base;

	 strUserInput = getNumber (PROMPT);
	 base = getBase(strUserInput);
		
	 if (strUserInput == QUIT) {
		 break;
		}

	 if (base == BINARY) {
		cout << "The decimal conversion is: " << binaryToDecimal (strUserInput) 
				 << endl;

		cout << "The hexadecimal conversion is: " << binaryToHex (strUserInput) 
				 << endl;
	 } 
	 else if (base == DECIMAL) {
		cout << "The binary conversion is: " << decimalToBinary (strUserInput) 
				 << endl;

		cout << "The hexadecimal conversion is: " << decimalToHex (strUserInput) 
				 << endl;

	 } 
	 else if (base == HEX) {
		cout << "The binary conversion is: " << hexToBinary (strUserInput) 
				 << endl;

		cout << "The decimal conversion is: " << hexToDecimal (strUserInput) 
				 << endl;
	 }
	}
  return EXIT_SUCCESS;
}


