#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include "boilerPlates.h"
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

void DeleteCommand(int argc, char *argv[]);
void CreateCommand(int argc, char *argv[]);
void OpenCommand(int argc, char *argv[]);
void CopyToClipboard(int argc, char *argv[]);
void InsertCommand(int argc, char *argv[]);

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
            DeleteCommand(argc, argv);
        }
        else if (command == "create" || command == "CREATE")
        {
            CreateCommand(argc, argv);
        }
        else if (command == "OPEN" || command == "open")
        {
            OpenCommand(argc, argv);
        }
        else if (command == "copy" || command == "COPY")
        {
            CopyToClipboard(argc, argv);
        }
        else if (command == "insert" || command == "INSERT")
        {
            InsertCommand(argc, argv);
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

void DeleteCommand(int argc, char *argv[])
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

void CreateCommand(int argc, char *argv[])
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

void OpenCommand(int argc, char *argv[])
{
    for (size_t a = 2; a < argc; a++)
    {
        std::fstream readFileLineWise(argv[a]);
        if (!readFileLineWise)
        {
            std::cout.width(50);
            std::cout << filePrefix(a - 1, argv[a]) << " File could not be read!!";
        }
        else
        {
            std::cout << "\t\t";
            std::cout << filePrefix(a - 1, argv[a]) << " File contents!!";
            std::string fileContent = "";
            std::cout << std::endl;
            while (getline(readFileLineWise, fileContent))
            {
                std::cout << fileContent << std::endl;
            }
            std::cout << std::endl;
        }
        readFileLineWise.close();
    }
}
void CopyToClipboard(int argc, char *argv[])
{

    std::string wholeContent = "";
    for (int a = 2; a < argc; a++)
    {
        std::fstream openFile(argv[a]);
        if (!openFile)
        {
            std::cout.width(50);
            std::cout << filePrefix(a - 1, argv[a]) << " File could not be read!!";
        }
        else
        {
            std::string content = "";
            while (std::getline(openFile, content))
            {
                wholeContent += content + "\n";
            }
            std::cout << filePrefix(a - 1, argv[a]) << " file's contents are copied ";
        }
    }

    std::cout << wholeContent;
}

void InsertCommand(int argc, char *argv[])
{
    for (int a = 2; a < argc; a++)
    {
        std::cout.width(10);
        std::cout << "Press CTRL + Z and ENTER  for closing and saving file \n\n";
        std::fstream openFile(argv[a]);
        if (!openFile)
        {
            std::cout.width(50);
            std::cout << filePrefix(a - 1, argv[a]) << " File could not be opened!!" << std::endl;
            std::cout << "Do you want to create the file instead and insert ? (y/n) ";
            char ans = getch();
            if (ans == 'y' || ans == 'Y')
            {
                std::fstream createFile(argv[a], std::ios_base::out);
                if (!createFile)
                {
                    std::cout << "\t\tThe file could not be created " << std::endl;
                }
                else
                {
                    std::cout << "\n Enter contents below: \n";
                    std::string content = "";
                    while (std::getline(cin, content))
                    {
                        createFile << content << "\n";
                    }

                    std::cout << filePrefix(a - 1, argv[a]) << " file's contents inserted! ";
                }
                createFile.close();
            }
        }
        else
        {

            std::string content = "";
            while (std::getline(cin, content))
            {
                openFile << content << "\n";
            }

            std::cout << filePrefix(a - 1, argv[a]) << " file's contents inserted! ";
        }
        openFile.close();
    }
}