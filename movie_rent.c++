#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    struct Node {
        int shop;
        int movie;
        int price;
        Node() = default;
        Node(int s, int m, int p) : shop(s), movie(m), price(p) {}
    };

    // Comparator: price ↑, shop ↑, movie ↑ (strict ordering)
    struct Cmp {
        bool operator()(const Node &a, const Node &b) const {
            if (a.price != b.price) return a.price < b.price;
            if (a.shop  != b.shop)  return a.shop  < b.shop;
            return a.movie < b.movie;
        }
    };

    // available copies grouped by movie id
    unordered_map<int, set<Node, Cmp>> availableByMovie;
    // all currently rented copies (global sorted set)
    set<Node, Cmp> rentedSet;
    // quick lookup (shop,movie) -> Node
    unordered_map<long long, Node> byPair;

    static long long key(int shop, int movie) {
        return ( (long long)shop << 32 ) | (unsigned long long)movie;
    }

public:
    // n is unused but kept for parity with problem signature
    MovieRentingSystem(int n, const vector<vector<int>>& entries) {
        for (const auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Node node(shop, movie, price);
            byPair[key(shop, movie)] = node;
            availableByMovie[movie].insert(node);
        }
    }

    // Return up to 5 shops for given movie: cheapest then shop asc
    vector<int> search(int movie) {
        vector<int> ans;
        auto itMap = availableByMovie.find(movie);
        if (itMap == availableByMovie.end() || itMap->second.empty()) return ans;
        auto it = itMap->second.begin();
        for (int i = 0; i < 5 && it != itMap->second.end(); ++i, ++it) {
            ans.push_back(it->shop);
        }
        return ans;
    }

    // Rent the (shop, movie): available -> rented
    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        auto it = byPair.find(k);
        if (it == byPair.end()) return;               // defensive
        Node node = it->second;
        auto amIt = availableByMovie.find(movie);
        if (amIt != availableByMovie.end()) {
            amIt->second.erase(node);
        }
        rentedSet.insert(node);
    }

    // Drop the (shop, movie): rented -> available
    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        auto it = byPair.find(k);
        if (it == byPair.end()) return;               // defensive
        Node node = it->second;
        rentedSet.erase(node);
        availableByMovie[movie].insert(node);
    }

    // Return up to 5 rented pairs [shop, movie] ordered by price, shop, movie
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        auto it = rentedSet.begin();
        for (int i = 0; i < 5 && it != rentedSet.end(); ++i, ++it) {
            ans.push_back({it->shop, it->movie});
        }
        return ans;
    }
};
