#include <CSE/CSU/logger.hpp>

#include <CSE/CSEA/core/engine.hpp>

#include <CSE/Experimental/test1/teststage.hpp>

#include <CSE/CSU/utilities.hpp>

#include <list>
#include <utility>
#include <iostream>

static const char *WINDOW_TITLE = "EVABEVAdoesnotSUX";
static const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char *argv[]) {
    CSEA::Core::Engine::Settings engineSettings;
    engineSettings.windowSettings.width = SCREEN_WIDTH;
    engineSettings.windowSettings.height = SCREEN_HEIGHT;
    engineSettings.windowSettings.windowTitle = WINDOW_TITLE;
    engineSettings.windowSettings.isResizeable = false;

    CSEA::Core::Engine::initialize(engineSettings);

    Experimental::Test1::TestStage *stage = new Experimental::Test1::TestStage();

    CSEA::Core::Engine::loadStage(stage);

    CSEA::Core::Engine::setActiveStage(stage);

    CSEA::Core::Engine::run();

    CSEA::Core::Engine::unloadStage(stage);

    delete stage;
    stage = NULL;

    CSEA::Core::Engine::shutdown();

    return 0;
}
