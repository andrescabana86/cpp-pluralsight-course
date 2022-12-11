#include <iostream>
#include <string>
#include <map>
using namespace std;

// print a pair
template <typename T1, typename T2>
void print_pair(pair<T1,T2> & p) {
    cout << p.first << ": " << p.second << endl;
}

// print the elements of the map
template<typename T>
void print_map(T & m) {
    if(m.empty()) return;
    for(auto x : m) print_pair(x);
    cout << endl;
}

// print a simple message
void message(const char * m) { cout << m << endl; }
template <typename T>
void message(const char * m, const T & v) { cout << m << ": " << v << endl; }

// MARK: - main

int main() {
    message("map of strings from initializer list");
    map<string, string> mapstr = { { "George", "Father" }, { "Ellen", "Mother" },
                                   { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };

    message("size", mapstr.size()); // size: 4
    message("get some values");
    message("George", mapstr["George"]); // George: Father
    message("Ellen", mapstr.at("Ellen")); // Ellen: Mother
    message("Spike", mapstr.find("Spike")->second); // Spike: Neighbor's Son
    message("print_map:");
    print_map(mapstr);
    /*
        Ellen: Mother
        George: Father
        Ruth: Daughter
        Spike: Neighbor's Son
    */

    message("insert an element");
    mapstr.insert( { "Luke", "Neighbor" } );
    message("size", mapstr.size()); // size: 5
    print_map(mapstr);
    /*
        Ellen: Mother
        George: Father
        Luke: Neighbor
        Ruth: Daughter
        Spike: Neighbor's Son
    */

    cout << "insert a duplicate:" << endl;
    auto rp = mapstr.insert( { "Luke", "Neighbor" } );
    if (rp.second) {
        message("insert succeeded");
        print_pair(*rp.first);
    } else {
        message("insert failed"); // insert failed
    }
    message("size", mapstr.size()); // size: 5
    print_map(mapstr);
    /*
        Ellen: Mother
        George: Father
        Luke: Neighbor
        Ruth: Daughter
        Spike: Neighbor's Son
    */

    message("multimap of strings from initializer list");
    multimap<string, string> multimapstr = { { "George", "Father" }, { "Ellen", "Mother" },
                                   { "Ruth", "Daughter" }, { "Luke", "Neighbor" } };
    cout << "insert a duplicate:" << endl;
    multimapstr.insert( { "Luke", "Neighbor" } );
    message("insert succeeded");
    message("size", mapstr.size()); // size: 5
    print_map(multimapstr);
    /*
        Ellen: Mother
        George: Father
        Luke: Neighbor
        Luke: Neighbor
        Ruth: Daughter
    */

    message("find and erase Spike");
    auto it = mapstr.find("Spike");
    if(it != mapstr.end()) {
        message("found");
        print_pair(*it); // Spike: Neighbor's Son
        mapstr.erase(it);
        message("erased");
    } else {
        message("not found");
    }
    message("size", mapstr.size()); // size: 4
    print_map(mapstr);
    /*
        Ellen: Mother
        George: Father
        Luke: Neighbor
        Ruth: Daughter
    */

    return 0;
}
