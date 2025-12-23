#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <string>
#include <ctime>
#include <cstdio>
#include <cmath>

class DateUtils {
public:
    static time_t convertToTime(std::string dateStr) {
        struct tm tm = {0};
        int year, month, day;

        if (sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
            tm.tm_year = year - 1900;
            tm.tm_mon = month - 1;
            tm.tm_mday = day;
        }
        return mktime(&tm);
    }

    static int getDurationDays(std::string start, std::string end) {
        time_t s = convertToTime(start);
        time_t e = convertToTime(end);
        
        if (e <= s) return 0;

        double seconds = difftime(e, s);
        return (int)round(seconds / 86400.0);
    }

    static bool isOverlap(std::string start1, std::string end1, std::string start2, std::string end2) {
        return (start1 < end2 && end1 > start2);
    }
};

#endif