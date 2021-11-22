//
// Created by NePutin on 9/29/2021.
//

#ifndef SIMPLEXMETHOD_SIMPLEXMETHOD_H
#define SIMPLEXMETHOD_SIMPLEXMETHOD_H

#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

namespace sm
{
    class SnapshotData
    {
    public:
        enum _type
        {
            main,
            result,
            negativeRemove,
            deltas,
            bazis
        };
    private:
        using varType = double;

        int sizeX;
        int sizeY;
        int mainX;
        int mainY;
        varType* resultData;
        varType resolvingElement;
        _type type;

        std::vector<std::vector<varType>> data_after;
        std::vector<std::vector<varType>> data_before;

    public:
        SnapshotData();

        SnapshotData(_type t, int sizeX, int sizeY, varType** data_new, varType** data_old, int mainX = 0, int mainY = 0,
                     varType resolvingElement = 0);

        SnapshotData(int sizeX, varType* resultData) : resultData(resultData), type(result), sizeX(sizeX)
        {}

        SnapshotData(varType** data, int sizeX, int sizeY);

        std::string typeToString()
        {
            std::string arr[] = {"simplex table", "result of the algorithm", "getting rid of negative free coefficients",
                                 "calculation of deltas", "equality takes place in the constraints, we find the basic variables"};
            return arr[type];
        }

        varType getResolvingElement()
        {
            return resolvingElement;
        }

        int getX()
        {
            return mainX;
        }

        int getY()
        {
            return mainY;
        }

        auto getType()
        {
            return type;
        }

        std::pair<int, int> size()
        {
            return {sizeX, sizeY};
        }

        varType getResult(int i)
        {
            if (resultData != nullptr && i < sizeX)
                return resultData[i];
            else
                return -1.f;
        }

        varType getNewData(int x, int y)
        {
            if (x < sizeX && y < sizeY)
                return data_after[x][y];
            else
                return -1.f;
        }

        varType getOldData(int x, int y)
        {
            if (x < sizeX && y < sizeY)
                return data_before[x][y];
            else
                return -1.f;
        }
    };

    class SimplexMethod
    {
    public:
        enum _state
        {
            waitData,
            removeNegativeCoefficent,
            calculationDeltas,
            simplexMethod,
            algorithmDone,
            cantBeSolved,
            bazisFind
        };
    private:
        using varType = double;
        _state state = waitData;
        int _varCount;
        int _limitedCount;
        int resolutionColumn = -1;
        int resolutionRow = -1;

        int leadingColumn = -1;
        int leadingRow = -1;
        varType* vars;

        varType** limits;
        varType** limits_old;
        varType** deltasData;
        std::pair<int, int> limits_size;
        varType resolvingElement;
        varType* resultData;
        int resultData_size;

        std::pair<int, int> deltasData_size;
        std::set<int> needBazis;
        std::map<int, int> orderCoefficients;

    public:
        SimplexMethod() = default;

        ~SimplexMethod()
        { clear(); }

        void findBazis();

        void calculationOfDeltas();

        void simplexMethod_iterative();

        void result();

        void removeNegativeCoefficientsB_itartive();

        std::pair<bool, SnapshotData> iteration3()
        {
            switch (state)
            {
                case removeNegativeCoefficent:
                    removeNegativeCoefficientsB_itartive();
                    return {true,
                            SnapshotData{SnapshotData::negativeRemove, limits_size.first, limits_size.second, limits, limits_old,
                                         leadingColumn,
                                         leadingRow, resolvingElement}};
                    break;
                case calculationDeltas:
                    calculationOfDeltas();
                    return {true, SnapshotData{deltasData, deltasData_size.first, deltasData_size.second}};
                    break;
                case simplexMethod:
                    simplexMethod_iterative();
                    return {true,
                            SnapshotData{SnapshotData::main, limits_size.first, limits_size.second, limits, limits_old, resolutionRow,
                                         resolutionColumn, resolvingElement}};
                    break;
                case algorithmDone:
                    result();
                    return {false, SnapshotData{resultData_size, resultData}};
                    break;
                case cantBeSolved:
                    return {false, {}};
                    break;
                case bazisFind:
                    findBazis();
                    return {true,
                            SnapshotData{SnapshotData::bazis, limits_size.first - 1, limits_size.second, limits, limits_old, resolutionRow,
                                         resolutionColumn,
                                         resolvingElement}};
                    break;
            }
            return {};
        }

        void clear();

        bool compare_float(varType x, varType y, varType epsilon = 0.001f); //because we use negative floats, there is a loss of accuracy,
        // we compare numbers up to 3 characters
        bool negativeBCheck();

        bool positiveDCheck();

        _state getState();

        void init(int varCount, int limitedCount, varType* variables, varType* limitations1, varType* limitations2,
                  int* limitations3);

        varType getVar(int i);


    };
}

#endif //SIMPLEXMETHOD_SIMPLEXMETHOD_H
