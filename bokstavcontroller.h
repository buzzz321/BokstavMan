#ifndef BOKSTAVCONTROLLER_H
#define BOKSTAVCONTROLLER_H
#include <QString>
#include <map>
#include <random>
#include <string>
#include <tuple>
#include <vector>

using RadioAlphbet = std::map<QString, QString>;
class BokstavController {
public:
  BokstavController();
  bool slurpFile(std::string filename);

  QString getRandomLetter();
  std::tuple<bool, QString> checkIfCorrect(QString letter, QString answer);

private:
  RadioAlphbet alpha;
  std::vector<QString> letter;
  std::default_random_engine generator;
};

#endif // BOKSTAVCONTROLLER_H
