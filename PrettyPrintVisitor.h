#pragma once

#include "VisitorBase.h"

class PrettyPrintVisitor :
	public VisitorBase
{
public:
	PrettyPrintVisitor();
	virtual ~PrettyPrintVisitor();

	void Visit(Engineer* iEngineer) override;
	void Visit(Manager* iManager) override;
};