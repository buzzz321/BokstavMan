#include "bokstavcontroller.h"
#include <chrono>
#include <fstream>
#include <iostream>

#include <vector>
BokstavController::BokstavController() {
  long seed = std::chrono::system_clock::now().time_since_epoch().count();
  generator.seed(seed);
}

bool BokstavController::slurpFile(std::string filename) {
  std::ifstream ifs;
  char token[256];
  ifs.open(filename, std::ifstream::in);

  if (!ifs.is_open()) {
    return false;
  }
  ifs.getline(token, sizeof(token)); // read version number and discard for now

  while (ifs.good()) {
    ifs.getline(token, sizeof(token), '\t'); // read letter for alfpabet
    letter.push_back(token);
    ifs.getline(token, sizeof(token)); // read abervation for letter
    name.push_back(token);
    std::cout << letter.back() << " " << name.back() << std::endl;
  }

  return true;
}

std::string BokstavController::getRandomLetter() {

  std::uniform_int_distribution<unsigned long> distribution(0,
                                                            letter.size() - 1);
  unsigned long dice_roll = distribution(generator);

  return letter[dice_roll];
}
