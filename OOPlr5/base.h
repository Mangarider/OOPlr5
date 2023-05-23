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
// Внутри функции создается локальный обьект. 
// При помощи конструктора копирования этот локальный обьект копируется в создаваемый тут же обьект,
// а локальный обьект удаляется.

Base func2() {
	cout << "Base func2()\n";
	Base* obj = new Base();
	return *obj;
}
// Динамически создается обьект. 
// Конструктором копирования копируется в создаваемый обьект и происходит выход из функции. 
// Динамически созданный обьект занимает память, которую никто не сможет освободить
Base* func3() {
	cout << "Base* func3()\n";
	Base obj;
	return &obj;
}
// Создается локальный обьект. Перед выходом из функции локальный обьект уничтожается.
// В создаваемый обьект возвращается адрес локального обьекта, который уничтожен.
// Любая попытка обратиться к свойствам или методам обьекта вызовет краш программмы или непредсказуемое поведение.

unique_ptr<Base> func4() {
	cout << "Base* func4()\n";
	unique_ptr<Base> unqObj(new Base());
	return unqObj;
}
// Создается локальный обьект и его адрес возвращается и помещается в создаваемый обьект.
// Потенциальная утечка памяти.
Base& func5() {
	cout << "Base& func5()\n";
	Base obj;
	return obj;
}
// Создается обьект. Перед выходом из функции этот обьект уничтожается, но ему успевает назанчиться новон имя obj5.
// Любая попытка обратиться к свойствам или методам обьекта вызовет краш программмы или непредсказуемое поведение.

Base& func6() {
	cout << "Base& func6\n";
	Base* obj = new Base();
	return *obj;
}
// Создается обьект. Его имя назначается ссылке obj6 после выхода из функции.
// Потенциальная утечка памяти. (delete &obj6)
void base() {

}