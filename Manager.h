#pragma once

#include "EmployeeBase.h"

#include <list>

class Manager :
	public EmployeeBase
{
protected:
	int maxExtraDaysOff;
	int leftExtraDaysOff;

public:
	Manager() = delete;
	Manager(std::string iName, std::string iSurname, int iDaysOff = 32, int iExtraDaysOff = 8);
	virtual ~Manager();

	//Single responsibility.
	void useDaysOff(int iDays) override;

	//Other responsibilities are performed by visitors.
	void Accept(VisitorBase& iVisitor) override;

	//Class public API
	int getMaxExtraDaysOff() const;
	int getLeftExtraDaysOff() const;
};

