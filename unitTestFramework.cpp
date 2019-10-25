#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <exception>
#include <sstream>

using namespace std;

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template <class T, class U>
void AssertEqual (const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << endl;
        os << "Hint: " << hint;
        throw runtime_error(os.str());
    }
}

// Checking for emptiness
void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

int main() {

    int a = 1;
    int b = 2;
    AssertEqual(a, b, "PhD");

    return 0;
}
