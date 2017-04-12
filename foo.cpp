#include < iostream > 
#include < cstdlib > 
#include < ctime > 
#include < cmath > 
#include < vector > 
#include < map > 
#include < algorithm >
using namespace std;

typedef long long ll;

vector < string > vs;
map < int, string > mis;

void init_vs(ll k) {
    vs.push_back("");
    for (int i = 1; i < k; i++) {
        int rem = i % 4;
        if (rem == 1) vs.push_back("十");
        else if (rem == 2) vs.push_back("百");
        else if (rem == 3) vs.push_back("千");
        if (rem == 0) {
            if (i / 4 == 1) vs.push_back("万");
            else if (i / 4 == 2) vs.push_back("亿");
            else if (i / 4 == 3) vs.push_back("兆");
            else if (i / 4 == 4) vs.push_back("京");
        }
    }
    reverse(vs.begin(), vs.end());
}

void init_mis(int mode) {
    if (mode == 0) {
        mis.insert(pair < int, string > (0, "零"));
        mis.insert(pair < int, string > (1, "一"));
        mis.insert(pair < int, string > (2, "二"));
        mis.insert(pair < int, string > (3, "三"));
        mis.insert(pair < int, string > (4, "四"));
        mis.insert(pair < int, string > (5, "五"));
        mis.insert(pair < int, string > (6, "六"));
        mis.insert(pair < int, string > (7, "七"));
        mis.insert(pair < int, string > (8, "八"));
        mis.insert(pair < int, string > (9, "九"));
    } else {
        mis.insert(pair < int, string > (0, "零"));
        mis.insert(pair < int, string > (1, "壹"));
        mis.insert(pair < int, string > (2, "贰"));
        mis.insert(pair < int, string > (3, "叁"));
        mis.insert(pair < int, string > (4, "肆"));
        mis.insert(pair < int, string > (5, "伍"));
        mis.insert(pair < int, string > (6, "陆"));
        mis.insert(pair < int, string > (7, "柒"));
        mis.insert(pair < int, string > (8, "捌"));
        mis.insert(pair < int, string > (9, "玖"));
    }
}

string foo(ll num, ll k) {
    string r("");
    vector < ll > llv;
    int bt;

    do {
        bt = num - num / 10 * 10;
        llv.push_back(bt);
        num /= 10;
    } while (num);
    reverse(llv.begin(), llv.end());

    bt = -1;
    for (vector < ll > ::size_type i = 0; i < llv.size(); i++) {
        if (llv[i] == 0) {
            if (bt != 0) {
                if (i < llv.size() - 1) r += mis[llv[i]];
            }
        } else r += mis[llv[i]] + vs[i + k - llv.size()];
        bt = llv[i];
    }
    return r;
}

int main(int argc, char * argv[]) {
    ll n, k, m;
    if (argc == 4) {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
        m = atoi(argv[3]);
        if (k > 19) {
            cout << "max support 10E19, set k=19!" << endl;
        }
    } else {
        n = 1;
        k = 8;
        m = 0;
    }
    locale::global(locale(""));
    srand((unsigned) time(NULL));
    init_vs(k);
    init_mis(m);

    for (ll i = 1; i <= n; i++) {
        ll num = rand() % ((ll) pow(10, k));
        //ll num=9; //when k>1
        //ll num=0;
        //ll num=27740803;
        //ll num=27740003;
        //ll num=23392580;
        string r = foo(num, k);
        cout << "Case\t" << i << ":\t" << num << "\t\t\t" << r << endl;
    }

    return 0;
}
