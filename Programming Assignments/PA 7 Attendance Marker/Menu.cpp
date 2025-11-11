#include "Menu.hpp"
#include <fstream>

Menu::Menu()
{
	choice = -1;
	limit = 0;
	pCur = nullptr;
}

Menu::~Menu()
{

}

int Menu::getChoice() const
{
	return choice;
}

void Menu::setChoice(int const newChoice)
{
	choice = newChoice;
}

List<Data> Menu::getList() const
{
	return list;
}

void Menu::setList(List<Data> const newList)
{
	list = newList;
}

ListNode<Data>* Menu::getListNode() const
{
	return pCur;
}

void Menu::setListNode(ListNode<Data>* newListNode)
{
	pCur = newListNode;
}

void Menu::ImportCourse(std::ifstream& inputStream)
{
	std::string line = "", name = "";
	Data d;
	std::getline(inputStream, line);
	while (std::getline(inputStream, line, ',')) // Ignores line number
	{
		std::getline(inputStream, line, ','); // ID
		d.setID(std::stoi(line));
		std::getline(inputStream, line, ','); // First Name
		name = line + ",";
		std::getline(inputStream, line, ','); // Last Name
		name = name + line;
		d.setName(name);
		std::getline(inputStream, line, ','); // Email
		d.setEmail(line);
		std::getline(inputStream, line, ','); // Units
		d.setUnits(line);
		std::getline(inputStream, line, ','); // Program
		d.setProgram(line);
		std::getline(inputStream, line, '\n'); // Level
		d.setLevel(line);

		list.insertNode(d);
	}
}

void Menu::LoadMaster(std::ifstream& masterInStream)
{
	std::string line = "", name = "";
	char character = '\0';
	Data d;
	while (std::getline(masterInStream, line, ',')) // Ignores line number
	{
		d = Data();
		std::getline(masterInStream, line, ','); // ID
		d.setID(std::stoi(line));
		std::getline(masterInStream, line, ','); // First Name
		name = line + ",";
		std::getline(masterInStream, line, ','); // Last Name
		name = name + line;
		d.setName(name);
		std::getline(masterInStream, line, ','); // Email
		d.setEmail(line);
		std::getline(masterInStream, line, ','); // Units
		d.setUnits(line);
		std::getline(masterInStream, line, ','); // Program
		d.setProgram(line);
		std::getline(masterInStream, line, ','); // Level
		d.setLevel(line);
		line = "";
		masterInStream.get(character);
		while (character != ',' && character != '\n')
		{
			line += character;
			masterInStream.get(character);
		}
		d.setNumOfAbsences(std::stoi(line));
		if (line != "0")
		{
			for (int j = 0; j < d.getNumOfAbsences() - 1; j++)
			{
				std::getline(masterInStream, line, ','); //absences
				d.setAbsence(line);
			}
			std::getline(masterInStream, line, '\n'); // last absences to account for newline
			d.setAbsence(line);
		}

		list.insertNode(d);
	}
}

void Menu::StoreMaster(std::ofstream& masterOutStream)
{
	std::string line = "";
	int i = 0;
	pCur = list.getHeadPtr();
	while (pCur != nullptr)
	{
		masterOutStream << i + 1 << "," << pCur->getData().getID() << "," << pCur->getData().getName() << "," << pCur->getData().getEmail() << "," << pCur->getData().getUnits() << "," << pCur->getData().getProgram() << "," << pCur->getData().getLevel() << "," << pCur->getData().getNumOfAbsences();
		if (pCur->getData().stackEmpty() == false)
		{
			masterOutStream << ",";
			pCur->getData().printStack(masterOutStream);
		}
		masterOutStream << std::endl;
		i++;
		pCur = pCur->getNext();
	}
}

void Menu::MarkAbsences()
{
	system("cls");
	pCur = list.getHeadPtr();
	while (pCur != nullptr)
	{
		pCur->getData().addAbsences();
		pCur = pCur->getNext();
	}
}

void Menu::GenerateReport()
{
	int choices = -1;
	system("cls");
	subMenu:
	std::cout << "\t1. Generate report for all students; showing only the most recent absence for each student.\n\t2. Generate report for students with absences that match or exceed limit" << std::endl;
	std::cin >> choices;

	if ((choices > 2 || choices < 1) && choices != -1)
	{
		std::cout << "Invalid input, try again" << std::endl;
		system("pause");
		goto subMenu;
	}

	switch (choices)
	{
	case 1: pCur = list.getHeadPtr();
		system("cls");
		while (pCur != nullptr && !pCur->getData().stackEmpty())
		{
			std::cout << pCur->getData().getName() << " Most recent Absence: " << pCur->getData().stackPeek() << std::endl;
			pCur = pCur->getNext();
		}
		system("pause");
		break;
	case 2:
		pCur = list.getHeadPtr();
		system("cls");
		std::cout << "What would you like the minimal absences for this report to be\?" << std::endl;
		std::cin >> limit;
		while (pCur != nullptr && pCur->getData().getNumOfAbsences() >= limit)
		{
			std::cout << pCur->getData().getName() << "Number of absences: " << pCur->getData().getNumOfAbsences() << " Most recent Absence : " << pCur->getData().stackPeek() << std::endl;
			pCur = pCur->getNext();
		}
		system("pause");
		break;
	}
}