//
// Created by andrescabana86 on 4/3/2023.
//

#include <iostream>
#include "WeatherStatistic.h"

int main() {
    std::vector<std::string> listOfFiles {
        "./data/Environmental_Data_Deep_Moor_2012.txt"
    };

    WeatherStatistic weatherStats{listOfFiles};

    return 0;
}