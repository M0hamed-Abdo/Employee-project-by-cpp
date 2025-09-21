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
	Employee(int new_id) {
		id = new_id;
	}
	int get_id() {
		return id;
	}
};
class Teacher : public Employee {
private:
	string subject;
public:
	Teacher(int new_id) : Employee(new_id) {}

	void record_employee() override {
		cout << "Enter Name :";
		cin >> name;
		cout << "Enter Age :";
		cin >> age;
		cout << "Enter Salary :";
		cin >> salary;
		cout << "Enter Subject :";
		cin >> subject;
	}
	void display_employee() override {
		cout << "-----Teacher-----" << endl;
		Employee::display_employee();
		cout << "Subject :" << subject << endl;
	}
};
class Engineer : public Employee {
private:
	string engineer_type;
public:
	Engineer(int new_id) : Employee(new_id) {}
	void record_employee() override {
		cout << "Enter Name :";
		cin >> name;
		cout << "Enter Age :";
		cin >> age;
		cout << "Enter Salary :";
		cin >> salary;
		cout << "Specialization :";
		cin >> engineer_type;
	}
	void display_employee() override {
		cout << "-----Engineer-----" << endl;
		Employee::display_employee();
		cout << "Engineering Specialization :" << engineer_type << endl;
	}
};
class Manager {
private:
vector<Employee*>emp;
public:
bool check_id(int id) {
		for (int i = 0; i < emp.size(); i++) {
			if (emp[i]->get_id() == id) {
				return false;
			}
		}
		return true;
	}
bool employee_empty() {
	if (emp.empty()) {
		cout << "-----No Employee Record-----" << endl;
		return true;
	}
	return false;
}
void add_employee() {
	cout << "\n";
	while (1) {
		int employee_type;
		cout << "[1]Add teacher" << endl;
		cout << "[2]Add Engineer" << endl;
		cout << "[3]Cancel\n" << endl;
		cout << "ENTER TYPE :";
		cin >> employee_type;
		if (employee_type != 1 && employee_type != 2 && employee_type != 3) {
			cout << "woring choiec" << endl;
			continue;
		}
		else if (employee_type == 3) {
			cout << "Cancelled by user "<< endl;
			return;

		}
		int new_id;
		while (true) {
			cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
			cout << "enter id :";
			cin >> new_id;
			if (check_id(new_id) == false) {
				cout << "This ID already used. Please try again." << endl;
				continue;
			}
			break;
		}
		if (employee_type == 1) {
			emp.push_back(new Teacher(new_id));
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			return;
		}
		else if (employee_type == 2) {
			emp.push_back(new Engineer(new_id));
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			return;

		}
	}
}
void add_multi_employee() {
	int employee_count;
	int employee_type;
	while (1) {
	cout << "\n";
	cout << "[1]Add Teacher" << endl;
	cout << "[2]Add Engineer" << endl;
	cout << "[3]Cancel" << endl;
	cout << "\n";
	cout << "ENTER TYPE :";
	cin >> employee_type;
	if (employee_type != 1 && employee_type != 2 && employee_type != 3) {
		cout << "Wrong choice" << endl;
		continue;
	}
	else if (employee_type == 3) {
		cout << "Cancelled by user " << endl;
		return;
	}
	cout << "\n";
	cout << "Enter Employee count:";
	cin >> employee_count;
	int new_id;
	for (int i = 0; i < employee_count;) {
		cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
		cout << "enter id :";
		cin >> new_id;
		if (check_id(new_id) == false) {
			cout << "This ID already used " << endl;
			continue;
		}
		if (employee_type == 1) {
			emp.push_back(new Teacher(new_id));
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			i++;
		}
		else if (employee_type == 2) {
			emp.push_back(new Engineer(new_id));
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			i++;
			}
		}
		return;
	}
}
void search_by_id() {
	if (employee_empty() == true) {
		return;
	}
	int id_search;
	cout << "\n";
	cout << "enter id for search :";
	cin >> id_search;
	for (int i = 0; i < emp.size(); i++) {
		if (id_search == emp[i]->get_id()) {
			emp[i]->display_employee();
			return;
		}
	}
		cout << "Not Found  Employee" << endl;
		return;
}
void update_by_id() {
	if (employee_empty() == true) {
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
	if (employee_empty() == true) {
		return;
	}
	cout << "enter id for Delete:";
	cin >> id_delete;
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i]->get_id() == id_delete) {
			delete emp[i];//
			emp.erase(emp.begin() + i);
			cout << "Employee Deleted Successfully" << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl;
}
void display_all() {
	if (employee_empty() == true) {
		return;
	}
	int display_choice;
	cout << "[1] All teacher" << endl;
	cout << "[2] All Engineer" << endl;
	cout << "[3] All Employee \n" << endl;
	cout << "Enter your choice :";
	cin >> display_choice;
	for (int i = 0; i < emp.size(); i++) {
		if (display_choice == 1) {
			Teacher* teacher = dynamic_cast<Teacher*>(emp[i]);
			if (teacher != nullptr) {
				teacher->display_employee();
			}
		}
		else if (display_choice == 2) {
			Engineer* engineer = dynamic_cast<Engineer*>(emp[i]);
			if (engineer != nullptr) {
				engineer->display_employee();
			}
		}
		else if (display_choice == 3) {
			for (auto emp_ptr : emp) {
				Teacher* teacher = dynamic_cast<Teacher*>(emp_ptr);
				if (teacher != nullptr) {
					teacher->display_employee();
					cout << "------------------" << endl;
				}
			}
			for (auto emp_ptr : emp) {
				Engineer* engineer = dynamic_cast<Engineer*>(emp_ptr);
				if (engineer != nullptr) {
					engineer->display_employee();
					cout << "------------------" << endl;
				}
			}
		}
		else {
			cout << "Wrong choice" << endl;
			return;
		}
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
		cout << "\n";
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
			display_all();
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
};
int main() {
	Manager  manager;
	manager.menue();
}
