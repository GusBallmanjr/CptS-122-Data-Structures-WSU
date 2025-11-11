#define _CRT_SECURE_NO_WARNINGS
#include "Data.hpp"

Data::Data()
{
	recordNumber = ID = numberOfAbsences = 0;
	name = email = program = units = "";
	level = NA;
}

Data::~Data()
{
	//deallocate stack
	while (!absences.empty())
	{
		absences.pop();
	}
}

unsigned int Data::getRecord() const
{
	return recordNumber;
}

unsigned int Data::getID() const
{
	return ID;
}

std::string Data::getUnits() const
{
	return units;
}

unsigned int Data::getNumOfAbsences() const
{
	return numberOfAbsences;;
}

std::string Data::getName() const
{
	return name;
}

std::string Data::getEmail() const
{
	return email;
}

std::string Data::getProgram() const
{
	return program;
}

std::string Data::getLevel() const
{
	if (level == Freshman)
	{
		return "Freshman";
	}
	else if (level == Sophomore)
	{
		return "Sophomore";
	}
	else if (level == Junior)
	{
		return "Junior";
	}
	else if (level == Senior)
	{
		return "Senior";
	}
	else if (level == Graduate)
	{
		return "Graduate";
	}
}

void Data::setRecord(unsigned int const newRecord)
{
	recordNumber = newRecord;
}

void Data::setID(unsigned int const newID)
{
	ID = newID;
}

void Data::setUnits(std::string const newUnits)
{
	units = newUnits;
}

void Data::setNumOfAbsences(unsigned int const newNum)
{
	numberOfAbsences = newNum;
}

void Data::setName(std::string const newName)
{
	name = newName;
}

void Data::setEmail(std::string const newEmail)
{
	email = newEmail;
}

void Data::setProgram(std::string const newProgram)
{
	program = newProgram;
}

void Data::setLevel(std::string const newLevel)
{
	if (newLevel == "Freshman")
	{
		level = Freshman;
	}
	else if (newLevel == "Sophomore")
	{
		level = Sophomore;
	}
	else if (newLevel == "Junior")
	{
		level = Junior;
	}
	else if (newLevel == "Senior")
	{
		level = Senior;
	}
	else if (newLevel == "Graduate")
	{
		level = Graduate;
	}
}

void Data::addAbsences()
{
	std::string answer, timeData;
tryAgain:
	system("cls");
	std::cout << "Was " << name << " absent today? (Y/N)" << std::endl;
	std::cin >> answer;

	if (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
	{
		std::cout << "Sorry answer was not valid, please try again." << std::endl;
		system("pause");
		goto tryAgain; 
	}
	else if (answer == "Y" || answer == "y")
	{
		time_t t = time(0); // get time now
		struct tm* now = localtime(&t);
		std::string timeData = std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_year + 1900);
		setAbsence(timeData);
		setNumOfAbsences(numberOfAbsences + 1);
	}
}

void Data::setAbsence(std::string newAbsence)
{
	absences.push(newAbsence);
}

void Data::printStack(std::ofstream& outstream)
{
	std::stack<std::string> temp;
	// to maintain order in stacks:
	for (int i = 0; i < numberOfAbsences; i++)
	{
		temp.push(absences.top());
		absences.pop();
	}
	for (int j = 0; j < numberOfAbsences; j++)
	{
		absences.push(temp.top());
		outstream << temp.top();
		if (j < numberOfAbsences - 1)
		{
			outstream << ",";
		}
		temp.pop();
	}
}

bool Data::stackEmpty()
{
	return absences.empty();
}

std::string Data::stackPeek()
{
	return absences.top();
}

void Data::operator=(Data rhs)
{
	recordNumber = rhs.recordNumber;
	ID = rhs.ID;
	numberOfAbsences = rhs.numberOfAbsences;
	name = rhs.name;
	email = rhs.email;
	program = rhs.program;
	units = rhs.units;
	level = rhs.level;
	absences = rhs.absences;
}
