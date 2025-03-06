#ifndef rsa_h
#define rsa_h

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector, std::pair;


vector<int> input();
inline void _print(const vector<int> &v);
vector<int> _multiply(const vector<int> &first, const vector<int> &second);
bool _gcd(const vector<int> &first, int e);
inline int _mod_int(vector<int> first, int e);
inline int _evklid(int a, int b);
vector<int> _pow(const vector<int> &first, int exp, const vector<int> &n);
vector<int> _mod(vector<int> first, vector<int> second);
pair<vector<int>, vector<int>> _divide(const vector<int> &first, const vector<int> &second);
bool _compare(const vector<int> &first, const vector<int> &second);
void _subtract(vector<int> &first, const vector<int> &second);
vector<int> division_int(vector<int> first, int e);
vector<int> pow_vector(const vector<int> &first, vector<int> d, const vector<int> &n);
inline bool equal(const vector<int> &first, const vector<int> &second);
vector<char> input_char();
pair<vector<int>, vector<int>> encryption_char(const vector<char> &message, int e, const vector<int> &n);
vector<int> decryption_char(pair<vector<int>, vector<int>> &cmessage, vector<int> &d, const vector<int> &n);
vector<int> calculate_d(const vector<int> &phi, int e);
vector<int> &operator ++(vector<int> &first);

#endif //rsa_h
