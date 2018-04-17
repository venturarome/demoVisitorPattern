#include "Engineer.h"

#include "VisitorBase.h"

#include <iostream>

Engineer::Engineer(std::string iName, std::string iSurname, std::string iTeam, int iDaysOff)
	: EmployeeBase(iName, iSurname, iDaysOff), team(iTeam)
{}

Engineer::~Engineer()
{
}

void Engineer::useDaysOff(int iDays)
{
	try
	{
		if (iDays <= this->leftDaysOff) this->leftDaysOff -= iDays;
		else throw std::out_of_range("Exception caught: not enough days to spend!");
	}
	catch(std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Should I call here Accept(StatsVisitor? sould I instantiate a new StatsVisitor or retrieve it from somewhere?
}


void Engineer::Accept(VisitorBase& iVisitor)
{
	iVisitor.Visit(this);
}

std::string Engineer::getTeam() const
{
	return team;
}
