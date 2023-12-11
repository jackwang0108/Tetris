#include <fstream>
#include <iostream>
#include <filesystem>
#include <tetris.hpp>
#include <argparse/argparse.hpp>

int main(int argc, char *argv[])
{
    argparse::ArgumentParser program("Tetris");
    program.add_description("Command-line Tetris Game, created by Jack Wang for practicing C++");
    program.add_argument("-l", "--start-level")
        .help("Start level of the game.")
        .scan<'i', int>()
        .default_value("1");

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    try
    {

        auto startLevel = program.get<int>("start-level");
        std::cout << startLevel << std::endl;
    }
    catch (const std::exception &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }
    return 0;
}