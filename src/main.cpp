// =====================================================================
// name: main.cpp
// project: space_invaders
// author: Mano Marichal
// date: 17.11.19
// copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// description:
// =====================================================================

#include "game/Game.h"

int main([[maybe_unused]] int argc, char* argv[])
{
        if (argc == 1)
                throw std::runtime_error("No file path passed, exiting");
        Game(std::string(argv[1])).playLevels();
        return 0;
}
