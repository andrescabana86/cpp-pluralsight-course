#pragma once

#include <map>
#include <string>
#include <vector>
#include <optional>

struct WeatherStat {
    int year, month, day, hour, minute, second;
    double airTemp, barometricPress, dewPoint, relativeHumidity, windDir, windGust, windSpeed;
    tm dateTime;
    time_t utcTime;

    WeatherStat();

    WeatherStat(int y, int m, int d, int h, int min, int sec, double airTemp, double barometricPress, double dewPoint,
                double relativeHumidity, double windDir, double windGust, double windSpeed);
};

class WeatherStatistic {
public:
    WeatherStatistic();

    WeatherStatistic(std::vector<std::string> listOfFilesLocations);

    void LoadFiles(std::vector<std::string> listOfFilesLocations);

private:
    std::map<time_t, WeatherStat> timeToPressureMap;

    void LoadDataFromFile(std::string fileLocation);

    std::optional<WeatherStat> ConvertToWeatherStat(std::vector<std::string> data);

    std::optional<WeatherStat> ConvertToDateTime(std::string date, std::string time);

    std::vector<std::string> SplitStringData(std::string &str);
};

