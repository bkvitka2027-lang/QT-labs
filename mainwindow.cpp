#include "MainWindow.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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
}
