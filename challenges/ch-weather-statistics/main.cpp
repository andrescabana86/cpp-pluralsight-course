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
    WeatherStatistic weatherStats{listOfFiles};

    std::string startDate, startTime;
    std::cout << std::endl << "Enter START DATE as yyyy_mm_dd: ";
    std::cin >> startDate;
    std::cout << "Enter START TIME as hh:mm:ss (24-hour): ";
    std::cin >> startTime;

    if (!weatherStats.IsValidDateTime(startDate, startTime)) {
        return 1;
    }

    // request end date/time from user
    std::string endDate, endTime;
    std::cout << "Enter END DATE as yyyy_mm_dd: ";
    std::cin >> endDate;
    std::cout << "Enter END TIME as hh:mm:ss (24-hour): ";
    std::cin >> endTime;

    if (!weatherStats.IsValidDateTime(endDate, endTime)) {
        return 1;
    }

    std::optional<double> coeff = weatherStats.computeCoefficient(startDate, startTime, endDate, endTime);
    if (!coeff.has_value()) {
        std::cerr << "ERROR: something went wrong!" << std::endl;
        exit(1);
    }

    std::cout << std::endl << "Coefficient: " << coeff * 24 * 60 * 60 << " inHg/day" << std::endl;
    // determine if it's sunny or stormy
    if (coeff < 0) {
        std::cout << "Stormy conditions... Looks like you might need an umbrella!" << std::endl;
    } else {
        std::cout << "Sunny conditions... Don't forget your sunscreen!" << std::endl;
    }

    return 0;
}