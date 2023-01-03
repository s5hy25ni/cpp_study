#include <iostream>
#include <string>

//class Base {
//public:
//	Base() { std::cout << "기반 클래스" << std:: endl; }
//	virtual void what() { std::cout << "기반 클래스의 what()" << std:: endl; }
//};
//
//class Derived : public Base {
//public:
//	Derived() : Base() { std::cout << "파생 클래스" << std::endl; }
//	void what() { std::cout << "파생 클래스의 what()" << std::endl; }
//};
//
//int main() {
//	Base p;
//	Derived c;
//
//	Base* p_c = &c;
//	Base* p_p = &p;
//
//	std::cout << "== 실제 객체는 Base ==" << std::endl;
//	p_p->what();
//
//	std::cout << "== 실제 객체는 Derived ==" << std::endl;
//	p_c->what();
//
//	return 0;
//}

//class Base {
//	std::string s;
//
//public:
//	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
//
//	void what() { std::cout << s << std::endl; }
//};
//class Derived : public Base {
//	std::string s;
//
//public:
//	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }
//
//	void what() { std::cout << s << std::endl; }
//};
//int main() {
//	Base p;
//	Derived c;
//
//	std::cout << "=== 포인터 버전 ===" << std::endl;
//	Base* p_c = &c;
//	p_c->what();
//
//	return 0;
//}

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std:: endl; }
	void what() override { std::cout << s << std::endl; }
};