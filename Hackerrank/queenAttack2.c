#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
 #define lll long long

lll min(lll a,lll b){
    if(a<b)return a;
    return b;
}
int main()
{
lll n, i, j, k, q1, q2, c, r;
 
 
 scanf("%lld %lld %lld %lld",&n,&k,&q1,&q2);
lll up = n - q1;
lll down = q1 - 1;
lll right = n - q2;
lll left = q2 - 1;
lll ldiagup = min(up, left);
lll ldiagdn = min(right, down);
lll rdiagup = min(right, up);
lll rdiagdown = min(left, down);
 
for (i = 0; i < k; i++)
{
//cin >> r >> c;
 scanf("%lld %lld",&r,&c);
if (c == q2)
{
if (r < q1)
{
if (q1 - r - 1< down)
down = q1 - r - 1;
 
}
 
if (r > q1)
{
if (r - q1 - 1 < up)
up = r - q1 - 1;
}
}
 
else if (r == q1)
{
if (c < q2)
{
if (q2 - c - 1 < left)
left = q2 - c - 1;
}
 
if (c > q2)
{
if (c - q2 - 1 < right)
right = c - q2 - 1;
}
 
}
 
else if (c + r == q1 + q2)
{
if (r > q1)
{
if (r - q1 - 1 < ldiagup)
ldiagup = r - q1 - 1;
}
 
if (r < q1)
{
if (q1 - r - 1 < ldiagdn)
ldiagdn = q1 - r - 1;
}
}
 
else if (q1 - q2 == r - c)
{
if (c > q2)
{
if (c - q2 - 1 < rdiagup)
rdiagup = c - q2 - 1;
}
 
if (c < q2)
{
if (q2 - c - 1 < rdiagdown)
rdiagdown = q2 - c - 1;
}
}
}
 
 
lll ans = left + right + ldiagup + up + down + ldiagdn + rdiagup + rdiagdown;
 printf("%lld\n",ans);
//cout << ans << endl;
}
