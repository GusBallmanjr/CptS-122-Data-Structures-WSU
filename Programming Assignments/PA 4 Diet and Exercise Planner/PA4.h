/*

*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

class ExercisePlan
{
public:
	ExercisePlan();
	~ExercisePlan();

	ExercisePlan(const ExercisePlan& copy);
	
	std::string getPlanName() const;
	std::string getDate() const;
	int getGoal() const;

	void setPlanName(const std::string planName);
	void setDate(const std::string date);
	void setGoal(const int goal);

private:
	std::string _planName, _date;
	int _goal;

};

class DietPlan
{
public:
	DietPlan();
	~DietPlan();

	DietPlan(const DietPlan& copy);

	std::string getPlanName() const;
	std::string getDate() const;
	int getGoal() const;

	void setPlanName(const std::string planName);
	void setDate(const std::string date);
	void setGoal(const int goal);
private:
	std::string _planName, _date;
	int _goal;
};

class FitnessAppWrapper
{
public: 
	FitnessAppWrapper();
	~FitnessAppWrapper();
	void loadDailyDietPlan(std::ifstream& fileStream, DietPlan& plan);
	void loadDailyExercisePlan(std::ifstream& fileStream, ExercisePlan& plan);
	void loadWeeklyExercisePlan(std::ifstream& fileStream, ExercisePlan weeklyPlan[]);
	void loadWeeklyDietPlan(std::ifstream& fileStream, DietPlan weeklyPlan[]);
	void storeWeeklyExercisePlan(std::ofstream& fileStream);
	void storeWeeklyDietPlan(std::ofstream& fileStream);
	void displayMenu();
	void runApp(void);
	bool menuInputs(void);
	void editDietPlan(int day);
	void editExercisePlan(int day);

private:
	ExercisePlan _weeklyExercisePlan[7];
	DietPlan _weeklyDietPlan[7];
	std::ifstream _exerciseInputStream;
	std::ifstream _dietInputStream;
	std::ofstream _dietOutputStream;
	std::ofstream _exerciseOutputStream;
	void displayDailyDietPlan(int day);
	void displayDailyExercisePlan(int day);
	void displayWeeklyDietPlan();
	void displayWeeklyExercisePlan();
	void storeDailyDietPlan(std::ofstream& output, int day);
	void storeDailyExercisePlan(std::ofstream& output, int day);
};

std::ofstream& operator<< (std::ofstream& rhs, ExercisePlan& lhs);
std::ofstream& operator<< (std::ofstream& rhs, DietPlan& lhs);
std::ifstream& operator>> (std::ifstream& rhs, ExercisePlan& lhs);
std::ifstream& operator>> (std::ifstream& rhs, DietPlan& lhs);
std::ostream& operator<< (std::ostream& rhs, ExercisePlan& lhs);
std::ostream& operator<< (std::ostream& rhs, DietPlan& lhs);
std::istream& operator>> (std::istream& rhs, ExercisePlan& lhs);
std::istream& operator>> (std::istream& rhs, DietPlan& lhs);