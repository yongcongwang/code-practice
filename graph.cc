#include <iostream>
#include <vector>
#include <unordered_set>

template <typename T>
struct Hasher;
template <typename T>
struct Vertex;

template <typename T>
struct Edge {
  Vertex<T>* to{nullptr};
  T weight{0};

  bool operator==(const Edge<T>& rhs) {
    return this->to == rhs.to && this->weight == rhs.weight;
  }
};

template <typename T>
struct Vertex {
  T data{};
  std::unordered_set<Edge<T>, Hasher<T>> edges{};

  bool operator==(const Vertex<T>& rhs) const {
    return this->data == rhs.data;
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
    if (auto res = vertexes_.find(ver); res == vertexes_.end()) {
      vertexes_.insert(ver);
    }
  }
  void add_vertex(const T& val) {
    add_vertex({val, {}});
  }
  void delete_vertex(const Vertex<T>& ver) {
    if (auto res = vertexes_.find(ver); res != vertexes_.end()) {
      vertexes_.erase(res);
    }
  }
  void delete_vertex(const T& ver) {
    delete_vertex({ver, {}});
  }

  void add_directed_edge(const Vertex<T>& from, const Vertex<T>& to,
                         const T& weight) {
    auto res_from = vertexes_.find(from);
    auto res_to = vertexes_.find(to);
    if (res_from != vertexes_.end() && res_to != vertexes_.end()) {
      res_from->edges.insert({&(*res_to), weight});
    }
  }
  void add_directed_edge(const T& from, const T& to, const T& weight) {
    add_directed_edge({from, {}}, {to, {}}, weight);
  }
  void delete_directed_edge(const Vertex<T>& from, const Vertex<T>& to) {
    if (auto res_from = vertexes_.find(from); res_from != vertexes_.end()) {
      auto& edges = res_from->edges;
      if (auto res_to = edges.find(to); res_to != edges.end()) {
        edges.erase(res_to);
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
    for (const auto& ver : vertexes_) {
      std::cout << "[" << ver.data << "]:" << std::endl;
      for (const auto& e : ver.edges) {
        std::cout << " -> " << e.to->data << std::endl;
      }
    }
  }

 private:
  std::unordered_set<Vertex<T>, Hasher<T>> vertexes_;
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

  Edge<int> edge{nullptr, 0};
  graph.add_directed_edge(1, 3, 0);

  graph.print_adjacency_list();
}
