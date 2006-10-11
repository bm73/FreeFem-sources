
template<class R>  
KNM_<R> & KNM_<R>::operator oper (const outProduct_KN_<R> & u)  
{
  //   *this  oper  A* t B 
    K_throwassert (shapei.SameShape(u.a) && shapej.SameShape(u.b) );
    long n= N(), m= M();
    
    R * ai(u.a),*aai=ai,cc, c= u.c;
    long stepi=u.a.step;
    R * bj, *bb(u.b);
    long stepj=u.b.step;
    KN_<const_R>  li((*this)(0,'.')); //  first line
    int stepij= li.step;
    for (long i=0;i<n;i++,ai += stepi,++li)
      {
        cc= c * *ai;
        R * mij = li;
        bj = bb;
        for (long j=0;   j<m; j++, bj += stepj, mij += stepij )         
          *mij oper cc * conj(*bj) ; 
       }
    return *this;
 }


template<class R>
template<class  A,class B,class C>
 KN_<R>& KN_<R>::operator oper (const F_KN_<A,B,C> & u)  {
    K_throwassert ( u.check(this->N()) );
    R * l(v);  //  first line   
    for (long i=0;i<n;i++,l += step)  
      *l oper  u[i]; 
    return *this;}

  
template<class R>
 KN_<R>& KN_<R>::operator oper (const Mul_KNM_KN_<R> & u)  {
    K_throwassert (SameShape(u.A.shapei) && !constant());
    R * l(v); KN_<const_R>  li(u.A(0,'.')); //  first line   
    for (long i=0;i<n;i++,l += step,++li)  
      *l oper (li,u.b); 
    return *this;}


template<class R>
 KN_<R>&  KN_<R>::operator oper (const DotStar_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    long stepa(u.a.step),stepb(u.b.step);
    R * l(v); const_R  *aa(u.a), *bb(u.b);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb)
      *l oper *aa * *bb;
    return *this;
  }
template<class R>
 KN_<R>&  KN_<R>::operator oper (const DotSlash_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    long stepa(u.a.step),stepb(u.b.step);
    R * l(v); const_R  *aa(u.a), *bb(u.b);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb)
      *l oper *aa / *bb;
    return *this;
  }

  
template<class R>
 KN_<R>&  KN_<R>::operator oper (const Add_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    long stepa(u.a.step),stepb(u.b.step);
    R * l(v); const_R  *aa(u.a), *bb(u.b);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb)
      *l oper *aa+*bb;
    return *this;
  }

template<class R>
 KN_<R>&  KN_<R>::operator oper (const Sub_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    long stepa(u.a.step),stepb(u.b.step);
    R * l(v); const_R  *aa(u.a), *bb(u.b);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb)
      *l oper  *aa-*bb;
    return *this;
  }
  
template<class R>
 KN_<R>&  KN_<R>::operator oper (const Mulc_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    long stepa(u.a.step);
    R * l(v); const_R  *aa(u.a),bb(u.b)  ;
    for (long i=0;i<n;i++,l += step, aa +=stepa)
      *l oper *aa * bb;
    return *this;
  }
  
template<class R>
 KN_<R>&  KN_<R>::operator oper (const Add_Mulc_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    const long stepa(u.a.step),stepb(u.b.step);
    const R ca(u.ca),cb(u.cb);    
    R * l(v);
    const R *aa(u.a),*bb(u.b);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb)
      *l oper *aa*ca + *bb*cb;
    return *this;
  }

template<class R>
 KN_<R>&  KN_<R>::operator oper (const if_arth_KN_<R> & u) {
    K_throwassert(u.a.N() == N()  );
    R zero=R();
    const long stepa(u.a.step),stepb(u.b.step),stepc(u.c.step);
    R * l(v);
    const R *aa(u.a),*bb(u.b),*cc(u.c);    
    for (long i=0;i<n;i++,l += step, aa +=stepa, bb += stepb ,  cc += stepc)
      *l oper ( (*aa != zero) ?  *bb : *cc);
    return *this;
  }
