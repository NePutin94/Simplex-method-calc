//
// Created by NePutin on 9/30/2021.
//

#include "../include/SimplexMethod.h"
#include <gtest/gtest.h>

using namespace sm;
using varType = double;

TEST(SimplexMethod, params1)
{
    sm::SimplexMethod s;
    varType vars[] = {-7, -3, -5};
    varType lim[] = {1, 1, 1, 1, 2, 3, 3, 2, 1};
    varType lim2[] = {50, 73, 75};
    int lim3[] = {1, 1, 1};
    s.init(3, 3, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int) SimplexMethod::removeNegativeCoefficent);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -223, 0.1);
}

TEST(SimplexMethod, params2)
{
    sm::SimplexMethod s;
    varType vars[] = {1, -1};
    varType lim[] = {-2, 1, 1, 1, 1, -2};
    varType lim2[] = {2, 5, 12};
    int lim3[] = {1, 1, 1};
    s.init(2, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -3, 0.1);
}

TEST(SimplexMethod, params3)
{
    sm::SimplexMethod s;
    varType vars[] = {-1, 8, 3};
    varType lim[] = {3, 1, 2, 1, 1, 1, -1, 3, -1};
    varType lim2[] = {6, 4, 4};
    int lim3[] = {-1, -1, -1};
    s.init(3, 3, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int) SimplexMethod::removeNegativeCoefficent);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 14, 0.1);
}

TEST(SimplexMethod, params4)
{
    sm::SimplexMethod s;
    varType vars[] = {-1, 2};
    varType lim[] = {1, -1, 3, -4, 1, 0};
    varType lim2[] = {3, -12, 5};
    int lim3[] = {1, -1, 1};
    s.init(2, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -3, 0.1);
}

TEST(SimplexMethod, params5)
{
    sm::SimplexMethod s;
    varType vars[] = {10, 12, 8};
    varType lim[] = {3, 4, 2, 4, 3, 3, 5, 3, 5};
    varType lim2[] = {1020, 940, 1010};
    int lim3[] = {1, 1, 1};
    s.init(3, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 0, 0.1);
}

TEST(SimplexMethod, params6) //unsolvable
{
    sm::SimplexMethod s;
    varType vars[] = {2, 1, -2};
    varType lim[] = {1, 1, -1, 1, -1, 2, -2, -8, 3};
    varType lim2[] = {8, 2, 1};
    int lim3[] = {-1, -1, -1};
    s.init(3, 3, vars, lim, lim2, lim3);
    bool check = false;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
        {
            check = true;
            break;
        }
    }
    ASSERT_EQ(check, true);
}

TEST(SimplexMethod, params7)
{
    sm::SimplexMethod s;
    varType vars[] = {3, 2, 1};
    varType lim[] = {0, 1, -1, 2, 1, 2, 2, -1, 2};
    varType lim2[] = {4, 6, 2};
    int lim3[] = {-1, -1, -1};
    s.init(3, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 17, 0.1);
}

TEST(SimplexMethod, params8)
{
    sm::SimplexMethod s;
    varType vars[] = {5, 10, 8};
    varType lim[] = {3, 5, 2, 4, 4, 4, 2, 4, 5};
    varType lim2[] = {60, 72, 100};
    int lim3[] = {1, 1, 1};
    s.init(3, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 0, 0.1);
}

TEST(SimplexMethod, params9)
{
    sm::SimplexMethod s;
    varType vars[] = {-4, -5};
    varType lim[] = {-1, 1, 1, 1};
    varType lim2[] = {4, 6};
    int lim3[] = {0, 0};
    s.init(2, 2, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -29, 0.1);
}

TEST(SimplexMethod, params10)
{
    sm::SimplexMethod s;
    varType vars[] = {1, 2};
    varType lim[] = {-1, 2, 1, 1, 1, -1, 0, 1};
    varType lim2[] = {2, 4, 2, 6};
    int lim3[] = {-1, -1, 1, 1};
    s.init(2, 4, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 6, 0.1);
}

TEST(SimplexMethod, params11)
{
    sm::SimplexMethod s;
    varType vars[] = {1, -3, 2};
    varType lim[] = {3, -1, 2, -2, 4, 0, -4, 3, 8};
    varType lim2[] = {7, 12, 10};
    int lim3[] = {1, 1, 1};
    s.init(3, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -11, 0.1);
}

TEST(SimplexMethod, params12)
{
    sm::SimplexMethod s;
    varType vars[] = {1, 1, 3};
    varType lim[] = {2, 1, 3, 1, 2, 4, 3, 1, -2};
    varType lim2[] = {6, 8, 4};
    int lim3[] = {-1, -1, -1};
    s.init(3, 3, vars, lim, lim2, lim3);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 14.f / 3.f, 0.1);
}

TEST(SimplexMethod, params13) //unsolvable
{
    sm::SimplexMethod s;
    varType vars[] = {-1, -100};
    varType lim[] = {2, 3, 3, 4, 54, 3};
    varType lim2[] = {-100, 2, 3};
    int lim3[] = {1, 1, 1};
    s.init(2, 3, vars, lim, lim2, lim3);
    bool check = false;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
        {
            check = true;
            break;
        }
    }
    ASSERT_EQ(check, true);
}

TEST(SimplexMethod, params14)
{
    sm::SimplexMethod s;
    varType vars[] = {-1,2,-1};
    varType lim[] = {1,4,1, 1,-2,1};
    varType lim2[] = {5,-1};
    int lim3[] = {0,0};
    s.init(3, 2, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int)SimplexMethod::bazisFind);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 1, 0.1);
}

TEST(SimplexMethod, params15)
{
    sm::SimplexMethod s;
    varType vars[] = {1,3,2,4,-2};
    varType lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
    varType lim2[] = {-2,0,7};
    int lim3[] = {0,0,0};
    s.init(5, 3, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int)SimplexMethod::bazisFind);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 23.f/4.f, 0.1);
}

TEST(SimplexMethod, params16)
{
    sm::SimplexMethod s;
    varType vars[] = {1,3,2,4,-2};
    varType lim[] = {-1,0,1,-2,-2, 0,1,-1,1,-2, 2,1,0,5,4};
    varType lim2[] = {-2,0,7};
    int lim3[] = {0,1,0};
    s.init(5, 3, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int)SimplexMethod::bazisFind);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, -(1.f/2.f), 0.1);
}

TEST(SimplexMethod, params17)
{
    sm::SimplexMethod s;
    varType vars[] = {9,5,4,3,2};
    varType lim[] = {1,-2,2,0,0, 1,2,1,1,0, 2,1,-4,0,2};
    varType lim2[] = {6,24,30};
    int lim3[] = {1,0,0};
    s.init(5, 3, vars, lim, lim2, lim3);
    ASSERT_EQ((int) s.getState(), (int)SimplexMethod::bazisFind);
    varType result = -1;
    while (true)
    {
        auto data = s.iteration3();
        if (data.second.getType() == sm::SnapshotData::result)
        {
            result = data.second.getResult(data.second.size().first - 1);
            break;
        }
        if (s.getState() == sm::SimplexMethod::cantBeSolved)
            break;
    }
    EXPECT_NEAR(result, 78.f, 0.1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}