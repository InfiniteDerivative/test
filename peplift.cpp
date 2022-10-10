// //Kth ancestor
// //https://www.youtube.com/watch?v=PE-kQVZxvWA&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=1

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>

// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }



// int MX = 17;
// vii table;
// void buildTable(vi parent)
// {
//     int n = parent.size();
//     table.resize(MX,vi(n));

//     //filling the first row
//     for(int i=0 ;i<n; i++)
//     {
//         table[0][i] = parent[i];
//     }

//     for(int i=1; i<MX; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             table[i][j] = table[i-1][table[i-1][j]];
//         }
//     }
// }

// int query(int a, int k)
// {
//     for(int i=0; i<MX; i++)
//     {
//         int mask = (1<<i);
//         if((k&mask)>0)
//         {
//             a = table[i][a];
//         }
//     }

//     return a;
// }

// int main()
// {
//     file_in_out();

//     int n;
//     cin>>n;
//     vi parent(n);
//     for(int i=0; i<n; i++)
//     {
//         cin>>parent[i];
//     }

//     buildTable(parent);

//     int q;
//     cin>>q;
    
//     while(q--)
//     {
//         int a,k;
//         cin>>a>>k;
//         int ans = query(a,k);
//         cout<<ans<<endl;
//     }
  

// }










// //Lowest Common Ancestor | Binary Lifting (inefficient approach)
// //https://www.youtube.com/watch?v=FzOSaw55Tp8&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=2&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>

// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// void display1d(vi arr)
// {
//     for(auto x:arr){cout<<x<<" ";}
//     cout<<endl;
// }
// void display2d(vii arr)
// {
//     for(auto x:arr)
//     {
//         for(auto y:x)
//         {
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

// vii children;
// vi level;
// vi parent;
// void inputTree(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         int cl;
//         cin>>cl;
//         for(int j=0; j<cl; j++)
//         {
//             int t;
//             cin>>t;
//             children[i].push_back(t);
//         }
//     }
// }


// //we use dfs to find level and parent
// void dfs(int node,int par,int height)
// {
//     parent[node] = par;
//     level[node] = height;
//     height++;
//     for(int c:children[node])
//     {
//         if(c != par)
//         {
//             dfs(c,node,height);
//         }
//     }
//     // height--;

// }

// int lca(int u, int v)
// {
//     if(level[u] > level[v])
//     {
//         swap(u,v);
//     }
//     //assuming level[v] > level[u]
//     while(level[u] != level[v])
//     {
//         v = parent[v];
//     }
//     //after the while loop completion both will be in the 
//     //same level

//     if(u==v)
//     {
//         return u;
//     }
//     while(u != v)
//     {
//         u = parent[u];
//         v = parent[v];
//     }

//     return v;
// }

// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
//     int k =0;
//     while(t--)
//     {
//         k++;
//         cout<<"Case "<<k<<":"<<endl;
//         int n;
//         cin>>n;
//         children.resize(n+1);
//         level.resize(n+1);
//         parent.resize(n+1);

//         inputTree(n);
        
//         dfs(1,0,1);
        
//         int q;
//         cin>>q;
//         while(q--)
//         {
//             int u,v;
//             cin>>u>>v;

//             int ans = lca(u,v);
//             cout<<ans<<endl;
//         }
//     }

// }












// //Lowest Common Ancestor | Binary Lifting (efficient approach)
// //https://www.youtube.com/watch?v=FzOSaw55Tp8&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=2&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>

// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// void display1d(vi arr)
// {
//     for(auto x:arr){cout<<x<<" ";}
//     cout<<endl;
// }
// void display2d(vii arr)
// {
//     for(auto x:arr)
//     {
//         for(auto y:x)
//         {
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }



// vii children;
// vi level;
// vi parent;
// void inputTree(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         int cl;
//         cin>>cl;
//         for(int j=0; j<cl; j++)
//         {
//             int t;
//             cin>>t;
//             children[i].push_back(t);
//         }
//     }
// }


// //we use dfs to find level and parent
// void dfs(int node,int par,int height)
// {
//     parent[node] = par;
//     level[node] = height;
//     height++;
//     for(int c:children[node])
//     {
//         if(c != par)
//         {
//             dfs(c,node,height);
//         }
//     }
//     // height--;

// }

// //inefficient method
// int lca(int u, int v)
// {
//     if(level[u] > level[v])
//     {
//         swap(u,v);
//     }
//     //assuming level[v] > level[u]
//     while(level[u] != level[v])
//     {
//         v = parent[v];
//     }
//     //after the while loop completion both will be in the 
//     //same level

//     if(u==v)
//     {
//         return u;
//     }
//     while(u != v)
//     {
//         u = parent[u];
//         v = parent[v];
//     }

//     return v;
// }


// //efficient method
// int MX = 9;
// vii table;

// void buildTable(vi parent)
// {
//     int n = parent.size();
//     table.resize(MX+1,vi(n+1));

//     // for(int i=0; i<=n; i++)
//     // {
//     //     table[0][i] = parent[i];
//     // }

//     table[0] = parent;

//     for(int i=1; i<=MX; i++)
//     {
//         for(int j=2; j<=n; j++)
//         {
//             int par = table[i-1][j];
//             table[i][j] = table[i-1][par];
//         }
//     }
// }


// //efficient way
// int lcaTable(int u, int v)
// {
//     if(level[u]>level[v])
//     {
//         swap(u,v);
//     }

//     int k = level[v] - level[u];
//     for(int i = MX; i>=0; i--)
//     {
//         int mask = 1<<i;
//         if((k&mask)>0)
//         {
//             v = table[i][v];
//         }
//     }

//     if(u==v)
//     {
//         return u;
//     }

//     for(int i= MX; i>=0; i--)
//     {
//         int up = table[i][u];
//         int vp = table[i][v];
//         if(up != vp)
//         {
//             u = up;
//             v = vp;
//         }

//     }

//     u = parent[u];
//     // while(u != v)
//     // {
//     //     u = parent[u];
//     //     v = parent[v];
//     // }

//     return u;
// }

// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
//     int k =0;
//     while(t--)
//     {
//         k++;
//         cout<<"Case "<<k<<":"<<endl;
//         int n;
//         cin>>n;
//         children.resize(n+1);
//         level.resize(n+1);
//         parent.resize(n+1);

//         inputTree(n);
        
//         dfs(1,0,1);
//         buildTable(parent);
        
//         int q;
//         cin>>q;
//         while(q--)
//         {
//             int u,v;
//             cin>>u>>v;

//             // int ans = lca(u,v);
//             int ans = lcaTable(u,v);
//             cout<<ans<<endl;
//         }
//     }

// }


























// //Lowest Common Ancestor | Binary Lifting (inefficient approach)
// //https://www.youtube.com/watch?v=FzOSaw55Tp8&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=2&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>

// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// void display1d(vi arr)
// {
//     for(auto x:arr){cout<<x<<" ";}
//     cout<<endl;
// }
// void display2d(vii arr)
// {
//     for(auto x:arr)
//     {
//         for(auto y:x)
//         {
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

// vii children;
// vi level;
// vi parent;
// void inputTree(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         int cl;
//         cin>>cl;
//         for(int j=0; j<cl; j++)
//         {
//             int t;
//             cin>>t;
//             children[i].push_back(t);
//         }
//     }
// }


// //we use dfs to find level and parent
// void dfs(int node,int par,int height)
// {
//     parent[node] = par;
//     level[node] = height;
//     height++;
//     for(int c:children[node])
//     {
//         if(c != par)
//         {
//             dfs(c,node,height);
//         }
//     }
//     // height--;

// }

// int lca(int u, int v)
// {
//     if(level[u] > level[v])
//     {
//         swap(u,v);
//     }
//     //assuming level[v] > level[u]
//     while(level[u] != level[v])
//     {
//         v = parent[v];
//     }
//     //after the while loop completion both will be in the 
//     //same level

//     if(u==v)
//     {
//         return u;
//     }
//     while(u != v)
//     {
//         u = parent[u];
//         v = parent[v];
//     }

//     return v;
// }

// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
//     int k =0;
//     while(t--)
//     {
//         k++;
//         cout<<"Case "<<k<<":"<<endl;
//         int n;
//         cin>>n;
//         children.resize(n+1);
//         level.resize(n+1);
//         parent.resize(n+1);

//         inputTree(n);
        
//         dfs(1,0,1);
        
//         int q;
//         cin>>q;
//         while(q--)
//         {
//             int u,v;
//             cin>>u>>v;

//             int ans = lca(u,v);
//             cout<<ans<<endl;
//         }
//     }

// }












// //Lowest Common Ancestor | Binary Lifting (efficient approach)
// //https://www.youtube.com/watch?v=FzOSaw55Tp8&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=2&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>

// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// void display1d(vi arr)
// {
//     for(auto x:arr){cout<<x<<" ";}
//     cout<<endl;
// }
// void display2d(vii arr)
// {
//     for(auto x:arr)
//     {
//         for(auto y:x)
//         {
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }



// vii children;
// vi level;
// vi parent;
// void inputTree(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         int cl;
//         cin>>cl;
//         for(int j=0; j<cl; j++)
//         {
//             int t;
//             cin>>t;
//             children[i].push_back(t);
//         }
//     }
// }


// //we use dfs to find level and parent
// void dfs(int node,int par,int height)
// {
//     parent[node] = par;
//     level[node] = height;
//     height++;
//     for(int c:children[node])
//     {
//         if(c != par)
//         {
//             dfs(c,node,height);
//         }
//     }
//     // height--;

// }

// //inefficient method
// int lca(int u, int v)
// {
//     if(level[u] > level[v])
//     {
//         swap(u,v);
//     }
//     //assuming level[v] > level[u]
//     while(level[u] != level[v])
//     {
//         v = parent[v];
//     }
//     //after the while loop completion both will be in the 
//     //same level

//     if(u==v)
//     {
//         return u;
//     }
//     while(u != v)
//     {
//         u = parent[u];
//         v = parent[v];
//     }

//     return v;
// }


// //efficient method
// int MX = 9;
// vii table;

// void buildTable(vi parent)
// {
//     int n = parent.size();
//     table.resize(MX+1,vi(n+1));

//     // for(int i=0; i<=n; i++)
//     // {
//     //     table[0][i] = parent[i];
//     // }

//     table[0] = parent;

//     for(int i=1; i<=MX; i++)
//     {
//         for(int j=2; j<=n; j++)
//         {
//             int par = table[i-1][j];
//             table[i][j] = table[i-1][par];
//         }
//     }
// }


// //efficient way
// int lcaTable(int u, int v)
// {
//     if(level[u]>level[v])
//     {
//         swap(u,v);
//     }

//     int k = level[v] - level[u];
//     for(int i = MX; i>=0; i--)
//     {
//         int mask = 1<<i;
//         if((k&mask)>0)
//         {
//             v = table[i][v];
//         }
//     }

//     if(u==v)
//     {
//         return u;
//     }

//     for(int i= MX; i>=0; i--)
//     {
//         int up = table[i][u];
//         int vp = table[i][v];
//         if(up != vp)
//         {
//             u = up;
//             v = vp;
//         }

//     }

//     u = parent[u];
//     // while(u != v)
//     // {
//     //     u = parent[u];
//     //     v = parent[v];
//     // }

//     return u;
// }

// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
//     int k =0;
//     while(t--)
//     {
//         k++;
//         cout<<"Case "<<k<<":"<<endl;
//         int n;
//         cin>>n;
//         children.resize(n+1);
//         level.resize(n+1);
//         parent.resize(n+1);

//         inputTree(n);
        
//         dfs(1,0,1);
//         buildTable(parent);
        
//         int q;
//         cin>>q;
//         while(q--)
//         {
//             int u,v;
//             cin>>u>>v;

//             // int ans = lca(u,v);
//             int ans = lcaTable(u,v);
//             cout<<ans<<endl;
//         }
//     }

// }
















// //Cats and Tree | Binary Lifting | Codechef (not efficient)
// // https://www.youtube.com/watch?v=EovPcjgpYxY&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=3&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>
// #define REP(i,a,b) for(int i=a; i<b; i++)
// #define REPeq(i,a,b) for(int i=a; i<=b; i++)

// template<typename T>
// void display1d(T text)
// {
//     for(auto x:text)
//     {
//         std::cout<<x<<" ";
//     }
//     std::cout<<std::endl;
// }

// template<typename T>
// void display2d(std::vector<std::vector<T>> vec)
// {
//     for(auto x:vec)
//     {
//         for(auto y:x)
//         {
//             std::cout<<y<<" ";
//         }
//         std::cout<<std::endl;
//     }
//     std::cout<<std::endl;
// }


// using namespace std;




// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// vii tree;
// vi parent;
// vi climb;


// void catsNTree(int n)
// {
//     vector<bool>occupied(n+1,0);
//     vi result(n+1);

//     // display1d(parent);
//     // display1d(occupied);
//     for(int i=1; i<=n; i++)
//     {   
//         if(occupied[climb[i]] == true)
//         {
//             result[i] = 0;
            
//         }
//         else 
//         {
//             int prev ;
//             int jmp = 0;
//             int c = climb[i];
//             while(occupied[c] == false )
//             {
//                 prev = c;
//                 c = parent[c];
                
//                 jmp++;
//                 if(c == 0)
//                 {
//                     occupied[c]=true;
//                     result[i] = jmp;

//                 }
//                     // cout<<"c: "<<c<<endl;
//                     // cout<<"occupied["<<c<<"]: "<<occupied[c]<<endl;
//                     // cout<<"jmp: "<<jmp<<endl<<endl;
//             }
        
//             occupied[prev] = true;
//             result[i] = jmp;
           

//         }
//     }
//     for(int i=1 ; i<result.size(); i++)
//     {
//         cout<<result[i]<<endl;
//     }
// }


// int main()
// {
//     file_in_out();

//     int n;
//     cin>>n;
//     parent.resize(n+1);
//     climb.resize(n+1);
//     REP(i,1,n+1) {cin>>parent[i];}
//     REP(i,1,n+1) {cin>>climb[i];}
    
//     catsNTree(n);
// }













// //Cats and Tree | Binary Lifting | Codechef (efficient)
// // https://www.youtube.com/watch?v=EovPcjgpYxY&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=3&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>
// #define REP(i,a,b) for(int i=a; i<b; i++)
// #define REPeq(i,a,b) for(int i=a; i<=b; i++)

// template<typename T>
// void display1d(T text)
// {
//     for(auto x:text)
//     {
//         std::cout<<x<<" ";
//     }
//     std::cout<<std::endl;
// }

// template<typename T>
// void display2d(std::vector<std::vector<T>> vec)
// {
//     for(auto x:vec)
//     {
//         for(auto y:x)
//         {
//             std::cout<<y<<" ";
//         }
//         std::cout<<std::endl;
//     }
//     std::cout<<std::endl;
// }


// using namespace std;




// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// vii tree;
// vi parent;
// vi climb;
// vector<bool>occupied;
// //inefficient way
// void catsNTree(int n)
// {
    
//     vi result(n+1);

//     // display1d(parent);
//     // display1d(occupied);
//     //looping for the number of jumps
//     for(int i=1; i<=n; i++)
//     {   
//         if(occupied[climb[i]] == true)
//         {
//             result[i] = 0;
            
//         }
//         else 
//         {
//             int prev ;
//             int jmp = 0;
//             int c = climb[i];
//             while(occupied[c] == false )
//             {
//                 prev = c;
//                 c = parent[c];
                
//                 jmp++;
//                 if(c == 0)
//                 {
//                     occupied[c]=true;
//                     result[i] = jmp;

//                 }
//                     // cout<<"c: "<<c<<endl;
//                     // cout<<"occupied["<<c<<"]: "<<occupied[c]<<endl;
//                     // cout<<"jmp: "<<jmp<<endl<<endl;
//             }
        
//             occupied[prev] = true;
//             result[i] = jmp;
           

//         }
//     }
//     for(int i=1 ; i<result.size(); i++)
//     {
//         cout<<result[i]<<endl;
//     }
// }



// //efficient way
// int MAXBIT = 18;

// vii table;

// void buildTable(int n)
// {
//     table.resize(MAXBIT+1,vi(n+1));
//     table[0] = parent;
//     for(int i=1; i<MAXBIT; i++)
//     {
//         for(int j=2; j<=n; j++)
//         {
//             int p = table[i-1][j];
//             table[i][j] = table[i-1][p];
//         }
//     }
// }

// int cal(int c)
// {
//     int curr = climb[c];
//     if(occupied[curr]) return 0;

//     int j = 1;

//     for(int i=MAXBIT; i>=0; i--)
//     {
//         int jparent = table[i][curr];//2^i parent of curr
//         if(occupied[jparent])
//         {

//         }
//         else 
//         {
//             curr = jparent;
//             j += 1<<i;
//         }
//     }
//     occupied[curr] = true;
//     return j;
// }

// int main()
// {
//     file_in_out();

//     int n;
//     cin>>n;
//     parent.resize(n+1);
//     climb.resize(n+1);
//     occupied.resize(n+1,0);
//     REP(i,1,n+1) {cin>>parent[i];}
//     REP(i,1,n+1) {cin>>climb[i];}

//     //added code
//     occupied[0] = 1;
//     buildTable(n);
//     for(int i=1; i<=n; i++)
//     {
//         int jumps = cal(i);
//         cout<<jumps<<endl;
//     }
// /* inefficient way
//     catsNTree(n);
//     */
// }







// //Longest Good Segment | Codechef (inefficient approach)
// //https://www.youtube.com/watch?v=x84LARr8B3g&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=6&ab_channel=Pepcoding

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>
// #define REP(i,a,b) for(int i=a; i<b; i++)
// #define REPeq(i,a,b) for(int i=a; i<=b; i++)

// template<typename T>
// void display1d(T text)
// {
//     for(auto x:text)
//     {
//         std::cout<<x<<" ";
//     }
//     std::cout<<std::endl;
// }

// template<typename T>
// void display2d(std::vector<std::vector<T>> vec)
// {
//     for(auto x:vec)
//     {
//         for(auto y:x)
//         {
//             std::cout<<y<<" ";
//         }
//         std::cout<<std::endl;
//     }
//     std::cout<<std::endl;
// }


// using namespace std;




// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// vi minStart;

// void minStartCalculation(vi nums, int k, int s)
// {
//     int j = 0, sum = 0;
//     for(int i=0; i<nums.size(); i++)
//     {
//         sum += nums[i];
//         while(sum > s)
//         {
//             sum -=nums[j];
//             j++;
//         }
//         minStart[i] = j-1;
//     }
// }

// int cal(int mx, int k)
// {
//     int mn = mx;
//     for(int i=1; i<=k and mn>-1; i++)
//     {
//         mn = minStart[mn];
//     }
//     return mx-mn;

// }

// void longestGoodSegment(vi nums, int k, int s)
// {
//     minStartCalculation(nums,k,s);
    
//     //now we consider every point as ending point
//     int mx = 0;
//     for(int i = nums.size()-1; i>=0; i--)
//     {
//         //this fn will caculate max no of jumps and 
//         //mx no of elements starting from i towards index 0
//         mx = max(mx,cal(i,k));
//     }
//     cout<<mx<<endl;
// }


// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
  
//     while(t--)
//     {
//         int n,k,s;
//         cin>>n>>k>>s;

//         vi nums(n);
//         REP(i,0,n){cin>>nums[i];}

//         minStart.resize(n);
//         longestGoodSegment(nums,k,s);
//     }
// }










// // //Longest Good Segment | Codechef (Efficient approach)
// // //https://www.youtube.com/watch?v=x84LARr8B3g&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=6&ab_channel=Pepcoding


// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>

// #define vi vector<int>
// #define vii vector<vi>
// #define vs vector<string>
// #define vd vector<double>
// #define vdll vector<long double>
// #define REP(i,a,b) for(int i=a; i<b; i++)
// #define REPeq(i,a,b) for(int i=a; i<=b; i++)

// template<typename T>
// void display1d(T text)
// {
//     for(auto x:text)
//     {
//         std::cout<<x<<" ";
//     }
//     std::cout<<std::endl;
// }

// template<typename T>
// void display2d(std::vector<std::vector<T>> vec)
// {
//     for(auto x:vec)
//     {
//         for(auto y:x)
//         {
//             std::cout<<y<<" ";
//         }
//         std::cout<<std::endl;
//     }
//     std::cout<<std::endl;
// }


// using namespace std;




// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// vi minStart;

// void minStartCalculation(vi nums, int k, int s)
// {
//     int j = 0, sum = 0;
//     for(int i=0; i<nums.size(); i++)
//     {
//         sum += nums[i];
//         while(sum > s)
//         {
//             sum -=nums[j];
//             j++;
//         }
//         minStart[i] = j-1;
//     }
// }


// //efficient approach
// //1≤K≤N≤10^5
// vii table;
// int maxBIT = 20;

// int cal(int mx, int k)
// {
//     int mn = mx;
//     //this will not be used in this efficient approcah
//     // for(int i=1; i<=k and mn>-1; i++)
//     // {
//     //     mn = minStart[mn];
//     // }

//     for(int i=maxBIT; i>=0 and mn>-1; i--)
//     {
//         int mask = 1<<i;
//         if((mask&k) > 0)
//         {
//             mn = table[i][mn];//like dp on the table
//         }

//     }
//     return mx-mn;

// }


// void buildTable(int n)
// {
//      table.resize(maxBIT,vi(n));
//      table[0] = minStart;

//      for(int i=1; i<maxBIT; i++)
//      {
//         for(int j=0; j<n; j++)
//         {
//             int par = table[i-1][j];
//             table[i][j] = par == -1 ? par : table[i-1][par];
//         }
//      }   
// }


// void longestGoodSegment(vi nums, int k, int s, int n)
// {
//     minStartCalculation(nums,k,s);
    
// //optimization
//     buildTable( n);

//     //now we consider every point as ending point
//     int mx = 0;
//     for(int i = nums.size()-1; i>=0; i--)
//     {
//         //this fn will caculate max no of jumps and 
//         //mx no of elements starting from i towards index 0
//         mx = max(mx,cal(i,k));
//     }
//     cout<<mx<<endl;
// }


// int main()
// {
//     file_in_out();

//     int t;
//     cin>>t;
  
//     while(t--)
//     {
//         int n,k,s;
//         cin>>n>>k>>s;

//         vi nums(n);
//         REP(i,0,n){cin>>nums[i];}

//         minStart.resize(n);
//         longestGoodSegment(nums,k,s,n);
//     }
// }











//Tree and Extra Edge
//https://www.youtube.com/watch?v=gVZO-_kTDik&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=6&ab_channel=Pepcoding

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
#include <map>
#include<limits>
#include <cfloat>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)

template<typename T>
void display1d(T text)
{
    for(auto x:text)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
void display2d(std::vector<std::vector<T>> vec)
{
    for(auto x:vec)
    {
        for(auto y:x)
        {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


using namespace std;




void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}


class Pairs
{
public:
    int nbr;
    int w;
    Pairs(){ }
    Pairs(int nbr, int w)
    {
        this->nbr = nbr;
        this->w = w;
    }
};

vector<vector<Pairs>> adj;
vector<long> Node2RootW;
vector<vector<int>> table;
int MAXBIT = 17 ;
vector<long> maxChild;
vi depth;


void inputTree(int n)
{
    adj.resize(n+1);
    //input the edges
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(Pairs(v,w));
        adj[v].push_back(Pairs(u,w));
    }
}

long dfs(int node, long sum, int par)
{
    Node2RootW[node] = sum;
    table[0][node ] = par; //getting 1st parent for each node

    long mx = 0;

    for(Pairs edge:adj[node])
    {
        if(edge.nbr != par)
        {
            depth[edge.nbr] = depth[node] + 1;
           long m = dfs(edge.nbr,sum+edge.w,node);

           int medge = m+edge.w;
           long  t = max(medge,edge.w);
           mx = max(mx,t);
        //    mx = max(mx,0);
        }
    
    }
    maxChild[node] = mx;
    return mx;
}

void buildTable(int n)
{
    for(int j=1; j<=MAXBIT; j++)
    {
        for(int i=1; i<=n; i++)
        {
            int par = table[j-1][i];
            table[j][i] = table[j-1][par];
        }
    }
}

int lca(int u, int v)
{
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }

    int k = depth[v] - depth[u];

    for(int i=MAXBIT; i>=0; i--)
    {
        int mask = 1<<i;
        if((k&mask) > 0)
        {
            v = table[i][v];
        }
    }

    if(u == v) return u;

    for(int i = MAXBIT; i>=0; i--)
    {
        int vp = table[i][v];
        int up = table[i][u];
        if(vp != up)
        {
            u = up;
            v = vp;
        }
    }
    return table[0][u];
}

int main()
{
    file_in_out();

    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        inputTree(n);
        Node2RootW.resize(n+1);
        table.resize(MAXBIT+1,vi(n+1));
        maxChild.resize(n+1);
        depth.resize(n+1);
        //we find the sum from each node to the root
        dfs(1,0,0);

        buildTable(n);
        while(q--)
        {
            int u,v,x;
            cin>>u>>v>>x;

            int lcaval = lca(u,v);
            long lcaSum = Node2RootW[u]-Node2RootW[lcaval] + Node2RootW[v]- Node2RootW[lcaval];
            long esum = maxChild[u] + maxChild[v] + x;
            cout<<max(lcaSum,esum)<<endl;
        }
        
    }

}
