#pragma once

#include <string>
#include <exception>

class EmployeeBase
{
protected:
	const std::string name;
	const std::string surname;
	int maxDaysOff;
	int leftDaysOff;

public:
	EmployeeBase() = delete;
	EmployeeBase(std::string iName, std::string iSurname, int iDaysOff)
		: name(iName), surname(iSurname), maxDaysOff(iDaysOff), leftDaysOff(iDaysOff) {}
	virtual ~EmployeeBase() {}

	//Single responsibility
	//virtual void addDaysOff(int iDays) = 0;
	virtual void useDaysOff(int iDays) = 0;

	//Class public API
	std::string getName() const { return this->name; }
	std::string getSurname() const { return this->surname; }
	int getMaxDaysOff() const { return this->maxDaysOff; }
	int getLeftDaysOff() const { return this->leftDaysOff; }


	//DOUBT: should this be extracted into an external class: Visitable. 
	virtual void Accept(class VisitorBase&) = 0;
};

//TODO
/*
class NotEnoughDaysOffException
	: public std::exception
{
	NotEnoughDaysOffException(char const* const message) throw();
	virtual char const* what() const throw();
};
*/
