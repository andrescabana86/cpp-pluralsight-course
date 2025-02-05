#pragma once

#include <map>
#include <string>
#include <vector>
#include <optional>
#include <semaphore>

struct WeatherStat {
    tm dateTime;
    double airTemp, barometricPress, dewPoint, relativeHumidity, windDir, windGust, windSpeed;

    WeatherStat();

    WeatherStat(tm dt, double airTemp, double barometricPress, double dewPoint,
                double relativeHumidity, double windDir, double windGust, double windSpeed);

    time_t getUTCTime();

    static std::optional<tm> ConvertToDateTime(const std::string &date, const std::string &time);
};

class WeatherStatistic {
public:
    WeatherStatistic();

    WeatherStatistic(std::vector<std::string> listOfFilesLocations);

    bool IsValidDateTime(std::string date, std::string time);

    std::optional<double>
    computeCoefficient(std::string startDate, std::string startTime, std::string endDate, std::string endTime);

private:
    std::binary_semaphore timeToPressureMapMutex{1};

    std::map<time_t, WeatherStat> timeToPressureMap;

    void LoadFiles(std::vector<std::string> listOfFilesLocations);

    void LoadDataFromFile(std::string fileLocation);

    std::optional<WeatherStat> ConvertToWeatherStat(std::vector<std::string> data);

    std::vector<std::string> SplitStringData(std::string &str);

    time_t GetFirstDateTime();

    time_t GetLastDateTime();
};

