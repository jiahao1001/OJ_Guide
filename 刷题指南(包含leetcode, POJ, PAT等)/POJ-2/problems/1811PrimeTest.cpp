#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
typedef long long LL;
int S = 8;
LL gcd(LL a,LL b){
    if(!b) return a;
    return gcd(b,a%b);
}
LL mul(LL a,LL b,LL M){
    LL res = 0;
    a %= M;
    while( b ){
        if( b & 1 ){
            res += a;
            if( res >= M ) res -= M;
        }
        a <<= 1;
        if( a >= M ) a -= M;
        b >>= 1;
    } 
    return res;
}
// a ^ b mod M
LL fast_mod( LL a, LL b, LL M ){
    LL res = 1;
    while( b ){
        if( b & 1 ) res = mul( res, a, M );
        a = mul( a, a, M );
        b >>= 1;
    }
    return res;
}

bool miller_rabin( LL n ){
    if( n < 2 )	return false;
    if( n == 2 ) return true;
    if( !( n & 1 ) ) return false;
    int t = 0;
    LL cur, pre, u = n - 1;
    while( !( u & 1 ) ){
        t++;
        u >>= 1;
    }
    
    for( int i = 0; i < S; ++i ){
        LL a = rand() % ( n - 2 ) + 2;
        if( ( a % n ) == 0 ) continue;
        cur = fast_mod( a, u, n );
        pre = cur;
        for( int j = 0; j < t; ++j ){
            cur = mul( pre, pre, n );
            if( cur == 1 && pre != 1 && pre != n - 1 )
                return false;
            pre = cur;
        }	
        if( cur != 1 ) return false;
    }
    return true;	
}
LL pollard_rho( LL n, LL c ){
    LL x, y, i = 1, k = 2, d;
    x = rand() % ( n - 1 ) + 1;
    y = x;
    while( true ){
        i++;
        x = ( mul( x, x, n ) + c ) % n;
        d = gcd( y - x + n, n );
        if( d > 1 && d < n ) return d;
        if( x == y ) 	return n;
        if( i == k ){
            y = x, k <<= 1;
        }
    }
}

LL fa[ 100000 ], cnt;
void fac( LL x ){
    if( miller_rabin( x ) ){
        fa[ cnt++ ] = x;
    }else{
        LL p = x;
        while( p >= x ){
            p = pollard_rho( p, (LL)( rand() % ( x - 1 ) + 1 ) );
        }
        fac( p );
        fac( x / p );
    }
}
int main(){
    LL t, n;
    scanf( "%lld", &t );
    while( t-- ){
        scanf( "%lld", &n );
        cnt = 0;
        if( miller_rabin( n ) ){
            puts( "Prime" );
        }else{
            fac( n );
            LL ans = fa[0];
            for( int i = 1; i < cnt; ++i ){
                if( ans > fa[i] ){
                    ans = fa[i];
                }
            }
            printf( "%lld\n", ans );
        }
    }	
    return 0;
}
