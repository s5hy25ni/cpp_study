#include <iostream>

/* class 
class Animal {
private:
	int food;
	int weight;

	void increase_weight(int inc) {
		weight += (inc / 3);
	}

public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		increase_weight(inc);
	}
	void view_stat() {
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};

int main() {
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}
*/

/* think  */

int input_year, input_month, input_day, select_num;

void input_not_int() {
	std::cout << std::endl;
	std::cout << "정수만 입력하세요." << std::endl;
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
}
void get_input_year() {
	std::cout << "연도 : ";
	std::cin >> input_year;
}
void get_input_month() {
	std::cout << "월 : ";
	std::cin >> input_month;
}
void get_input_day() {
	std::cout << "일 : ";
	std::cin >> input_day;
	std::cout << std::endl;
}

int cheak_leap(int year) {
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
		return 1;
	}
	else if (year % 4 == 0 && year % 100 == 0) {
		return 0;
	}
	else if (year % 4 == 0) {
		return 1;
	}
	else return 0;
}

void get_input_date() {
	for (;;) {
		get_input_year();
		if (std::cin.fail()) {
			input_not_int();
		}
		else if (input_year <= 0) {
			std::cout << "0 이상의 정수를 입력하세요." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	for (;;) {
		get_input_month();
		if (std::cin.fail()) {
			input_not_int();
		}
		else if (input_month < 1 || input_month>12) {
			std::cout << "1과 12 사이의 정수를 입력하세요." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	for (;;) {
		int input_end = 1;
		get_input_day();
		if (std::cin.fail()) {
			input_not_int();
		}
		else {
			switch (input_month) {
			case 2:
				if (cheak_leap(input_year)) { // 윤년이면
					if (1 > input_day || 29 < input_day) {
						std::cout << "윤년입니다. 1과 29 사이의 정수를 입력하세요." << std::endl;
						std::cout << std::endl;
						input_end = 0;
					}
				}
				else { // 평년이면
					if (1 > input_day || 28 < input_day) {
						std::cout << "평년입니다. 1과 28 사이의 정수를 입력하세요." << std::endl;
						std::cout << std::endl;
						input_end = 0;
					}
				}
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (1 > input_day || 30 < input_day) {
					std::cout << "1과 30 사이의 정수를 입력하세요." << std::endl;
					std::cout << std::endl;
					input_end = 0;
				};
				break;

			default:
				if (1 > input_day || 31 < input_day) {
					std::cout << "1과 31 사이의 정수를 입력하세요." << std::endl;
					std::cout << std::endl;
					input_end = 0;
				};
				break;
			}
		}
		if (input_end) break;
	}
}

class Date {
	int year_;
	int month_; // 1부터 12까지
	int day_; // 1부터 31까지

	int cal_month;
	int cal_day;
	int cal_end;

public:
	void SetDate(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	};
	void AddDay(int inc) {
		AddYear(inc / 365);
		inc %= 365;
		cal_day = day_ + inc;
		for (;;) {
			cal_end = 1;
			switch (month_) {
			case 2:
				if (cheak_leap(year_)) {
					if (cal_day <= 29) {
						day_ = cal_day;
					}
					else {
						cal_day -= 29;
						AddMonth(1);
						cal_end = 0;
					}
				}
				else {
					if (cal_day <= 28) {
						day_ = cal_day;
					}
					else {
						cal_day -= 28;
						AddMonth(1);
						cal_end = 0;
					}
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (cal_day <= 30) {
					day_ = cal_day;
				}
				else {
					cal_day -= 30;
					AddMonth(1);
					cal_end = 0;
				}
				break;
			default:
				if (cal_day <= 31) {
					day_ = cal_day;
				}
				else {
					cal_day -= 31;
					AddMonth(1);
					cal_end = 0;
				}
				break;
			}
			if (cal_end) break;
		}
	};
	void AddMonth(int inc) {
		AddYear(inc / 12);
		inc %= 12;
		cal_month = month_ + inc;
		if (cal_month <= 12) month_ = cal_month;
		else {
			AddYear(1);
			month_ = cal_month - 12;
		}
	};
	void AddYear(int inc) {
		year_ += inc;
	};

	void ShowDate() {
		std::cout << "현재 날짜는 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << std::endl;
		std::cout << std::endl;
	}
};

int main() {

	Date currentDate;
	int plus_num;

	std::cout << "=============== 날짜를 입력해주세요. ===============" << std::endl;
	std::cout << std::endl;
	get_input_date();
	currentDate.SetDate(input_year, input_month, input_day);

	for (;;) {
		std::cout << std::endl;
		std::cout << "=============== 원하는 기능을 선택하세요. ===============" << std::endl;
		std::cout << std::endl;
		currentDate.ShowDate();
		std::cout << "1. 현재 날짜 바꾸기" << std::endl;
		std::cout << "2. 연도 더하기" << std::endl;
		std::cout << "3. 월 더하기" << std::endl;
		std::cout << "4. 일 더하기" << std::endl;
		std::cout << "0. 끝내기" << std::endl;
		std::cout << std::endl;
		std::cout << "선택 : ";
		std::cin >> select_num;
		std::cout << std::endl;

		if (std::cin.fail()) {
			input_not_int();
			continue;
		}

		switch (select_num) {
			case 1:
				std::cout << "=============== [ 1. 현재 날짜 바꾸기 ] ===============" << std::endl;
				std::cout << std::endl;
				get_input_date();
				currentDate.SetDate(input_year, input_month, input_day);
				continue;

			case 2:
				std::cout << "=============== [ 2. 연도 더하기 ] ===============" << std::endl;
				std::cout << std::endl;
				std::cout << "더하고 싶은 연수를 입력하세요. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					input_not_int();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl;
					std::cout << std::endl;
					continue;
				}
				currentDate.AddYear(plus_num);
				continue;

			case 3:
				std::cout << "=============== [ 3. 월 더하기 ] ===============" << std::endl;
				std::cout << std::endl;
				std::cout << "더하고 싶은 개월수를 입력하세요. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					input_not_int();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl;
					std::cout << std::endl;
					continue;
				}
				currentDate.AddMonth(plus_num);
				continue;

			case 4:
				std::cout << "=============== [ 4. 일 더하기 ] ===============" << std::endl;
				std::cout << std::endl;
				std::cout << "더하고 싶은 일수를 입력하세요. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					input_not_int();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl;
					std::cout << std::endl;
					continue;
				}
				currentDate.AddDay(plus_num);
				continue;

			case 0:
				std::cout << "=============== 프로그램을 종료합니다. ===============" << std::endl;
				break;

			default:
				std::cout << "0~4번 중에 선택하세요." << std::endl;
				std::cout << std::endl;
				continue;
		}
		break;
	}
}

