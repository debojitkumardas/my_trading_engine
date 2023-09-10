#pragma once

#include <map>
#include <ostream>
#include <boost/optional.hpp>

class OrderBook {

    /** using a map because it sorts it's element by key
     *  it's a map between price to the actual amount for bid */
    std::map<int, int> bids;

    /** using a map because it sorts it's element by key
     *  it's a map between price to the actual amount for ask */
    std::map<int, int> asks;

    void Add (int price, int amount, bool bid);
    void Remove(int price, int amount, bool bid);

public:
    struct BidAsk {
        // using Entry = std::pair<int, int>;
        using Entry = boost::optional<std::pair<int, int>>;
        Entry bid;
        Entry ask;
        boost::optional<int> Spread() const;
    };

    bool IsEmpty() const;
    void AddBid(int price, int amount);
    void AddAsk(int price, int amount);
    void RemoveBid(int price, int amount);
    void RemoveAsk(int price, int amount);

    BidAsk GetBidAsk() const;

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& book);
};
