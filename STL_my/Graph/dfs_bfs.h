#pragma once 

namespace std_my {

	void bfs_list(std::vector<std::vector<int>>& graph, int start) {
		std::vector<int> used(graph.size(), 0);
		std::queue<int> q;
		used[start] = 1;
		q.push(start);

		while (!q.empty()) {
			int current_vertex = q.front();
			q.pop();
			std::cout << current_vertex << "  ";
			for (int i{}; i != graph[current_vertex].size(); ++i) {
				int adjacent_vertex = graph[current_vertex][i];
				if (!used[adjacent_vertex]) {
					q.push(adjacent_vertex);
					used[adjacent_vertex] = 1;
				}
			}
		}
	}


	void bfs_matrix(std::vector<std::vector<int>>& graph, int start) {
		std::vector<int> used(graph.size(), 0);
		std::queue<int> q;
		q.push(start);
		used[start] = 1;

		while (!q.empty()) {
			int current_vertex = q.front();
			q.pop();
			std::cout << current_vertex << "  ";
			for (int i{}; i != graph[current_vertex].size(); ++i) {
				if (graph[current_vertex][i] == 1) {
					int adjacent_vertex = i;
					if (used[adjacent_vertex] != 1) {
						q.push(i);
						used[i] = 1;
					}

				}
			}
		}
	}


	void dfs_list(std::vector<std::vector<int>>& graph, std::vector<int>& used, int start) {
		used[start] = 1;
		std::cout << start << "  ";
		for (int i{}; i != graph[start].size(); ++i) {
			int adjacent_vertex = graph[start][i];
			if (!used[adjacent_vertex]) {
				dfs_list(graph, used, adjacent_vertex);
			}
		}
	}

	void dfs_list(std::vector<std::vector<int>>& graph, int start) {
		std::vector<int> used(graph.size(), 0);
		dfs_list(graph, used, start);
	}


	void dfs_matrix(std::vector<std::vector<int>>& graph, std::vector<int>& used, int start) {
		used[start] = 1;
		std::cout << start << "  ";
		for (int i{}; i != graph[start].size(); ++i) {
			if (graph[start][i] == 1) {
				if (!used[i]) {
					dfs_matrix(graph, used, i);
				}
			}
		}
	}

	void dfs_matrix(std::vector<std::vector<int>>& graph, int start) {
		std::vector<int> used(graph.size(), 0);
		dfs_matrix(graph, used, 0);
	}



}