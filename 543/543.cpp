#include<bits/stdc++.h>
#define tam 1000005
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
 
bool comp(ll a, ll b){
	return a > b;
} 

bitset <tam> vis;
vi primos;
 
void generar(){
	vis.set();
	vis[0] = vis[1] = 0;
	for(int i = 2; i * i < tam; i++){
		if(vis[i]){
			for(int j = i * i; j < tam; j += i){
				vis[j] = 0;
			}
		}
	}
	primos.reserve(79000);
	for(int i = 3; i < tam; i++){
		if(vis[i]) primos.PB(i);
	}
} 
 
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	
	generar();
	while(1){
		int n;
		cin >> n;
		if(!n) break;
		int t = primos.size();
		int num1, num2;
		for(int i = 0; i < t; i++){
			num1 = primos[i];
			int j = lower_bound(primos.begin(), primos.end(), n - num1) - primos.begin();
			num2 = primos[j];
			if(num1 + num2 == n){
				cout << n << " = " << num1 << " + " << num2 << "\n";
				break;
			}
		}
	}
	
	
	return 0;
}
