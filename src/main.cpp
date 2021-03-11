#include <iostream>
#include <cstdlib>
#include <ctime>
#include "messages.h"

using namespace std;

int main() {
    srand(time(nullptr));

    int RandIndex = rand() % 527;
    cout << commitMessages::messages[RandIndex];

    return 0;
}