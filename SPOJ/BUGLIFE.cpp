//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked

list<int> adj[2001];
int g[2001];

bool susp = false;
void gi(int *p){
	register int c = gc(), x=0;
	while(c<48||c>57) c = gc();
	while(c>=48&&c<=57) {
		x = x*10 + c - 48;
		c = gc();
	}
	*p = x;
}

void traverse(int i){
	list<int>::iterator l = adj[i].begin();
	while(l!=adj[i].end())
	{
		int j = *l;
		if(g[j]==-1){
			g[j] = (g[i]==1)?0:1;
			traverse(j);
		}
		else if(g[i]==g[j]){
			susp = true;
			return;
		}
		l++;
	}
}

int main(){
	int t,n,m,i,j,cas=1;
	gi(&t);
	for(;cas<=t;cas++){
		gi(&n);
		gi(&m);
		for(i=1;i<=n;i++){
			adj[i].clear();
			g[i] = -1;
		}
		while(m--){
			gi(&i);
			gi(&j);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		susp = false;
		for(i=1;i<=n;i++){
			if(g[i]==-1){
				g[i] = 1;
				traverse(i);
			}
			if(susp) break;
		}
		printf("Scenario #%d:\n",cas);
		if(susp) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
	}
	return 0;
}