#include "Manager.h"

#include "VisitorBase.h"

#include <iostream>

Manager::Manager(std::string iName, std::string iSurname, int iDaysOff, int iExtraDaysOff)
	: EmployeeBase(iName, iSurname, iDaysOff), maxExtraDaysOff(iExtraDaysOff), leftExtraDaysOff(iExtraDaysOff)
{}

Manager::~Manager()
{
}

void Manager::useDaysOff(int iDays)
{
	try
	{
		if (iDays <= this->leftDaysOff) this->leftDaysOff -= iDays;
		else if (iDays <= this->leftDaysOff + this->leftExtraDaysOff)
		{
			this->leftExtraDaysOff -= (iDays - this->leftDaysOff);
			this->leftDaysOff = 0;
		}
		else throw std::out_of_range("Exception caught: not enough days to spend!");
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Manager::Accept(VisitorBase & iVisitor)
{
	iVisitor.Visit(this);
}

int Manager::getMaxExtraDaysOff() const
{
	return maxExtraDaysOff;
}

int Manager::getLeftExtraDaysOff() const
{
	return leftExtraDaysOff;
}
