/*

*/

#include "PA4.h"

DietPlan::DietPlan()
{
	_goal = 0;
	_planName = "Empty";
	_date = "N/A";
}

DietPlan::~DietPlan()
{
}

DietPlan::DietPlan(const DietPlan& copy)
{
	this->_date = copy._date;
	this->_goal = copy._goal;
	this->_planName = copy._planName;
}

std::string DietPlan::getPlanName() const
{
	return _planName;
}

std::string DietPlan::getDate() const
{
	return _date;
}

int DietPlan::getGoal() const
{
	return _goal;
}

void DietPlan::setPlanName(const std::string planName)
{
	_planName = planName;
}

void DietPlan::setDate(const std::string date)
{
	_date = date;
}

void DietPlan::setGoal(const int goal)
{
	_goal = goal;
}