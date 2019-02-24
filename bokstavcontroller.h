#ifndef BOKSTAVCONTROLLER_H
#define BOKSTAVCONTROLLER_H
#include <random>
#include <string>
#include <vector>

class BokstavController {
public:
  BokstavController();
  bool slurpFile(std::string filename);

  std::string getRandomLetter();

private:
  std::vector<std::string> letter;
  std::vector<std::string> name;
  std::default_random_engine generator;
};

#endif // BOKSTAVCONTROLLER_H
