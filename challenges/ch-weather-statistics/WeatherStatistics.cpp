#include "WeatherStatistics.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>

WeatherStat::WeatherStat() {};

WeatherStat::WeatherStat(int y, int m, int d, int h, int min, int sec)
        : year(y), month(m), day(d), hour(h), minute(min), second(sec) {
    // Set the dateTime and utcTime members based on the year, month, day, hour, minute, and seconds
    dateTime.tm_year = year - 1900;  // Years since 1900
    dateTime.tm_mon = month - 1;     // Months since January (0-based)
    dateTime.tm_mday = day;          // Day of the month (1-based)
    dateTime.tm_hour = hour;         // Hours since midnight (0-23)
    dateTime.tm_min = minute;        // Minutes after the hour (0-59)
    dateTime.tm_sec = second;        // Seconds after the minute (0-60)
    // Compute the UTC time based on the local time
    utcTime = mktime(&dateTime);
}

WeatherStatistics::WeatherStatistics() {};

WeatherStatistics::WeatherStatistics(std::vector<std::string> listOfFilesLocations) {
    LoadFiles(listOfFilesLocations);
}

void WeatherStatistics::LoadFiles(std::vector<std::string> listOfFilesLocations) {
    for (std::string fileLoc : listOfFilesLocations) {
        LoadDataFromFile(fileLoc);
    }
}

void WeatherStatistics::LoadDataFromFile(std::string fileLocation) {
    std::cout << "Loading... " << fileLocation << " file" << std::endl;
    std::ifstream fileIn(fileLocation);
    if (!fileIn.is_open()) {
        std::cerr << "file: " << fileLocation << " cannot be opened." << std::endl;
        return;
    }

    std::string line;
    std::istringstream buffer;
    fileIn.ignore(LONG_MAX, '\n');
    while (std::getline(fileIn, line)) {
        std::string date, time;
        buffer.str(line);
        double airTemp, barometricPress, dewPoint, relativeHumidity, windDir, windGust, windSpeed;
        // buffer uses ">>" operator to identify values separated by spaces
        // date and time are string, so buffer reads until it finds a non-string char
        // when the first string ends (date) it puts inside date string variable
        // it continues reading until it finds another string (time)
        // put next string inside time variable, and it continues until it finds a double (airTemp)
        // it will continue until the end
        buffer >> date >> time >> airTemp >> barometricPress >> dewPoint >> relativeHumidity >> windDir >> windGust >> windSpeed;
        std::optional<WeatherStat> stat = ConvertToDateTime(date, time);
        if (!stat.has_value()) {
            continue;
        }
        timeToPressureMap[stat.value().utcTime] = stat.value();
        buffer.clear();
    };
    fileIn.close();
}

std::optional<WeatherStat> WeatherStatistics::ConvertToDateTime(std::string date, std::string time) {
    // parse values from date
    int yyyy, mm, dd = 0;
    int dateMatches = std::sscanf(date.c_str(), "%d_%d_%d", &yyyy, &mm, &dd);
    if (dateMatches != 3) {
        return std::nullopt;
    }

    // parse values from time
    int h, m, s = 0;
    int timeMatches = std::sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    if (timeMatches != 3) {
        return std::nullopt;
    }

    WeatherStat stat {yyyy, mm, dd, h, m, s };

    return stat;
}

