#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>
#include <QStringList>  // ДОДАТИ ЦЕЙ РЯДОК

enum class UnitType { Length, Mass, Temperature };
enum class LengthUnit { Meters, Kilometers, Inches, Feet, Miles };
enum class MassUnit { Kilograms, Pounds, Ounces };
enum class TemperatureUnit { Celsius, Fahrenheit, Kelvin };

class Converter
{
public:
    Converter();

    double convert(double value, UnitType type, int fromIndex, int toIndex) const;

    static QStringList lengthUnits();
    static QStringList massUnits();
    static QStringList temperatureUnits();

private:
    double toBase(double value, UnitType type, int fromIndex) const;
    double fromBase(double value, UnitType type, int toIndex) const;

    double lengthToBase(double value, LengthUnit unit) const;
    double lengthFromBase(double value, LengthUnit unit) const;

    double massToBase(double value, MassUnit unit) const;
    double massFromBase(double value, MassUnit unit) const;

    double temperatureToBase(double value, TemperatureUnit unit) const;
    double temperatureFromBase(double value, TemperatureUnit unit) const;
};

#endif
