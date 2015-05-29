class __declspec(dllexport) EmployeeBase
{
public:
	EmployeeBase();

	void FillBaseWithTestData();

	std::vector<std::shared_ptr<Employee>> base;
};
