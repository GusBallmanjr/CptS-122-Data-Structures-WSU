#include "DataAnalysis.hpp"

DataAnalysis::DataAnalysis()
{
	openStream();
	treePurchased.setRoot(nullptr);
	treeSold.setRoot(nullptr);
}

DataAnalysis::~DataAnalysis()
{
	csvStream.close();
}

void DataAnalysis::runAnalysis()
{
	//openStream();
	getLines();
	writeAnalytics();
}

void DataAnalysis::openStream()
{
	csvStream.open("data.csv");
	std::string header;
	if (csvStream.is_open())
	{
		std::getline(csvStream, header);
	}
}

bool DataAnalysis::getLine(std::string* newData, std::string* newUnits, std::string* transactionField)
{
	if (std::getline(csvStream, *newUnits, ','))
	{
		std::getline(csvStream, *newData, ',');
		std::getline(csvStream, *transactionField, '\n');
		return true;
	}
	else
	{
		return false;
	}
}

void DataAnalysis::getLines()
{
	std::string newData = "", newUnits = "", transactionField = "";
	while (getLine(&newData, &newUnits, &transactionField))
	{
		comp(newData, newUnits, transactionField);
	}
	std::cout << "Purchased Tree: " << std::endl;
	treePurchased.inOrderTraversal();
	std::cout << std::endl << "Sold Tree: " << std::endl;
	treeSold.inOrderTraversal();
}

void DataAnalysis::comp(std::string newData, std::string newUnits, std::string transactionField)
{

	if (transactionField == "Purchased")
	{
		treePurchased.insert(newData, std::stoi(newUnits));
	}
	else if (transactionField == "Sold")
	{
		treeSold.insert(newData, std::stoi(newUnits));
	}
}

void DataAnalysis::writeAnalytics()
{
	std::cout << "Least purchased item: " << treePurchased.findSmallest() << "\tUnits purchased: " << treePurchased.findData(treePurchased.findSmallest()) << std::endl << "Least sold item: " << treeSold.findSmallest() << "\tUnits sold: " << treeSold.findData(treeSold.findSmallest()) << std::endl << "Most purchased item: " << treePurchased.findLargest() << "\t Units purchased: " << treePurchased.findData(treePurchased.findLargest()) << std::endl << "Most sold item: " << treeSold.findLargest() << "\t Units sold: " << treeSold.findData(treeSold.findLargest()) << std::endl;
}
