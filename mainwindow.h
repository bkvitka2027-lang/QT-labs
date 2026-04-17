#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "Converter.h"

QT_BEGIN_NAMESPACE
class QTabWidget;
class QWidget;
class QLineEdit;
class QComboBox;
class QDoubleValidator;
QT_END_NAMESPACE
=======
#include <QTabWidget>
#include <QLineEdit>
#include <QComboBox>
>>>>>>> fdccab4731117b96d59bb5faf2cb18834e6859f2

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

<<<<<<< HEAD
private slots:
    void onTopTextEdited();
    void onBottomTextEdited();
    void onUnitChanged();
    void onTabChanged(int index);

private:
    void setupUI();
    void createLengthTab();
    void createMassTab();
    void createTemperatureTab();
    void updateFromTop(bool isUserInput = true);
    void updateFromBottom(bool isUserInput = true);
    void performConversionAndUpdate(QLineEdit* sourceEdit, QLineEdit* targetEdit,
                                    int fromUnitIndex, int toUnitIndex);
    bool isValidNumber(const QString& text) const;
    QString formatNumber(double value) const;

    Converter m_converter;
    QTabWidget* m_tabWidget;
    QDoubleValidator* m_validator;

    struct TabData {
        QWidget* widget;
        QLineEdit* topEdit;
        QLineEdit* bottomEdit;
        QComboBox* topUnitCombo;
        QComboBox* bottomUnitCombo;
        UnitType type;
    };
    TabData m_tabs[3];
=======
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
>>>>>>> fdccab4731117b96d59bb5faf2cb18834e6859f2
};

#endif
