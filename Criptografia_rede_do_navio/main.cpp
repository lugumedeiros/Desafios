#include <iostream>
#include <vector>
#include <bitset>

void test_binary_array(std::vector<std::bitset<8>> arr) {
  //for testing only
  for (auto i : arr) {
    std::cout << i << " ";
  }
  std::cout << "\nEnd of the test." << std::endl;
}

int main() {

  int end_of_text{ -1 };
  std::bitset<8> user_input{};
  std::vector<std::bitset<8>> encrypted_chars{};

  std::cout << "O fim da lista precisa ter '-1'.\n\
Exemplo: 11100001 11110011 -1" << std::endl;

  while(std::cin >> user_input && user_input != end_of_text) {
    encrypted_chars.push_back(user_input);
  }

  std::cout << std::endl;
  std::cout << "input recebido: ";
  test_binary_array(encrypted_chars);

  //last 2 binary digits will be changed.
  std::vector<std::bitset<8>> first_change_array{};
  for (auto i : encrypted_chars) {
    auto first_change_chr{ i };
    first_change_chr ^= 3; // 0000 0011
    first_change_array.push_back(first_change_chr);
  }
  std::cout << "\nResultado do flip: ";
  test_binary_array(first_change_array);

  //first 4 digits will swap with last 4 digits.
  std::vector<std::bitset<8>> second_change_array{};
  for (auto i : first_change_array) {
    std::bitset<8> swap_a{ i };
    std::bitset<8> swap_b{ i };
    swap_a = (swap_a &= 240) >> 4;
    swap_b = (swap_b &= 15) << 4;
    std::bitset<8> new_value{swap_a | swap_b};
    second_change_array.push_back(new_value);
  }

  std::cout << "\nBinary change result: ";
  test_binary_array(second_change_array);

  std::vector<char> decrypted_message{};
  for (auto i : second_change_array) {
    unsigned long int n{ i.to_ulong() };
    char decrypted_chr{ static_cast<char>(n) };
    decrypted_message.push_back(decrypted_chr);
  }

  //Final Test
  std::cout << "\nMensagem decriptada: ";
  for (auto i : decrypted_message) {
    std::cout << i;
  }
  std::cout << "\nFim da mensagem" << std::endl;
  return 0;
}
