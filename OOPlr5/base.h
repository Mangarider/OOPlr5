#pragma once
#include <iostream>
#include <typeinfo>
#include <memory>

using namespace std;


class Base {
public:
	Base() {
		cout << typeid(this).name() << " : default constuctor \n";
	};
	Base(Base* obj) {
		cout << typeid(this).name() << " : copy constuctor * \n";
	};
	Base(const Base& obj) {
		cout << typeid(this).name() << " : copy constuctor & \n";
	};
	Base(const Base&& obj) = delete;
	~Base() {
		cout << typeid(this).name() << " : destructor" << '\n';
	};
};

class Desc : public Base {
public:
	Desc() {
		cout << typeid(this).name() << " : default constuctor \n";
	};
	Desc(Base* obj) {
		cout << typeid(this).name() << " : copy constuctor * \n";
	};
	Desc(const Base& obj) {
		cout << typeid(this).name() << " : copy constuctor & \n";
	};
	~Desc() {
		cout << typeid(this).name() << " : destructor" << '\n';
	};
};

void func1(Base obj) {
	cout << "func1(Base obj)\n";
}

void func2(Base* obj) {
	cout << "func2(Base* obj)\n";
}

void func3(Base& obj) {
	cout << "func3(Base& obj)\n";
}

/*Base func1() {
	cout << "Base func1()\n";
	Base obj;
	return obj;
}*/
// ������ ������� ��������� ��������� ������. 
// ��� ������ ������������ ����������� ���� ��������� ������ ���������� � ����������� ��� �� ������,
// � ��������� ������ ���������.

Base func2() {
	cout << "Base func2()\n";
	Base* obj = new Base();
	return *obj;
}
// ����������� ��������� ������. 
// ������������� ����������� ���������� � ����������� ������ � ���������� ����� �� �������. 
// ����������� ��������� ������ �������� ������, ������� ����� �� ������ ����������
Base* func3() {
	cout << "Base* func3()\n";
	Base obj;
	return &obj;
}
// ��������� ��������� ������. ����� ������� �� ������� ��������� ������ ������������.
// � ����������� ������ ������������ ����� ���������� �������, ������� ���������.
// ����� ������� ���������� � ��������� ��� ������� ������� ������� ���� ���������� ��� ��������������� ���������.

unique_ptr<Base> func4() {
	cout << "Base* func4()\n";
	unique_ptr<Base> unqObj(new Base());
	return unqObj;
}
// ��������� ��������� ������ � ��� ����� ������������ � ���������� � ����������� ������.
// ������������� ������ ������.
Base& func5() {
	cout << "Base& func5()\n";
	Base obj;
	return obj;
}
// ��������� ������. ����� ������� �� ������� ���� ������ ������������, �� ��� �������� ����������� ����� ��� obj5.
// ����� ������� ���������� � ��������� ��� ������� ������� ������� ���� ���������� ��� ��������������� ���������.

Base& func6() {
	cout << "Base& func6\n";
	Base* obj = new Base();
	return *obj;
}
// ��������� ������. ��� ��� ����������� ������ obj6 ����� ������ �� �������.
// ������������� ������ ������. (delete &obj6)
void base() {

}