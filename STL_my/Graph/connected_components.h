#pragma once
#include"dfs_bfs.h"
namespace std_my {

	/*void dfs_listc(std::vector<std::vector<int>>& graph, std::vector<int>& used, int start) {
		used[start] = 1;
		std::cout << start << "  ";
		for (int i{}; i != graph[start].size(); ++i) {
			int adjacent_vertex = graph[start][i];
			if (!used[adjacent_vertex]) {
				dfs_list(graph, used, adjacent_vertex);
			}
		}

	}*/


	void connected_components(std::vector<std::vector<int>>& graph) {
		std::vector<int> used(graph.size(), 0);
		for (int i{}; i != graph.size(); ++i) {
			if (!used[i]) {
				//dfs_listc(graph, used, i);
				dfs_list(graph, used, i);
				std::cout << "\n";
			}
		}

	}

}