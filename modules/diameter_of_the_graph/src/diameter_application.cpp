// Copyright 2019 Savkin Yuriy

#include <cstring>
#include <string>
#include <stdexcept>
#include <limits>
#include "include/diameter_application.h"

std::string DiameterApplication::operator()(int argc, const char** argv) {
    if (argc <= 1) {
        return HelpInfo();
    }

    matrix m;
    if (strcmp(argv[1], "init") == 0) {
        if (argc < 3)
            return "Incorrect usage of command \"init\"";
        int n;
        try {
            n = CastNumber(argv[2]);
        }
        catch(const std::runtime_error& re) {
            return "Error with argument " +
                std::to_string(2) + ": " + re.what();
        }
        m.resize(n);
        for (int i = 0; i < n; ++i) {
            m[i].assign(n, 0);
        }
    } else if (strcmp(argv[1], "help") == 0) {
        return HelpInfo();
    } else if (strcmp(argv[1], "add") == 0) {
        return "Incorrect usage of command \"add\"";
    } else if (strcmp(argv[1], "del") == 0) {
        return "Incorrect usage of command \"del\"";
    } else {
        return "Unknown command: " + std::string(argv[1]);
    }

    int i = 3;
    while (i < argc) {
        if (strcmp(argv[i], "add") == 0) {
            int x[2];
            if (i + 2 >= argc)
                return "Error: add has too few arguments";
            for (int j = 0; j < 2; ++j) {
                try {
                    x[j] = CastNumber(argv[i + j + 1]);
                }
                catch(const std::runtime_error& re) {
                    return "Error with argument " +
                        std::to_string(i + j + 1) + ": " + re.what();
                }
                if (static_cast<unsigned>(x[j]) >= m.size())
                    return "Error with argument " +
                        std::to_string(i + j + 1) + ": out of range";
            }
            m[x[0]][x[1]] = m[x[1]][x[0]] = 1;
            i += 3;
        } else if (strcmp(argv[i], "del") == 0) {
            int x[2];
            if (i + 2 >= argc)
                return "Error: del has too few arguments";
            for (int j = 0; j < 2; ++j) {
                try {
                    x[j] = CastNumber(argv[i + j + 1]);
                }
                catch(const std::runtime_error& re) {
                    return "Error with argument " +
                        std::to_string(i + j + 1) + ": " + re.what();
                }
                if (static_cast<unsigned>(x[j]) >= m.size())
                    return "Error with argument " +
                        std::to_string(i + j + 1) + ": out of range";
            }
            m[x[0]][x[1]] = m[x[1]][x[0]] = 0;
            i += 3;
        } else if (strcmp(argv[i], "help") == 0) {
            return "Incorrect usage of command \"help\"";
        } else if (strcmp(argv[i], "init") == 0) {
            return "Incorrect usage of command \"init\"";
        } else {
            return "Unknown command: " + std::string(argv[i]);
        }
    }

    Graph gr(std::move(m), static_cast<int>(m.size()));
    int diam = gr.DiameterOfGraph();
    if (diam == std::numeric_limits<int>::max() / 2)
        return "Error: disconnected graph";
    if (diam == -2)
        return "Error: graph has no vertexes";
    return std::to_string(diam);
}

std::string DiameterApplication::HelpInfo() {
    return "Commands:\n"
           "init <number> - sets number of vertexes.\n"
           "This command must be the first and is to be used once\n"
           "add <x> <y> - adds edges (x, y) and (y, x) to graph.\n"
           "del <x> <y> - deletes edges (x, y) and (y, x) from graph.\n"
           "help - prints helping information";
}

int DiameterApplication::CastNumber(const char* num) {
    unsigned i = 0;
    int x;
    while (num[i] != '\0') {
        if (!isdigit(num[i]))
            throw std::runtime_error("not a number");
        ++i;
    }
    try {
        x = std::stoi(num);
    }
    catch (std::out_of_range& err) {
        throw std::runtime_error("too big number");
    }
    if (x > 50)
        throw std::runtime_error("too big number");
    return x;
}
