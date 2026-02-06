//#define DEBUG_CONSOLE // Uncomment this if you want a debug console to start. You can use the Console class to print. You can use Console::inStrings to get input.

#include <4dm.h>

using namespace fdm;

// Initialize the DLLMain
initDLL

$hook(void, StateIntro, init, StateManager& s)
{
	original(self, s);

	// initialize opengl stuff
	glewExperimental = true;
	glewInit();
	glfwInit();
}

$hook(void, StateGame, addChatMessage, Player* player, const stl::string& message, uint32_t color)
{
	if (message == "/kill")
	{
		player->health = -1.0f;
		return;
	}

	original(self, player, message, color);
}
