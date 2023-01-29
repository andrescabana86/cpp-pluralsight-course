#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
using namespace std;

// print the elements of the array
template<typename T>
void printv(vector<T> & a) {
    for(T &i : a) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
template<typename T>
void message(const char * s, const T & v) { cout << s << ": " << v << endl; }

// return is_prime
template <typename T>
const bool is_prime(const T & num) {
    if (num <= 1) return false;
    bool primeflag = true;
    for (T l = 2; l< num; ++l) {
        if (num % l==0) {
            primeflag = false;
            break;
        }
    }
    return primeflag;
}

// return is_odd
template <typename T>
const bool is_odd(const T & n) {
    return ((n%2) == 1);
}

int main() {
    message("===============TESTING CONDITION EXAMPLE===============");
    vector<int> p1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,1,37
    };
    printv(p1);
    message("use all_of()");
    if (all_of(p1.begin(), p1.end(), is_prime<int>)) {
        cout << "they are all prime numbers" << endl;
    } else {
        cout << "they are not all prime numbers" << endl;
    }
    message("use any_of()");
    if (any_of(p1.begin(), p1.end(), is_prime<int>)) {
        cout << "any of them is prime number" << endl;
    } else {
        cout << "none of them is prime number" << endl;
    }
    message("use none_of()");
    if (none_of(p1.begin(), p1.end(), is_prime<int>)) {
        cout << "none of them is prime number" << endl;
    } else {
        cout << "one of them is prime number" << endl;
    }

    message("===============SEARCHING AND COUNTING EXAMPLE===============");
    vector<int> s1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(s1);
    message("use find()");
    auto it = find(s1.begin(), s1.end(), 32); // find first occurrence
    if (it != s1.end()) {
        size_t idx = it - s1.begin();
        cout << "found number at index " << idx << ": " << *it << endl;
    } else {
        cout << "number not found." << endl;
    }
    message("use find_if()");
    auto itf = find_if(s1.begin(), s1.end(), is_odd<int>); // find first occurrence that matches the unary condition
    if (itf != s1.end()) {
        size_t idx = itf - s1.begin();
        cout << "found number at index " << idx << ": " << *itf << endl;
    } else {
        cout << "number not found." << endl;
    }
    message("use find_if_not()");
    auto itfn = find_if_not(s1.begin(), s1.end(), is_odd<int>); // find first occurrence that does not match the unary condition
    if (itfn != s1.end()) {
        size_t idx = itfn - s1.begin();
        cout << "found number at index " << idx << ": " << *itfn << endl;
    } else {
        cout << "number not found." << endl;
    }
    message("use search()");
    vector<int> sub_s1 = {
        32,15,76,91,61
    };
    auto its = search(s1.begin(), s1.end(), sub_s1.begin(), sub_s1.end()); // find exact sequence of numbers from arr2 into arr1
    if (its != s1.end()) {
        size_t idx = its - s1.begin();
        cout << "found number at index " << idx << ": " << *its << endl;
    } else {
        cout << "number not found." << endl;
    }
    message("use count()");
    auto c = count(s1.begin(), s1.end(), 85); // count occurrences of a number
    cout << "found " << c << " occurrences" << endl;
    message("use count_if()");
    auto cif = count_if(s1.begin(), s1.end(), is_odd<int>); // count occurrences of a number that matches the unary condition
    cout << "found " << cif << " is_odd occurrences" << endl;

    message("===============REPLACING AND REMOVING EXAMPLE===============");
    vector<int> rpl1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(rpl1);
    message("replace all coincidences with value");
    replace(rpl1.begin(), rpl1.end(), 76, 11);
    printv(rpl1);
    message("replace all odd with value");
    replace_if(rpl1.begin(), rpl1.end(), is_odd<int>, 22);
    printv(rpl1);
    message("remove specific element or elements");
    auto rpl1_it = remove(rpl1.begin(), rpl1.end(),22);
    if (rpl1_it != rpl1.end()) {
        cout << "replaced " << *rpl1_it << endl;
        rpl1.resize(rpl1_it - rpl1.begin());
    } else {
        cout << "element not found" << endl;
    }
    printv(rpl1);
    message("remove specific element or elements based on a unary condition operator");
    vector<int> rm1 = {
        11,22,33,44,55,66,77,88,99
    };
    printv(rm1);
    auto rm1_it = remove_if(rm1.begin(), rm1.end(), is_odd<int>);
    if (rm1_it != rm1.end()) {
        cout << "replaced all odd" << endl;
        rm1.resize(rm1_it - rm1.begin());
    } else {
        cout << "element not found" << endl;
    }
    printv(rm1);
    message("remove duplicate adjacent elements");
    vector<int> dup1 = {
        1,2,3,3,4,5,5,6,6,7,88,99
    };
    printv(dup1);
    auto dup1_it = unique(dup1.begin(), dup1.end()); // if all unsorted, you have to sort first
    if (dup1_it != dup1.end()) {
        cout << "replaced all duplicates" << endl;
        dup1.resize(dup1_it - dup1.begin());
    } else {
        cout << "element not found" << endl;
    }
    printv(dup1);
    message("===============MODIFY EXAMPLE===============");
    vector<int> cp1 = {
            71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(cp1);
    message("reverse() from one container to another");
    vector<int> copy_md1(cp1);
    printv(copy_md1);
    reverse(copy_md1.begin(),copy_md1.end());
    printv(copy_md1);
    message("fill() container with value");
    vector<int> copy_cp1(cp1);
    printv(copy_cp1);
    fill(copy_cp1.begin(), copy_cp1.end()-5,999);
    printv(copy_cp1);
    message("fill_n() container with value");
    vector<int> copy_cp2(cp1);
    printv(copy_cp2);
    fill_n(copy_cp2.begin(), 10,666);
    printv(copy_cp2);
    message("generate() values for a container");
    vector<int> gen_cp2(cp1);
    printv(gen_cp2);
    generate(gen_cp2.begin(), gen_cp2.end(), [](/*no params*/)->int { return rand()%100; });
    printv(gen_cp2);
    message("random_shuffle() values of a container (DEPRECATED)");
    vector<int> rand_cp1(cp1);
    printv(rand_cp1);
    random_shuffle(rand_cp1.begin(), rand_cp1.end());
    printv(rand_cp1);
    message("shuffle() values of a container (REPLACEMENT OF random_shuffle())");
    // requires a number generator
    random_device rd;
    mt19937 g(rd()); // random generator
    vector<int> shuffle_cp1(cp1);
    printv(shuffle_cp1);
    shuffle(shuffle_cp1.begin(), shuffle_cp1.end(), g);
    printv(shuffle_cp1);

    message("===============PARTITION EXAMPLE===============");
    vector<int> part1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(part1);
    message("all odd values at the beginning of the partition");
    vector<int> part2(part1);
    printv(part2);
    partition(part2.begin(), part2.end(), is_odd<int>);
    printv(part2);
    message("all odd values at the beginning of the partition but within relative order");
    vector<int> part3(part1);
    printv(part3);
    stable_partition(part3.begin(), part3.end(), is_odd<int>);
    printv(part3);
    message("partition and copy results into other two vectors");
    vector<int> part4(part1);
    printv(part4);
    size_t partition_size = count_if(part4.begin(), part4.end(), is_odd<int>);
    vector<int> res1_part4(partition_size), res2_part4(part4.size() - partition_size);
    partition_copy(part4.begin(), part4.end(), res1_part4.begin(), res2_part4.begin(), is_odd<int>);
    printv(res1_part4);
    printv(res2_part4);

    message("===============SORTING EXAMPLE===============");
    vector<int> sort1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(sort1);
    message("sorts using a sort comparison lambda function");
    sort(sort1.begin(), sort1.end(), [](const int &l, const int &r)->bool { return l < r; });
    printv(sort1);

    message("===============MERGING EXAMPLE===============");
    vector<int> merge1 = {
        1,2,3,4,5,6,7,8,9
    };
    vector<int> merge2 = {
        11,22,33,44,55,66,77,88,99
    };
    printv(merge1);
    printv(merge2);
    message("merge both ordered vectors");
    auto gtcomp = [](const int &l, const int &r)->bool { return l < r; };
    vector<int> merge3(merge1.size() + merge2.size());
    merge(
        merge1.begin(), merge1.end(),
        merge2.begin(), merge2.end(),
        merge3.begin(), gtcomp);
    printv(merge3);

    message("===============BINARY SEARCH EXAMPLE===============");
    int number = 47;
    vector<int> bi1 = {
        71,85,47,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,47,48,86,62,24,1,36
    };
    printv(bi1);
    message("binary search must be always inside sorted vectors");
    sort(bi1.begin(), bi1.end());
    printv(bi1);
    message("binary search result:");
    // it returns true or false depending on the search result
    if (binary_search(bi1.begin(), bi1.end(), number))
        cout << "found " << number << endl;
    else
        cout << "did not find " << number << endl;
    message("lower bound result:");
    auto bi1_loit = lower_bound(bi1.begin(), bi1.end(), number); // returns iterator of first match
    auto bi1_loit_prev = bi1_loit;
    auto bi1_loit_next = bi1_loit;
    if (bi1_loit != bi1.end()) {
        cout << "previous value: " << *(--bi1_loit_prev) << " iterator" << endl;
        cout << "found " << *bi1_loit << " iterator" << endl;
        cout << "next value: " << *(++bi1_loit_next) << " iterator" << endl;
    } else
        cout << "did not find " << number << endl;
    message("upper bound result:");
    auto bi1_upit = upper_bound(bi1.begin(), bi1.end(), number); // returns iterator of last match
    auto bi1_upit_prev = bi1_upit;
    auto bi1_upit_next = bi1_upit;
    if (bi1_upit != bi1.end()) {
        cout << "previous value: " << *(--bi1_upit_prev) << " iterator" << endl;
        cout << "found " << *bi1_upit << " iterator" << endl;
        cout << "next value: " << *(++bi1_upit_next) << " iterator" << endl;
    } else
        cout << "did not find " << number << endl;
    message("equal range bound result:");
    auto bi1_eqit = equal_range(bi1.begin(), bi1.end(), number); // returns iterator of last match
    auto bi1_eqit_prev = bi1_eqit.first;
    auto bi1_eqit_next = bi1_eqit.second;
    cout << "previous lower bound of range: " << *(--bi1_eqit_prev) << " iterator" << endl;
    cout << "lower bound of range: " << *bi1_eqit.first << " iterator" << endl;
    cout << "upper bound of range: " << *bi1_eqit.second << " iterator" << endl;
    cout << "next upper bound of range: " << *(++bi1_eqit_next) << " iterator" << endl;

    return 0;
}
