<<<<<<< HEAD
#include "MainWindow.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
=======
#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
>>>>>>> fdccab4731117b96d59bb5faf2cb18834e6859f2
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
<<<<<<< HEAD
    , m_validator(new QDoubleValidator(this))
{
    m_validator->setNotation(QDoubleValidator::StandardNotation);
    setupUI();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUI()
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    m_tabWidget = new QTabWidget(this);
    mainLayout->addWidget(m_tabWidget);

    createLengthTab();
    createMassTab();
    createTemperatureTab();

    setWindowTitle("Converter");
    setMinimumSize(400, 250);
    resize(450, 300);
}

void MainWindow::createLengthTab()
{
    QWidget* tab = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(tab);

    QHBoxLayout* topLayout = new QHBoxLayout();
    m_tabs[0].topEdit = new QLineEdit();
    m_tabs[0].topEdit->setPlaceholderText("Enter value");
    m_tabs[0].topEdit->setValidator(m_validator);
    m_tabs[0].topUnitCombo = new QComboBox();
    m_tabs[0].topUnitCombo->addItems(Converter::lengthUnits());
    topLayout->addWidget(m_tabs[0].topEdit);
    topLayout->addWidget(m_tabs[0].topUnitCombo);
    layout->addLayout(topLayout);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    m_tabs[0].bottomEdit = new QLineEdit();
    m_tabs[0].bottomEdit->setPlaceholderText("Converted value");
    m_tabs[0].bottomEdit->setValidator(m_validator);
    m_tabs[0].bottomUnitCombo = new QComboBox();
    m_tabs[0].bottomUnitCombo->addItems(Converter::lengthUnits());
    bottomLayout->addWidget(m_tabs[0].bottomEdit);
    bottomLayout->addWidget(m_tabs[0].bottomUnitCombo);
    layout->addLayout(bottomLayout);

    layout->addStretch();
    m_tabs[0].widget = tab;
    m_tabs[0].type = UnitType::Length;

    m_tabWidget->addTab(tab, "Length");

    connect(m_tabs[0].topEdit, &QLineEdit::textEdited, this, &MainWindow::onTopTextEdited);
    connect(m_tabs[0].bottomEdit, &QLineEdit::textEdited, this, &MainWindow::onBottomTextEdited);
    connect(m_tabs[0].topUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);
    connect(m_tabs[0].bottomUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);
}

void MainWindow::createMassTab()
{
    QWidget* tab = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(tab);

    QHBoxLayout* topLayout = new QHBoxLayout();
    m_tabs[1].topEdit = new QLineEdit();
    m_tabs[1].topEdit->setPlaceholderText("Enter value");
    m_tabs[1].topEdit->setValidator(m_validator);
    m_tabs[1].topUnitCombo = new QComboBox();
    m_tabs[1].topUnitCombo->addItems(Converter::massUnits());
    topLayout->addWidget(m_tabs[1].topEdit);
    topLayout->addWidget(m_tabs[1].topUnitCombo);
    layout->addLayout(topLayout);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    m_tabs[1].bottomEdit = new QLineEdit();
    m_tabs[1].bottomEdit->setPlaceholderText("Converted value");
    m_tabs[1].bottomEdit->setValidator(m_validator);
    m_tabs[1].bottomUnitCombo = new QComboBox();
    m_tabs[1].bottomUnitCombo->addItems(Converter::massUnits());
    bottomLayout->addWidget(m_tabs[1].bottomEdit);
    bottomLayout->addWidget(m_tabs[1].bottomUnitCombo);
    layout->addLayout(bottomLayout);

    layout->addStretch();
    m_tabs[1].widget = tab;
    m_tabs[1].type = UnitType::Mass;

    m_tabWidget->addTab(tab, "Mass");

    connect(m_tabs[1].topEdit, &QLineEdit::textEdited, this, &MainWindow::onTopTextEdited);
    connect(m_tabs[1].bottomEdit, &QLineEdit::textEdited, this, &MainWindow::onBottomTextEdited);
    connect(m_tabs[1].topUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);
    connect(m_tabs[1].bottomUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);
}

void MainWindow::createTemperatureTab()
{
    QWidget* tab = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(tab);

    QHBoxLayout* topLayout = new QHBoxLayout();
    m_tabs[2].topEdit = new QLineEdit();
    m_tabs[2].topEdit->setPlaceholderText("Enter value");
    m_tabs[2].topEdit->setValidator(m_validator);
    m_tabs[2].topUnitCombo = new QComboBox();
    m_tabs[2].topUnitCombo->addItems(Converter::temperatureUnits());
    topLayout->addWidget(m_tabs[2].topEdit);
    topLayout->addWidget(m_tabs[2].topUnitCombo);
    layout->addLayout(topLayout);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    m_tabs[2].bottomEdit = new QLineEdit();
    m_tabs[2].bottomEdit->setPlaceholderText("Converted value");
    m_tabs[2].bottomEdit->setValidator(m_validator);
    m_tabs[2].bottomUnitCombo = new QComboBox();
    m_tabs[2].bottomUnitCombo->addItems(Converter::temperatureUnits());
    bottomLayout->addWidget(m_tabs[2].bottomEdit);
    bottomLayout->addWidget(m_tabs[2].bottomUnitCombo);
    layout->addLayout(bottomLayout);

    layout->addStretch();
    m_tabs[2].widget = tab;
    m_tabs[2].type = UnitType::Temperature;

    m_tabWidget->addTab(tab, "Temperature");

    connect(m_tabs[2].topEdit, &QLineEdit::textEdited, this, &MainWindow::onTopTextEdited);
    connect(m_tabs[2].bottomEdit, &QLineEdit::textEdited, this, &MainWindow::onBottomTextEdited);
    connect(m_tabs[2].topUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);
    connect(m_tabs[2].bottomUnitCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onUnitChanged);

    connect(m_tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
}

void MainWindow::onTopTextEdited()
{
    int index = m_tabWidget->currentIndex();
    updateFromTop(true);
}

void MainWindow::onBottomTextEdited()
{
    int index = m_tabWidget->currentIndex();
    updateFromBottom(true);
}

void MainWindow::onUnitChanged()
{
    int index = m_tabWidget->currentIndex();
    QLineEdit* topEdit = m_tabs[index].topEdit;
    QLineEdit* bottomEdit = m_tabs[index].bottomEdit;

    if (!topEdit->text().isEmpty() && isValidNumber(topEdit->text())) {
        updateFromTop(false);
    } else if (!bottomEdit->text().isEmpty() && isValidNumber(bottomEdit->text())) {
        updateFromBottom(false);
    }
}

void MainWindow::onTabChanged(int index)
{
    QLineEdit* topEdit = m_tabs[index].topEdit;
    QLineEdit* bottomEdit = m_tabs[index].bottomEdit;

    if (!topEdit->text().isEmpty() && isValidNumber(topEdit->text())) {
        updateFromTop(false);
    } else if (!bottomEdit->text().isEmpty() && isValidNumber(bottomEdit->text())) {
        updateFromBottom(false);
    }
}

void MainWindow::updateFromTop(bool isUserInput)
{
    int index = m_tabWidget->currentIndex();
    QLineEdit* topEdit = m_tabs[index].topEdit;
    QLineEdit* bottomEdit = m_tabs[index].bottomEdit;
    int fromUnit = m_tabs[index].topUnitCombo->currentIndex();
    int toUnit = m_tabs[index].bottomUnitCombo->currentIndex();

    performConversionAndUpdate(topEdit, bottomEdit, fromUnit, toUnit);
}

void MainWindow::updateFromBottom(bool isUserInput)
{
    int index = m_tabWidget->currentIndex();
    QLineEdit* topEdit = m_tabs[index].topEdit;
    QLineEdit* bottomEdit = m_tabs[index].bottomEdit;
    int fromUnit = m_tabs[index].bottomUnitCombo->currentIndex();
    int toUnit = m_tabs[index].topUnitCombo->currentIndex();

    performConversionAndUpdate(bottomEdit, topEdit, fromUnit, toUnit);
}

void MainWindow::performConversionAndUpdate(QLineEdit* sourceEdit, QLineEdit* targetEdit,
                                            int fromUnitIndex, int toUnitIndex)
{
    QString sourceText = sourceEdit->text();

    if (!isValidNumber(sourceText)) {
        if (!sourceText.isEmpty()) {
            sourceEdit->setStyleSheet("QLineEdit { background-color: #ffcccc; }");
        }
        return;
    }

    sourceEdit->setStyleSheet("");

    int index = m_tabWidget->currentIndex();
    double value = sourceText.toDouble();

    double result = m_converter.convert(value, m_tabs[index].type, fromUnitIndex, toUnitIndex);

    QString formattedResult = formatNumber(result);

    bool blocked = targetEdit->blockSignals(true);
    targetEdit->setText(formattedResult);
    targetEdit->blockSignals(blocked);
}

bool MainWindow::isValidNumber(const QString& text) const
{
    if (text.isEmpty()) return false;
    bool ok;
    text.toDouble(&ok);
    return ok;
}

QString MainWindow::formatNumber(double value) const
{
    if (std::abs(value) < 0.0001 && value != 0.0) {
        return QString::number(value, 'e', 10);
    }
    return QString::number(value, 'g', 10);
=======
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
>>>>>>> fdccab4731117b96d59bb5faf2cb18834e6859f2
}
