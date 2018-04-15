#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stack>
#include <iomanip>


/**
 * Number of Naps problem main file
 * @return
 */
void print_tuple_info(std::vector<std::tuple<int,int,std::string>> abcd) {

    for(std::iterator i = abcd.begin(); i != abcd.end();++i) {
        std::cout << std::get<0>(abcd.at(i));
        std::cout << std::get<1>(abcd.at(i));
        std::cout << std::get<2>(abcd.at(i));
    }
}


int main() {

    int number_of_scheduled_appointments;

    // First the user input the number of cases for that day
    typedef std::vector<std::tuple<int,int,std::string>> appointment_information;


    do {
        std::cin >> number_of_scheduled_appointments;
        appointment_information k;

        for (int i = 0; i < number_of_scheduled_appointments; ++i) {
            std::string t1, t2, app_info;

            std::cin>>t1;
            std::cin>>t2;
            std::cin>>app_info;
            int one = std::stoi(t1);
            int two = std::stoi(t2);
            /*
             * Sudo code
             * first take in user inpt
             * convert both of the strings of integers into a
             */
            k.push_back(std::tuple<int,int,std::string>(one,two,app_info));
            print_tuple_info(k);
        }

        k.clear();
    }while(number_of_scheduled_appointments != -1);


    return 0;
}