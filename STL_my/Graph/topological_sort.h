#pragma once

namespace std_my {

	void dfs_top(std::vector<std::vector<int>>& graph, std::vector<int>& used, std::vector<int>& time_out, int start) {
		used[start] = 1;
		for (int i{}; i != graph[start].size(); ++i) {
			int adjacent_vertex = graph[start][i];
			if (used[adjacent_vertex] != 1) {
				dfs_top(graph, used, time_out, adjacent_vertex);
			}
		}
		time_out.push_back(start);
	}

	void topological_sort(std::vector<std::vector<int>>& graph) {
		std::vector<int> used(graph.size(), 0);
		std::vector<int> time_out;
		for (int i{}; i != graph.size(); ++i) {
			if (!used[i]) {
				dfs_top(graph, used, time_out, i);
			}
		}

		std::reverse(time_out.begin(), time_out.end());

		for (int i{}; i != time_out.size(); ++i) {
			std::cout << i << " -> " << time_out[i] << "\n";
		}
	}


}