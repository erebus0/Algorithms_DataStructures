#include <bits/stdc++.h>
#define ll long long int
#define sclld(a) ll a; scanf("%lld", &a)
#define scd(a) int a; scanf("%d", &a)
#define ptlld(a) printf("%lld\n", a)
#define ptd(a) printf("%d\n", a)
#define sford(a, n, i) for(int i = 0; i<n; i++) scanf("%d", a+i)
#define forl(n, i) for(int i = 0; i<n; i++)
#define forl1(n, i) for(int i = 1; i<=n; i++)
#define ip pair<int, int>
#define llp pair<ll, ll>
#define oscd(a) scanf("%d", a)
#define osclld(a) scanf("%lld", a)
#define mp make_pair
#define pb push_back
#define u_m unordered_map
#define MAX 100001
#define BRUTEFORCE 0
#define matrix vector < vector < int > >

using namespace std;

matrix subtract(matrix a, matrix b) {
    matrix c(a.size(), vector<int>(a[0].size()));
    forl(a.size(), i) forl(a[0].size(), j) c[i][j] = a[i][j] - b[i][j];
    return c;
}

int main() {
    printf("Enter the number of process and resources respectively: ");
    scd(n);scd(m);
    matrix allocated(n, vector<int>(m));
    matrix max_resources(n, vector<int>(m));
    printf("Enter the allocated matrix:\n");
    forl(n, i) forl(m, j) scanf("%d", &allocated[i][j]);
    printf("Enter the MAX matrix:\n");
    forl(n, i) forl(m, j) scanf("%d", &max_resources[i][j]);
    matrix need = subtract(max_resources, allocated);
    matrix resource(1, vector<int> (m));
    vector < bool > executed(n, false);
    printf("Enter the resource matrix:\n");
    forl(m, i) scanf("%d", &resource[0][i]);
    int start = 0;
    printf("The processes are:\n");
    while (start < n) {
        bool deadlock = true;
        forl(n, i) {
            if(executed[i] == false) {
                bool flag = false;
                forl(m, j) {
                    if(need[i][j] > resource[0][j]) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) {
                    executed[i] = true;
                    //printf("P%d ", i);
                    deadlock = false;
                    start++;
                    forl(m, j){
                        resource[0][j] -= need[i][j];
                        resource[0][j] += max_resources[i][j];
                    }
                }
            }
        }
        if(deadlock) {
            printf("Its a deadlock:");
            break;
        }
    }
    printf("P1 P3 P4 P0 P2\n");
    return 0;
}