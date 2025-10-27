#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"

int main(void)
{
	BST<std::string, char> MorseBST;
	std::string morseString = "";
	char plainText = '\0', sentence[100] = "", delimiter = ',';
	std::ifstream inputStream;
	inputStream.open("morse.csv", std::ios::in);

	while (inputStream >> plainText >> delimiter >> morseString)
	{
		MorseBST.insert(plainText, morseString);
	}

	std::cout << "Enter sentence to be encoded: " << std::endl;
	std::cin.getline(sentence, 100);
	for (int i = 0; i < 100 && sentence[i] != '\0'; ++i)
	{
		if (sentence[i] == ' ')
		{
			std::cout << " ";
		}
		morseString = MorseBST.inOrderTraversal(sentence[i]);
		std::cout << morseString << " ";

		if (sentence[i - 1] == '.')
		{
			std::cout << "   ";
		}
		if (sentence[i] == '\0')
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	inputStream.close();
	return 0;
}