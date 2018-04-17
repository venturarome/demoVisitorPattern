#include "StatsVisitor.h"

#include "Engineer.h"
#include "Manager.h"

StatsVisitor::StatsVisitor()
	: numEngineers(0), numManagers(0)
{}


StatsVisitor::~StatsVisitor()
{}

void StatsVisitor::Visit(Engineer * iEngineer)
{
	std::string aTeam = iEngineer->getTeam();
	int aLeftDays = iEngineer->getLeftDaysOff();
	int aMaxDays = iEngineer->getMaxDaysOff();

	if(this->teamDaysOff.count(aTeam) == 0)
	{
		this->teamDaysOff.insert(std::make_pair(aTeam, leftDays_maxDays(aLeftDays, aMaxDays)));
	}
	else
	{
		this->teamDaysOff[aTeam].first += aLeftDays;
		this->teamDaysOff[aTeam].second += aMaxDays;
	}

	this->numEngineers++;
}

void StatsVisitor::Visit(Manager * iManager)
{
	int aLeftExtraDays = iManager->getLeftExtraDaysOff();
	int aMaxExtraDays = iManager->getMaxExtraDaysOff();
	int aLeftDays = iManager->getLeftDaysOff();
	int aMaxDays = iManager->getMaxDaysOff();

	this->managerDaysOff.first += aLeftDays + aLeftExtraDays;
	this->managerDaysOff.second += aMaxDays + aMaxExtraDays;

	this->numManagers++;
}

leftDays_maxDays StatsVisitor::getDaysOffTeam(std::string iTeam) const
{
	// Use try-catch, or an if-sstatement to check if the team exists.
	return this->teamDaysOff.at(iTeam);
}

leftDays_maxDays StatsVisitor::getDaysOffEngineers() const
{
	leftDays_maxDays aTotalDays(0, 0);
	for(auto aTeam : this->teamDaysOff)
	{
		aTotalDays.first += aTeam.second.first;
		aTotalDays.second += aTeam.second.second;
	}
	return aTotalDays;
}

leftDays_maxDays StatsVisitor::getDaysOffManagers() const
{
	return this->managerDaysOff;
}
