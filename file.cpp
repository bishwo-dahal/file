#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include <cctype>
#include "errors.h"
#include "boilerplates.h"
#include "functions.h"

using std::cin;
using std::cout;
using std::string;
// just for simplicity

std::string filePrefix(int num, std::string filename)
{
    std::string out = "";
    out = std::to_string(num) + "). \"" + filename + "\" ";
    return out;
}

void printTable(std::string firstParam, std::string secondParam, int width = 15)
{
    const char separator = ' ';
    // const int width = 15;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << firstParam;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << secondParam << std::endl;
}
void printTable(std::string firstParam, double secondParam, int width = 15)
{
    const char separator = ' ';
    // const int width = 15;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << firstParam;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << secondParam << std::endl;
}
std::string getBoilerPlate(std::string extName)
{
    BoilerPlates plates;
    extName = Functions::toLowerCase(extName);
    if (extName == "js")
    {
        std::cout << "There are couple of choices: \n";
        printTable("1. ", "For simple JS File");
        printTable("2. ", "For Node JS File");
        std::cout << "Enter Your Choice (Default is 1) ";
        char ans = std::getchar();
        if (ans == '2')
        {
            extName = "node" + extName;
        }
    }

    return plates.getBoilerPlate(extName);
}
std::string getExtension(std::string fileName)
{
    std::string extName = "";
    for (int fLength = 0; fLength < fileName.length(); fLength++)
    {
        if (fileName.at(fLength) == '.')
        {
            extName = fileName.substr(fLength + 1, fileName.length() - fLength);
        }
    }
    return extName;
}

void DeleteCommand(int argc, char *argv[]);
void CreateCommand(int argc, char *argv[]);
void OpenCommand(int argc, char *argv[]);
void CopyToClipboard(int argc, char *argv[]);
void InsertCommand(int argc, char *argv[]);
void ShowCommand(int argc, char *argv[]);
void RenameCommand(int argc, char *argv[]);
void SizeCommand(int argc, char *argv[]);

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout.width(50);
        std::cout << "\t\tPLEASE PROVIDE SUFFICIENT FILE NAMES" << std::endl;
    }
    else if (argc == 2)
    {
        std::string command = argv[1];
        if (Functions::compareCaseInsensitive(command, "show"))
        {
            ShowCommand(argc, argv);
        }
        else
        {
            std::cout.width(50);
            std::cout << "\t\tCOMMAND NOT FOUND OR LESS APPROPRIATE COMMANDS \n\n"
                      << std::endl;
        }
    }
    else
    {
        std::string command = argv[1];

        if (Functions::compareCaseInsensitive(command, "delete"))
        {
            DeleteCommand(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "create"))
        {
            CreateCommand(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "open"))
        {
            OpenCommand(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "copy"))
        {
            CopyToClipboard(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "insert"))
        {
            InsertCommand(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "rename"))
        {
            RenameCommand(argc, argv);
        }
        else if (Functions::compareCaseInsensitive(command, "size"))
        {
            SizeCommand(argc, argv);
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
            std::string fileName = argv[a];
            std::string extensionName = getExtension(fileName);

            openFile << getBoilerPlate(extensionName) << std::endl;

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
void RenameCommand(int argc, char *argv[])
{
    if (argc % 2 != 0)
    {
        std::cout << "\n\tNOO! Insufficient Files Name \n\n";
        return;
    }
    int ctr = 1;

    for (int a = 2; a < argc; a++)
    {
        int isRenamed = rename(argv[a], argv[a + 1]);
        if (isRenamed != 0)
        {
            std::cout << "" << filePrefix(ctr, argv[a]) << " file Could not be renamed to " << argv[a + 1];
        }
        else
        {
            std::cout << filePrefix(ctr, argv[a]) << " file  renamed to " << argv[a + 1];
        }
        std::cout << std::endl;
        a++;
        ctr++;
        // This is for adding one which becomes +2 as whole
        // if given file replace a.txt b.txt  // skips b.txt and jumps to another
    }
}

void SizeCommand(int argc, char *argv[])
{
    double totalSize = 0;
    std::string sizeType = "-b";
    for (int a = 2; a < argc; a++)
    {
        std::string argument = argv[a];
        if (argument == "-b" || argument == "-B" || argument == "-mb" || argument == "-MB" || argument == "-kb" || argument == "-KB" || argument == "-gb" || argument == "-Gb")
        {
            sizeType = argument;
            break;
        }
    }
    int ctr = 1;
    // std::cout << "Filenames" << std::setw(8) << std::setfill(' ') << "Sizes" << std::endl;
    printTable(std::string("Filenames"), std::string("Size"));
    for (int a = 2; a < argc; a++)
    {
        if (argv[a] == sizeType)
            continue;

        std::fstream findSize(argv[a], std::ios_base::binary | std::ios_base::in);
        if (!findSize)
        {
            Errors err;
            err.fileNotOpened(argv[a], ctr);
        }
        else
        {
            findSize.seekg(0, std::ios_base::end);
            double fileSize = findSize.tellg();

            if (sizeType == "-kb" || sizeType == "-KB")
            {
                fileSize /= 1024.0;
            }
            else if (sizeType == "-mb" || sizeType == "-MB")
            {
                fileSize /= 1024.0;
                fileSize /= 1024.0;
            }
            else if (sizeType == "-gb" || sizeType == "-GB")
            {
                fileSize /= 1024.0;
                fileSize /= 1024.0;
                fileSize /= 1024.0;
            }
            totalSize += fileSize;
            printTable(filePrefix(ctr, argv[a]), fileSize);
        }
        ctr++;
    } // Getting the parameters of function

    printTable("Total", totalSize);
}
void ShowCommand(int argc, char *argv[])
{

    string path = "./";

    std::cout << path;
}