#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLineEdit>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget *tabWidget;

    QLineEdit *lineLengthFrom, *lineLengthTo;
    QComboBox *comboLengthFrom, *comboLengthTo;

    QLineEdit *lineMassFrom, *lineMassTo;
    QComboBox *comboMassFrom, *comboMassTo;

    QLineEdit *lineTempFrom, *lineTempTo;
    QComboBox *comboTempFrom, *comboTempTo;

    void setupUI();
    void setupComboBoxes();
    void setupValidators();
};

#endif
