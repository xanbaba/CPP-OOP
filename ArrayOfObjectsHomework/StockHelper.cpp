#include "StockHelper.h"

#include <iostream>

void StockHelper::print_items(Stock& stock)
{
    std::cout << "Stock:\n" <<
        "\tquantity of items: " << stock.get_items_count() << '\n';

    for (int i = 0; i < stock.get_items_count(); ++i)
    {
        auto item = stock.get_item(i);
        const auto item_name = item->get_name();
        const auto item_price = item->get_price();
        std::cout << "\tItem: { name: " << item_name << ' ' << "price: " << item_price << " }\n";
        delete[] item_name;
    }
}
