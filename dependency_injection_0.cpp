/*
In this example, the Order class depends on a PaymentMethod for paying for the pizza. 
The **concrete implementation** of the PaymentMethod **is injected into** the Order class through the constructor. 
The Order class **does not** have to know about the specific implementation of the PaymentMethod it is using, 
and can use any implementation that implements the PaymentMethod interface.

By using dependency injection, we can make the code more flexible and reusable. 
For example, if we want to add a new payment method (e.g., PayPal), 
we can simply implement a new concrete class that implements the PaymentMethod interface, 
and use it in the same way as the CreditCard and Cash implementations. 
The Order class remains unchanged, and we can switch between different payment methods dynamically.
*/

#include <iostream>
#include <memory>

// Interface class
class PaymentMethod {
 public:
  virtual ~PaymentMethod() = default;
  virtual void Pay(double amount) = 0;
};

// Concrete implementation of the PaymentMethod interface
class CreditCard : public PaymentMethod {
 public:
  void Pay(double amount) override {
    std::cout << "Paying $" << amount << " with credit card." << std::endl;
  }
};

// Another concrete implementation of the PaymentMethod interface
class Cash : public PaymentMethod {
 public:
  void Pay(double amount) override {
    std::cout << "Paying $" << amount << " with cash." << std::endl;
  }
};

// Class that uses the PaymentMethod interface
class Order {
 public:
  explicit Order(std::unique_ptr<PaymentMethod> paymentMethod)
      : paymentMethod_(std::move(paymentMethod)) {}

  void PlaceOrder(double amount) {
    paymentMethod_->Pay(amount);
    std::cout << "Order placed successfully!" << std::endl;
  }

 private:
  std::unique_ptr<PaymentMethod> paymentMethod_;
};

int main() {
  auto creditCard = std::make_unique<CreditCard>();
  Order order(std::move(creditCard));
  order.PlaceOrder(20.0);

  auto cash = std::make_unique<Cash>();
  Order order2(std::move(cash));
  order2.PlaceOrder(20.0);

  return 0;
}
