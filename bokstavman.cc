#include "bokstavman.h"
#include "ui_bokstavman.h"
#include <iostream>

BokstavMan::BokstavMan(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BokstavMan) {
  ui->setupUi(this);
  bool success = logic.slurpFile("data.txt");
  if (!success) {
    std::cout << "Errol!!\n";
  }
  ui->radioAlfa->setText(logic.getRandomLetter());
}

BokstavMan::~BokstavMan() { delete ui; }

void BokstavMan::checkAnswer() {
  auto letter = ui->radioAlfa->text();
  auto answer = ui->lineEdit->text().toLower();
  auto correct = logic.checkIfCorrect(letter, answer);

  if (std::get<0>(correct)) {
    ui->correct->setText("Rätt!");
  } else {
    auto text = "Fel, rätt svar är: " + std::get<1>(correct);
    ui->correct->setText(text);
  }
  ui->lineEdit->clear();
  ui->radioAlfa->clear();
  ui->radioAlfa->setText(logic.getRandomLetter());
}

void BokstavMan::on_checkButton_clicked() { checkAnswer(); }

void BokstavMan::on_lineEdit_returnPressed() { checkAnswer(); }
