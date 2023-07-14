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

    // taking user input

    int choice = 1;

    while (choice) {

        std::cout << "Type in 1-6: ";
        std::cin >> user_option;
        std::cout << "Your choice: " << user_option << std::endl;

        switch (user_option) {
            case 1:
                std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
                break;
            case 2:
                std::cout << "Market looks good." << std::endl;
                break;
            case 3:
                std::cout << "Mark and offer - enter the amount." << std::endl;
                break;
            case 4:
                std::cout << "Make a bid - enter the amount." << std::endl;
                break;
            case 5:
                std::cout << "Your wallet is empty." << std::endl;
                break;
            case 6:
                std::cout << "Going to next time frame." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Choose from 1-6." << std::endl;
                break;
        }

        std::cout << "Enter 0 to exit or 1 to continue: ";
        std::cin >> choice;

        if (choice == 0)
            std::cout << "Exiting!!" << std::endl;
    }

    return 0;
}
