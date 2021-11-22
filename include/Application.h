//
// Created by NePutin on 9/29/2021.
//

#ifndef SIMPLEXMETHOD_APPLICATION_H
#define SIMPLEXMETHOD_APPLICATION_H

#include <imgui-SFML.h>
#include <imgui.h>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "SimplexMethod.h"

namespace sm
{
    class Application
    {
    private:
        using varType = double;
        enum _state
        {
            INITIALDATA,
            OTHERDATA,
            SOLUTION
        } state;
        enum _sign
        {
            EQUAL = 0,
            GREATEROREQUAL = -1,
            LESSOREQUAL = 1
        } sign;

        sf::RenderWindow* window;
        sf::View view;
        sf::Clock clock;
        sf::Clock deltaClock;
        sf::Vector2f wSize;

        SimplexMethod s;
        int varCount;
        int resCount;
        int* typeSign;
        bool alloc = false;
        varType* limitersData;
        varType* limitersRValue;
        varType* variables;

        std::string text;
        std::vector<SnapshotData> dataS;
        std::stringstream stream;

        std::string signToStr(_sign s);

    public:
        Application(sf::RenderWindow& w) : window(&w), varCount(0), resCount(0), state(INITIALDATA)
        {
            setTheme();
            autoFill();
        }

        void update();

        void handleEvent(sf::Event& event);

        void draw();

        void setTheme();

        void initDataLayout();

        void allocData();

        void clear();

        void solutionLayout();

        void inputDataLayout();

        void start();

        void remove_neg_coeff_print(sm::SnapshotData& d);

        void deltas_table_print(sm::SnapshotData& d);

        void simplex_table_print(sm::SnapshotData& d);

        void bazis_table_print(sm::SnapshotData& d);

        void result_print(sm::SnapshotData& d);

        void autoFill()
        {
//            resCount = 3;
//            varCount = 3;
//            allocData();
//            float vars[] = {-1, 8, 3};
//            float lim[] = {3, 1, 2, 1, 1, 1, -1, 3, -1};
//            float lim2[] = {6, 4, 4};
//            int _lim3[] = {-1, -1, -1};
//            std::copy(vars, vars + 3, variables);
//            std::copy(lim, lim + 9, limitersData);
//            std::copy(lim2, lim2 + 3, limitersRValue);
//            std::copy(_lim3, _lim3 + 3, typeSign);

//            resCount = 3;
//            varCount = 3;
//            allocData();
//            varType vars[] = {-7, -3, -5};
//            varType lim[] = {1, 1, 1, 1, 2, 3, 3, 2, 1};
//            varType lim2[] = {50, 73, 75};
//            int _lim3[] = {1, 1, 1};
//            std::copy(vars, vars + 3, variables);
//            std::copy(lim, lim + 9, limitersData);
//            std::copy(lim2, lim2 + 3, limitersRValue);
//            std::copy(_lim3, _lim3 + 3, typeSign);

//            resCount = 2;
//            varCount = 3;
//            allocData();
//            varType vars[] = {-1, -100};
//            varType lim[] = {2, 3, 3, 4, 54, 3};
//            varType lim2[] = {-100, 2, 3};
//            int _lim3[] = {1, 1, 1};
//            std::copy(vars, vars + 2, variables);
//            std::copy(lim, lim + 6, limitersData);
//            std::copy(lim2, lim2 + 3, limitersRValue);
//            std::copy(_lim3, _lim3 + 3, typeSign);

            resCount = 3;
            varCount = 5;
            allocData();
            varType vars[] = {1,3,2,4,-2};
            varType lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
            varType lim2[] = {-2,0,7};
            int _lim3[] = {0,1,0};
            std::copy(vars, vars + 5, variables);
            std::copy(lim, lim + 15, limitersData);
            std::copy(lim2, lim2 + 3, limitersRValue);
            std::copy(_lim3, _lim3 + 3, typeSign);

//            resCount = 2;
//            varCount = 3;
//            allocData();
//            double vars[] = {-1,-1,-1};
//            double lim[] = {-1,1,1, 3,-1,1};
//            double lim2[] = {2,0};
//            int _lim3[] = {0,0};
//            std::copy(vars, vars + 3, variables);
//            std::copy(lim, lim + 6, limitersData);
//            std::copy(lim2, lim2 + 2, limitersRValue);
//            std::copy(_lim3, _lim3 + 2, typeSign);

//            resCount = 4;
//            varCount = 2;
//            varType vars[] = {1, 2};
//            varType lim[] = {-1, 2, 1, 1, 1, -1, 0, 1};
//            varType lim2[] = {2, 4, 2, 6};
//            int _lim3[] = {-1, -1, 1, 1};
//            allocData();
//            std::copy(vars, vars + 2, variables);
//            std::copy(lim, lim + 8, limitersData);
//            std::copy(lim2, lim2 + 4, limitersRValue);
//            std::copy(_lim3, _lim3 + 4, typeSign);
        }
    };
}

#endif //SIMPLEXMETHOD_APPLICATION_H
