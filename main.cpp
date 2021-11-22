

#include <iostream>
#include "include/SimplexMethod.h"
#include "include/Application.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1100, 800), "simplex method", sf::Style::Default);
    ImGui::SFML::Init(window, true);
    ImGuiIO& IO = ImGui::GetIO();
    IO.Fonts->Clear();
    IO.Fonts->AddFontFromFileTTF("Data\\ArialRegular.ttf", 16.f);
    ImGui::SFML::UpdateFontTexture();
    sm::Application app(window);
    app.start();
//    sm::SimplexMethod s;
//    double vars[] = {1,3,2,4,-2};
//    double lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
//    double lim2[] = {-2,0,7};
//    int lim3[] = {0,1,0};
//    s.init(5, 3, vars, lim, lim2, lim3);
//    s.iteration3();

//    sm::SimplexMethod s;
//    double vars[] = {-7, -3, -5};
//    double lim[] = {1, 1, 1, 1, 2, 3, 3, 2, 1};
//    double lim2[] = {50, 73, 75};
//    int lim3[] = {1, 1, 1};
//    s.init(3, 3, vars, lim, lim2, lim3);
//    s.iteration3();
//    sm::SimplexMethod s;
//    double vars[] = {1,3,2,4,-2};
//    double lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
//    double lim2[] = {-2,0,7};
//    int lim3[] = {0,0,0};
//    s.init(5, 3, vars, lim, lim2, lim3);
//    s.findBazis();
//    sm::SimplexMethod s;
//    double vars[] = {1,3,2,4,-2};
//    double lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
//    double lim2[] = {-2,0,7};
//    int lim3[] = {0,0,0};
//    s.init(5, 3, vars, lim, lim2, lim3);
//    s.findBazis();
//    float result = -1;
    return 0;
}
