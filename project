#include <iostream>
#include <vector>
using namespace std;
class Employee {
protected:
	int id;
	string name;
	int age;
	float salary;
public:
	virtual void record_employee() = 0;
	virtual void display_employee() {
		cout << "ID :" << id << endl;
		cout << "NAME :" << name << endl;
		cout << "AGE :" << age << endl;
		cout << "SALARY :" << salary << endl;
	}
	void set_id(int new_id) {
		id = new_id;
	}
	int get_id() {
		return id;
	}
};
class Teacher : public Employee{
private:
	string subject;
public:
	void record_employee() override{
		cout << "Enter Name :";
		cin >> name;
		cout << "Enter Age :";
		cin >> age;
		cout << "Enter Salary :";
		cin >> salary;
		cout << "Enter Teacher Subject :";
		cin >> subject;
	}
	void display_employee() override{
		Employee::display_employee();
		cout << "Teacher Subject :" << subject << endl;
	}
};
class Engineer : public Employee{
private:
	string engineer_type;
public:
	void record_employee() override {
		cout << "Enter Name :";
		cin >> name;
		cout << "Enter Age :";
		cin >> age;
		cout << "Enter Salary :";
		cin >> salary;
		cout << "Engineering Specialization :";
		cin >> engineer_type;
	}
	void display_employee() override {
		Employee::display_employee();
		cout << "Engineering Specialization :" << engineer_type << endl;
	}
};

vector<Employee*>emp;
bool add_teacher() {
	cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
	int new_id;
	cout << "enter id :";
	cin >> new_id;
	for (int i = 0; i < emp.size(); i++) {
		if (new_id == emp[i]->get_id()) {
			cout << "This ID already used " << endl;
			return false;
		}
	}
	emp.push_back(new Teacher);
	emp.back() ->set_id(new_id);
	emp.back()->record_employee();
	cout << "Done Record" << endl;
	return true;
}
bool add_engineer() {
	cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
	int new_id;
	cout << "enter id :";
	cin >> new_id;
	for (int i = 0; i < emp.size(); i++) {
		if (new_id == emp[i]->get_id()) {
			cout << "This ID already used " << endl;
			return false;
		}
	}
	emp.push_back(new Engineer);
	emp.back()->set_id(new_id);
	emp.back()->record_employee();
	cout << "Done Record" << endl;
	return true;
}

void add_employee() {
	cout << "\n";
	while (1) {
		int employee_type;
		cout << "[1]Add teacher" << endl;
		cout << "[2]Add Engineer" << endl;
		cout << "[3]cancl\n" << endl;
		cout << "ENTER TYPE :";
		cin >> employee_type;
		if (employee_type == 1) {
			add_teacher();
			return;
		}
		else if (employee_type == 2) {
			add_engineer();
			return;

		}
		else if (employee_type == 3) {
			return;
		}
		else {
			cout << "Wrong choice ,try agin" << endl;
		}
	}
}
void add_multi_employee() {
	int employee_count;
	int employee_type;
	cout << "[1]Add Teacher" << endl;
	cout << "[2]Add Engineer" << endl;
	cout << "[3]cancl\n" << endl;
	cout << "ENTER TYPE :";
	cin >> employee_type;  
	cout <<  "\n";
	cout << "Enter Employee count:";
	cin >> employee_count;
	for (int i = 0; i < employee_count;) {
		if(employee_type == 1){
			if (add_teacher() == true) {
				i++;
			}
		}
		else if (employee_type == 2) {
			if (add_engineer() == true) {
			i++;
			}
		}
		else if (employee_type == 3) {
			return;
		}
	}
}

bool employee_list_is_empty() {
	return emp.empty();
}
void search_by_id() {
	if (employee_list_is_empty() == true) {
		cout << "------NO EMPLOYEE RECORD------" << endl;
		return;
	}
	int id_search;
	cout << "enter id for search :";
	cin >> id_search;
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i]->get_id() == id_search) {
			emp[i]->display_employee();
		}
	}
}
void update_by_id() {
	if (employee_list_is_empty() == true) {
		cout << "-----No Employee Record-----" << endl;
		return;
	}
	int id_update;
	cout << "enter id for update :";
	cin >> id_update;
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i]->get_id() == id_update) {
			emp[i]->record_employee();
			cout << "Employee Updated Successfully" << endl;
			return;
		}
	}
	cout << "This ID Not Found" << endl;
}
void delete_employee() {
	int id_delete;
	if (employee_list_is_empty() == true) {
		cout << "-----No Employee Record-----" << endl;
		return;
	}
	cout << "enter id for Delete:";
	cin >> id_delete;
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i]->get_id() == id_delete) {
			delete emp[i];
			emp.erase(emp.begin() + i);
			cout << "Employee Deleted Successfully" << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl;
}
void display_all_teacher() {
	int count_of_teacher = 1;
	if (employee_list_is_empty() == true) {
		cout << "------NO EMPLOYEE RECORD------" << endl;
	}
	else {
		for (auto type_emp : emp) {
			Teacher* teacher = dynamic_cast <Teacher*>(type_emp);
			if (teacher != nullptr) {
				cout << "-----Teacher #" << count_of_teacher++ << "-----" << endl;
				teacher->display_employee();
				cout << "----------------" << endl;
			}
		}
	}
}
void display_all_engineer() {
	int count_of_engineer = 1;
	if (employee_list_is_empty() == true) {
		cout << "------NO EMPLOYEE RECORD------" << endl;
	}
	else {
		for (auto type_emp : emp) {
			Engineer* engineer = dynamic_cast <Engineer*>(type_emp);
			if (engineer != nullptr) {
				cout << "-----Engineer #" << count_of_engineer++ << "-----" << endl;
				engineer->display_employee();
				cout << "----------------" << endl;
			}
		}
	}
}
void display_all_employee() {
	int display_choice;
	if (emp.size() == 0) {
		cout << "------NO EMPLOYEE RECORD------" << endl;
		return;
	}
	cout << "[1] All teacher" << endl;
	cout << "[2] All Engineer" << endl;
	cout << "[3] All Employee \n" << endl;
	cout << "Enter your choice :";
	cin >> display_choice;
	if (display_choice == 1) {
		display_all_teacher();
	}
	else if (display_choice == 2) {
		display_all_engineer();
	}
	else if (display_choice == 3) {
		cout << "   Teachers Section" << endl;
		display_all_teacher();
		cout << "\n";
		cout << "   Engineering Section" << endl;
		display_all_engineer();
		cout << "\n";
	}
	else {
		cout << "Woring choice " << endl;
		return;
	}
}
void menue() {
	int choice;
	while (1) {
		cout << "\n";
		cout << "====Main Menu====" << endl;
		cout << "[1] Add Employee" << endl;
		cout << "[2] Add Multi Employee" << endl;
		cout << "[3] Update by ID" << endl;
		cout << "[4] Delete Employee" << endl;
		cout << "[5] search by ID" << endl;
		cout << "[6] Display All Employee" << endl;
		cout << "[0] Exit" << endl;
		cout << "Enter your choice :";
		cin >> choice;

		switch (choice) {
		case 1:
			add_employee();
			break;
		case 2:
			add_multi_employee();
			break;
		case 3:
			update_by_id();
			break;
		case 4:
			delete_employee();
			break;
		case 5:
			search_by_id();
			break;
		case 6:
			display_all_employee();
			break;
		case 0:
			cout << "Exiting....." << endl;
			exit(0);
		default:
			cout << "the woring type" << endl;
			break;
		}
	}
}
int main() {
	menue();
}
