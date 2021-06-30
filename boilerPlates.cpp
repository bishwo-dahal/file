#include "boilerplates.h"
/*
BoilerPlates::BoilerPlates( args )
{
    HTML = "
           < !DOCTYPE html >
           <html lang =\"en\">
                       < head>
           <meta charset =\"UTF-8\">
                          < meta http - equiv =\"X-UA-Compatible\" content=\"IE=edge\">
                                               < meta name =\"viewport\" content=\"width=device-width, initial-scale=1.0\">
                                                            < title>
               Document</ title>
           </ head>
           <body>

           </ body>
           </ html> ";
           CPP = "
#include <iostream>
        using std::cout;
    int main(int argc, char *argv[])
    {
        std::cout <<\"Hello World using file \";
            return 0;
    }
    ";
        C = "
#include <stdio.h>
        int
        main(int argc, char *argv[])
    {
        printf(\"Hello using file\");
        return 0;
    }
    ";
    NODEJS = "
    const express = require(\"express\");
    const app = express();
    const PORT = 3030;
    app.get(\"/\",(req,res)=>{
            res.send(\"Main Route\");
});
    app.get(\"/hello\",(req,res)=>{
        res.send(\"Hello route\");
    });
    app.listen(
        PORT, (err) = >
                      {
                          if (err)
                          {
                              console.log(err);
                          }
                          else
                          {
                              console.log(`Connected to PORT $ { PORT }`);
                          }
                      });
    ";
        CSS = "
            *
    {
    padding:
        0px;
    margin:
        0px;
    }
    ";
        std::cout
        << NODEJS;
    }
    

        // BoilerPlates::~BoilerPlates()
        // {
        // }
*/
std::string BoilerPlates::getBoilerPlates(std::string type)
{

    if (type == "HTML")
    {
        return "hello";
    }
    return "just showing for now";
}