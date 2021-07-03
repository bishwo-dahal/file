#ifndef BOILERPLATES_H
#define BOILERPLATES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "functions.h"
class BoilerPlates
{
private:
    std::vector<std::pair<std::string, std::string>> plates;
    std::string HTML;
    std::string CSS;
    std::string CPP;
    std::string JS;
    std::string NODEJS;
    // std::string QT;
    std::string MYSQL;
    std::string C;
    std::string H;
    std::string MD;
    std::string PYTHON;
    std::string VUE;

public:
    BoilerPlates();

    ~BoilerPlates()
    {
    }

    std::string getBoilerPlate(std::string type);
};
std::string BoilerPlates::getBoilerPlate(std::string type)
{
    for (int totalSize = 0; totalSize < plates.size(); totalSize++)
    {
        if (type == plates.at(totalSize).first)
            return plates.at(totalSize).second;
    }

    return Functions::getCurrentTime();
}
BoilerPlates::BoilerPlates()
{
    HTML =
        "     < !DOCTYPE html >\n"
        "     <html lang =\"en\">\n"
        "                 < head>\n"
        "     <meta charset =\"UTF-8\">\n"
        "                    < meta http - equiv =\"X-UA-Compatible\" content=\"IE=edge\">\n"
        "                                         < meta name =\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "                                                      < title>\n"
        "         Document</ title>\n"
        "     </ head>\n"
        "     <body>\n"
        "\n"
        "     </ body>\n"
        "     </ html> ";
    CPP =
        "#include <iostream>\n"
        "            using std::cout;\n"
        "        int main(int argc, char *argv[])\n"
        "        {\n"
        "            cout <<\"Hello World using file \";\n"
        "                return 0;\n"
        "        }\n";
    C =
        "#include <stdio.h>\n"
        "int  main(int argc, char *argv[])\n"
        "        {\n"
        "        printf(\"Hello using file\");\n"
        "        return 0;\n"
        "        }\n";
    H = "#ifndef NAME_H\n"
        "#define NAME_H\n"
        "/* Write Code Here */\n"
        "#endif";
    NODEJS =
        "const express = require(\"express\");\n"
        "const app = express();\n"
        "const PORT = 3030;\n"
        "app.get(\"/\",(req,res)=>{\n"
        "        res.send(\"Main Route\");\n"
        "});\n"
        "app.get(\"/hello\",(req,res)=>{\n"
        "    res.send(\"Hello route\");\n"
        "});\n"
        "app.listen(PORT, (err) =>{\n"
        "    if (err){"
        "        console.log(err);\n"
        "       }else{\n"
        "        console.log(`Connected to PORT $ { PORT }`);\n"
        "            }\n"
        "     });\n";
    CSS =
        "                *\n"
        " {\n"
        "        padding:\n"
        "            0px:\n"
        "        margin:\n"
        "            0px:\n"
        "        }\n";
    MD = "# This is title ";
    PYTHON = "print(\"Hello World\")";
    VUE = "<template>\n"
          " Message is{{msg}}</ template>\n"
          "      <script> export default\n"
          "  {\n"
          "  name:\n"
          "      'HelloWorld',\n"
          "          data(){\n"
          "              return {\n"
          "                  msg : 'Hello This is message',\n"
          "              }}</ script>\n"
          "          <style scoped>\n"
          "          </ style> \n";
    plates.push_back(std::make_pair("html", HTML));
    plates.push_back(std::make_pair("css", CSS));
    plates.push_back(std::make_pair("js", JS));
    plates.push_back(std::make_pair("nodejs", NODEJS));
    plates.push_back(std::make_pair("cpp", CPP));
    plates.push_back(std::make_pair("c", C));
    plates.push_back(std::make_pair("h", H));
    plates.push_back(std::make_pair("hpp", H));
    plates.push_back(std::make_pair("hxx", H));
    plates.push_back(std::make_pair("md", MD));
    plates.push_back(std::make_pair("py", PYTHON));
    plates.push_back(std::make_pair("vue", VUE));
}

#endif

/*

<template>
Message is {{msg}}
</template>

<script>
export default {
  name: 'HelloWorld',
  data () {
    return {
      msg: 'Hello This is message',
    }
  }
</script>

<style scoped>

</style>

*/