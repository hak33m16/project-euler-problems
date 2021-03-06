//////////////////////////////
//
// Abdel-Hakeem Badran
// Project Euler
// 10/22/2017
//
//////////////////////////////

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <math.h>

// ## //
//
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
//
// Answer: 233168
//
// ## //

void problem1() {

	int input;
	std::cout << "Please input an integer: ";
	std::cin >> input;

	int i = input - 1, sum = 0;
	while (i > 0) {

		if (i % 5 == 0 || i % 3 == 0) {
			sum += i;
		}

		--i;

	}

	std::cout << "Sum of integers below " << input << " that are factors of 3 or 5: " << sum << std::endl;

	system("PAUSE");

}

//## //
//
// Each new term in the Fibonacci sequence is generated by adding the previous two terms.By starting with 1 and 2, the first 10 terms will be :
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even - valued terms.
//
// ## //

void problem2() {

	int temp = 0, term1 = 1, term2 = 2, evenSum = 2;
	std::cout << term1 << std::endl;
	std::cout << term2 << std::endl;
	while (term2 <= 4000000) {
		temp = term1 + term2;
		term1 = term2;
		term2 = temp;
		//std::cout << term1 << std::endl;
		if (term2 % 2 == 0) evenSum += term2;
		std::cout << term2 << std::endl;
	}

	std::cout << std::endl << "Total of even terms: " << evenSum << std::endl;

	system("PAUSE");

}

// ## //
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143?
//
// Answer: 6857
//
// ## //

void problem3() {

	int long long input;
	std::cout << "Please input an integer: ";
	std::cin >> input;
	
	std::set<int long long> factors;
	int long long factor;
	double currentValue = input, temp = 0;
	for (int long long i = 2; i <= currentValue; ++i) {

		temp = currentValue / (double) i; // Make sure that i is a factor of our currentValue before we set them.

		//std::cout << std::fixed << "Testing if value (" << currentValue << "/" << i << ") = " << temp << " is a non-decimal." << std::endl;

		if (temp == floor(temp)) { // EX.) floor(1.5) == 1: In order for i to be a factor, currentValue/i MUST have floor(n) == n
			
			//std::cout << "It was!" << std::endl;
			currentValue = temp;
			factor = i;
			factors.insert(factor);
			//std::cout << "Factor found: " << factor << std::endl;
		}
	}

	std::set<int long long> primeValues;
	for (std::set<int long long>::iterator set_i = factors.begin(); set_i != factors.end(); ++set_i) {

		bool isPrime = true;
		for (int long long i = 2; i < *set_i; ++i) {
			if (*set_i % i == 0) isPrime = false; // If a number between 2 and i is a factor of some value n, n cannot be prime
		}

		if (isPrime) primeValues.insert(*set_i);

	}

	std::cout << "Prime Values: " << std::endl;
	for (std::set<int long long>::iterator set_i = primeValues.begin(); set_i != primeValues.end(); ++set_i) {
		std::cout << *set_i << std::endl;
	}

	system("PAUSE"); // Assumes compilation takes place in Windows environment

}

// ## //
//
// A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 � 99.
//
// Find the largest palindrome made from the product of two 3 - digit numbers.
//
// ## //

void problem4() {

	int power;
	std::cout << "Please enter the size of n-digit values to compare." << std::endl
		<< "EX. 3 = 999 * 999: ";
	std::cin >> power;

	int currentProduct, multiplicand, multiplier, largestPalindrome = 0;
	std::string product = "", reverseProduct = "";
	for (multiplier = (int) (pow(10, power) - 1); multiplier >= (int) (pow(10, power - 1)); -- multiplier) {
		for (multiplicand = (int) (pow(10, power) - 1); multiplicand >= (int) (pow(10, power - 1)); --multiplicand){

			currentProduct = multiplicand * multiplier;
			if (currentProduct % 10 != 0 && currentProduct > largestPalindrome) {

				product = std::to_string(currentProduct);
				for (int i = product.length() - 1; i >= 0; --i) {
					reverseProduct += product[i];
				}

				if (product == reverseProduct) {
					if (currentProduct > largestPalindrome) largestPalindrome = currentProduct;
				}

				reverseProduct = "";

			}
		}
	}

	std::cout << "Largest palindrome: " << largestPalindrome << std::endl;

	system("PAUSE");

}

// ## //

int main() {

	int selection = -1;
	while (true) {

		std::cout << "Which problem would you like to see? (" << "1 - 4" << ") . . . (0 to exit)\n>> ";
		std::cin >> selection;

		switch (selection) {
			case 0: exit(0);
				break;

			case 1: problem1(); // Completed on: 10/23/2017
				break;

			case 2: problem2(); // Completed on: 10/23/2017
				break;

			case 3: problem3(); // Completed on: 10/23/2017
				break;

			case 4: problem4(); // Completed on: 10/23/2017
				break;

			default: std::cout << "Invalid input.\n";
				break;

		}

		// Clear invalid input from stream
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}

	return 0;
}