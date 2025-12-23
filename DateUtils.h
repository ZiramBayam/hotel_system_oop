#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <string>

class DateUtils {
public:
    static bool isOverlap(std::string start1, std::string end1, std::string start2, std::string end2) {
        return (start1 <= end2 && end1 >= start2);
    }
};

#endif