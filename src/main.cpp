#include <iostream>
#include <ctime>
#include "messages.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int RandIndex = rand() % commitMessages::messageLength;

    string msg = "git commit -a -m \"";
    msg.append(commitMessages::messages[RandIndex]);
    msg.append("\"");

    system(msg.c_str());
    return 0;
}