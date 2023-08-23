package orderbook

import (
	"math/rand"
	"time"
)

type Limit struct {
    price float64
    orders []*Order
    total_volume float64
}

func NewLimit(price float64) *Limit {
    return &Limit{
	price: price,
	orders: []*Order{},
    }
}

func (l *Limit) AddOrder(o *Order) {
    l.orders = append(l.orders, o)
    l.total_volume += o.size
}

type Order struct {
    id int64
    size float64
    timestamp int64
    is_bid bool
}

func NewOrder(is_bid bool, size float64) *Order {
    return &Order{
	id: rand.Int63n(100000),
	size: size,
	timestamp: time.Now().UnixNano(),
	is_bid: is_bid,
    }
}

func NewBidOrder(size float64) *Order {
    return NewOrder(false, size)
}

func NewAskOrder(size float64) *Order {
    return NewOrder(false, size)
}
