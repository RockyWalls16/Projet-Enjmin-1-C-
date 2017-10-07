#include "GameController.h"
#include "utils/TimeManager.h"

int main(int argc, char* args[])
{
	GameController::getInstance().initGame();
	GameController::getInstance().loopGame();

	return 0;
}
