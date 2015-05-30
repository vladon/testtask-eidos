#pragma once

#ifndef CLASSES_H
#define CLASSES_H

#include <map>

class Employee
{
public:
	enum class Position
	{
		Mounter,		// ���������
		Electronician,	// �����������
		Developer,		// �����������
		Economist,		// ���������
		CppDeveloper	// ����������� C++
	};

public:
	Employee() = delete;

	virtual const std::string GetInfo();
	virtual double GetSalary();

protected:
	static const std::map<Position, const std::string> PositionNames;

	Employee(const std::string a_firstName, const std::string a_lastName, const Position a_position, double a_salary);


	std::string firstName;
	std::string lastName;
	Position position;
	double salary;
};

class Mounter : public Employee
{
public:
	enum class MountingDepartment
	{
		Workshop,	// ���
		Warehouse	// �����
	};
	static const std::map<MountingDepartment, const std::string> MountingDepartmentNames;

	Mounter() = delete;
	Mounter(const std::string a_firstName, const std::string a_lastName, double a_salary, MountingDepartment a_mountingDepartment);

	const std::string GetInfo() override;

private:
	MountingDepartment mountingDepartment;
};

class Electronician : public Employee
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

class Developer : public Employee
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

class Economist : public Employee
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

class CppDeveloper : public Developer
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
	int experience;		// ���� � �����
	std::string ide;	// ����� ����������
};

#endif // CLASSES_H
