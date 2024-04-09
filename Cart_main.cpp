#include<iostream>
#include<string>
#include<vector>
#include"Datamodel.h" // Assuming you have defined the 'Product' and 'Cart' classes in "Datamodel.h"
using namespace std;

vector<Product> allProducts = {
   Product(1, "Apple", 30),
   Product(2, "Mango", 35),
   Product(3, "Guava", 20),
   Product(4, "Banana", 50),
   Product(5, "Strawberry", 150),
   Product(6, "Pineapple", 70),
   Product(7, "Blue Berry", 80)
};

Product chooseProduct() {
   string productList;
   cout << "Available Products" << endl;

   for (auto product : allProducts) {
      productList.append(product.getDisplayName() + "\n");
   }
   cout << productList << "--------------------------------------" << endl;
   string choice;
   cin >> choice;

   for (int i = 0; i < allProducts.size(); i++) {
      if (allProducts[i].getShortName() == choice) {
         return allProducts[i];
      }
   }
   cout << "Product Not Found!" << endl;
   // You should return a default Product object here or handle this case differently
   return Product(); // Assuming you have a default constructor for Product
}

bool checkout(Cart& cart) {
   if (cart.isEmpty()) {
      cout << "Cart is empty!" << endl;
      return false;
   }
   int total = cart.getTotal();
   cout << "Total: " << total << " Pay in Cash: ";
   int paid;
   cin >> paid;
   if (paid >= total) {
      cout << "Change: " << paid - total << endl;
      cout << "Thank you for shopping!" << endl;
      return true;
   }
   else {
      cout << "Not enough Cash!" << endl;
      return false;
   }
}

int main() {
   char action;
   Cart cart;
   while (true) {
      cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout, (e)xit" << endl;
      cin >> action;
      if (action == 'a') {
         // Add to cart
         // View all the products + choose a product and add to the cart
         Product product = chooseProduct();
         cout << "Added to the cart: " << product.getDisplayName() << endl;
         cart.addProduct(product);
      }
      else if (action == 'v') {
         // View the cart
         cout << "-----------------" << endl;
         cart.viewCart();
         cout << "-----------------" << endl;
      }
      else if (action == 'c') {
         // Checkout
         if (checkout(cart)) {
            break;
         }
      }
      else if (action == 'e') {
         // Exit the program
         break;
      }
      else {
         cout << "Invalid action. Please choose a valid option." << endl;
      }
   }
   return 0;
}



   
 