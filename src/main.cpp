#include <iostream>
#include <exception>
#include "game.h"

int main(int argc,
         char** argv) {
    try {
        RunGame();
    }
    catch (const std::exception& e) {
        // TODO: Replace with terminate handler that prints a stack trace or something
        std::cerr << "Uncaught exception: " << e.what() << std::endl;
    }

    return 0;
}
