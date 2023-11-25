#include <iostream>

#include "Stock.h"
#include "StockHelper.h"

int main(int argc, char* argv[])
{
    // while (true)
    {
        Stock stock;
        Item item1{"Head&Shoulders", 4};
        Item item2{"Pepsi", 4};
        Item item3{"Coca-Cola", 4};
        Item item4{"Fuse-Tea", 4};
        Item item5{"Apple", 4};
        Item item6{"Lay's", 4};
        Item item7{"Pringles", 4};
    
        stock.add_item(item1);
        stock.add_item(item2);
        stock.add_item(item3);
        stock.add_item(item4);
        stock.add_item(item5);
        stock.add_item(item6);
        stock.add_item(item7);
    
        StockHelper::print_items(stock);
    }
    
}
