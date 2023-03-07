#include "WeatherStatistic.h"
#include <iostream>
#include <fstream>
#include <optional>
#include <regex>
#include <chrono>
#include <thread>

WeatherStat::WeatherStat() {};

WeatherStat::WeatherStat(tm dt, double airTemp, double barometricPress, double dewPoint,
                         double relativeHumidity,
                         double windDir, double windGust, double windSpeed)
        : dateTime(dt), airTemp(airTemp), barometricPress(barometricPress), dewPoint(dewPoint),
          relativeHumidity(relativeHumidity), windDir(windDir), windGust(windGust), windSpeed(windSpeed) {}

time_t WeatherStat::getUTCTime() {
    return std::mktime(&dateTime);
}

std::optional<tm> WeatherStat::ConvertToDateTime(const std::string &date, const std::string &time) {
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

    tm dateTime;
    // Set the dateTime and utcTime members based on the year, month, day, hour, minute, and seconds
    dateTime.tm_year = yyyy - 1900;  // Years since 1900
    dateTime.tm_mon = mm - 1;     // Months since January (0-based)
    dateTime.tm_mday = dd;          // Day of the month (1-based)
    dateTime.tm_hour = h;         // Hours since midnight (0-23)
    dateTime.tm_min = m;        // Minutes after the hour (0-59)
    dateTime.tm_sec = s;        // Seconds after the minute (0-60)

    return dateTime;
}

WeatherStatistic::WeatherStatistic() {};

WeatherStatistic::WeatherStatistic(std::vector<std::string> listOfFilesLocations) {
    LoadFiles(listOfFilesLocations);
}

void WeatherStatistic::LoadFiles(std::vector<std::string> listOfFilesLocations) {
    std::vector<std::thread> writers;
    for (std::string fileLoc: listOfFilesLocations) {
        writers.push_back(
                std::thread(&WeatherStatistic::LoadDataFromFile, this, fileLoc)
        );
    }
    for (std::thread &t: writers) {
        t.join();
    }
}

void WeatherStatistic::LoadDataFromFile(std::string fileLocation) {
    std::cout << "Loading... " << fileLocation << " file" << std::endl;
    std::ifstream fileIn(fileLocation);
    if (!fileIn.is_open()) {
        std::cerr << "file: " << fileLocation << " cannot be opened." << std::endl;
        return;
    }
    auto start = std::chrono::high_resolution_clock::now();
    std::string line;
    std::vector<std::string> data;
    std::optional<WeatherStat> stat;
    fileIn.ignore(LONG_MAX, '\n');
    while (std::getline(fileIn, line)) {
        data = SplitStringData(line);
        stat = ConvertToWeatherStat(data);
        if (!stat.has_value()) {
            std::cerr << "line: " << line << " cannot be converted." << std::endl;
            continue;
        }
        timeToPressureMapMutex.acquire();
        timeToPressureMap.emplace(stat->getUTCTime(), std::move(*stat));
        timeToPressureMapMutex.release();
    };
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " milliseconds." << std::endl;
    fileIn.close();
}

std::optional<WeatherStat> WeatherStatistic::ConvertToWeatherStat(std::vector<std::string> data) {
    std::optional<tm> dateTime = WeatherStat::ConvertToDateTime(data[0], data[1]);
    if (!dateTime.has_value()) {
        return std::nullopt;
    }

    WeatherStat stat{
            dateTime.value(),
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

bool WeatherStatistic::IsValidDate(std::string dt) {
    // parse values from date
    int yyyy, mm, dd = 0;
    int dateMatches = std::sscanf(dt.c_str(), "%d_%d_%d", &yyyy, &mm, &dd);
    if (dateMatches != 3) {
        return false;
    }

    return true;
}

bool WeatherStatistic::IsValidTime(std::string dt) {
    // parse values from time
    int h, m, s = 0;
    int timeMatches = std::sscanf(dt.c_str(), "%d:%d:%d", &h, &m, &s);
    if (timeMatches != 3) {
        return false;
    }

    return true;
}
