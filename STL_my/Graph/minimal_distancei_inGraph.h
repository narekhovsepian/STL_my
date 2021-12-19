#pragma once

namespace std_my {

	void minimal_distance_graphe(std::vector<std::vector<int>>& graph, int start) {
		std::vector<int> used(graph.size(), -1);
		std::queue<int>q;
		used[start] = 0;
		q.push(start);
		while (!q.empty()) {
			int current_vertex = q.front();
			q.pop();
			for (int i{}; i != graph[current_vertex].size(); ++i) {
				int adjacent_vertex = graph[current_vertex][i];
				if (used[adjacent_vertex] == -1) {
					q.push(adjacent_vertex);
					used[adjacent_vertex] = used[current_vertex] + 1;
				}
			}
		}

		for (int i{}; i != used.size(); ++i) {
			std::cout << i << "  " << used[i] << "\n";
		}
	}


}