#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>
#include <regex>

class Validate
{
public:
    static bool is_valid_phone(const std::string &phone)
    {
        // Kiểm tra xem số điện thoại có đúng 10 chữ số hay không
        std::regex phone_regex("^\\d{10}$");
        return std::regex_match(phone, phone_regex);
    }
    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool validateDate(const std::string &date)
    {
        std::stringstream ss(date);
        std::string day_str, month_str, year_str;

        if (!std::getline(ss, day_str, '/') || !std::getline(ss, month_str, '/') || !std::getline(ss, year_str, '/'))
        {
            return false;
        }

        int day, month, year;
        try
        {
            day = std::stoi(day_str);
            month = std::stoi(month_str);
            year = std::stoi(year_str);
        }
        catch (const std::invalid_argument &e)
        {
            return false;
        }
        catch (const std::out_of_range &e)
        {
            return false;
        }

        if (year < 2000)
        {
            return false;
        }

        if (month < 1 || month > 12)
        {
            return false;
        }

        std::vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year))
        {
            days_in_month[1] = 29;
        }

        if (day < 1 || day > days_in_month[month - 1])
        {
            return false;
        }

        return true;
    }
    bool validateTime(const std::string &time)
    {
        std::stringstream ss(time);
        std::string hour_str, minute_str;

        if (!std::getline(ss, hour_str, ':') || !std::getline(ss, minute_str, ':'))
        {
            return false;
        }

        int hour, minute;
        try
        {
            hour = std::stoi(hour_str);
            minute = std::stoi(minute_str);
        }
        catch (const std::invalid_argument &e)
        {
            return false;
        }
        catch (const std::out_of_range &e)
        {
            return false;
        }

        if (hour < 0 || hour > 23)
        {
            return false;
        }

        if (minute < 0 || minute > 59)
        {
            return false;
        }

        return true;
    }
    bool validateShiftTime(const std::string &shiftTime)
    {
        return shiftTime == "Morning" || shiftTime == "Afternoon" || shiftTime == "Evening";
    }
};

#endif