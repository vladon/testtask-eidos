// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "Classes_stdafx.h"

#include "Classes.h"

// Employee
const std::map<Employee::Position, const std::string> Employee::PositionNames =
	{
		{ Employee::Position::Mounter, "Mounter" },
		{ Employee::Position::Electronician, "Electronician" },
		{ Employee::Position::Developer, "Developer" },
		{ Employee::Position::Economist, "Economist" },
		{ Employee::Position::CppDeveloper, "C++ Developer" }
	};

Employee::Employee(const std::string a_firstName, const std::string a_lastName, const Position a_position, double a_salary)
	: firstName(a_firstName),
	lastName(a_lastName),
	position(a_position),
	salary(a_salary)
{
}

const std::string Employee::GetInfo()
{
	return
		"Name: " + lastName + ", " + firstName + "\n" +
		"Position: " + PositionNames.at(position) + "\n" +
		"Salary: " + std::to_string(GetSalary());
}

double Employee::GetSalary()
{
	return salary;
}

// Mounter
const std::map<Mounter::MountingDepartment, const std::string> Mounter::MountingDepartmentNames =
	{
		{ Mounter::MountingDepartment::Workshop, "Workshop" },
		{ Mounter::MountingDepartment::Warehouse, "Warehouse" },
	};

Mounter::Mounter(const std::string a_firstName, 
				 const std::string a_lastName, 
				 double a_salary, 
				 MountingDepartment a_mountingDepartment)
	: Employee(a_firstName, a_lastName, Employee::Position::Mounter, a_salary), 
	mountingDepartment(a_mountingDepartment)
{

}

const std::string Mounter::GetInfo()
{
	return
		Employee::GetInfo() + "\n" +
		"Department: " + MountingDepartmentNames.at(mountingDepartment);
}



// Electronician
const std::map<Electronician::OhmLaw, const std::string> Electronician::ohmLawsNames = 
	{ 
		{ Electronician::OhmLaw::OhmLaw1, "Ohm Law #1" },
		{ Electronician::OhmLaw::OhmLaw2, "Ohm Law #2" }
	};

Electronician::Electronician(const std::string a_firstName, 
							 const std::string a_lastName, 
							 double a_salary, 
							 KnownOhmLaws a_knownOhmLaws)
	: Employee(a_firstName, a_lastName, Employee::Position::Electronician, a_salary),
	knownOhmLaws(a_knownOhmLaws)
{

}

const std::string Electronician::GetInfo()
{
	std::stringstream ss;

	ss << Employee::GetInfo() << "\n";

	ss << "Knowing of Ohm Laws: " << "\n";
	for (auto & kv : knownOhmLaws) {
		ss << "\t" << Electronician::ohmLawsNames.at(kv.first) << " : " << ((kv.second) ? "Yes" : "No") << "\n";
	}

	return ss.str();
}

// Developer
Developer::Developer(const std::string a_firstName,
					 const std::string a_lastName,
					 double a_salary,
					 const std::string a_developmentLanguage,
					 const std::string a_university)
					 : Employee(a_firstName, a_lastName, Employee::Position::Developer, a_salary),
					 developmentLanguage(a_developmentLanguage),
					 university(a_university)
{

}

const std::string Developer::GetInfo()
{
	return
		Employee::GetInfo() + "\n" +
		"Develops in: " + developmentLanguage + "\n" +
		"Graduated from: " + university;
}

// Economist
Economist::Economist(const std::string a_firstName,
					 const std::string a_lastName,
					 double a_salary,
					 int a_nCompanies)
					 : Employee(a_firstName, a_lastName, Employee::Position::Economist, a_salary),
					 nCompanies(a_nCompanies)
{

}

const std::string Economist::GetInfo()
{
	return
		Employee::GetInfo() + "\n" +
		"Works with " + std::to_string(nCompanies) + " " + ((nCompanies == 1) ? "company" : "companies");
}

// CppDeveloper
CppDeveloper::CppDeveloper(const std::string a_firstName,
						   const std::string a_lastName,
						   double a_salary,
						   const std::string a_university,
						   int a_experience,
						   const std::string a_ide)
						   : Developer(a_firstName,
									   a_lastName,
									   a_salary,
									   "C++",
									   a_university),
						   experience(a_experience),
						   ide(a_ide)
{
	position = Employee::Position::CppDeveloper;
}

const std::string CppDeveloper::GetInfo()
{
	return
		Developer::GetInfo() + "\n" +
		"Experience: " + std::to_string(experience) + " " + ((experience == 1) ? "year" : "years") + "\n" +
		"Using IDE: " + ide;
}
