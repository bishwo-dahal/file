#include "boilerPlates.h"

boilerPlates::boilerPlates(/* args */)
{
}

boilerPlates::~boilerPlates()
{
}

std::string boilerPlates::getBoilerPlates(std::string type){
    if(type == "HTML"){
        return "hello";
    }    
    return "just showing for now";
}