//============================================================================
// Name        : PWorldGen.cpp
// Author      : Tewos
// Version     :
// Copyright   : GPLv3
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graphics/ntsa.h"
#include "Core/UI.h"


const uint SCREEN_WIDTH = 800;
const uint SCREEN_HEIGHT = 600;

int main() {
	INFO("Welcome to the Pangea World Generator v0.0.0");
	MainUI hello_world;
	hello_world.Run(SCREEN_WIDTH, SCREEN_HEIGHT);

	return 0;
}
