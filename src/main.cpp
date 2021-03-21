#include <iostream>
#include <ctime>
#include "messages.h"

using namespace std;

int main(int argc, char **argv) {
    string gitArgs = "-a";

    srand(static_cast<unsigned int>(time(nullptr)));
    int RandIndex = rand() % commitMessages::messageLength;

    string msg = "git commit " + gitArgs + " -m \"" + commitMessages::messages[RandIndex] + "\"";

    cout << msg << endl;
    system(msg.c_str());
    return 0;
}