#include <iostream>
#include <string>

int main(void)
{
	std::string first_name, friend_name, wish;
	int age;

	std::cout << "Enter the name of the person you want to write to : ";
	std::cin >> first_name;
	std::cout << "Enter the name of the friend you want to ralet to : ";
	std::cin >> friend_name;
	std::cout << "Enter the age of the person you want to write to : ";
	std::cin >> age;

	if (age >= 10 && age <= 110) {
		if (age < 12) {
			wish = "Next year you will be ";
			wish += std::to_string(age + 1);
			wish += ".";
		} else if (age == 17) {
			wish = "Next year you will able to vote.";
		} else if (age > 70) {
			wish = "Are you retired ?";
		}
	} else {
		std::cout << "you're kidding !" << std::endl;
	}

	std::cout << "Dear " << first_name << "," << std::endl;
	std::cout << "\t\tHow are doing ? I am fine, I miss you." << std::endl;
	std::cout << "How is your study progessing, hope you are doing your level best." << std::endl;
	std::cout << "Have you seen " << friend_name << " lately ?" << std::endl;
	std::cout << wish << std::endl;
	std::cout << "Hope to hear from you soon!" << std::endl;
	std::cout << "Yours sincerly," << std::endl;
	std::cout << "Thiwanka." << std::endl;
	return(0);
}
