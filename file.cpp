#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

std::string getCurrentTime()
{
    std::string date = "";
    time_t now = time(0);
    char *currentTime = ctime(&now);

    date = currentTime;
    return date;
}

std::string filePrefix(int num, std::string filename)
{
    std::string out = "";
    out = to_string(num) + "). " + filename + " ";
    return out;
}

int main(int argc, char *argv[])
{

    if (argc <= 2)
    {
        std::cout.width(50);
        std::cout << "\t\tPLEASE PROVIDE SUFFICIENT FILE NAMES" << std::endl;
    }
    else
    {
        std::string command = argv[1];

        if (command == "delete" || command == "DELETE")
        {
            for (int a = 2; a < argc; a++)
            {
                int removed = remove(argv[a]);
                if (removed != 0)
                {
                    std::cout.width(50);
                    std::cout << filePrefix(a - 1, argv[a]) << " cannot be deleted \t" << std::endl;
                }
                else
                {
                    std::cout << filePrefix(a - 1, argv[a]) << " deleted successfully! " << std::endl;
                }
            }
        }
        else if (command == "create" || command == "CREATE")
        {
            for (int a = 2; a < argc; a++)
            {
                if (std::ifstream(argv[a]))
                {
                    std::cout.width(50);
                    std::cout << filePrefix(a - 1, argv[a]) << " FILE IS ALREADY PRESENT" << std::endl;
                    continue;
                }
                std::ofstream openFile(argv[a]);
                if (!openFile)
                {
                    std::cout << filePrefix(a - 1, argv[a]) << "THE FILE COULD NOT BE CREATED" << std::endl;
                }
                else
                {
                    openFile << getCurrentTime() << std::endl;
                    std::cout << filePrefix(a - 1, argv[a]) << "  created Successfully\n";
                    openFile.close();
                }
            }
        }
        else
        {
            std::cout.width(50);
            std::cout << "\t\tCOMMAND NOT FOUND\n\n"
                      << std::endl;
        }
    }

    std::cout << "\n\t\tCOMPILED AT   " << __TIMESTAMP__ << std::endl;

    return 0;
}