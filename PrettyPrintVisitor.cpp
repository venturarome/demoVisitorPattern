#include "PrettyPrintVisitor.h"

#include "Engineer.h"
#include "Manager.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace
{
	const int kWidth = 30;
	const std::string prefixl = "* ";	// Could be done with a decorator?
	const std::string suffixl = " *";

	std::string FillLine()
	{
		return std::string(kWidth, '*') + "\n";
	}

	std::string Pretty(std::string s)
	{
		std::stringstream prettyFormat;
		int aWidth = kWidth - suffixl.length();
		prettyFormat << std::left << std::setw(aWidth) << (prefixl + s) << suffixl << std::endl;
		return prettyFormat.str();
	}

	std::string FullName(EmployeeBase * iEmployee)
	{
		return iEmployee->getName() + " " + iEmployee->getSurname();
	}

	/*std::string Position(EmployeeBase * iEmployee)
	{
		return std::string(typeid(iEmployee).name());
	}*/
}


PrettyPrintVisitor::PrettyPrintVisitor()
{
}


PrettyPrintVisitor::~PrettyPrintVisitor()
{
}

void PrettyPrintVisitor::Visit(Engineer* iEngineer)
{
	std::string aTeam = iEngineer->getTeam();
	int aMaxDaysOff = iEngineer->getMaxDaysOff();
	int aLeftDaysOff = iEngineer->getLeftDaysOff();

	std::stringstream ss;
	ss << FillLine();
	ss << Pretty(FullName(iEngineer));
	ss << FillLine();
	ss << Pretty("Position: Engineer");
	ss << Pretty("Team: " + aTeam);
	ss << Pretty("Nominal days off:");
	ss << Pretty("  - Used: " + std::to_string(aMaxDaysOff - aLeftDaysOff));
	ss << Pretty("  - Left: " + std::to_string(aLeftDaysOff));
	ss << FillLine() << std::endl;

	std::cout << ss.str();
}

void PrettyPrintVisitor::Visit(Manager* iManager)
{
	int aMaxDaysOff = iManager->getMaxDaysOff();
	int aLeftDaysOff = iManager->getLeftDaysOff();
	int aMaxExtraDaysOff = iManager->getMaxExtraDaysOff();
	int aLeftExtraDaysOff = iManager->getLeftExtraDaysOff();

	std::stringstream ss;
	ss << FillLine();
	ss << Pretty(FullName(iManager));
	ss << FillLine();
	ss << Pretty("Position: Manager");
	ss << Pretty("Nominal days off:");
	ss << Pretty("  - Used: " + std::to_string(aMaxDaysOff - aLeftDaysOff));
	ss << Pretty("  - Left: " + std::to_string(aLeftDaysOff));
	ss << Pretty("Extra days off:");
	ss << Pretty("  - Used: " + std::to_string(aMaxExtraDaysOff - aLeftExtraDaysOff));
	ss << Pretty("  - Left: " + std::to_string(aLeftExtraDaysOff));
	ss << FillLine() << std::endl;

	std::cout << ss.str();
}
