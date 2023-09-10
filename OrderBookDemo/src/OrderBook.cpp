#include "hdr/OrderBook.h"
#include <ostream>

bool OrderBook::IsEmpty() const {
    return bids.empty() && asks.empty();
}

void OrderBook::AddBid(int price, int amount) {
    Add(price, amount, true);
}

void OrderBook::AddAsk(int price, int amount) {
    Add(price, amount, false);
}

void OrderBook::Add(int price, int amount, bool bid) {
    if (bid)
        bids[price] += amount;
    else
        asks[price] += amount;
}

std::ostream& operator<<(std::ostream& os, const OrderBook& book) {
    if (book.IsEmpty()) {
        os << "ORDER BOOK EMPTY";
        return os;
    }

    for (auto it = book.asks.rbegin(); it != book.asks.rend(); ++it) {
        os << it->first << "\t" << it->second << "\n";
    }
    os << "\n";

    for (auto it = book.bids.rbegin(); it != book.bids.rend(); ++it) {
        os << it->first << "\t" << it->second << "\n";
    }

    return os;
}

OrderBook::BidAsk OrderBook::GetBidAsk() const {
    BidAsk result;

    auto best_bid = bids.rbegin();
    if (best_bid != bids.rend())
        result.bid = *best_bid;

    auto best_ask = asks.begin();
    if (best_ask != asks.end())
        result.ask = *best_ask;

    return result;
}

void OrderBook::RemoveBid(int price, int amount) {
    Remove(price, amount, true);
}
void OrderBook::RemoveAsk(int price, int amount) {
    Remove(price, amount, false);
}

void OrderBook::Remove(int price, int amount, bool bid) {
    auto& table = bid ? bids : asks;
    auto it = table.find(price);
    if (it != table.end()) {
        it->second -= amount;
        if (it->second == 0)
            table.erase(it);
    }
}
