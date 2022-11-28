#include <boost/program_options.hpp>

#include "LevelCreator/LevelCreator.h"

int main(int argc, char** argv) {
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("width", po::value<uint>(), "set resolution width")
      ("height", po::value<uint>(), "set resolution height")
      ("save_path", po::value<std::string>(), "set level save path")
      ("load_path", po::value<std::string>(), "set level load path");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << desc << "\n";
    return 1;
  }

  LevelCreator::CreatorArguments arguments;

  if (!vm["width"].empty())
  { arguments.resolution.width = vm["width"].as<uint>(); }

  if (!vm["height"].empty())
  { arguments.resolution.height = vm["height"].as<uint>(); }

  if (!vm["save_path"].empty())
  { arguments.savePath = vm["save_path"].as<std::string>(); }

  if (!vm["load_path"].empty())
  { arguments.loadPath = vm["load_path"].as<std::string>(); }

  LevelCreator::mainLoop(arguments);

  return 0;
}