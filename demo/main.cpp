#include <iostream>
#include <list>

/** prints the menu has six of them
 *  Its pretty cool */
void print_menu() {
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

}

int get_user_option() {

    int user_option = 0;
    std::cout << "Type in 1-6: ";
    std::cin >> user_option;
    std::cout << "You choose: " << user_option << std::endl;

    return user_option;
}

void print_help() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void print_market_stats() {
    std::cout << "Market looks good." << std::endl;
}

void enter_offer() {
    std::cout << "Mark and offer - enter the amount." << std::endl;
}

void enter_bid() {
    std::cout << "Make a bid - enter the amount." << std::endl;
}

void print_wallet() {
    std::cout << "your wallet is empty." << std::endl;
}

void goto_next_time_frame() {
    std::cout << "Going to next time frame." << std::endl;
}

void process_user_option(int user_option) {

    if (user_option == 0) {
        std::cout << "Invalid choice. Choose from 1-6." << std::endl;
    }
    if (user_option == 1) {
        print_help();
    }
    if (user_option == 2) {
        print_market_stats();
    }
    if (user_option == 3) {
        enter_offer();
    }
    if (user_option == 4) {
        enter_bid();
    }
    if (user_option == 5) {
        print_wallet();
    }
    if (user_option == 6) {
        goto_next_time_frame();
    }
}

int main(void) {

    int user_option = 0;
    int choice = 1;

    print_menu();

    // looping the menu
    while (choice != 0) {

        // taking user input
        user_option = get_user_option();

        // processing the user input
        process_user_option(user_option);

        // prompting the user to check if they want to continue
        std::cout << "Do you want to continue (1: yes; 0: no): ";
        std::cin >> choice;
    }

    return 0;
}
