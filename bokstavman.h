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

private:
  Ui::BokstavMan *ui;
  BokstavController logic;
};

#endif // BOKSTAVMAN_H
