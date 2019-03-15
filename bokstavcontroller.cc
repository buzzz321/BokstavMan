#include "bokstavcontroller.h"
#include <chrono>
#include <fstream>
#include <iostream>

#include <vector>
BokstavController::BokstavController() {
  unsigned long seed = (unsigned long)std::chrono::system_clock::now()
                           .time_since_epoch()
                           .count();
  generator = std::default_random_engine(seed);
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
    ifs.getline(token, sizeof(token), '\t'); // read letter for alphabet
    QString letter(token);
    if (letter == "") {
      continue;
    }
    this->letter.push_back(letter);
    ifs.getline(token, sizeof(token)); // read abervation for letter
    alpha[letter] = token;
    // std::cout << letter.toStdString() << " " << token << std::endl;
  }

  return true;
}

QString BokstavController::getRandomLetter() {

  std::uniform_int_distribution<unsigned long> distribution(0,
                                                            alpha.size() - 1);
  unsigned long dice_roll = distribution(generator);

  return letter[dice_roll];
}

std::tuple<bool, QString> BokstavController::checkIfCorrect(QString letter,
                                                            QString answer) {
  auto found = alpha.find(letter);
  auto end = alpha.cend();
  if (found != end) {
    if (found->second.toLower() == answer) {
      return std::make_tuple(true, "");
    }
    return std::make_tuple(false, found->second);
  }

  return std::make_tuple(false, "Error");
}
