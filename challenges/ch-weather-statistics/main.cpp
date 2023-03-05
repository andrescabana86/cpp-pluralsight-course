//
// Created by andrescabana86 on 4/3/2023.
//

#include <iostream>
#include "WeatherStatistics.h"

int main() {
    std::vector<std::string> listOfFiles {
        "./data/Environmental_Data_Deep_Moor_2012.txt"
    };

    WeatherStatistics weatherStats{listOfFiles};

    return 0;
}