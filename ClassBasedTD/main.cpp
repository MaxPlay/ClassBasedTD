#include "Core/Application.h"

using namespace CBTD;

int main()
{
    Application* app = Application::GetApplication();
    app->Run();
}