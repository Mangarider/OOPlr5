#pragma once
#include<iostream>
#include<memory>

using namespace std;

class Msg {
protected:
	string msg = "";
public:
	virtual string print_hello() {
		cout << "virtual method of base class\n";
		return "hello!";
	}
	void setMsg(string new_msg) {
		cout << "default method of base class\n";
		msg = new_msg;
	}
	virtual ~Msg() {
		cout << typeid(this).name() << " : destructor\n";
	}
};

class BracketsMsg : public Msg {
public:
	string print_hello() override {
		cout << "overrided method of child class\n";
		return "(" + Msg::print_hello() + ")";
	}
	void setMsg(string new_msg) {
		cout << "inherited method of child class\n";
		msg = "(" + new_msg + ")";
	}
	~BracketsMsg() {
		cout << typeid(this).name() << " : destructor\n";
	}
};


void overrided_and_inherited() {
	BracketsMsg br_msg;
	br_msg.Msg::print_hello();
	br_msg.print_hello();
	br_msg.Msg::setMsg("1");
	br_msg.setMsg("1");
}

void definition_virtual() {
	{
		Msg* msg = new BracketsMsg();
		cout << msg->print_hello() << '\n';
	}
	cout << "------------\n";
	{
		Msg* msg_p = new BracketsMsg();

		delete msg_p;
	}
}

void smart_pointers() {
	unique_ptr<int> unqObj = make_unique<int>();
	unique_ptr<int> unqObj2(move(unqObj));
	cout << unqObj << '\n' << unqObj2.get() << '\n';
	cout << '\n';

	shared_ptr<int> shrdObj(new int());
	shared_ptr<int> shrdObj2 = shrdObj;
	cout << shrdObj << '\n' << shrdObj2.get() << '\n';
	shrdObj.reset();
	cout << '\n';
	cout << shrdObj << '\n' << shrdObj2.get() << '\n';
}