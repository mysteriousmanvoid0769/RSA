#include "rsa.h"

using std::string, std::cin, std::cout;

vector<int> input()
{
    string input;
    vector<int> input_vector;

    cin >> input;

    for(char digit: input)
    {
        if(digit >= '0' && digit <= '9')
        {
            input_vector.push_back(digit - '0');
        }
    }
    
    std::reverse(input_vector.begin(), input_vector.end());

    return input_vector;
}

inline void _print(const vector<int> &v)
{
    for(auto iter = v.rbegin(); iter != v.rend(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n";
}

vector<int> _multiply(const vector<int> &first, const vector<int> &second)
{
    vector<int> mp_vector;

    mp_vector.resize(first.size() + second.size() + 1);

    for(size_t i = 0; i != first.size(); i++)
    {
        int transfer = 0;

        for(size_t j = 0; j != second.size(); j++)
        {
            int mp = first[i] * second [j] + mp_vector[i + j] + transfer;
            mp_vector[i + j] = mp % 10;
            transfer = mp / 10;
        }
        
        mp_vector[i + second.size()] += transfer;
    }

    while(mp_vector.back() == 0)
    {
        mp_vector.pop_back();
    }
   
    return mp_vector;
}

bool _gcd(const vector<int> &first, const int e)
{
    int mod_gcd_integer = _mod_int(first, e);
    
    int gcd_res = _evklid(mod_gcd_integer, e);
    
    return gcd_res == 1;
}

int _mod_int(vector<int> first, int e)
{
	int mod = 0;
	
	std::reverse(first.begin(), first.end());
	
	for(int digit: first)
	{
		mod = (mod * 10 + digit) % e; 
	}
	
	return mod;
}

int _evklid(int a, int b)
{
	while(b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

vector<int> _pow(const vector<int> &first, int e, const vector<int> &n)
{
    vector<int> pow_vector = {1};
    vector<int> mod_vector = _mod(first, n);

    while (e > 0) 
    {
        if (e % 2 == 1)
        {
            pow_vector = _mod(_multiply(pow_vector, mod_vector), n);
		}

        mod_vector = _mod(_multiply(mod_vector, mod_vector), n);
        e >>= 1;
    }

    return pow_vector;
}

vector<int> _mod(vector<int> first, vector<int> second)
{
    auto[quotient, remainder] = _divide(first, second);
    return remainder;
}

pair<vector<int>, vector<int>> _divide(const vector<int> &first, const vector<int> &second)
{
    vector<int> quotient;
    vector<int> remainder;
    

    for (int i = first.size() - 1; i >= 0; i--) 
    {
        remainder.insert(remainder.begin(), first[i]);

        while (remainder.size() > 1 && remainder.back() == 0)
        {
            remainder.pop_back();
        } 
        
        int ch = 0;

        while (_compare(second, remainder))
        {
            _subtract(remainder, second);
            ch++;
        }
        quotient.push_back(ch);
    }

    std::reverse(quotient.begin(), quotient.end());

    while (quotient.size() > 1 && quotient.back() == 0)
    {
        quotient.pop_back();
    } 

    return {quotient, remainder};
}

bool _compare(const vector<int> &first, const vector<int> &second)
{
    if (first.size() != second.size())
    {
        return first.size() < second.size();
    } 
    for (int i = first.size() - 1; i >= 0; i--) 
    {
        if (first[i] != second[i])
        {
            return first[i] < second[i];
        } 
    }
    return true;
}

void _subtract(vector<int> &first, const vector<int> &second)
{
    if(equal(first, second))
    {
        first = {0};
        return;
    }
    int t;
    t = 0;

    for(size_t i = 0; i < first.size(); i++)
    {
        int p;
        p = t;

        if(i < second.size())
        {
            p += second[i];
        }

        if(first[i] < p)
        {
            first[i] += 10;
            t = 1;
        }
        else
        {
            t = 0;
        }

        first[i] -= p;
    }

    while(first.back() == 0)
    {
        first.pop_back();
    }
}

//---------------------------------------------------------------------------------

vector<int> division_int(vector<int> first, const int e)
{
    vector<int> divider_vector;

    std::reverse(first.begin(), first.end());

    int divider = 0;

    for (int digit : first)
    {
        divider = (divider * 10) + digit;

        int res = divider / e;

        divider_vector.push_back(res);

        divider %= e;
    }


    while (!divider_vector.empty() && divider_vector[0] == 0) 
    {
        divider_vector.erase(divider_vector.begin());
    }

    std::reverse(divider_vector.begin(), divider_vector.end());

    return divider_vector;
}

vector<int> pow_vector(const vector<int> &first, vector<int> d, const vector<int> &n)
{
    vector<int> pow_vector = {1};
    vector<int> mod_vector = _mod(first, n);
    vector<int> two = {2};
    vector<int> zero = {0};

    while (!equal(zero, d))
    {
        auto[quotient, remainder] = _divide(d, two);

        if (equal({1}, remainder))
        {
            pow_vector = _mod(_multiply(pow_vector, mod_vector), n);
		}

        mod_vector = _mod(_multiply(mod_vector, mod_vector), n);
        d = quotient;
    }

    return pow_vector;
}

inline bool equal(const vector<int> &first, const vector<int> &second)
{
    return first == second;
}

vector<char> input_char()
{
    string input;
    vector<char> input_vector;

    cin >> input;

    for(char symbol: input)
    {
        input_vector.push_back(symbol);
    }

    return input_vector;
}

pair<vector<int>, vector<int>> encryption_char(const vector<char> &message, int e, const vector<int> &n)
{
    pair<vector<int>, vector<int>> result;
    
    vector<int> res;
    vector<int> count;
    
    for(char symbol: message)
    {
		int count_int = 0;
		int sym = symbol;
		cout << sym << "\n";

		while(sym > 0)
		{
			res.push_back(sym % 10);
			sym /= 10;
			count_int++;
		}

		count.push_back(count_int);
	}
	
	vector<int> res_pow;
	
	res_pow = _pow(res, e, n);
	
	cout << "res_pow\t";
	_print(res_pow);
		
	result.first = res_pow;
	result.second = count;    

    return result;
}

vector<int> decryption_char(pair<vector<int>, vector<int>> &cmessage, vector<int> &d, const vector<int> &n)
{
    
    vector<int> res;
    
    string output;

    res = pow_vector(cmessage.first, d, n);
    
    vector<int> t_int;
    t_int = res;
    
    std::reverse(cmessage.second.begin(), cmessage.second.end());
    
    for(size_t i = 0; i < cmessage.second.size(); i++)
    {
		int count;
		int count_erase;
		count = cmessage.second[i];
		count_erase = cmessage.second[i];
		
		int num = 0;
		for(auto iter = t_int.end() - 1; iter != t_int.begin() - 1; iter--)
		{
			num = (num * 10) + *iter;
			count--;
			if(count < 1)
			{
				break;
			}
		}
		
		t_int.erase(t_int.end() - count_erase, t_int.end());
		
		output += static_cast<char> (num);
	} 
	
	std::reverse(output.begin(), output.end());
	cout << "output\t" << output << "\n";

    return res;
}

//----------------------------------------------------------------------------------

vector<int> calculate_d(const vector<int> &phi, int e)
{
    vector<int> k {1};
    vector<int> first;

    while(1)
    {
        first = _multiply(phi, k);
        ++first; 

        int t; 
        t = _mod_int(first, e);

        if(t == 0)
        {
            break;
        }

        ++k;
    }

    cout << "k\t";
    _print(k);

    vector<int> d;

    d = division_int(first, e);

    return d;
}

vector<int> &operator ++(vector<int> &first)
{
    int t = 0;
    first[0] += 1;

    for(size_t i = 0; i != first.size(); i++)
    {
        first[i] += t; 
        t = 0;
        if(first[i] > 9)
        {
            t = 1;
            first[i] -= 10;
        }
    }

    if(t == 1)
    {
        first.push_back(1);
    }

    return first;
}