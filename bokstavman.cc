#include "bokstavman.h"
#include "ui_bokstavman.h"
#include <iostream>

BokstavMan::BokstavMan(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BokstavMan) {
  ui->setupUi(this);
  bool fail = logic.slurpFile("data.txt");
  if (fail) {
    std::cout << "Errol!!\n";
  }
  ui->radioAlfa->setText(logic.getRandomLetter().c_str());
}

BokstavMan::~BokstavMan() { delete ui; }

void BokstavMan::on_checkButton_clicked() {
  ui->radioAlfa->clear();
  ui->radioAlfa->setText(logic.getRandomLetter().c_str());
}
