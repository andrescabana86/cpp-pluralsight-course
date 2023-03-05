#pragma once

#include <map>
#include <string>
#include <vector>
#include <optional>

struct WeatherStat {
    tm dateTime;
    double airTemp, barometricPress, dewPoint, relativeHumidity, windDir, windGust, windSpeed;
    time_t utcTime;

    WeatherStat();

    WeatherStat(tm dateTime, double airTemp, double barometricPress, double dewPoint,
                double relativeHumidity, double windDir, double windGust, double windSpeed);

    static std::optional<tm> ConvertToDateTime(const std::string &date, const std::string &time);
};

class WeatherStatistic {
public:
    WeatherStatistic();

    WeatherStatistic(std::vector<std::string> listOfFilesLocations);

private:
    std::map<time_t, WeatherStat> timeToPressureMap;

    void LoadFiles(std::vector<std::string> listOfFilesLocations);

    void LoadDataFromFile(std::string fileLocation);

    std::optional<WeatherStat> ConvertToWeatherStat(std::vector<std::string> data);


    std::vector<std::string> SplitStringData(std::string &str);


};

