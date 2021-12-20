#pragma once


namespace std_my {

	void floyd_warshal(std::vector<std::vector<int>> graph) {
		const int n = graph.size();
		for (int k{}; k != n; ++k)
			for (int i{}; i != n; ++i)
				for (int j{}; j != n; ++j)
					graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);

		for (int i{}; i != n; ++i) {
			for (int j{}; j != n; ++j) {
				if (i == j) {
					std::cout << "0 ";
				}
				else
					std::cout << graph[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
}