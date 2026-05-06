products ={
    "laptop": 1200,
    "phone": 800,
    "tablet": 450,
    "monitor": 300,
    "keyboard": 100
}

new_price = {
    product: price for product,price in products.items() if price > 500

}
# neee = { pro : pri for pro, pri in products.items() if pri > 500}
print(new_price)