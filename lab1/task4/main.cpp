#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    ofstream out;
    out.open("index.html");
    if(out.is_open()){
        out << "<!DOCTYPE html>\n"
               "<html lang=\"en\">\n"
               "<body style=\"margin: 0\">\n"
               "<table style=\"width: 100vw; height: 100vh; border-collapse:collapse;\">\n";

        for(int i = 0; i < 256; i++){
            out << "<tr>\n"
                   "    <td style=\"background-color: rgb("<< 255-i << "," << 255-i << "," << 255-i << ");\"></td>\n"
                   "</tr>\n";
        }

        out <<"</table>\n"
               "</body>\n"
               "</html>";
    }
    return 0;
}
