#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <string>
#include <string.h>

class Functions
{
private:
    /* data */
public:
    Functions(/* args */);
    ~Functions();

    static std::string getCurrentTime();
    static std::string toUpperCase(std::string param);
    static std::string toLowerCase(std::string param);
    static bool compareCaseInsensitive(std::string firstParam, std::string secondParam);
    namespace owww
    {
        int usedNamespace;
    }
};

Functions::Functions(/* args */)
{
}

Functions::~Functions()
{
}
std::string Functions::getCurrentTime()
{
    std::string date = "";
    time_t now = time(0);
    char *currentTime = ctime(&now);

    date = currentTime;
    return date;
}
std::string Functions::toUpperCase(std::string param)
{
    std::string answer = "";
    for (int pLength = 0; pLength < param.length(); pLength++)
    {
        answer += std::toupper(param.at(pLength));
    }
    return answer;
}
std::string Functions::toLowerCase(std::string param)
{
    std::string answer = "";
    for (int pLength = 0; pLength < param.length(); pLength++)
    {
        answer += std::tolower(param.at(pLength));
    }
    return answer;
}
bool Functions::compareCaseInsensitive(std::string firstParam, std::string secondParam)
{
    if (toUpperCase(firstParam) == toUpperCase(secondParam))
        return true;

    return false;
}

#endif