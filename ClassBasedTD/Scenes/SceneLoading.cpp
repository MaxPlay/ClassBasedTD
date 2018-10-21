#include "SceneLoading.h"
#include "Scenes.h"
#include "SceneManagement/SceneManager.h"

using namespace CBTD;
using namespace Scenes;

void CBTD::LoadScenes(SceneManagement::SceneManager * manager)
{
    manager->AddScene(new InGame("ingame"));
    manager->AddScene(new Loading("loading", true));
}
