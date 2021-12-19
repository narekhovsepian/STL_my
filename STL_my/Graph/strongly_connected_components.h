#pragma once
#include"topological_sort.h"
#include"dfs_bfs.h"
namespace std_my {

	void strongly_connected_components(std::vector<std::vector<int>>& graph) {
		std::vector<int> used(graph.size(), 0);
		std::vector<std::vector<int>> rev_graph(graph.size());

		std::vector<int> time_out;


		for (int i{}; i != graph.size(); ++i) {
			if (!used[i]) {
				dfs_top(graph, used, time_out, i);
			}
		}
		std::reverse(time_out.begin(), time_out.end());

		for (int i{}; i != graph.size(); ++i) {
			for (int j{}; j != graph[i].size(); ++j) {
				rev_graph[graph[i][j]].push_back(i);
			}
		}
		for (int i{}; i != used.size(); ++i) {
			used[i] = 0;
		}
		char a = 'A';
		for (int i{}; i != time_out.size(); ++i) {
			if (!used[time_out[i]]) {
				std::cout << a << " -> ";
				dfs_list(rev_graph, used, time_out[i]);
				std::cout << "\n\n";
				++a;
			}
		}


	}


}