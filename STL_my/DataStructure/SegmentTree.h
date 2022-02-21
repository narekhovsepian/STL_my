#pragma once



namespace std_my {

	std::vector<int> tree;

	template<typename Pred>
	void build_tree(const std::vector<int>& a, int v = 1, int l = 0, int r = 0, Pred p = {}) {

		if (l == r) {
			tree[v] = a[l];
			return;
		}

		int m = (l + r) / 2;

		build_tree<Pred>(a, v * 2, l, m);
		build_tree<Pred>(a, v * 2 + 1, m + 1, r);

		tree[v] = p(tree[v * 2], tree[v * 2 + 1]);
	}

	template<typename Pred>
	void update_tree(int i, int x, int v, int l = 0, int r = 0, Pred p = {}) {

		if (l == r) {
			tree[v] = x;
			return;
		}

		int m = (l + r) / 2;

		if (i <= m) {
			update_tree<Pred>(i, x, v * 2, l, m);
		}
		else {
			update_tree<Pred>(i, x, v * 2 + 1, m + 1, r);
		}

		tree[v] = p(tree[v * 2], tree[v * 2 + 1]);

	}

	template<typename Pred>
	int sum(int i, int j, int v = 1, int l = 0, int r = 0,Pred p = {}) {

		if (i > j)
			return 0;

		if (i == l && j == r) {
			return tree[v];
		}

		int m = (l + r) / 2;
		if (j <= m) {
			sum<Pred>(i, j, v * 2, l, m);
		}
		else
			if (m < i) {
				sum<Pred>(i, j, v * 2 + 1, m + 1, r);
			}
			else
				return p(sum<Pred>(i, m, v * 2, l, m), sum<Pred>(m + 1, j, v * 2 + 1, m + 1, r));


	}










}