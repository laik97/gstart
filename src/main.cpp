#include <boost/program_options.hpp>
#include <iostream>
#include <string>

#include "gstart/gstart.h"
#include "shapes/workerShape.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv) {
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")(
      "level_path", po::value<std::string>(), "Path of level_creator json dump");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << desc << "\n";
    return 1;
  }

  GstartArguments args;

  if (!vm["level_path"].empty())
  { args.levelLoadPath = vm["level_path"].as<std::string>(); }

  Resolution resolution{ 800, 600 };

  auto runningWorkers = std::vector<Worker>{ Worker{
      WorkerShape{ resolution.getMiddle<sf::Vector2f, float>(), 0.0 } } };

  LevelCreator::WindowConfig windowConfig;

  if (!args.levelLoadPath.empty())
  { windowConfig = LevelCreator::LevelLoader::load(args.levelLoadPath); }

  auto world = windowConfig.level.getBuildingBlocks();

  auto game = Gstart::makeGstart(windowConfig.resolution);
  game->run(runningWorkers, world);

  return 0;
}