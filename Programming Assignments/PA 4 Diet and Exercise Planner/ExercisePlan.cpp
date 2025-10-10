/*

*/

#include "PA4.h"

ExercisePlan::ExercisePlan()
{
	_goal = 0;
	_planName = "Empty";
	_date = "N/A";
}

ExercisePlan::~ExercisePlan()
{
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	this->_date = copy._date;
	this->_goal = copy._goal;
	this->_planName = copy._planName;
}

std::string ExercisePlan::getPlanName() const
{
	return _planName;
}

std::string ExercisePlan::getDate() const
{
	return _date;
}

int ExercisePlan::getGoal() const
{
	return _goal;
}

void ExercisePlan::setPlanName(const std::string planName)
{
	_planName = planName;
}

void ExercisePlan::setDate(const std::string date)
{
	_date = date;
}

void ExercisePlan::setGoal(const int goal)
{
	_goal = goal;
}