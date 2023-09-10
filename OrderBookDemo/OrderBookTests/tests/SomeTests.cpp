#include "hdr/OrderBook.h"
#include "gtest/gtest.h"

TEST(OrderBookTests, OrderBookEmptyByDefault) {
    OrderBook book;
    EXPECT_TRUE(book.IsEmpty());
}

TEST(OrderBookTests, OrderAdditionWorks) {
    OrderBook book;
    book.AddBid(123, 456);
    auto bidask = book.GetBidAsk();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);
}

TEST(OrderBookTests, OrderRemovalWorks) {
    OrderBook book;
    book.AddBid(123, 456);
    book.RemoveBid(123, 156);
    auto bidask = book.GetBidAsk();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456-136, bid.second);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
