#include <iostream>
#include <string>
using namespace std;


string compareOfLongNumbers(string num1, string num2) {
  if (num1.length() > num2.length()) return "First is bigger";
  if (num1.length() < num2.length()) return "Second is bigger";
  //Посимвольное сравнение если строки равны
  if (num1 > num2) return "First is bigger";
  if (num1 < num2) return "Second is bigger";
  return "Numbers are equal";
}

string sumOfLongNumbers(string num1, string num2) {
  // Делаем num1 длиннее num2
  if (num1.length() < num2.length()) {
    string intermediateValue = num1;
    num1 = num2;
    num2 = intermediateValue;
  }

  string resultOfSum = "";
  int carry = 0;
  int diff = num1.length() - num2.length();

  
  for (int indexI = num1.length() - 1; indexI >= 0; --indexI) {
    int digit1 = num1[indexI] - '0';
    int digit2 = (indexI >= diff) ? num2[indexI - diff] - '0' : 0;

    int sum = digit1 + digit2 + carry;
    carry = sum / 10;
    resultOfSum = to_string(sum % 10) + resultOfSum;
  }

  if (carry > 0) {
    resultOfSum = to_string(carry) + resultOfSum;
  }

  return resultOfSum;
}

string multiplication(string num, int digit) {
  string result = "";
  int carry = 0;

  for (int indexI = num.length() - 1; indexI >= 0; --indexI) {
    int product = (num[indexI] - '0') * digit + carry;
    carry = product / 10;
    result = to_string(product % 10) + result;
  }

  if (carry > 0) {
    result = to_string(carry) + result;
  }

  return result;
}

int main() {
  string num1, num2;
  int multplicationNumber;

  cout << "Enter first number: ";
  cin >> num1;

  while (num1.find_first_not_of("0123456789") != string::npos) {
    cout << "EROR!!! PLESE enter number" << endl;
    cin >> num1;
  }

  cout << "Enter second number: ";
  cin >> num2;

  while (num2.find_first_not_of("0123456789") != string::npos) {
    cout << "EROR!!! PLESE enter number" << endl;
    cin  >> num2;
  }
  cout << "Enter number for multiplication: ";
  cin  >> multplicationNumber;

  cout << "\nRESULTS:" << endl
       << "\nNumber " << compareOfLongNumbers(num1, num2) << endl
       << "\nSUM: " << sumOfLongNumbers(num1, num2) << endl
       << "\nMultiplication: " << multiplication(num1, multplicationNumber) << endl
       << "\nMultiplication: " << multiplication(num2, multplicationNumber) << endl;

  return 0;
}