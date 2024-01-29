#include <iostream>
#include <vector>
#include <string>

//A ideia do programa é permitir que o usuario coloque quantidades variaveis de numeros em que
//suas distancias serão calculadas, e que em caso de multiplas distancias iguais, também serão contados
//para o resultado final.

std::vector<int> get_int_array() {
	std::vector<int> arr{};
	std::string input_value{};
	std::string end_word{ "fim" };
	while (std::cin >> input_value && input_value != "fim") {
		arr.push_back(std::stoi(input_value));
	}
	return arr;
}

int main() {
	std::cout << "Por favor forneca a primeira lista de ints, ao terminar a lista digite \"fim\": \n";
	std::vector<int> first_arr{ get_int_array() };
	std::cout << "Por favor forneca a segunda lista de ints, ao terminar a lista digite \"fim\": \n";
	std::vector<int> second_arr{ get_int_array() };

	int closest_distance{ 9999999 };
	int current_distance{};
	std::vector<int> all_current_ints{ 1 };
	int counter_of_equal_distance{ 1 };

	for (int i : first_arr) {
		for (int j : second_arr) {
			current_distance = abs(i - j);
			if (current_distance < closest_distance) {
				all_current_ints.clear();
				counter_of_equal_distance = 1;
				all_current_ints.push_back(i);
				all_current_ints.push_back(j);
				closest_distance = current_distance;
			}
			else if (current_distance == closest_distance) {
				all_current_ints.push_back(i);
				all_current_ints.push_back(j);
				++counter_of_equal_distance;
			}
		}
	}
	std::cout << "Foram encontrados " << counter_of_equal_distance <<
		" pares que resultam na distancia de " << closest_distance << "!\n";
	std::cout << "Os pares sao (lista 1 : lista 2):";
	for (int i{ 0 }; i < counter_of_equal_distance * 2; i += 2) {
		std::cout << " " << all_current_ints[i] << ":" << all_current_ints[i + 1];
		if (i < all_current_ints.size() -2) {
			std::cout << ";";
		}
	}
	return 0;
}
