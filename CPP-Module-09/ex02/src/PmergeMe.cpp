/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:40:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/15 16:46:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::~PmergeMe( ) { }

PmergeMe::PmergeMe(char **av) {
	std::list<std::string> chopped_string;
	std::list<std::string> temp;
	for (int i = 1; av[i]; i++) {
		temp = this->split(std::string(av[i]));
		chopped_string.insert(chopped_string.end(), temp.begin(), temp.end());
	}
	for (std::list<std::string>::iterator it = chopped_string.begin(); it != chopped_string.end(); ++it) {
		if (it->find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Sequece has not only positive numbers");
		this->list.push_back(std::atoi(it->c_str()));
		this->deque.push_back(std::atoi(it->c_str()));
	}
}
// Jacobsthal: J(n) = (2^n - (-1)^n) / 3
int	PmergeMe::get_jacobsthal(int n) const {
    return (int)((pow(2.0, n) - pow(-1.0, n)) / 3.0);
}

void PmergeMe::ford_johnson(std::list<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    // 1. Fase de Emparelhamento
    std::list<Pair> pairs;
    int straggler = 0;
    bool has_straggler = (n % 2 != 0);
    
    if (has_straggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    // Como std::list não tem indexação, usamos iteradores para parear
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end()) {
        int first = *it++;
        int second = *it++;
        Pair p;
        if (first > second) { p.winner = first; p.loser = second; }
        else { p.winner = second; p.loser = first; }
        pairs.push_back(p);
    }

    // 2. Ordenar Vencedores Recursivamente
    std::list<int> winners;
    for (std::list<Pair>::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
        winners.push_back(p_it->winner);
    }
    ford_johnson(winners);

    // 3. Criar Main Chain inicial
    std::list<int> main_chain;
    main_chain.push_back(winners.front()); // Menor vencedor

    // Insere o perdedor do menor vencedor na frente (sem comparações extras)
    for (std::list<Pair>::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
        if (p_it->winner == winners.front()) {
            main_chain.push_front(p_it->loser);
            pairs.erase(p_it);
            break;
        }
    }

    // Adiciona os outros vencedores ordenados
    std::list<int>::iterator w_it = winners.begin();
    for (++w_it; w_it != winners.end(); ++w_it) {
        main_chain.push_back(*w_it);
    }

    // 4. Preparar Pendentes para inserção via Jacobsthal
    std::list<int> pending;
    for (std::list<int>::iterator wc_it = winners.begin(); wc_it != winners.end(); ++wc_it) {
        if (*wc_it == winners.front()) continue; // Já inserido
        for (std::list<Pair>::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
            if (p_it->winner == *wc_it) {
                pending.push_back(p_it->loser);
                break;
            }
        }
    }
    if (has_straggler) pending.push_back(straggler);

    // 5. Inserção em Blocos (Lógica Jacobsthal)
    int j_idx = 3;
    size_t inserted = 0;
    size_t total_to_insert = pending.size();

    while (inserted < total_to_insert) {
        int j_val = get_jacobsthal(j_idx);
        int prev_j_val = get_jacobsthal(j_idx - 1);
        
        int block_size = j_val - prev_j_val;
        if (block_size <= 0) { j_idx++; continue; }

        // Pegamos o bloco atual de pendentes
        int upper = std::min((int)total_to_insert, j_val - 1);
        int lower = prev_j_val - 1;

        // Inserir do fim do bloco para o início
        for (int i = upper - 1; i >= lower; --i) {
            // Acessar elemento i na lista 'pending' (custo O(n) em list)
            std::list<int>::iterator p_it = pending.begin();
            std::advance(p_it, i);
            int val = *p_it;

            // Busca binária na main_chain (std::upper_bound em list faz busca linear de iteradores)
            std::list<int>::iterator pos = std::upper_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
            inserted++;
        }
        j_idx++;
    }

    arr = main_chain;
}

// Gera o n-ésimo número de Jacobsthal
void PmergeMe::ford_johnson(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    // 1. Fase de Emparelhamento
    std::deque<Pair> pairs;
    int straggler;
    bool has_straggler = (n % 2 != 0);
    
    if (has_straggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        Pair p;
        if (arr[i] > arr[i+1]) {
            p.winner = arr[i];
			p.loser = arr[i+1];
        } else {
            p.winner = arr[i+1];
			p.loser = arr[i];
        }
        pairs.push_back(p);
    }

    // 2. Ordenar Vencedores Recursivamente
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].winner);
    }
    ford_johnson(winners);

    // 3. Criar Main Chain inicial
    std::deque<int> main_chain;
    main_chain.push_back(winners[0]); // O menor vencedor

    // Encontrar o perdedor do primeiro vencedor e colocá-lo no início (0 comparações extras)
    for (std::deque<Pair>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->winner == winners[0]) {
            main_chain.push_front(it->loser);
            pairs.erase(it);
            break;
        }
    }

    // Adicionar o restante dos vencedores ordenados à Main Chain
    for (size_t i = 1; i < winners.size(); ++i) {
        main_chain.push_back(winners[i]);
    }

    // 4. Inserção dos Perdedores usando Blocos de Jacobsthal
    // Criamos uma lista de pendentes baseada nos vencedores já posicionados
    std::deque<int> pending;
    for (size_t i = 1; i < winners.size(); ++i) {
        for (std::deque<Pair>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->winner == winners[i]) {
                pending.push_back(it->loser);
                break;
            }
        }
    }
    if (has_straggler) pending.push_back(straggler);

    // Lógica simplificada de Jacobsthal para ordem de inserção
    size_t inserted_count = 0;
    int j_idx = 3; // Começamos no J3 = 3
    
    while (inserted_count < pending.size()) {
        int j_val = get_jacobsthal(j_idx);
        int prev_j_val = get_jacobsthal(j_idx - 1);
        
        // Determina o limite superior do bloco atual
        int upper = std::min((int)pending.size(), j_val - 1);
        int lower = prev_j_val - 1;

        // Insere do final do bloco para o início (estratégia Ford-Johnson)
        for (int i = upper - 1; i >= lower; --i) {
            if (i >= (int)pending.size()) continue;
            
            int item = pending[i];
            std::deque<int>::iterator pos = std::upper_bound(main_chain.begin(), main_chain.end(), item);
            main_chain.insert(pos, item);
            inserted_count++;
        }
        j_idx++;
    }

    arr = main_chain;
}

//process
//split inputs into pairs
//for each pair place the smaller one in one group and the larger in another
//recursively sort thee group of larger elements
//insert the smaller elements into the sorted larger sequence
//Each insertion uses binary search on  limited range

void PmergeMe::sort(void) {
	struct timeval beggining, end;
	long seconds, microseconds, totalTime;

	std::cout << "Before: ";
	std::deque<int>::size_type size = this->deque.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << this->deque[i] << " ";
	}
	std::cout << std::endl;

	gettimeofday(&beggining, NULL);

	ford_johnson(deque);
	
	gettimeofday(&end, NULL);

	seconds = end.tv_sec - beggining.tv_sec;
    microseconds = end.tv_usec - beggining.tv_usec;
    totalTime = (seconds * 1000000) + microseconds;

	std::cout << "After: ";
	std::cout << "deque: ";
	for (size_t i = 0; i < size; i++) {
		std::cout << this->deque[i] << " ";  // ✅ OK, deque foi ordenado
	}

	
	std::cout << std::endl;

	std::cout << "Time top process a range of " << size << "with std::deque: " << totalTime << std::endl;
	
	gettimeofday(&beggining, NULL);

	ford_johnson(list);
	
	gettimeofday(&end, NULL);
	std::cout << "list: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << " ";
	}

	seconds = end.tv_sec - beggining.tv_sec;
    microseconds = end.tv_usec - beggining.tv_usec;
    totalTime = (seconds * 1000000) + microseconds;

	std::cout << "Time top process a range of " << size << "with std::list: " << totalTime << std::endl;
}

std::list<std::string> PmergeMe::split(const std::string& input) {
    std::list<std::string> result;
    std::string token;
    std::string::size_type i = 0;
    const std::string::size_type n = input.size();

    // Skip leading spaces and tabs
    while (i < n && (input[i] == ' ' || input[i] == '\t'))
        ++i;

    while (i < n) {
        // Collect characters for the current token
        token.clear();
        while (i < n && input[i] != ' ' && input[i] != '\t') {
            token += input[i];
            ++i;
        }

        if (!token.empty())
            result.push_back(token);

        // Skip consecutive spaces and tabs
        while (i < n && (input[i] == ' ' || input[i] == '\t'))
            ++i;
    }

    return result;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}
