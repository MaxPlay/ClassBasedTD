#include "SceneLoading.h"
#include "SceneManagement/SceneManager.h"

#include "Scenes/InGame.h"
#include "Scenes/Loading.h"


using namespace CBTD;

void CBTD::LoadScenes(SceneManager* manager)
{
    manager->AddScene(new InGame("ingame"));
    manager->AddScene(new Loading("loading", true));
}
