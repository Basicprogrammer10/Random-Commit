#include <iostream>
#include <ctime>


#include "messages.hpp"
#include "windows.hpp"

using namespace std;

int main(int argc, char **argv) {
    colorInit();
    string gitArgs = "-a ";

    if (argc > 1){
        gitArgs = "";
        for (int i = 1; i < argc; i++) {
            gitArgs += argv[i];
            gitArgs += " ";
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int RandIndex = rand() % commitMessages::messageLength;

    string msg = "git commit " + gitArgs + "-m \"" + commitMessages::messages[RandIndex] + "\"";

    cout << "\033[32m[*] Running: \033[34m" << msg << "\033[0m" << endl;
    system(msg.c_str());
    return 0;
}