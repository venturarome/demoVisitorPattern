#pragma once

#include "EmployeeBase.h"

class Engineer :
	public EmployeeBase
{
protected:
	std::string team;

public:
	Engineer() = delete;
	Engineer(std::string iName, std::string iSurname, std::string iTeam, int iDaysOff = 32);
	virtual ~Engineer();

	//Single responsibility.
	void useDaysOff(int iDays) override;

	//Other responsibilities are performed by visitors.
	void Accept(VisitorBase& iVisitor) override;

	//Class public API
	std::string getTeam() const;
};

