#ifndef ERRORS_H
#define ERRORS_H
class Errors
{
public:
    Errors()
    {
    }

    void fileNotOpened(std::string file_name, int number)
    {
        std::cout.width(50);
        if (number != -1)
        {
            std::cout << std::to_string(number) << "). " << file_name << " file not opened" << std::endl;
        }
        else
        {
            std::cout << " " << file_name << " file not opened " << std::endl;
        }
    }
};
#endif