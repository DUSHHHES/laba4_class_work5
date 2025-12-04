#pragma once


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Globalization;


public enum class CargoType {
    GENERAL,
    FRAGILE,
    DANGEROUS,
    PERISHABLE
};

static String^ CargoTypeToString(CargoType type) {
    switch (type) {
    case CargoType::GENERAL:    return "Общий";
    case CargoType::FRAGILE:    return "Хрупкий";
    case CargoType::DANGEROUS:  return "Опасный";
    case CargoType::PERISHABLE: return "Скоропортящийся";
    default:                    return "Неизвестный";
    }   
}



public ref class Tariff {
public:
    property String^ Name;
    property double PricePerKm;
    property CargoType Type;
    property double Discount; 

    
    Tariff() {}

    // Метод для расчета итоговой стоимости с учетом скидки
    double getFinalPrice() {
        if (Discount > 0 && Discount <= 100) {
            return PricePerKm * (1.0 - Discount / 100.0);
        }
        return PricePerKm;
    }

    // Переопределяем ToString для удобного отображения в ComboBox и других списках
    virtual String^ ToString() override {
        return Name;
    }
};

// Класс для описания одного клиента
public ref class Client {
public:
    property String^ Name;
    property String^ ContactInfo;

    virtual String^ ToString() override {
        return Name;
    }
};

// Класс для описания одного заказа
public ref class Order {
public:
    property Client^ OrderClient;
    property Tariff^ OrderTariff;
    property double Distance;

    // Метод для расчета стоимости заказа
    double calculateCost() {
        if (OrderTariff != nullptr) {
            return OrderTariff->getFinalPrice() * Distance;
        }
        return 0.0;
    }
};