#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {

    cout << "Test HTML: ";

    vector<string> html = {
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<body style=\"margin: 0\">\n"
            "<table style=\"width: 100vw; height: 100vh; border-collapse:collapse;\">\n"
    };

    for (int i = 0; i < 256; i++) {
        html.push_back("<tr>\n"
                       "    <td style=\"background-color: rgb(" + to_string(255 - i) + "," + to_string(255 - i) + "," +
                       to_string(255 - i) + ");\"></td>\n"
                                            "</tr>\n");
    }

    html.push_back("</table>\n"
                   "</body>\n"
                   "</html>");

    assert(html[0] == "<!DOCTYPE html>\n"
                      "<html lang=\"en\">\n"
                      "<body style=\"margin: 0\">\n"
                      "<table style=\"width: 100vw; height: 100vh; border-collapse:collapse;\">\n");

    assert(html[1] == "<tr>\n"
                      "    <td style=\"background-color: rgb(255,255,255);\"></td>\n"
                      "</tr>\n");

    assert(html[255] == "<tr>\n"
                      "    <td style=\"background-color: rgb(1,1,1);\"></td>\n"
                      "</tr>\n");

    assert(html[256] == "<tr>\n"
                        "    <td style=\"background-color: rgb(0,0,0);\"></td>\n"
                        "</tr>\n");

    assert(html[257] == "</table>\n"
                        "</body>\n"
                        "</html>");

    cout << "passed" << endl;
    return 0;
}