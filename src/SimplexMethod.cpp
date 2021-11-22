//
// Created by NePutin on 9/29/2021.
//

#include "../include/SimplexMethod.h"

void sm::SimplexMethod::clear()
{
    for (int i = 0; i < deltasData_size.first; ++i)
        delete[] deltasData[i];
    for (int i = 0; i < limits_size.first; ++i)
        delete[] limits[i];
    for (int i = 0; i < limits_size.first; ++i)
        delete[] limits_old[i];
    delete[] limits;
    delete[] limits_old;
    delete[] deltasData;
    delete[] resultData;
    vars = nullptr;
    _varCount = 0;
    _limitedCount = 0;
    resolvingElement = 0;
    resolutionColumn = -1;
    resolutionRow = -1;
    leadingColumn = -1;
    leadingRow = -1;
    orderCoefficients.clear();
    state = waitData;
}

void
sm::SimplexMethod::init(int varCount, int limitedCount, sm::SimplexMethod::varType* variables, sm::SimplexMethod::varType* limitations1,
                        sm::SimplexMethod::varType* limitations2, int* limitations3)
{
    if (state == waitData)
    {
        _varCount = varCount;
        _limitedCount = limitedCount;
        vars = variables;

        for (int i = 0; i < limitedCount; ++i)
            if (*(limitations3 + i) == 0)
                needBazis.emplace(i);

        resultData_size = _limitedCount + _varCount + 1 - needBazis.size();
        limits_size.first = limitedCount + 1;
        limits_size.second = varCount + limitedCount + 1 - needBazis.size();
        deltasData_size.first = limits_size.second;
        deltasData_size.second = _limitedCount * 2 + 2;

        float limTest[limits_size.first][limits_size.second];

        deltasData = new varType* [deltasData_size.first];
        for (int i = 0; i < deltasData_size.first; ++i)
            deltasData[i] = new varType[deltasData_size.second];
        resultData = new varType[resultData_size];

        limits = new varType* [limits_size.first];
        for (int i = 0; i < limits_size.first; ++i)
            limits[i] = new varType[limits_size.second];

        limits_old = new varType* [limits_size.first];
        for (int i = 0; i < limits_size.first; ++i)
            limits_old[i] = new varType[limits_size.second];
        for (int i = 0; i < limits_size.first ; ++i) //value of all cells to zero
            std::fill(limits[i], limits[i] + limits_size.second, 0);

        for (int i = 0; i < limits_size.first - 1; ++i) //set x_ij value
        {
            for (int j = 0; j < varCount; ++j)
            {
                limits[i][j] = *(limitations1 + (j + (i * varCount)));
                limTest[i][j] = limits[i][j];
            }
        }

        for (int i = 0; i < limits_size.first; ++i) //set b_i value
        {
            limits[i][limits_size.second - 1] = *(limitations2 + i);
            limTest[i][limits_size.second - 1] = limits[i][limits_size.second - 1];
        }

        int mustBeNegative[_limitedCount];
        std::fill(mustBeNegative, mustBeNegative + _limitedCount, 1);
        int jOffset = varCount;
        for (int i = 0; i < limitedCount; ++i)
        {
            int z = *(limitations3 + i);
            if (z == 1)
            {
                limits[i][jOffset] = z;
                limTest[i][jOffset] = limits[i][jOffset];
                jOffset++;
            } else if (z < 0)
            {
                mustBeNegative[i] = -1;
                limits[i][jOffset] = z;
                limTest[i][jOffset] = limits[i][jOffset];
                jOffset++;
            }
        }

//        int jOffset = 0;
//        for (int i = 0, i_2 = 0; i < limits_size.first; ++i) //coefficients of the basic variables
//        {
//            for (int j = varCount; j < limits_size.second - 1; ++j)
//            {
//                if (needBazis.count(i) == 0 && j == varCount + jOffset)
//                {
//                    if (*(limitations3 + i_2) < 0)
//                    {
//                        mustBeNegative[i] = -1;
//                    }
//                    limits[i][j] = *(limitations3 + i_2);
//                    limTest[i][j] = limits[i][j];
//                } else
//                {
//                    limits[i][j] = 0;
//                    limTest[i][j] = limits[i][j];
//                }
//            }
//            i_2++;
//            ++jOffset;
//        }

        limits[limitedCount][0] = 0;
        for (int i = 0; i < limits_size.first; ++i) //canonical form
        {
            for (int j = 0; j < limits_size.second; ++j)
            {
                if (limits[i][j] != 0)
                    limits[i][j] *= mustBeNegative[i];
                limTest[i][j] = limits[i][j];
            }
        }

        for (int i = 0; i < limits_size.second; ++i) //set deltas as zero
        {
            limits[limitedCount][i] = 0;
        }

        for (int i = 0; i < limitedCount - needBazis.size(); ++i) //default C_i init
            orderCoefficients.emplace(i, limitedCount + i);

        if (needBazis.size() > 0)
            state = bazisFind;
        else
            state = removeNegativeCoefficent;
    }
}

void sm::SimplexMethod::findBazis()
{
    for (int i = 0; i < limits_size.first; ++i)
    {
        for (int j = 0; j < limits_size.second; ++j)
            limits_old[i][j] = limits[i][j];
    }
    for (auto val: needBazis)
    {
        int res2 = -1;
        for (int i = 0; i < limits_size.second - 1; ++i)
        {
            varType _val = limits[val][i];
            if (!compare_float(_val, 0))
            {
                res2 = i;
                break;
            }
        }

        resolvingElement = limits[val][res2];
        for (int i = 0; i < limits_size.second; ++i)
        {
            varType a = limits[val][i];
            varType res = a / resolvingElement;
            limits[val][i] = res;
        }
        for (int i = 0; i < limits_size.first - 1; ++i)
        {
            if (i != val)
            {
                auto b = limits[i][res2];
                for (int j = 0; j < limits_size.second; ++j)
                {
                    varType a = limits[val][j];
                    limits[i][j] -= a * b;
                }
            }
        }
        orderCoefficients.insert_or_assign(val, res2);
    }
    state = removeNegativeCoefficent;
}


void sm::SimplexMethod::simplexMethod_iterative()
{
    if (positiveDCheck())
    {
        for (int i = 0; i < limits_size.first; ++i)
        {
            for (int j = 0; j < limits_size.second; ++j)
                limits_old[i][j] = limits[i][j];
        }
        varType maxDelta = 0;
        resolutionColumn = -1;
        for (int i = 0; i < limits_size.second - 1; ++i)
        {
            varType val = limits[limits_size.first - 1][i];
            if (val > 0 && !compare_float(maxDelta, val) && maxDelta < val)
            {
                maxDelta = val;
                resolutionColumn = i;
            }
        }

        bool allNegative = true;

        varType minBDiv = std::numeric_limits<int>::max();
        resolutionRow = -1;
        for (int i = 0; i < _limitedCount; ++i)
        {
            varType a = limits[i][limits_size.second - 1];
            varType b = limits[i][resolutionColumn];
            if (b > 0)
                allNegative = false;
            varType res = (b > 0 && !compare_float(b, 0) && !compare_float(a, 0)) ? (a / b) : std::numeric_limits<int>::max();
            if (res < minBDiv)
            {
                minBDiv = res;
                resolutionRow = i;
            }
        }

        if (allNegative)
        {
            state = cantBeSolved;
            return;
        }

        if (resolutionRow == -1 || resolutionColumn == -1)
        {
            state = cantBeSolved;
            return;
        }

        resolvingElement = limits[resolutionRow][resolutionColumn];
        for (int i = 0; i < limits_size.second; ++i)
        {
            varType a = limits[resolutionRow][i];
            varType res = a / resolvingElement;
            limits[resolutionRow][i] = res;
        }

        for (int i = 0; i < limits_size.first - 1; ++i)
        {
            if (i != resolutionRow)
            {
                auto b = limits[i][resolutionColumn];
                for (int j = 0; j < limits_size.second; ++j)
                {
                    varType a = limits[resolutionRow][j];
                    limits[i][j] -= a * b;
                }
            }
        }
        orderCoefficients.insert_or_assign(resolutionRow, resolutionColumn);
        state = calculationDeltas; // refresh delta value
    } else
    {
        resolutionColumn = -1;
        resolutionRow = -1;
        state = algorithmDone;
    }
}

void sm::SimplexMethod::removeNegativeCoefficientsB_itartive()
{
    if (negativeBCheck())
    {
        for (int i = 0; i < limits_size.first; ++i)
        {
            for (int j = 0; j < limits_size.second; ++j)
                limits_old[i][j] = limits[i][j];
        }
        leadingColumn = -1;
        varType max = 0;
        for (int i = 0; i < limits_size.first - 1; ++i)
        {
            varType val = limits[i][limits_size.second - 1];
            if (val < 0 && !compare_float(max, val) && std::abs(max) < std::abs(val))
            {
                max = val;
                leadingColumn = i;
            }
        }

        leadingRow = -1;
        varType max2 = 0;
        bool allPositive = true;
        for (int i = 0; i < limits_size.second - 1; ++i)
        {
            varType val = limits[leadingColumn][i];
            if (val < 0)
            {
                allPositive = false;
                if (!compare_float(max2, val) && std::abs(max2) < std::abs(val))
                {
                    max2 = val;
                    leadingRow = i;
                }
            }
        }

        if (allPositive || leadingRow == -1 || leadingRow == -1)
        {
            state = cantBeSolved;
            return;
        }

        resolvingElement = limits[leadingColumn][leadingRow];
        for (int i = 0; i < limits_size.second; ++i)
        {
            varType a = limits[leadingColumn][i];
            varType res = a / resolvingElement;
            limits[leadingColumn][i] = res;
        }
        for (int i = 0; i < limits_size.first - 1; ++i)
        {
            if (i != leadingColumn)
            {
                auto b = limits[i][leadingRow];
                for (int j = 0; j < limits_size.second; ++j)
                {
                    varType a = limits[leadingColumn][j];
                    limits[i][j] -= a * b;
                }
            }
        }
        orderCoefficients.insert_or_assign(leadingColumn, leadingRow);
    } else
    {
        leadingRow = -1;
        leadingColumn = -1;
        resolvingElement = -1;
        state = calculationDeltas;
    }
}

void sm::SimplexMethod::result()
{
    varType result = 0;
    for (int i = 0; i < limits_size.second - 1; ++i)
    {
        varType a = getVar(i);
        varType b;
        for (auto& c: orderCoefficients)
        {
            if (c.second == i)
            {
                int index = c.first;
                b = limits[index][limits_size.second - 1];
                break;
            } else b = 0;
        }
        resultData[i] = a * b;
        if (compare_float(resultData[i], 0))
            resultData[i] = 0;
        result += a * b;
    }
    resultData[limits_size.second - 1] = result;
    state = algorithmDone;
}

void sm::SimplexMethod::calculationOfDeltas()
{
    for (int i = 0; i < limits_size.second; ++i)
    {
        varType sum = 0;
        int j2 = 0;
        for (int j = 0; j < limits_size.first - 1; ++j)
        {
            varType a = getVar(orderCoefficients[j]);
            varType b = limits[j][i];
            auto res = a * b;
            deltasData[i][j2++] = a;
            deltasData[i][j2++] = b;
            sum += res;
        }
        limits[limits_size.first - 1][i] = sum - getVar(i);
        deltasData[i][j2++] = getVar(i);
        deltasData[i][j2] = limits[limits_size.first - 1][i];
    }
    state = simplexMethod;
}

bool sm::SimplexMethod::compare_float(sm::SimplexMethod::varType x, sm::SimplexMethod::varType y, sm::SimplexMethod::varType epsilon)
{
    if (fabs(x - y) < epsilon)
        return true;
    return false;
}

bool sm::SimplexMethod::negativeBCheck()
{
    bool hasNegativeB = false;
    for (int i = 0; i < _limitedCount; ++i)
    {
        varType val = limits[i][limits_size.second - 1];
        if (!compare_float(val, 0) && val < 0)
            hasNegativeB = true;
    }
    return hasNegativeB;
}

bool sm::SimplexMethod::positiveDCheck()
{
    bool hasPositiveD = false;
    for (int i = 0; i < limits_size.second - 1; ++i)
    {
        varType val = limits[limits_size.first - 1][i];
        if (val > 0 && !compare_float(val, 0))
            hasPositiveD = true;
    }
    return hasPositiveD;
}

sm::SimplexMethod::_state sm::SimplexMethod::getState()
{
    return state;
}

sm::SimplexMethod::varType sm::SimplexMethod::getVar(int i)
{
    varType var = 0;
    if (i < _varCount + 1)
        var = *(vars + i);
    return var;
}


sm::SnapshotData::SnapshotData()
        : type(main),
          sizeY(-1),
          sizeX(-1),
          mainX(-1),
          mainY(-1),
          resolvingElement(-1)
{

}

sm::SnapshotData::SnapshotData(sm::SnapshotData::_type t, int sizeX, int sizeY, varType** data_new, varType** data_old, int mainX,
                               int mainY,
                               sm::SnapshotData::varType resolvingElement)
        : type(t),
          sizeY(sizeY),
          sizeX(sizeX),
          mainX(mainX),
          mainY(mainY),
          resolvingElement(resolvingElement)
{
    data_after.resize(sizeX);
    data_before.resize(sizeX);
    for (int i = 0; i < sizeX; ++i)
    {
        data_after[i].resize(sizeY);
        data_before[i].resize(sizeY);
        for (int j = 0; j < sizeY; ++j)
        {
            data_after[i][j] = data_new[i][j];
            data_before[i][j] = data_old[i][j];
        }
    }
}

sm::SnapshotData::SnapshotData(varType** data, int sizeX, int sizeY)
        : type(deltas),
          sizeX(sizeX),
          sizeY(sizeY)
{
    data_after.resize(sizeX);
    for (int i = 0; i < sizeX; ++i)
    {
        data_after[i].resize(sizeY);
        for (int j = 0; j < sizeY; ++j)
            data_after[i][j] = data[i][j];
    }
}
