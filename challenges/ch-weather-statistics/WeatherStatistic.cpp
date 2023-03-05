#include "WeatherStatistic.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <chrono>
#include <regex>

WeatherStat::WeatherStat() {};

WeatherStat::WeatherStat(int y, int m, int d, int h, int min, int sec, double airTemp, double barometricPress,
                         double dewPoint, double relativeHumidity, double windDir, double windGust, double windSpeed)
        : year(y), month(m), day(d), hour(h), minute(min), second(sec), airTemp(airTemp),
          barometricPress(barometricPress), dewPoint(dewPoint), relativeHumidity(relativeHumidity),
          windDir(windDir), windGust(windGust), windSpeed(windSpeed) {
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

WeatherStatistic::WeatherStatistic() {};

WeatherStatistic::WeatherStatistic(std::vector<std::string> listOfFilesLocations) {
    LoadFiles(listOfFilesLocations);
}

void WeatherStatistic::LoadFiles(std::vector<std::string> listOfFilesLocations) {
    for (std::string fileLoc: listOfFilesLocations) {
        LoadDataFromFile(fileLoc);
    }
}

void WeatherStatistic::LoadDataFromFile(std::string fileLocation) {
    std::cout << "Loading... " << fileLocation << " file" << std::endl;
    std::ifstream fileIn(fileLocation);
    if (!fileIn.is_open()) {
        std::cerr << "file: " << fileLocation << " cannot be opened." << std::endl;
        return;
    }
    std::string line;
    fileIn.ignore(LONG_MAX, '\n');
    while (std::getline(fileIn, line)) {
        std::vector<std::string> data = SplitStringData(line);
        std::optional<WeatherStat> stat = ConvertToWeatherStat(data);
        if (!stat.has_value()) {
            std::cerr << "line: " << line << " cannot be converted." << std::endl;
            continue;
        }
        timeToPressureMap[stat.value().utcTime] = stat.value();
    };
    fileIn.close();
}

std::optional<WeatherStat> ConvertToWeatherStat(std::vector<std::string> data) {
    // parse values from date
    int yyyy, mm, dd = 0;
    int dateMatches = std::sscanf(data[0].c_str(), "%d_%d_%d", &yyyy, &mm, &dd);
    if (dateMatches != 3) {
        return std::nullopt;
    }

    // parse values from time
    int hh, m, s = 0;
    int timeMatches = std::sscanf(data[1].c_str(), "%d:%d:%d", &hh, &m, &s);
    if (timeMatches != 3) {
        return std::nullopt;
    }

    WeatherStat stat{
            yyyy, mm, dd, hh, m, s,
            std::stod(data[2]),
            std::stod(data[3]),
            std::stod(data[4]),
            std::stod(data[5]),
            std::stod(data[6]),
            std::stod(data[7]),
            std::stod(data[8]),
    };

    return stat;
}

std::optional<WeatherStat> WeatherStatistic::ConvertToDateTime(std::string date, std::string time) {
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

    return stat;
}

/**
 * SplitStringData()
 * returns data[] with all Weather data for each line
 * this works because the format of data line is well known
 * @param str
 * @return std::vector<std::string> data
 */
std::vector<std::string> WeatherStatistic::SplitStringData(std::string &str) {
    std::vector<std::string> data;
    std::regex re("[^ \t]+");
    std::smatch match;
    while (std::regex_search(str, match, re)) {
        data.push_back(match.str());
        str = match.suffix();
    }
    return data;
}


