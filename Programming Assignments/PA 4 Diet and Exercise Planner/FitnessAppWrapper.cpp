#include "PA4.h"

FitnessAppWrapper::FitnessAppWrapper()
{
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	_exerciseInputStream.close();
	_dietInputStream.close();
	_exerciseOutputStream.close();
	_dietOutputStream.close();
}

void FitnessAppWrapper::loadDailyDietPlan(std::ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyExercisePlan(std::ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyExercisePlan(std::ifstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		loadDailyExercisePlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyDietPlan(std::ifstream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		loadDailyDietPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyExercisePlan(std::ofstream& fileStream)
{
	for (int i = 0; i < 7; ++i)
	{
		storeDailyExercisePlan(fileStream, i);
	}
}

void FitnessAppWrapper::storeWeeklyDietPlan(std::ofstream& fileStream)
{
	for (int i = 0; i < 7; ++i)
	{
		storeDailyDietPlan(fileStream, i);
	}
}
void FitnessAppWrapper::displayMenu()
{
	system("cls");
	std::cout << "1. Load weekly diet plan from file.\n2. Load weekly exercise plan from file.\n3. Store weekly diet plan to file.\n4. Store weekly exercise plan to file.\n5. Display weekly diet plan to screen.\n6. Display weekly exercise plan to screen.\n7. Edit daily diet plan.\n8. Edit daily exercise plan.\n9. Exit." << std::endl;
}

void FitnessAppWrapper::runApp(void)
{
	_exerciseInputStream.open("exercisePlans.txt", std::ios::in);
	loadWeeklyExercisePlan(_exerciseInputStream, _weeklyExercisePlan);
	_dietInputStream.open("dietPlans.txt", std::ios::in);
	loadWeeklyDietPlan(_dietInputStream, _weeklyDietPlan);
	displayMenu();
}

bool FitnessAppWrapper::menuInputs(void)
{
	int selection = 0, i = -1;
	bool outcome = false;
	std::string day = "";
selectionInsert:
	std::cin >> selection;
	if (selection < 1 || selection > 9)
	{
		goto selectionInsert;
	}
	switch (selection)
	{
	case 1: // Load Diet Plan 
		_dietInputStream.close();
		_dietInputStream.open("dietPlans.txt", std::ios::in);
		loadWeeklyDietPlan(_dietInputStream, _weeklyDietPlan);
		break;
	case 2: // Load Exercise Plan
		_exerciseInputStream.close();
		_exerciseInputStream.open("exercisePlans.txt", std::ios::in);
		loadWeeklyExercisePlan(_exerciseInputStream, _weeklyExercisePlan);
		break;
	case 3: // Store Diet Plan
		_dietInputStream.close();
		_dietOutputStream.open("dietPlans.txt", std::ios::out);
		storeWeeklyDietPlan(_dietOutputStream);
		_dietOutputStream.close();
		_dietInputStream.open("dietPlans.txt", std::ios::in);
		break;
	case 4: // Store Exercise Plan
		_exerciseInputStream.close();
		_exerciseOutputStream.open("exercisePlans.txt", std::ios::out);
		storeWeeklyExercisePlan(_exerciseOutputStream);
		_exerciseOutputStream.close();
		_exerciseInputStream.open("exercisePlans.txt", std::ios::in);
		break;
	case 5: // Display Weekly Diet Plan 
		system("cls");
		displayWeeklyDietPlan();
		break;
	case 6: // Display Weekly Exercise Plan
		system("cls");
		displayWeeklyExercisePlan();
		break;
	case 7: // Edit Diet Plan
		system("cls");
	daytypeDiet:
		std::cout << "Which day's plan would you like to edit\?" << std::endl;
		std::cin >> day;
		if (day == "Monday" || day == "monday")
		{
			i = 0;
		}
		else if (day == "Tuesday" || day == "tuesday")
		{
			i = 1;
		}
		else if (day == "Wednesday" || day == "wednesday")
		{
			i = 2;
		}
		else if (day == "Thursday" || day == "thursday")
		{
			i = 3;
		}
		else if (day == "Friday" || day == "friday")
		{
			i = 4;
		}
		else if (day == "Saturday" || day == "saturday")
		{
			i = 5;
		}
		else if (day == "Sunday" || day == "sunday")
		{
			i = 6;
		}
		else
		{
			std::cout << "Day not found. Please try again." << std::endl;
			goto daytypeDiet;
		}
		editDietPlan(i);
		break;
	case 8: // Edit Exercise Plan
		system("cls");
	daytypeExercise:
		std::cout << "Which day's plan would you like to edit\?" << std::endl;
		std::cin >> day;
		if (day == "Monday" || day == "monday")
		{
			i = 0;
		}
		else if (day == "Tuesday" || day == "tuesday")
		{
			i = 1;
		}
		else if (day == "Wednesday" || day == "wednesday")
		{
			i = 2;
		}
		else if (day == "Thursday" || day == "thursday")
		{
			i = 3;
		}
		else if (day == "Friday" || day == "friday")
		{
			i = 4;
		}
		else if (day == "Saturday" || day == "saturday")
		{
			i = 5;
		}
		else if (day == "Sunday" || day == "sunday")
		{
			i = 6;
		}
		else
		{
			std::cout << "Day not found. Please try again." << std::endl;
			goto daytypeExercise;
		}
		editExercisePlan(i);
		break;
	case 9: // Terminate Program
		outcome = true;
		break;
	}
	return outcome;
}

void FitnessAppWrapper::editDietPlan(int day)
{
	std::string newPlanName = "", newDate = "";
	int newGoal = 0;
	displayDailyDietPlan(day);
	std::cout << std::endl << "What would you like to edit the plan name to\?" << std::endl;
	std::cin >> newPlanName;
	std::cout << "What would you like to edit the calorie goal to\?" << std::endl;
	std::cin >> newGoal;
	std::cout << "What would you like to edit the date of this plan to\?" << std::endl;
	std::cin >> newDate;

	_weeklyDietPlan[day].setPlanName(newPlanName);
	_weeklyDietPlan[day].setGoal(newGoal);
	_weeklyDietPlan[day].setDate(newDate);
}

void FitnessAppWrapper::editExercisePlan(int day)
{
	std::string newPlanName = "", newDate = "";
	int newGoal = 0;
	displayDailyExercisePlan(day);
	std::cout << std::endl << "What would you like to edit the plan name to\?" << std::endl;
	std::cin >> newPlanName;
	std::cout << "What would you like to edit the calorie goal to\?" << std::endl;
	std::cin >> newGoal;
	std::cout << "What would you like to edit the date of this plan to\?" << std::endl;
	std::cin >> newDate;

	_weeklyExercisePlan[day].setPlanName(newPlanName);
	_weeklyExercisePlan[day].setGoal(newGoal);
	_weeklyExercisePlan[day].setDate(newDate);
}

void FitnessAppWrapper::displayDailyDietPlan(int day)
{
	std::cout << _weeklyDietPlan[day];
}

void FitnessAppWrapper::displayDailyExercisePlan(int day)
{
	std::cout << _weeklyExercisePlan[day];
}

void FitnessAppWrapper::displayWeeklyDietPlan()
{
	for (int i = 0; i < 7; ++i)
	{
		std::cout << _weeklyDietPlan[i];
	}
}

void FitnessAppWrapper::displayWeeklyExercisePlan()
{
	for (int i = 0; i < 7; ++i)
	{
		std::cout << _weeklyExercisePlan[i];
	}
}

void FitnessAppWrapper::storeDailyDietPlan(std::ofstream& output, int day)
{
	output << _weeklyDietPlan[day];
}

void FitnessAppWrapper::storeDailyExercisePlan(std::ofstream& output, int day)
{
	output << _weeklyExercisePlan[day];
}

std::ofstream& operator<<(std::ofstream& rhs, ExercisePlan& lhs)
{
	rhs << lhs.getPlanName() << std::endl;
	rhs << lhs.getGoal() << std::endl;
	rhs << lhs.getDate() << std::endl;
	rhs << std::endl;
	return rhs;
}

std::ofstream& operator<<(std::ofstream& rhs, DietPlan& lhs)
{
	rhs << lhs.getPlanName() << std::endl;
	rhs << lhs.getGoal() << std::endl;
	rhs << lhs.getDate() << std::endl;
	rhs << std::endl;
	return rhs;
}

std::ifstream& operator>> (std::ifstream& rhs, ExercisePlan& lhs)
{
	char line[100] = "";

	rhs.getline(line, 100, '\n');
	lhs.setPlanName(line);
	rhs.getline(line, 100, '\n');
	lhs.setGoal(atoi(line));
	rhs.getline(line, 100);
	lhs.setDate(line);
	rhs.getline(line, 100, '\n');

	return rhs;
}

std::ifstream& operator>> (std::ifstream& rhs, DietPlan& lhs)
{
	char line[100] = "";

	rhs.getline(line, 100, '\n');
	lhs.setPlanName(line);
	rhs.getline(line, 100, '\n');
	lhs.setGoal(atoi(line));
	rhs.getline(line, 100);
	lhs.setDate(line);
	rhs.getline(line, 100, '\n');

	return rhs;
}

std::ostream& operator<<(std::ostream& rhs, ExercisePlan& lhs)
{
	rhs << lhs.getPlanName() << std::endl;
	rhs << lhs.getGoal() << std::endl;
	rhs << lhs.getDate() << std::endl;
	rhs << std::endl;
	return rhs;
}

std::ostream& operator<<(std::ostream& rhs, DietPlan& lhs)
{
	rhs << lhs.getPlanName() << std::endl;
	rhs << lhs.getGoal() << std::endl;
	rhs << lhs.getDate() << std::endl;
	rhs << std::endl;
	return rhs;
}

std::istream& operator>> (std::istream& rhs, ExercisePlan& lhs)
{
	char line[100] = "";

	rhs.getline(line, 100, '\n');
	lhs.setPlanName(line);
	rhs.getline(line, 100, '\n');
	lhs.setGoal(atoi(line));
	rhs.getline(line, 100);
	lhs.setDate(line);
	rhs.getline(line, 100, '\n');

	return rhs;
}

std::istream& operator>> (std::istream& rhs, DietPlan& lhs)
{
	char line[100] = "";

	rhs.getline(line, 100, '\n');
	lhs.setPlanName(line);
	rhs.getline(line, 100, '\n');
	lhs.setGoal(atoi(line));
	rhs.getline(line, 100);
	lhs.setDate(line);
	rhs.getline(line, 100, '\n');

	return rhs;
}
