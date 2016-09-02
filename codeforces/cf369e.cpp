
LL pw( LL a, LL b ) {
    LL s=1,r=a;
    while ( b ) {
        if ( b&1 ) s=s*r%MOD;
        b>>=1;
        r=r*r%MOD;
    }
    return s;
}

int main() {
    LL n,k;
    R(n,k);
    if ( n<=60 && k>(1LL<<n) ) {
        W(1,1);
        return 0;
    }
    LL p;
    LL q=pw(pw(2,n),k);
    if ( k>=MOD ) {
        p=0;
    } else {
        p=1;
        LL t=pw(2,n)%MOD;
        REP(i,k) p=p*(t-i+MOD)%MOD;
    }
    LL c2=n;
    REP1(i,1,59) c2+=(k-1)>>i;
    dump(p,q,c2);
    p=p*pw(INV2,c2)%MOD;
    q=q*pw(INV2,c2)%MOD;
    p=(q-p+MOD)%MOD;
    W(p,q);
    return 0;
}