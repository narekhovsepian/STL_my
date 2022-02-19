#pragma once



namespace std_my {
	
	void dfs_euler(std::vector<std::vector<int>>& graph, std::map<std::pair<int, int>, int>& edges,
		std::vector<int>& cycle, int start_vertex) {

		for (int i{}; i != graph[start_vertex].size(); ++i) {
			int adjacent_vertex = graph[start_vertex][i];
			int a = start_vertex;
			int b = adjacent_vertex;

			if (a > b) {
				std::swap(a, b);
			}
			if (edges[{a, b}] != 0) {
				edges[{a, b}]--;
				dfs_euler(graph, edges, cycle, adjacent_vertex);
			}
		}
		cycle.push_back(start_vertex);
	}


	void EulerPathandCycle(std::vector<std::vector<int>>& graph, const int& start_vertex) {
		std::map<std::pair<int, int>, int> edges;
		std::vector<int> odd_vertices;
		std::vector<int> cycle;
	
		for (int i{}; i != graph.size(); ++i)
			if (graph[i].size() % 2 == 1)
				odd_vertices.push_back(i);

		if (odd_vertices.size() > 2) {
			std::cout << "No Euler Path and Cycle" << std::endl;
			return;
		}

		if (odd_vertices.size() == 2) {
			graph[odd_vertices[0]].push_back(odd_vertices[1]);
			graph[odd_vertices[1]].push_back(odd_vertices[0]);

		}

		for (int i{}; i != graph.size(); ++i) {
			for (int j{}; j != graph[i].size(); ++j) {
				if (i < graph[i][j]) {
					edges[{i, graph[i][j]}]++;
				}
			}
		}

		dfs_euler(graph, edges, cycle, 0);

		
		if (odd_vertices.size() == 2) {

			for (int i{ 1 }; i < cycle.size(); ++i) {

				if ((cycle[i - 1] == odd_vertices[0] && cycle[i] == odd_vertices[1]) || 
					(cycle[i - 1] == odd_vertices[1] && cycle[i] == odd_vertices[0])) {

					std::vector<int> new_cycle;

					for (int j = i; j < i + cycle.size(); ++j) {
						int index = j % cycle.size();
						if (index == 0)
							continue;

						new_cycle.push_back(cycle[index]);
					}
					cycle = std::move(new_cycle);
				}
			}
		}
		
		for (const auto& i :cycle)
			std::cout << i + 1 << " ";
	}



}