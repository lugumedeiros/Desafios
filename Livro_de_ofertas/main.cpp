#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
	std::cout << "Adicione os comandos em ordem de: Posicao, Acao, Valor, Quantidade.\n";
	std::cout << "Todos os valores devem ser divididos por um espaco. Ao finalizar adicione '-1'.\n";
	std::vector<double> command_list{};
	double user_inp{};
	while (std::cin >> user_inp && user_inp != -1) {
		command_list.push_back(user_inp);
	}
	
	std::map<std::string, double> book;
		book["value"] = 0;
		book["quantity"] = 0;

	std::vector<std::map<std::string, double>> book_collection{};
	unsigned int num_books{0};
	for (int i{ 0 }; i < command_list.size(); i += 4) {
		unsigned int position	{ static_cast<unsigned int>(command_list[i]-1) };
		unsigned int command	{ static_cast<unsigned int>(command_list[i+1]) };
		double value			{ command_list[i+2] };
		unsigned int quantity	{ static_cast<unsigned int>(command_list[i+3]) };
		
		//se inserir em um espaço ja inserido
		if (position+1 <= num_books && command == 0) {
			command = 1;
		}
		//se deletar um espaço inexistente
		if (position+1 > num_books && command == 2) {
			continue;
		}
		
		//for testing
		std::cout << "\nlog:\npos:" << position << " com:" << command << " val:" << value << " qnt:" << quantity;

		switch (command) {
			case 0: //insert
				num_books++;
				book_collection.push_back(book);
				book_collection[position]["value"] = value;
				book_collection[position]["quantity"] = quantity;
				std::cout << "\nnew book added at pos:" << position+1 << std::endl;;
				break;
			case 1: //modify
				std::cout << "\nnew mod at pos:" << position+1;
				if (value != 0) {
					book_collection[position]["value"] = value;
					std::cout << " value changed:" << value;
				}
				if (quantity != 0) {
					book_collection[position]["quantity"] = quantity;
					std::cout << " quantity changed:" << quantity;
				}
				std::cout << "\n";
				break;
			case 2: //delete
				book_collection.erase(book_collection.begin() + position);
				--num_books;
				std::cout << "\nbook deleted at pos:" << position+1 << "\n";
				break;
		}
	}
	std::cout << "\nA quantidade restante de livros eh: " << num_books;
	for (int i{ 0 }; i < num_books; i++) {
		std::cout << "\nPosicao " << i + 1 << ", valor: " << book_collection[i]["value"] <<
			", quantidade: " << book_collection[i]["quantity"];
	}
	return 0;
}
