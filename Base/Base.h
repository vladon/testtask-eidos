#pragma once

#include <memory>
#include <vector>

#include "../Classes/Classes.h"

class EmployeeBase
{
public:
	EmployeeBase();

	void FillBaseWithTestData();

	std::vector<std::shared_ptr<Employee>> base;
};
