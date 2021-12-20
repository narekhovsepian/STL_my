#pragma once

namespace std_my {

	void dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, const int& start_vertex) {
		std::vector<int> distance(graph.size(), 100000);
		std::set < std::pair<int, int>> s;
		distance[start_vertex] = 0;
		s.insert({ 0,start_vertex });
		while (!s.empty()) {
			int current_vertex = s.begin()->second;
			s.erase(s.begin());
			for (int i{}; i != graph[current_vertex].size(); ++i) {
				int adjacent_vertex = graph[current_vertex][i].first;
				int weight = graph[current_vertex][i].second;
				if (distance[current_vertex] + weight < distance[adjacent_vertex]) {
					s.erase({ distance[adjacent_vertex],adjacent_vertex });
					distance[adjacent_vertex] = distance[current_vertex] + weight;
					s.insert({ distance[adjacent_vertex],adjacent_vertex });
				}


			}
		}

		for (const auto& i : distance)
			std::cout << i << " ";

	}

}

