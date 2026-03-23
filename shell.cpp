#include <iostream>

int main(){

    while(1){
        std::string text;
        std::cout << "basic > " ;

        std::getline(std::cin, text);
        std::cout << text << '\n';
    }

    return 0;
}