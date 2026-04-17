#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Converter.h"

QT_BEGIN_NAMESPACE
class QTabWidget;
class QWidget;
class QLineEdit;
class QComboBox;
class QDoubleValidator;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
};

#endif
