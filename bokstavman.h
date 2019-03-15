#ifndef BOKSTAVMAN_H
#define BOKSTAVMAN_H

#include "bokstavcontroller.h"

#include <QMainWindow>

namespace Ui {
class BokstavMan;
}

class BokstavMan : public QMainWindow {
  Q_OBJECT

public:
  explicit BokstavMan(QWidget *parent = nullptr);
  ~BokstavMan();

private slots:
  void on_checkButton_clicked();

  void on_lineEdit_returnPressed();

private:
  Ui::BokstavMan *ui;
  BokstavController logic;
  void checkAnswer();
};

#endif // BOKSTAVMAN_H
