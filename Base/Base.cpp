// Base.cpp : Defines the exported functions for the DLL application.
//

#include "Base_stdafx.h"

#include "Base.h"

EmployeeBase::EmployeeBase()
{

}

void EmployeeBase::FillBaseWithTestData()
{
	base.clear();
	base.reserve(10);

	base.emplace_back(
		new Mounter(
			"Ivan", 
			"Ivanov", 
			100.0, 
			Mounter::MountingDepartment::Warehouse
		)
	);

	base.emplace_back(
		new Electronician(
			"Petr", 
			"Petrov", 
			101.0, 
			{ 
				{ Electronician::OhmLaw::OhmLaw1, true }
			}
		)
	);

	base.emplace_back(
		new Developer(
			"Sidor",
			"Sidorov",
			102.0,
			"Python",
			"Kazan Federal University"
		)
	);

	base.emplace_back(
		new Economist(
			"Nastya",
			"Nastina",
			103.0,
			5
		)
	);


	//base.emplace_back(
	//	new CppDeveloper(
	//			"Mihail",
	//			"Mihaylov",
	//			104.0,
	//			"Moscow State University",
	//			3,
	//			"Visual Studio"
	//	)
	//);
}
