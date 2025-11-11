#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <fstream>


typedef enum level
{
	NA = 0, Freshman = 1, Sophomore = 2, Junior = 3, Senior = 4, Graduate = 5
} Level;

//typedef enum dataType
//{
//	Record, ID, Units, Absences, Name, Email, Program, LEVEL
//} DataType;

class Data
{
public:
	Data();
	~Data();

	unsigned int getRecord() const;
	unsigned int getID() const;
	std::string getUnits() const;
	unsigned int getNumOfAbsences() const;
	std::string getName() const;
	std::string getEmail() const;
	std::string getProgram() const;
	std::string getLevel() const;

	void setRecord(unsigned int const newRecord);
	void setID(unsigned int const newID);
	void setUnits(std::string const newUnits);
	void setNumOfAbsences(unsigned int const newNum);
	void setName(std::string const newName);
	void setEmail(std::string const newEmail);
	void setProgram(std::string const newProgram);
	void setLevel(std::string const newLevel);

	void addAbsences();
	void setAbsence(std::string const newAbsence);
	void printStack(std::ofstream& instream);

	bool stackEmpty();
	std::string stackPeek();
	void operator=(Data rhs);

private:
	unsigned int recordNumber, ID, numberOfAbsences;
	std::string name, email, program, units;
	Level level;
	std::stack<std::string> absences;
};
