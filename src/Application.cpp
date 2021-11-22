//
// Created by NePutin on 9/29/2021.
//

#include "../include/Application.h"

void sm::Application::setTheme()
{
    ImGuiStyle* style = &ImGui::GetStyle();
    style->WindowPadding = ImVec2(10, 9);
    style->WindowRounding = 5.0f;
    style->FramePadding = ImVec2(3, 5);
    style->FrameRounding = 3.0f;
    style->ItemSpacing = ImVec2(10, 8);
    style->ItemInnerSpacing = ImVec2(8, 6);
    style->IndentSpacing = 25.0f;
    style->ScrollbarSize = 12.0f;
    style->ScrollbarRounding = 9.0f;
    style->GrabMinSize = 6.0f;
    style->GrabRounding = 3.0f;
    style->AntiAliasedLinesUseTex = false;

    style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
    style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
    style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
    style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
    style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
    style->Colors[ImGuiCol_FrameBg] = ImVec4(0.324, 0.154, 0.415, 1.00f);
    style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.215f, 0.192f, 0.337f, 1.00f);
    style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_TitleBg] = ImVec4(0.117f, 0.074f, 0.207f, 1.00f);
    style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.117f, 0.074f, 0.207f, 1.00f);
    style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.127f, 0.08f, 0.3f, 1.00f);
    style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.211f, 0.133f, 0.368f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
    style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_CheckMark] = ImVec4(0.831f, 0.286f, 1.f, 0.58f);
    style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
    style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_Button] = ImVec4(0.263, 0.221, 0.485, 1.00f);
    style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.1f, 0.3f, 1.00f);
    style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.24f, 0.11f, 0.45f, 1.00f);
    style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.188f, 0.043f, 0.274f, 1.00f);
    style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.325f, 0.011f, 0.447f, 1.00f);
    style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.266f, 0.098f, 0.87f, 0.00f);
    style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.172f, 0.f, 1.f, 1.00f);
    style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
    style->Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.98f, 0.95f, 0.83f);
}

void sm::Application::initDataLayout()
{
    ImGui::PushItemWidth(100);

    ImGui::Spacing();
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) / 2);
    ImGui::Text("Enter the initial data.");
    ImGui::Spacing();

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y - (ImGui::GetWindowSize().y / 2 - 150)) / 2);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 241) / 2);
    ImGui::DragInt("Number of variables (0<n<=5)", &varCount, 1, 0, 5);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 241) / 2);
    ImGui::DragInt("Number of restrictions (0<n<=5)", &resCount, 1, 0, 5);

    if (varCount > 5)
        varCount = 5;

    if (resCount > 5)
        resCount = 5;

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 120) / 2);
    if (ImGui::Button("Next Step", {120, 0}))
    {
        if (resCount > 0 && varCount > 0)
            state = OTHERDATA;
    }
    ImGui::PopItemWidth();
}

void sm::Application::solutionLayout()
{
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
    ImGui::BeginChild("SolutionTitle", {0, 45}, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDecoration);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 70) / 2);
    ImGui::Text("Solution");
    ImGui::EndChild();
    ImGui::PopStyleVar();
    if (s.getState() == SimplexMethod::cantBeSolved)
    {
        ImGui::TextColored(ImVec4{0.775, 0.277, 0.247, 1}, "This task cannot be solved.");
    } else
    {
        ImGui::BeginChild("SolutionMain", {0, window->getSize().y - 200.f}, ImGuiWindowFlags_NoScrollbar);
        if (s.getState() == SimplexMethod::waitData)
            s.init(varCount, resCount, variables, limitersData, limitersRValue, typeSign);
        ImGui::SetCursorPosX((wSize.x) / 2);
        if ((s.getState() != SimplexMethod::waitData && s.getState() != SimplexMethod::algorithmDone) &&
            ImGui::Button("iteration", {100, 0}))
            dataS.emplace_back(s.iteration3().second);

        ImGui::SameLine();
        ImGui::SetCursorPosX((wSize.x - 300) / 2);
        if ((s.getState() != SimplexMethod::waitData && s.getState() != SimplexMethod::algorithmDone) &&
            ImGui::Button("auto", {100, 0}))
        {
            bool next = true;
            while (next)
            {
                auto val = s.iteration3();
                dataS.emplace_back(val.second);
                next = val.first;
            }
        }
        ImGui::Spacing();
        int index = 0;
        for (auto& d: dataS)
        {
            ImGui::PushID(index);
            auto label =
                    "Iteration index: " + std::to_string(++index) +
                    ((d.getType() == SnapshotData::result) ? ". Has Result." : ".");
            bool open = ImGui::CollapsingHeader(label.c_str());
            if (open)
            {
                ImGui::Text("Type: %s", d.typeToString().c_str());
                switch (d.getType())
                {
                    case SnapshotData::main:
                        simplex_table_print(d);
                        break;
                    case SnapshotData::result:
                        result_print(d);
                        break;
                    case SnapshotData::negativeRemove:
                        remove_neg_coeff_print(d);
                        break;
                    case SnapshotData::deltas:
                        deltas_table_print(d);
                        break;
                    case SnapshotData::bazis:
                        bazis_table_print(d);
                        break;
                }
            }
            ImGui::PopID();
        }
        ImGui::EndChild();
    }
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
    ImGui::BeginChild("SolNavigation", {0, 60}, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDecoration);
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SetCursorPosX((wSize.x - 280.f) / 2.f);
    if (ImGui::Button("Go back to the beginning", {280, 0}))
    {
        dataS.clear();
        s.clear();
        clear();
        state = INITIALDATA;
    }
    ImGui::EndChild();
    ImGui::PopStyleVar();
}

void sm::Application::inputDataLayout()
{
    allocData();
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 70) / 2);
    ImGui::Text("Data entry.");

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::Text("f = c_1*x_1 + x_2*x_2 + ... + c_n*x_n");
    if (ImGui::BeginTable("##table1", varCount, ImGuiTableFlags_SizingStretchProp))
    {
        ImGui::TableNextRow();
        for (int column = 0; column < varCount; ++column)
        {
            ImGui::PushID(column);
            ImGui::TableNextColumn();
            std::string label = "X" + std::to_string(column);
            ImGui::InputScalar(label.c_str(), ImGuiDataType_Double, &variables[column], NULL, NULL,
                               "%.2f");
            ImGui::PopID();
        }
        ImGui::EndTable();
    }

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::Text("a_1*x_1 + a_2*x_2 + ... + a_n*x_n [>=,=,<=] B");
    if (ImGui::BeginTable("##table2", varCount + 2,
                          ImGuiTableFlags_SizingStretchProp))
    {
        for (int row = 0; row < resCount; row++)
        {
            ImGui::PushID(row);
            ImGui::TableNextRow();
            for (int column = 1; column < varCount + 1; column++)
            {
                ImGui::TableNextColumn();
                std::string label = "x" + std::to_string(column) + "##" + std::to_string(row + column);
                ImGui::InputScalar(label.c_str(), ImGuiDataType_Double, &limitersData[(column - 1) + (row * varCount)], NULL, NULL,
                                   "%.2f");
            }

            ImGui::TableNextColumn();
            if (ImGui::Button(signToStr((_sign) typeSign[row]).c_str(), {70, 0}))
                ImGui::OpenPopup("sign_popup");
            if (ImGui::BeginPopup("sign_popup"))
            {
                for (int i = -1; i < 2; i++)
                    if (ImGui::Selectable(signToStr((_sign) i).c_str()))
                        typeSign[row] = (int) i;
                ImGui::EndPopup();
            }

            ImGui::TableNextColumn();
            ImGui::SetNextItemWidth(70);
            ImGui::InputScalar("B", ImGuiDataType_Double, &limitersRValue[row], NULL, NULL,
                               "%.2f");
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
    ImGui::Text("x_i>=0, i = 1..n");

    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 120) / 2);
    ImGui::SetCursorPosY((ImGui::GetCursorPos().y + 150));
    if (ImGui::Button("Next Step", {120, 0}))
        state = SOLUTION;
}

void sm::Application::handleEvent(sf::Event& event)
{
    while (window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window->close();
            break;
        }
    }
}

void sm::Application::draw()
{
    window->clear(sf::Color{113, 48, 255});
    ImGui::SFML::Render(*window);
    window->display();
}

void sm::Application::start()
{
    while (window->isOpen())
    {
        sf::Event event{};
        handleEvent(event);
        ImGui::SFML::Update(*window, deltaClock.restart());
        update();
        draw();
    }
}

void sm::Application::allocData()
{
    if (!alloc)
    {
        limitersData = new varType[resCount * varCount]();
        limitersRValue = new varType[resCount]();
        variables = new varType[varCount]();
        typeSign = new int[resCount]();
        alloc = true;
    }
}

void sm::Application::clear()
{
    if (alloc)
    {
        delete[] limitersData;
        delete[] limitersRValue;
        delete[] variables;
        delete[] typeSign;
        resCount = 0;
        varCount = 0;
        alloc = false;
    }
}

std::string sm::Application::signToStr(sm::Application::_sign s)
{
    std::string arr[] = {"=", ">=", "<="};
    switch (s)
    {
        case EQUAL:
            return arr[0];
            break;
        case GREATEROREQUAL:
            return arr[1];
            break;
        case LESSOREQUAL:
            return arr[2];
            break;
    }
    return "";
}

void sm::Application::remove_neg_coeff_print(sm::SnapshotData& d)
{
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg
                                   | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY;
    ImGui::Spacing();
    if (d.getX() >= 0 && d.getY() >= 0)
    {
        ImGui::Text("resolving row = %i | resolving column = %i | resolving element = %f", d.getX(), d.getY(),
                    d.getResolvingElement());
        if (ImGui::BeginTable("##table_old", d.size().second, flags, {0, 150}))
        {
            for (int i = 0; i < d.size().first; ++i)
            {
                ImGui::TableNextRow();
                for (int j = 0; j < d.size().second; ++j)
                {
                    ImGui::TableNextColumn();
                    ImGui::Text("[%i][%i] = %.2f ", i, j, d.getOldData(i, j));
                    if (i == d.getX())
                    {
                        ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.111, 0.646, 0.875, 0.9));
                        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                    }
                    if (j == d.getY())
                    {
                        ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.498, 0.322, 0.875, 0.9));
                        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                    }
                    if (i == d.getX() && j == d.getY())
                    {
                        ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.178, 0.210, 0.875, 0.9));
                        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                    }
                }
            }
            ImGui::EndTable();
        }
    } else
        ImGui::Text("Go to the next step.");

    if (ImGui::BeginTable("##table_new", d.size().second, flags, {0, 150}))
    {
        for (int i = 0; i < d.size().first; ++i)
        {
            ImGui::TableNextRow();
            for (int j = 0; j < d.size().second; ++j)
            {
                ImGui::TableNextColumn();
                ImGui::Text("[%i][%i] = %.2f ", i, j, d.getNewData(i, j));
                if (i == d.getX() || j == d.getY())
                {
                    ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.111, 0.646, 0.875, 0.9));
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                }
            }
        }
        ImGui::EndTable();
    }
}

void sm::Application::deltas_table_print(sm::SnapshotData& d)
{
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg
                                   | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY;
    ImGui::Spacing();
    if (ImGui::BeginTable("##table", d.size().second / 2 + 1, flags, {0, 150}))
    {
        for (int i = 0; i < (d.size().second - 1) / 2; ++i)
        {
            auto num = std::to_string(i);
            std::string label = "C_e_" + num + " * a_ij";
            ImGui::TableSetupColumn(label.c_str());
        }
        ImGui::TableSetupColumn("C_i");
        ImGui::TableSetupColumn("delta");
        ImGui::TableHeadersRow();
        for (int i = 0; i < d.size().first; ++i)
        {
            ImGui::TableNextRow();
            auto sz = d.size().second;
            for (int j = 1; j < sz / 2; ++j)
            {
                ImGui::TableNextColumn();
                ImGui::Text("%.2f * %.2f", d.getNewData(i, j * 2 - 1), d.getNewData(i, j * 2 - 2));
            }
            ImGui::TableNextColumn();
            ImGui::Text("%.2f", d.getNewData(i, d.size().second - 2));
            ImGui::TableNextColumn();
            ImGui::Text("%.2f", d.getNewData(i, d.size().second - 1));
        }
        ImGui::EndTable();
    }
}

void sm::Application::simplex_table_print(sm::SnapshotData& d)
{
    std::string label;
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg
                                   | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY;
    if (d.getX() >= 0 && d.getY() >= 0)
    {
        ImGui::Text("resolving row = %i | resolving column = %i | resolving element = %f", d.getX(), d.getY(),
                    d.getResolvingElement());
        ImGui::Spacing();
        if (ImGui::BeginTable("##table_old", d.size().second, flags, {0, 150}))
        {
            for (int i = 0; i < (d.size().second - 1); ++i)
            {
                auto num = std::to_string(i);
                label = "old_x_" + num;
                ImGui::TableSetupColumn(label.c_str());
            }
            ImGui::TableSetupColumn("B");
            ImGui::TableHeadersRow();
            for (int i = 0; i < d.size().first; ++i)
            {
                ImGui::TableNextRow();
                for (int j = 0; j < d.size().second; ++j)
                {
                    ImGui::TableNextColumn();
                    ImGui::Text("[%i][%i] = %.2f ", i, j, d.getOldData(i, j));
                    if (d.getX() >= 0 && d.getY() >= 0)
                    {
                        if (i == d.getX())
                        {
                            ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.111, 0.646, 0.875, 0.9));
                            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                        }
                        if (j == d.getY())
                        {
                            ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.498, 0.322, 0.875, 0.9));
                            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                        }
                        if (i == d.getX() && j == d.getY())
                        {
                            ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.178, 0.210, 0.875, 0.9));
                            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                        }
                    }
                }
            }
            ImGui::EndTable();
        }
    } else
        ImGui::Text("All deltas are negative, go to the next step");

    if (ImGui::BeginTable("##table_new", d.size().second, flags, {0, 150}))
    {
        for (int i = 0; i < (d.size().second - 1); ++i)
        {
            auto num = std::to_string(i);
            label = "new_x_" + num;
            ImGui::TableSetupColumn(label.c_str());
        }
        ImGui::TableSetupColumn("B");
        ImGui::TableHeadersRow();
        for (int i = 0; i < d.size().first; ++i)
        {
            ImGui::TableNextRow();
            for (int j = 0; j < d.size().second; ++j)
            {
                ImGui::TableNextColumn();
                ImGui::Text("[%i][%i] = %.2f ", i, j, d.getNewData(i, j));
                if (d.getX() >= 0 && d.getY() >= 0)
                {
                    if (i == d.getX() || j == d.getY())
                    {
                        ImU32 cell_bg_color = ImGui::GetColorU32(ImVec4(0.111, 0.646, 0.875, 0.9));
                        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
                    }
                }
            }
        }
        ImGui::EndTable();
    }
}

void sm::Application::result_print(sm::SnapshotData& d)
{
    stream.str("");
    for (int i = 0; i < d.size().first - 2; ++i)
        stream << d.getResult(i) << " + ";
    stream << d.getResult(d.size().first - 2) << " = " << d.getResult(d.size().first - 1);
    ImGui::Text("answer: %s", stream.str().c_str());
}

void sm::Application::update()
{
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoDecoration;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    window_flags |= ImGuiWindowFlags_NoFocusOnAppearing;
    wSize = {window->getSize().x / 1.05f, window->getSize().y / 1.05f};

    ImGui::SetNextWindowSize(ImVec2(wSize.x, wSize.y));
    ImGui::SetNextWindowBgAlpha(0.9);

    ImGui::SetNextWindowPos(ImVec2((window->getSize().x - (wSize.x)) / 2,
                                   (window->getSize().y - (wSize.y)) / 2), ImGuiCond_Always, {0, 0});

    ImGui::Begin("MainWindow", NULL, window_flags);
    switch (state)
    {
        case INITIALDATA:
            initDataLayout();
            break;
        case OTHERDATA:
            inputDataLayout();
            break;
        case SOLUTION:
            solutionLayout();
            break;
    }
    ImGui::End();
}

void sm::Application::bazis_table_print(sm::SnapshotData& d)
{
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg
                                   | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY;

    if (ImGui::BeginTable("##table6", d.size().second, flags, {0, 150}))
    {
        for (int i = 0; i < d.size().first; ++i)
        {
            ImGui::TableNextRow();
            for (int j = 0; j < d.size().second; ++j)
            {
                ImGui::TableNextColumn();
                ImGui::Text("[%i][%i] = %f ", i, j, d.getOldData(i, j));
            }
        }
        ImGui::EndTable();
    }

    if (ImGui::BeginTable("##table7", d.size().second, flags, {0, 150}))
    {
        for (int i = 0; i < d.size().first; ++i)
        {
            ImGui::TableNextRow();
            for (int j = 0; j < d.size().second; ++j)
            {
                ImGui::TableNextColumn();
                ImGui::Text("[%i][%i] = %f ", i, j, d.getNewData(i, j));
            }
        }
        ImGui::EndTable();
    }
}
