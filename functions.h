#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <string>
#include <string.h>

namespace Functions
{
    std::string getCurrentTime()
    {
        std::string date = "";
        time_t now = time(0);
        char *currentTime = ctime(&now);

        date = currentTime;
        return date;
    }
    std::string toUpperCase(std::string param)
    {
        std::string answer = "";
        for (int pLength = 0; pLength < param.length(); pLength++)
        {
            answer += std::toupper(param.at(pLength));
        }
        return answer;
    }
    std::string toLowerCase(std::string param)
    {
        std::string answer = "";
        for (int pLength = 0; pLength < param.length(); pLength++)
        {
            answer += std::tolower(param.at(pLength));
        }
        return answer;
    }
    bool compareCaseInsensitive(std::string firstParam, std::string secondParam)
    {
        if (toUpperCase(firstParam) == toUpperCase(secondParam))
            return true;

        return false;
    }

}
#endif