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
	static int generate_id() {
        static int id_count = 200;
        return id_count++;
    }
	Employee() {
		id = generate_id();
	}
	virtual void record_employee() = 0;
	virtual void display_employee() {
		cout << "ID :" << id << endl;
		cout << "NAME :" << name << endl;
		cout << "AGE :" << age << endl;
		cout << "SALARY :" << salary << endl;
	}
	int get_id() {
		return id;
	}
};
class Student{
private:
    string name;
    int age;
public:
    void record_student(){
        cout << "enter Student name:";
        cin >> name;
        cout << "enter your age:";
        cin >> age;
    }
    void display_student(){
        cout << "Student name :" << name << endl;
        cout << "Student age :" << age << endl;
    }
    
};
class Teacher : public Employee {
private:
	string subject;
    vector<Student*>student;
public:
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
	    cout << "--- Students ---" << endl;
	    for(int i=0;i<student.size();i++){
	        student[i]->display_student();
	    }
	}
	void add_student(){
	    student.push_back(new Student());
        student.back()->record_student();
        cout << "Student added successfully!" << endl;
	}
};
class Engineer : public Employee {
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
		cout << "Specialization :";
		cin >> engineer_type;
	}
	void display_employee() override {
		cout << "-----Engineer-----" << endl;
		Employee::display_employee();
		cout << "Engineering Specialization :" << engineer_type << endl;
	}
};
class Employee_Manager {
private:
int teacher_count = 0;
int engineer_count = 0;
vector<Employee*>emp;
public:
void add_employee() {
	cout << "\n";
	while (1) {
		int employee_type;
		cout << "[1]Add Teacher" << endl;
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
			cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
		if (employee_type == 1) {
			emp.push_back(new Teacher());
			emp.back()->record_employee();
			teacher_count ++;
			cout << "DONE RECORD" << endl;
			return;
		}else if(employee_type == 2){
		    emp.push_back(new Engineer());
		    emp.back()->record_employee();
		    engineer_count ++;
		    cout << "DONE RECORD" << endl;
			return;
		}
	}
}
void add_multi_employee() {
    int  employee_count , employee_type;
    while (1){
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
	for (int i = 0; i < employee_count;) {
		cout << "------RECORD #" << emp.size() + 1 << "------" << endl;
		if (employee_type == 1) {
			emp.push_back(new Teacher());
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			i++;
		}
		else if (employee_type == 2) {
			emp.push_back(new Engineer());
			emp.back()->record_employee();
			cout << "Done Record" << endl;
			i++;
			}
		}
		return;
    }
}
void search_by_id() {
    if (emp.empty()) {
        cout << "NO EMPLOYEE RECORD" << endl;
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
    if (emp.empty()) {
        cout << "NO EMPLOYEE RECORD" << endl;
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
    if (emp.empty()) {
        cout << "NO EMPLOYEE RECORD" << endl;
        return;
    }
    int id_delete;
    cout << "Enter ID for delete: ";
    cin >> id_delete;
    for (int i = 0; i < emp.size(); i++) {
        if (emp[i]->get_id() == id_delete) {
            if (dynamic_cast<Teacher*>(emp[i])) teacher_count--;
            if (dynamic_cast<Engineer*>(emp[i])) engineer_count--;
            delete emp[i];
            emp.erase(emp.begin() + i);
            cout << "Employee Deleted Successfully" << endl;
            return;
        }
    }
    cout << "ID Not Found" << endl;
}
void display_all() {
    int display_choice;
    cout << "[1] All teacher" << endl;
    cout << "[2] All Engineer" << endl;
    cout << "Enter your choice :";
    cin >> display_choice;

    if (display_choice == 1) {
        if (teacher_count == 0) {
            cout << "No RECORD Teacher" << endl;
            return;
        }
        cout << "Total Teachers [" << teacher_count << "]" << endl;
        for (int i = 0; i < emp.size(); i++) {
            Teacher* teacher = dynamic_cast<Teacher*>(emp[i]);
            if (teacher != nullptr) {
                teacher->display_employee();
            }
        }
    }
    else if (display_choice == 2) {
        if (engineer_count == 0) {
            cout << "No RECORD Engineer" << endl;
            return;
        }
        cout << "Total Engineers [" << engineer_count << "]" << endl;
        for (int i = 0; i < emp.size(); i++) {
            Engineer* engineer = dynamic_cast<Engineer*>(emp[i]);
            if (engineer != nullptr) {
                engineer->display_employee();
            }
        }
    }
    else {
        cout << "Wrong choice" << endl;
    }
}
void add_student_to_teacher() {
    if(teacher_count == 0){
        cout << "NO TEACHER RECORD" << endl;
        return;
    }
    int teacher_id;
    cout << "Enter Teacher ID to add student: ";
    cin >> teacher_id;
    for (int i = 0; i < emp.size(); i++) {
        Teacher* teacher = dynamic_cast<Teacher*>(emp[i]);
        if (teacher->get_id() == teacher_id) {
            teacher->add_student();
            return;
        }
    }
    cout << "Teacher not found!" << endl;
}

void menu() {

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
		cout << "[7] Add Student to Teacher" << endl;
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
 		case 7:
 			add_student_to_teacher();
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
	Employee_Manager  manager;
	manager.menu();
}
