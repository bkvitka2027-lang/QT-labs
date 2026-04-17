#include "Converter.h"
#include <QStringList>
#include <cmath>

Converter::Converter() = default;

QStringList Converter::lengthUnits()
{
    return {"meters (m)", "kilometers (km)", "inches (in)", "feet (ft)", "miles (mi)"};
}

QStringList Converter::massUnits()
{
    return {"kilograms (kg)", "pounds (lb)", "ounces (oz)"};
}

QStringList Converter::temperatureUnits()
{
    return {"Celsius (°C)", "Fahrenheit (°F)", "Kelvin (K)"};
}

double Converter::lengthToBase(double value, LengthUnit unit) const
{
    switch (unit) {
    case LengthUnit::Meters:     return value;
    case LengthUnit::Kilometers: return value * 1000.0;
    case LengthUnit::Inches:     return value * 0.0254;
    case LengthUnit::Feet:       return value * 0.3048;
    case LengthUnit::Miles:      return value * 1609.344;
    }
    return 0.0;
}

double Converter::lengthFromBase(double value, LengthUnit unit) const
{
    switch (unit) {
    case LengthUnit::Meters:     return value;
    case LengthUnit::Kilometers: return value / 1000.0;
    case LengthUnit::Inches:     return value / 0.0254;
    case LengthUnit::Feet:       return value / 0.3048;
    case LengthUnit::Miles:      return value / 1609.344;
    }
    return 0.0;
}

double Converter::massToBase(double value, MassUnit unit) const
{
    switch (unit) {
    case MassUnit::Kilograms: return value;
    case MassUnit::Pounds:    return value * 0.45359237;
    case MassUnit::Ounces:    return value * 0.028349523125;
    }
    return 0.0;
}

double Converter::massFromBase(double value, MassUnit unit) const
{
    switch (unit) {
    case MassUnit::Kilograms: return value;
    case MassUnit::Pounds:    return value / 0.45359237;
    case MassUnit::Ounces:    return value / 0.028349523125;
    }
    return 0.0;
}

double Converter::temperatureToBase(double value, TemperatureUnit unit) const
{
    switch (unit) {
    case TemperatureUnit::Celsius:    return value + 273.15;
    case TemperatureUnit::Fahrenheit: return (value - 32.0) * 5.0/9.0 + 273.15;
    case TemperatureUnit::Kelvin:     return value;
    }
    return 0.0;
}

double Converter::temperatureFromBase(double value, TemperatureUnit unit) const
{
    switch (unit) {
    case TemperatureUnit::Celsius:    return value - 273.15;
    case TemperatureUnit::Fahrenheit: return (value - 273.15) * 9.0/5.0 + 32.0;
    case TemperatureUnit::Kelvin:     return value;
    }
    return 0.0;
}

double Converter::toBase(double value, UnitType type, int fromIndex) const
{
    switch (type) {
    case UnitType::Length:
        return lengthToBase(value, static_cast<LengthUnit>(fromIndex));
    case UnitType::Mass:
        return massToBase(value, static_cast<MassUnit>(fromIndex));
    case UnitType::Temperature:
        return temperatureToBase(value, static_cast<TemperatureUnit>(fromIndex));
    }
    return 0.0;
}

double Converter::fromBase(double value, UnitType type, int toIndex) const
{
    switch (type) {
    case UnitType::Length:
        return lengthFromBase(value, static_cast<LengthUnit>(toIndex));
    case UnitType::Mass:
        return massFromBase(value, static_cast<MassUnit>(toIndex));
    case UnitType::Temperature:
        return temperatureFromBase(value, static_cast<TemperatureUnit>(toIndex));
    }
    return 0.0;
}

double Converter::convert(double value, UnitType type, int fromIndex, int toIndex) const
{
    double inBase = toBase(value, type, fromIndex);
    return fromBase(inBase, type, toIndex);
}
