#pragma once
#include <fstream>
#include "BST.hpp"

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST treeSold, treePurchased;
	std::ifstream csvStream;
	void openStream();
	bool getLine(std::string* newData, std::string* newUnits, std::string* transactionField);
	void getLines();
	void comp(std::string newData, std::string newUnits, std::string transactionField);
	void writeAnalytics();
};