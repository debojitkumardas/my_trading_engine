#include <iostream>

int main(void) {

    // 1 print help
    std::cout << "1. Print help " << std::endl;

    // 2 print exchange stat
    std::cout << "2. Print exchange stats " << std::endl;

    // 3 make an offer
    std::cout << "3. Make an offer " << std::endl;

    // 4 make a build
    std::cout << "4. Make a bid " << std::endl;

    // 5 print wallet
    std::cout << "5. Print wallet " << std::endl;

    // 6 continue
    std::cout << "6. Continue " << std::endl;

    std::cout << "=====================" << std::endl;

    int user_option = 0;

    std::cout << "Type in 1-6: ";
    std::cin >> user_option;
    std::cout << "Your choice: " << user_option << std::endl;

    return 0;
}
