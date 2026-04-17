#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupComboBoxes();
    setupValidators();

    setWindowTitle("Converter");
    setMinimumSize(450, 300);
    resize(550, 400);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    tabWidget = new QTabWidget(this);

    QWidget *tabLength = new QWidget();
    QWidget *tabMass = new QWidget();
    QWidget *tabTemp = new QWidget();

    QVBoxLayout *layoutLength = new QVBoxLayout(tabLength);
    QVBoxLayout *layoutMass = new QVBoxLayout(tabMass);
    QVBoxLayout *layoutTemp = new QVBoxLayout(tabTemp);

    layoutLength->setSpacing(15);
    layoutLength->setContentsMargins(15, 15, 15, 15);
    layoutMass->setSpacing(15);
    layoutMass->setContentsMargins(15, 15, 15, 15);
    layoutTemp->setSpacing(15);
    layoutTemp->setContentsMargins(15, 15, 15, 15);

    lineLengthFrom = new QLineEdit();
    lineLengthTo = new QLineEdit();
    comboLengthFrom = new QComboBox();
    comboLengthTo = new QComboBox();

    lineMassFrom = new QLineEdit();
    lineMassTo = new QLineEdit();
    comboMassFrom = new QComboBox();
    comboMassTo = new QComboBox();

    lineTempFrom = new QLineEdit();
    lineTempTo = new QLineEdit();
    comboTempFrom = new QComboBox();
    comboTempTo = new QComboBox();

    lineLengthFrom->setMinimumHeight(30);
    lineLengthTo->setMinimumHeight(30);
    lineMassFrom->setMinimumHeight(30);
    lineMassTo->setMinimumHeight(30);
    lineTempFrom->setMinimumHeight(30);
    lineTempTo->setMinimumHeight(30);

    comboLengthFrom->setMinimumWidth(120);
    comboLengthTo->setMinimumWidth(120);
    comboMassFrom->setMinimumWidth(120);
    comboMassTo->setMinimumWidth(120);
    comboTempFrom->setMinimumWidth(120);
    comboTempTo->setMinimumWidth(120);

    comboLengthFrom->setMinimumHeight(30);
    comboLengthTo->setMinimumHeight(30);
    comboMassFrom->setMinimumHeight(30);
    comboMassTo->setMinimumHeight(30);
    comboTempFrom->setMinimumHeight(30);
    comboTempTo->setMinimumHeight(30);

    lineLengthFrom->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lineLengthTo->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lineMassFrom->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lineMassTo->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lineTempFrom->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lineTempTo->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    lineLengthTo->setReadOnly(true);
    lineMassTo->setReadOnly(true);
    lineTempTo->setReadOnly(true);

    lineLengthFrom->setClearButtonEnabled(true);
    lineMassFrom->setClearButtonEnabled(true);
    lineTempFrom->setClearButtonEnabled(true);

    QHBoxLayout *rowLength1 = new QHBoxLayout();
    QHBoxLayout *rowLength2 = new QHBoxLayout();
    QHBoxLayout *rowMass1 = new QHBoxLayout();
    QHBoxLayout *rowMass2 = new QHBoxLayout();
    QHBoxLayout *rowTemp1 = new QHBoxLayout();
    QHBoxLayout *rowTemp2 = new QHBoxLayout();

    rowLength1->addWidget(lineLengthFrom);
    rowLength1->addWidget(comboLengthFrom);
    rowLength2->addWidget(lineLengthTo);
    rowLength2->addWidget(comboLengthTo);

    rowMass1->addWidget(lineMassFrom);
    rowMass1->addWidget(comboMassFrom);
    rowMass2->addWidget(lineMassTo);
    rowMass2->addWidget(comboMassTo);

    rowTemp1->addWidget(lineTempFrom);
    rowTemp1->addWidget(comboTempFrom);
    rowTemp2->addWidget(lineTempTo);
    rowTemp2->addWidget(comboTempTo);

    QLabel *arrowLength = new QLabel("↓");
    QLabel *arrowMass = new QLabel("↓");
    QLabel *arrowTemp = new QLabel("↓");

    arrowLength->setAlignment(Qt::AlignCenter);
    arrowMass->setAlignment(Qt::AlignCenter);
    arrowTemp->setAlignment(Qt::AlignCenter);

    QFont arrowFont;
    arrowFont.setPointSize(14);
    arrowFont.setBold(true);
    arrowLength->setFont(arrowFont);
    arrowMass->setFont(arrowFont);
    arrowTemp->setFont(arrowFont);

    layoutLength->addLayout(rowLength1);
    layoutLength->addWidget(arrowLength);
    layoutLength->addLayout(rowLength2);
    layoutLength->addStretch();

    layoutMass->addLayout(rowMass1);
    layoutMass->addWidget(arrowMass);
    layoutMass->addLayout(rowMass2);
    layoutMass->addStretch();

    layoutTemp->addLayout(rowTemp1);
    layoutTemp->addWidget(arrowTemp);
    layoutTemp->addLayout(rowTemp2);
    layoutTemp->addStretch();

    tabWidget->addTab(tabLength, "Length");
    tabWidget->addTab(tabMass, "Mass");
    tabWidget->addTab(tabTemp, "Temperature");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(tabWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::setupComboBoxes()
{
    comboLengthFrom->addItem("meters (m)", "m");
    comboLengthFrom->addItem("kilometers (km)", "km");
    comboLengthFrom->addItem("inches (in)", "in");
    comboLengthFrom->addItem("feet (ft)", "ft");
    comboLengthFrom->addItem("miles (mi)", "mi");
    comboLengthFrom->setCurrentIndex(0);

    comboLengthTo->addItem("meters (m)", "m");
    comboLengthTo->addItem("kilometers (km)", "km");
    comboLengthTo->addItem("inches (in)", "in");
    comboLengthTo->addItem("feet (ft)", "ft");
    comboLengthTo->addItem("miles (mi)", "mi");
    comboLengthTo->setCurrentIndex(1);

    comboMassFrom->addItem("kilograms (kg)", "kg");
    comboMassFrom->addItem("pounds (lb)", "lb");
    comboMassFrom->addItem("ounces (oz)", "oz");
    comboMassFrom->setCurrentIndex(0);

    comboMassTo->addItem("kilograms (kg)", "kg");
    comboMassTo->addItem("pounds (lb)", "lb");
    comboMassTo->addItem("ounces (oz)", "oz");
    comboMassTo->setCurrentIndex(1);

    comboTempFrom->addItem("Celsius (°C)", "C");
    comboTempFrom->addItem("Fahrenheit (°F)", "F");
    comboTempFrom->addItem("Kelvin (K)", "K");
    comboTempFrom->setCurrentIndex(0);

    comboTempTo->addItem("Celsius (°C)", "C");
    comboTempTo->addItem("Fahrenheit (°F)", "F");
    comboTempTo->addItem("Kelvin (K)", "K");
    comboTempTo->setCurrentIndex(1);
}

void MainWindow::setupValidators()
{
    QDoubleValidator *doubleValidator = new QDoubleValidator(this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    doubleValidator->setDecimals(10);

    lineLengthFrom->setValidator(doubleValidator);
    lineMassFrom->setValidator(doubleValidator);
    lineTempFrom->setValidator(doubleValidator);

    lineLengthFrom->setPlaceholderText("Enter value...");
    lineLengthTo->setPlaceholderText("Result");
    lineMassFrom->setPlaceholderText("Enter value...");
    lineMassTo->setPlaceholderText("Result");
    lineTempFrom->setPlaceholderText("Enter value...");
    lineTempTo->setPlaceholderText("Result");
}
