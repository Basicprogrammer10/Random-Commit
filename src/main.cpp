#include <iostream>
#include <ctime>
#include "messages.h"

using namespace std;

int main(int argc, char **argv) {
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

    cout << "[*] Running: " << msg << endl;
    system(msg.c_str());
    return 0;
}