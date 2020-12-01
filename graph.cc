#include <iostream>
#include <vector>

template <typename T>
struct Vertex {
  T data{};
  std::size_t index{0};
  bool visited{false};

  bool operator==(const Vertex<T>& rhs) {
    return this->data == rhs.data;
  }
};

template <typename T>
struct Edge {
  Vertex<T> from{};
  Vertex<T> to{};
  T weight{0};
};

template <typename T>
class Graph {
 public:
  Graph() = default;
  ~Graph() = default;
  Graph(const Graph& rhs) = delete;
  Graph& operator=(const Graph& rhs) = delete;

 public:
  void add_vertex(const T& val) {
    if (auto res = adjacency_list_.find({val}); res == adjacency_list_.end()) {
      adjacency_list_.emplace_back({val}, {});
    }
  }
  void delete_vertex(const T val) {
    if (auto res = adjacency_list_.find({val}); res != adjacency_list_.end()) {
      adjacency_list_.erase(res);
    }
  }

  void add_directed_edge(const Vertex<T>& from, const Vertex<T>& to,
                         const T& weight) {
    if (auto res = adjacency_list_.find(from); res != adjacency_list_.end()) {
      res->second.emplace_back(from, to, weight);
    }
  }
  void delete_directed_edge(const Vertex<T>& from, const Vertex<T>& to) {
    if (auto res = adjacency_list_.find(from); res != adjacency_list_.end()) {
      adjacency_list_.erase(res);
    }
  }
  void add_undirected_edge(const Vertex<T>& from, const Vertex<T>& to) {
    add_directed_edge(from, to, 0);
    add_directed_edge(to, from, 0);
  }
  void delete_undirected_edge(const Vertex<T>& from, const Vertex<T>& to) {
    delete_directed_edge(from, to);
    delete_directed_edge(to, from);
  }

  const std::vector<Edge<T>>& get_edges(const Vertex<T>& ver) {
    if (auto res = adjacency_list_.find(ver); res != adjacency_list_.end()) {
      return adjacency_list_->second;
    }
    return {};
  }
  const std::vector<Edge<T>>& get_edges(const T& ver) {
    return get_edges({ver});
  }

  void size() const {
    return size_;
  }

  void empty() const {
    return size() == 0;
  }

  void print_adjacency_list() const {
    for (const auto& adj : adjacency_list_) {
      std::cout << "[" << adj.first.data << "]:" << std::endl;
      for (const auto& e : adj.second) {
        std::cout << "  " << e.from.data << " -> " e.to.data << std::endl;
      }
    }
  }

 private:
  std::unordered_map<Vertex<T>, std::vector<Edge<T>>> adjacency_list_{};
  std::size_t size_{0};
};
