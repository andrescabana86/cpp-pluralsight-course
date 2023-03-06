//
// Created by andrescabana86 on 4/3/2023.
//
#include <iostream>
#include "WeatherStatistic.h"

int main() {
    std::vector<std::string> listOfFiles{
            "./data/Environmental_Data_Deep_Moor_2012.txt",
            "./data/Environmental_Data_Deep_Moor_2013.txt",
            "./data/Environmental_Data_Deep_Moor_2014.txt",
            "./data/Environmental_Data_Deep_Moor_2015.txt",
    };

    // request start date/time from user
    /*
    std::string startDate, startTime;
    std::cout << std::endl << "Enter START DATE as yyyy_mm_dd: ";
    std::cin >> startDate;
    std::cout << "Enter START TIME as hh:mm:ss (24-hour): ";
    std::cin >> startTime;
    */
    WeatherStatistic weatherStats{listOfFiles};

    return 0;
}