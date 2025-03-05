#include "rsa.h"

using std::cout;

int main()
{
    vector<int> p;
    vector<int> q;

    cout << "p\t";
    p = input();
    cout << "q\t";
    q = input();

    vector<int> n = _multiply(p, q);
   
    cout << "n\t";
    _print(n);

    p[0] -= 1;
    q[0] -= 1;

    cout << "p - 1\t";
    _print(p);

    cout << "q - 1\t";
    _print(q);

    vector<int> phi = _multiply(p, q);

    cout << "phi\t";
    _print(phi);

    int e = 2;

    do
    {   
        e -= 1;
        e = e << 1;
        e += 1;
      
    } while (!_gcd(phi,e));
    
    cout << "e\t" << e << "\n";
      
    vector<int> d;
    
    d = calculate_d(phi, e);

    cout << "d\t";
    _print(d);

    vector<char> message;

    cout << "message\t";
    message = input_char();

    pair<vector<int>, vector<int>> cf;
    cf = encryption_char(message, e, n);

    vector<int> dc;

    dc = decryption_char(cf, d, n);

    cout << "df\t";
    _print(dc);


    return 0;
    
    
}
