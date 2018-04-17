#pragma once

class VisitorBase
{
public:
	VisitorBase() {}
	virtual ~VisitorBase() {}

	virtual void Visit(class Engineer*) = 0;
	virtual void Visit(class Manager*) = 0;
};