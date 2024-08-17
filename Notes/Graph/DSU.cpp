#include <vector>
#include <numeric>
#include <algorithm>

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0), size(n, 1), num_components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite_by_size(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                std::swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            num_components--;
            return true;
        }
        return false;
    }

    bool unite_by_rank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            num_components--;
            return true;
        }
        return false;
    }

    int component_size(int x) {
        return size[find(x)];
    }

    int components() const {
        return num_components;
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(parent.size());
        std::vector<int> group_size(parent.size(), 0);
        for (int i = 0; i < parent.size(); i++) {
            leader_buf[i] = find(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(parent.size());
        for (int i = 0; i < parent.size(); i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < parent.size(); i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> size;
    int num_components;
};