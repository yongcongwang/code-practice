#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

template <typename T>
struct Vertex {
  T data{};

  bool operator==(const Vertex<T>& rhs) const {
    return this->data == rhs.data;
  }
};

template <typename T>
struct Edge {
  Vertex<T> from{};
  Vertex<T> to{};
  T weight{0};

  bool operator==(const Edge<T>& rhs) const {
    return from == rhs.from && to == rhs.to;
  }
};

template <typename T>
struct Hasher {
  std::size_t operator()(const Vertex<T>& key) const {
    return std::hash<T>()(key.data);
  }

  std::size_t operator()(const Edge<T>& key) const {
    return std::hash<T>()(key.to->data) ^ (std::hash<T>()(key.weight) << 1);
  }
};

template <typename T>
class Graph {
 public:
  Graph() {}
  ~Graph() = default;
  Graph(const Graph& rhs) = delete;
  Graph& operator=(const Graph& rhs) = delete;

 public:
  void add_vertex(const Vertex<T>& ver) {
    if (auto res = ver_edges_.find(ver); res == ver_edges_.end()) {
      ver_edges_.insert(ver, {});
    }
  }
  void add_vertex(const T& val) {
    add_vertex({val});
  }
  void delete_vertex(const Vertex<T>& ver) {
    if (auto res = ver_edges_.find(ver); res != ver_edges_.end()) {
      ver_edges_.erase(res);
    }
  }
  void delete_vertex(const T& ver) {
    delete_vertex({ver});
  }

  void add_directed_edge(const Vertex<T>& from, const Vertex<T>& to,
                         const T& weight) {
    if (auto res = ver_edges_.find(from); res != ver_edges_.end()) {
      res->second.emplace(from, to, weight);
    }
  }
  void add_directed_edge(const T& from, const T& to, const T& weight) {
    add_directed_edge({from}, {to}, weight);
  }
  void delete_directed_edge(const Vertex<T>& from, const Vertex<T>& to) {
    if (auto res = ver_edges_.find(from); res != ver_edges_.end()) {
      auto& edges = res->second;
      if (auto edge = edges.find({from, to}); edge != edges.end()) {
        edges.erase(edge);
      }
    }
  }
  void delete_directed_edge(const T& from, const T& to) {
    delete_directed_edge({from}, {to});
  }
  void add_undirected_edge(const Vertex<T>& from, const Vertex<T>& to,
                           const T& weight) {
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
  }
  void add_undirected_edge(const T& from, const T& to, const T& weight) {
    add_undirected_edge({from}, {to}, weight);
  }
  void delete_undirected_edge(const Vertex<T>& from, const Vertex<T>& to) {
    delete_directed_edge(from, to);
    delete_directed_edge(to, from);
  }
  void delete_undirected_edge(const T& from, const T& to) {
    delete_undirected_edge({from}, {to});
  }

  void print_adjacency_list() const {
    for (const auto& v_e : ver_edges_) {
      std::cout << "[" << v_e.first.data << "]:" << std::endl;
      for (const auto& e : v_e.second) {
        std::cout << " -> " << e.to.data << std::endl;
      }
    }
  }

 private:
  std::unordered_map<
      Vertex<T>, std::unordered_set<Edge<T>, Hasher<T>>, Hasher<T>> ver_edges_;
};

int main() {
  Graph<int> graph{};
  graph.add_vertex(1);
  graph.add_vertex(2);
  graph.add_vertex(3);
  graph.add_vertex(4);
  
  graph.delete_vertex(4);
  graph.delete_vertex(3);
  graph.delete_vertex(3);

  graph.add_directed_edge(1, 3, 0);

  graph.print_adjacency_list();
}
