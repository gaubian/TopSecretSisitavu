#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fo(i,a,n) for (int i=a;i<n;i++)
#define of(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PI = pair<int,int>;
#define int LL

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
const double EPS = 1e-8;

template <typename T>
typename T::value_type maximum(T &cont) {
    typename T::value_type best = *(cont.begin());
    for(typename T::value_type x : cont) setmax(best, x);
    return best;
}

template <typename T>
typename T::value_type maximum(T &cont, typename T::value_type best) {
    for(typename T::value_type x : cont) setmax(best, x);
    return best;
}

template <typename T>
typename T::value_type minimum(T &cont) {
    typename T::value_type best = *(cont.begin());
    for(typename T::value_type x : cont) setmin(best, x);
    return best;
}

template <typename T>
typename T::value_type minimum(T &cont, typename T::value_type best) {
    for(typename T::value_type x : cont) setmin(best, x);
    return best;
}

template <typename D>
D dPower(D base, LL exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}

vector<int> range(int a, int b) {
    vector<int> tab;
    for(int i = a; i < b; ++i) tab.push_back(i);
    return tab;
}

vector<int> range(int n) {
    return range(0, n);
}

template<typename T1, typename T2>
vector<pair<T1,T2>> zip(vector<T1> &A, vector<T2> &B) {
    vector<pair<T1, T2>> ans;
    for(int i = 0; i < A.size() && i < B.size(); ++i)
        ans.push_back(make_pair(A[i], B[i]));
    return ans;
}

template<typename A, typename B>
pair<vector<A>, vector<B>> unzip(vector<pair<A, B>> &T) {
    pair<vector<A>, vector<B>> ans;
    for(pair<A, B> x : T) {
        T.first.push_back(x.first);
        T.second.push_back(x.second);
    }
    return ans;
}

template<typename A, typename B>
pair<B, A> rev(const pair<A,B> &p) {
    return make_pair(p.second, p.first);
}

template<typename A, typename B>
vector<pair<B, A>> rev(const vector<pair<A,B>> &T) {
    vector<pair<B, A>> ans;
    for(auto p : T) ans.push_back(make_pair(p.second, p.first));
    return ans;
}

template<typename T>
vector<T> read_tab(int n) {
    vector<T> ans(n);
    for(int i = 0; i < n; ++i) cin >> ans[i];
    return ans;
}

template<typename A, typename B>
vector<pair<A,B>> read_tab(int n) {
    vector<pair<A,B>> ans(n);
    for(int i = 0; i < n; ++i) cin >> ans[i].first >> ans[i].second;
    return ans;
}

template<typename T>
vector<vector<T>> read_matrix(int m, int n) {
    vector<vector<T>> mat(m, vector<T> (n));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        cin >> mat[i][j];
    return mat;
}

template<typename T>
vector<vector<T>> transpose(vector<vector<T>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<T>> trans_mat(n, vector<T> (m));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        trans_mat[j][i] = mat[i][j];
    return trans_mat;
}

template<typename T>
vector<vector<T>> rotate(vector<vector<T>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<T>> rot_mat(n, vector<T> (m));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        rot_mat[j][i] = mat[m-i][j];
    return rot_mat;
}

template<long long MOD>
struct ModInt
{
    long long x;
    ModInt() : x(0) { }
    ModInt(long long u) : x(u) { if (x >= MOD || x < 0) { x %= MOD; if (x < 0) x += MOD; } } 
    ModInt(const ModInt &m) : x(m.x) { }
    ModInt& operator=(const ModInt &m) { x = m.x; return *this; }
    friend bool operator==(const ModInt& a, const ModInt& b) { return a.x == b.x; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.x != b.x; }
    friend bool operator<(const ModInt& a, const ModInt& b) { return a.x < b.x; }
 
    ModInt& operator+=(const ModInt& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(const ModInt& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    ModInt& operator*=(const ModInt& m) { x = (x*m.x)%MOD; return *this; }    
 
    friend ModInt operator+(const ModInt& a, const ModInt &b) { return ModInt(a) += ModInt(b); }
    friend ModInt operator-(const ModInt& a, const ModInt &b) { return ModInt(a) -= ModInt(b); }
    friend ModInt operator*(const ModInt& a, const ModInt &b) { return ModInt(a) *= ModInt(b); }
 
    static long long fp(long long u, long long k) {
        if (k == 0) return 1;
        long long res = fp(u, k/2);
        res = (res*res) % MOD;
        if (k & 1) res = (res*u) % MOD;
        return res;
    }
 
    ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
    ModInt inv() { return ModInt(fp(x, MOD-2)); }

    friend ostream& operator<<(ostream& os, const ModInt& v) {
        return (os << v.x);
    }
    friend istream& operator>>(istream& is, ModInt& v) {
        LL temp;
        is >> temp;
        v = ModInt(temp);
        return is;
    }

    ModInt& operator/=(const ModInt& m) { x = (x*fp(m.x, MOD - 2)) % MOD; return *this; }    
    friend ModInt operator/(const ModInt& a, const ModInt &b) { return ModInt(a) /= ModInt(b); }
};

template<typename C>
struct is_iterable {
  typedef long false_type;
  typedef char true_type;

  template<class T> static false_type check(...);
  template<class T> static true_type  check(int,
                    typename T::const_iterator = C().end());

  enum { value = sizeof(check<C>(0)) == sizeof(true_type) };
};

template <typename>
struct is_pair : std::false_type
{ };

template <typename T, typename U>
struct is_pair<std::pair<T, U>> : std::true_type
{ };

template<typename T> void print(T x);

template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print_tuple(const Tuple& t) 
    {
        TuplePrinter<Tuple, N-1>::print_tuple(t);
        std::cout << ",";
        print(std::get<N-1>(t));
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print_tuple(const Tuple& t) 
    {
        print(std::get<0>(t));
    }
};

template<class... Args>
void print(std::tuple<Args...>& t) {
    cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print_tuple(t);
    cout << ")";
}

template<typename T>
void print(T x) {
    if constexpr (is_iterable<T>::value) {
        if constexpr (is_same<string, T>::value) {
            cout << '"' << x << '"';
        }
        else {
            cout << '[';
            bool fst = true;
            for(auto y : x) {
                if(!fst) cout << ',';
                fst = false;
                print(y);
            }
            cout << ']';
        }
    }
    else {
        if constexpr (is_pair<T>::value) {
            cout << '(';
            print(x.first);
            cout << ',';
            print(x.second);
            cout << ')';
        }
        else cout << x;
    }
}

vector<pair<string,LL>> div_gcd(vector<pair<string,LL>> &tab) {
    vector<pair<string,LL>> ttab;
    LL tot_gcd = 0;
    for(auto p : tab) tot_gcd = gcd(tot_gcd, p.second);
    vector<pair<string,LL>> ans;
    for(auto p : tab) ans.pb(mp(p.first, p.second / tot_gcd));
    return ans;
}

LL rule(LL x, LL sum, LL D) {
    if(x == 0) return 0;
    x = (x * 10) / sum;
    //if(sum % x == 0) return sum / x;
    return 1 + x/sum;
}

signed main() {
    LL D, N, M, C, B;
    cin >> D >> N >> M >> C >> B;
    vector<tuple<LL,LL,string,LL>> edges;
    vector<map<LL,LL>> G(N);
    vector<map<LL,LL>> revG(N);
    map<pair<LL,LL>,string> p_to_s;
    map<string,pair<LL,LL>> s_to_p;
    for(LL i = 0; i < M; ++i) {
        LL b, e, l;
        string s;
        cin >> b >> e >> s >> l;
        edges.push_back(make_tuple(b,e,s,l));
        G[b][e] = l;
        revG[e][b] = l;
        p_to_s[make_pair(b,e)] = s;
        s_to_p[s] = make_pair(b,e);
    }
    vector<vector<string>> paths;
    for(LL i = 0; i < C; ++i) {
        LL P;
        cin >> P;
        vector<string> tab;
        for(LL j = 0; j < P; ++j) {
            string s;
            cin >> s;
            tab.push_back(s);
        }
        paths.push_back(tab);
    }
    /*cout << "digraph G {\n";
    for(auto t : edges) cout << get<0>(t) << " -> " << get<1>(t) << ";\n";
    cout << "}";
    */
    // can_arrive
    vector<LL> score(C,0);
    for(LL i = 0; i < C; ++i) {
        LL sum = 0;
        vector<string> path_i = paths[i];
        for(LL j = 1; j < path_i.size(); ++j) {
            string s = path_i[j];
            LL b = s_to_p[s].first;
            LL e = s_to_p[s].second;
            sum += G[b][e] + 1;
        }
        if(sum > D) score[i] = 0;
        else score[i] = 1050LL/sum;
        //else score[i] = D - sum;
    }

    // proportional
    map<string,LL> nb_cars_in;
    for(LL i = 0; i < C; ++i) {
        for(int j = 0; j < paths[i].size() - 1; ++j) {
            string s = paths[i][j];
            nb_cars_in[s] += score[i];
        }
    }

    map<string,LL> sum_start;
    for(LL i = 0; i < C; ++i) {
        for(LL j = 0; j < paths[i].size(); ++j)
            sum_start[paths[i][0]] += (score[i] / (1 << j));
    }

    cout << N << '\n';
    for(LL i = 0; i < N; ++i) {
        LL sum = 0;
        for(auto p_in_n : revG[i]) {
            LL in_n = p_in_n.first;
            string s_name = p_to_s[mp(in_n,i)];   
            sum += nb_cars_in[s_name];
        }
        vector<tuple<LL,string,LL>> ans;
        for(auto p_in_n : revG[i]) {
            LL in_n = p_in_n.first;
            string s_name = p_to_s[mp(in_n,i)];
            LL x = rule(nb_cars_in[s_name],sum,D);
            if(x > 0) ans.push_back(mt(-sum_start[s_name],s_name,x)); 
        }
        //ans = div_gcd(ans);
        if(ans.size() == 0) {
            LL j = 0;
            for(auto p_in_n : revG[i]) {
                j = p_in_n.first;
                break;
            }
            string s = p_to_s[mp(j,i)];
            ans.push_back(mt(-sum_start[s],s,1));
        }
        sort(all(ans));
        cout << i << '\n' << ans.size() << '\n';
        for(auto p : ans) cout << get<1>(p) << ' ' << get<2>(p) << '\n';
    }
}
