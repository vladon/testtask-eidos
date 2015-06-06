// Test.cpp : Defines the entry point for the console application.
//

#include "Test_stdafx.h"

#include "../Classes/Classes.h"
#include "../Base/Base.h"

void printAllEmployees(std::shared_ptr<EmployeeBase> employeeBase)
{
	for (auto kv : employeeBase->base) {
		std::cout << kv->GetInfo() << std::endl << "-----------" << std::endl << std::endl;
	}
}

void printAllSalaries(std::shared_ptr<EmployeeBase> employeeBase)
{
	for (auto kv : employeeBase->base) {
		std::cout << kv->GetSalary() << std::endl << "-----------" << std::endl << std::endl;
	}
}

void printAllSalariesAscending(std::shared_ptr<EmployeeBase> employeeBase)
{
	std::vector<double> salaries;

	for (auto kv : employeeBase->base) {
		salaries.push_back(kv->GetSalary());
	}

	std::sort(salaries.begin(), salaries.end(), std::less<double>());

	for (auto kv : salaries) {
		std::cout << kv << std::endl;
	}
}

void printAllSalariesDescending(std::shared_ptr<EmployeeBase> employeeBase)
{
	std::vector<double> salaries;

	for (auto kv : employeeBase->base) {
		salaries.push_back(kv->GetSalary());
	}

	std::sort(salaries.begin(), salaries.end(), std::greater<double>());

	for (auto kv : salaries) {
		std::cout << kv << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::shared_ptr<EmployeeBase> employeeBase = std::make_shared<EmployeeBase>();
	employeeBase->FillBaseWithTestData();


	// Key scan loop for Windows only
	HANDLE stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);

	DWORD events = 0;
	DWORD eventsRead = 0;

	std::cout <<
		"Usage:\n" <<
		"\ta-z\t- prints all employees info\n" <<
		"\t1-9\t- prints all employees salaries\n" <<
		"\t+\t- prints all salaries in ascending order\n" <<
		"\t-\t- prints all salaries in descending order\n" <<
		"\tEnter\t- quit\n";

	bool isRunning = true;

	while (isRunning) {
		if (GetNumberOfConsoleInputEvents(stdInputHandle, &events) != 0) {

			if (events != 0) {
				INPUT_RECORD inputRecord;

				for (DWORD i = 0; i < events; ++i) {
					ReadConsoleInput(stdInputHandle, &inputRecord, 1, &eventsRead);

					if ((inputRecord.EventType == KEY_EVENT) && (inputRecord.Event.KeyEvent.bKeyDown)) {
						WORD virtualKeyCode = inputRecord.Event.KeyEvent.wVirtualKeyCode;

						// std::cout << virtualKeyCode << std::endl;

						// virtual key codes from https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
#						define KEY_A 0x41
#						define KEY_Z 0x5A
#						define KEY_0 0x30
#						define KEY_9 0x39

						if ((virtualKeyCode >= KEY_A) && (virtualKeyCode <= KEY_Z)) {
							printAllEmployees(employeeBase);
						}
						else if (((virtualKeyCode >= KEY_0) && (virtualKeyCode <= KEY_9)) || ((virtualKeyCode >= VK_NUMPAD0) && (virtualKeyCode <= VK_NUMPAD9))) {
							printAllSalaries(employeeBase);
						}
						else if ((virtualKeyCode == VK_OEM_PLUS) || (virtualKeyCode == VK_ADD)) {
							printAllSalariesAscending(employeeBase);
						}
						else if ((virtualKeyCode == VK_OEM_MINUS) || (virtualKeyCode == VK_SUBTRACT)) {
							printAllSalariesDescending(employeeBase);
						}
						else if ((virtualKeyCode == VK_RETURN)) {
							isRunning = false;
						}
					}
				}
			}
		}
		else {
			std::cerr << "Error occured: " << GetLastError() << std::endl;
			isRunning = false;
		}
	}

	return 0;
}

