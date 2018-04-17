#include "EmployeeBase.h"
#include "Engineer.h"
#include "Manager.h"
#include "PrettyPrintVisitor.h"
#include "StatsVisitor.h"

#include <iomanip>
#include <iostream>

int main()
{
	// Instantiate some employees:
	std::list<EmployeeBase*> employees =
	{
		new Engineer("Ventura", "R Mendo", "HOTEL", 35),
		new Engineer("Hicham", "el Fathi", "HOTEL"),
		new Engineer("Iñaki", "Crespo", "RAIL", 36),
		new Engineer("Alix", "Kamano", "AIR"),
		new Manager("Sebastien", "Roche", 38),
		new Manager("Edmond", "Abboud", 38, 10)
	};

	//Create visitors:
	StatsVisitor stats_visitor;
	PrettyPrintVisitor pretty_print_visitor;
	

	// Spend some holidays:
	for(auto employee : employees) employee->useDaysOff(32 * std::rand()/RAND_MAX);

	// Use visitors:
	for (auto employee : employees)
	{
		employee->Accept(pretty_print_visitor);
		employee->Accept(stats_visitor);
	}

	//check stats:
	leftDays_maxDays days[] = 
	{
		stats_visitor.getDaysOffTeam("HOTEL"),
		stats_visitor.getDaysOffEngineers(),
		stats_visitor.getDaysOffManagers()
	};

	std::cout << "..:: REMAINING DAYS OFF ::.." << std::endl;
	std::cout << "Days Off of the team 'Hotel':  " << std::setw(3) << days[0].first << "/" << std::setw(3) << days[0].second << std::endl;
	std::cout << "Days Off of Engineers (total): " << std::setw(3) << days[1].first << "/" << std::setw(3) << days[1].second << std::endl;
	std::cout << "Days Off of Managers (total):  " << std::setw(3) << days[2].first << "/" << std::setw(3) << days[2].second << std::endl;

	getchar();
	return 0;
}
