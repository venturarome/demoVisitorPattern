#pragma once

#include "VisitorBase.h"
#include <utility>
#include <string>
#include <map>

typedef std::pair<int, int> leftDays_maxDays;

class StatsVisitor :
	public VisitorBase
{
private:
	std::map<std::string, leftDays_maxDays> teamDaysOff;
	leftDays_maxDays managerDaysOff;
	int numEngineers;
	int numManagers;

public:
	StatsVisitor();
	virtual ~StatsVisitor();

	//Visitor
	void Visit(Engineer* iEngineer) override;
	void Visit(Manager* iManager) override;

	//Public API
	leftDays_maxDays getDaysOffTeam(std::string iTeam) const;
	leftDays_maxDays getDaysOffEngineers() const;
	leftDays_maxDays getDaysOffManagers() const;
};

