#pragma once
#include "Node.hpp"

class TransactionNode : public Node
{
public:
	TransactionNode(std::string const newData, int const newUnits) : Node(newData) { units = newUnits; }
	~TransactionNode() {}

	int getUnits() const { return units; }
	void setUnits(int const newUnits) { units = newUnits; }

	void printData() override { std::cout << "\tData: " << getData() << "\tUnits: " << getUnits() << std::endl; }
private:
	int units;
};