#include "Core/Application.h"

using namespace CBTD;
using namespace Core;

int main()
{
    Application* app = Application::GetApplication();
    app->Run();
}