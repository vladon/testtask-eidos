#pragma once

#ifndef CLASSES_H
#define CLASSES_H

class __declspec(dllexport) Employee
{
public:
	enum class Position
	{
		Mounter,		// монтажник
		Electronician,	// электронщик
		Developer,		// разработчик
		Economist,		// экономист
		CppDeveloper	// разработчик C++
	};

public:
	Employee() = delete;

protected:
	static const std::map<Position, const std::string> PositionNames;

	Employee(const std::string a_firstName, const std::string a_lastName, const Position a_position, double a_salary);

	virtual const std::string GetInfo();
	virtual double GetSalary();

	std::string firstName;
	std::string lastName;
	Position position;
	double salary;
};

class __declspec(dllexport) Mounter : public Employee
{
public:
	enum class MountingDepartment
	{
		Workshop,	// цех
		Warehouse	// склад
	};
	static const std::map<MountingDepartment, const std::string> MountingDepartmentNames;

	Mounter() = delete;
	Mounter(const std::string a_firstName, const std::string a_lastName, double a_salary, MountingDepartment a_mountingDepartment);

	const std::string GetInfo() override;

private:
	MountingDepartment mountingDepartment;
};

class __declspec(dllexport) Electronician : public Employee
{
public:
	enum class OhmLaw
	{
		OhmLaw1,
		OhmLaw2
	};
	static const size_t kOhmLawsCount = 2;

	static const std::map<OhmLaw, const std::string> ohmLawsNames;

	typedef std::map<OhmLaw, bool> KnownOhmLaws;

	Electronician() = delete;
	Electronician(const std::string a_firstName, const std::string a_lastName, double a_salary, KnownOhmLaws a_knownOhmLaws);

	const std::string GetInfo() override;

private:
	KnownOhmLaws knownOhmLaws;
};

class __declspec(dllexport) Developer : public Employee
{
public:
	Developer() = delete;
	Developer(const std::string a_firstName, 
			  const std::string a_lastName, 
			  double a_salary, 
			  const std::string a_developmentLanguage, 
			  const std::string a_university);

	virtual const std::string GetInfo() override;

protected:
	std::string developmentLanguage;

private:
	std::string university;
};

class __declspec(dllexport) Economist : public Employee
{
public:
	Economist() = delete;
	Economist(const std::string a_firstName,
			  const std::string a_lastName,
			  double a_salary,
			  int a_nCompanies);

	const std::string GetInfo() override;

private:
	int nCompanies;
};

class __declspec(dllexport) CppDeveloper : Developer
{
public:
	CppDeveloper() = delete;
	CppDeveloper(const std::string a_firstName,
				 const std::string a_lastName,
				 double a_salary,
				 const std::string a_university,
				 int a_experience,
				 const std::string ide);

	const std::string GetInfo() override;

private:
	int experience;		// стаж в годах
	std::string ide;	// среда разработки
};

#endif // CLASSES_H
