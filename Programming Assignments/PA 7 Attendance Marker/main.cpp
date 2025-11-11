#include "List.hpp"
#include "Data.hpp"
#include "Menu.hpp"

int main(void)
{
	std::ifstream inputStream, masterInStream;
	std::ofstream masterOutStream;
	char absentResult = '\0';
	int choice = -1;
	Menu m;

MainMenu:
	system("cls");
	std::cout << "Main Menu:\n\t1. Import course list\n\t2. Load master list\n\t3. Store master list\n\t4. Mark absences\n\t5. Generate report\n\t6. Exit" << std::endl;
	std::cin >> choice;
	m.setChoice(choice);

	if ((m.getChoice() > 6 || m.getChoice() < 1) && m.getChoice() != -1)
	{
		std::cout << "Invalid response, please try again." << std::endl;
		choice = -1;
		system("pause");
		goto MainMenu;
	}

	switch (m.getChoice())
	{
	case 1:  // Import Course List
		inputStream.open("classList.csv", std::ios::in);
		m.ImportCourse(inputStream);
		inputStream.close();
		goto MainMenu;
		break;
	case 2: // Load Master List
		masterInStream.open("master.csv", std::ios::in);
		m.LoadMaster(masterInStream);
		masterInStream.close();
		goto MainMenu;
		break;
	case 3: // Store Master List
		masterOutStream.open("master.csv", std::ios::out);
		m.StoreMaster(masterOutStream);
		masterOutStream.close();
		goto MainMenu;
		break;
	case 4: // Mark Absences
		m.MarkAbsences();
		goto MainMenu;
		break;
	case 5: // Generate Report
		m.GenerateReport();
		goto MainMenu;
		break;
	case 6: return 0; // Exit
		break;
	}
}