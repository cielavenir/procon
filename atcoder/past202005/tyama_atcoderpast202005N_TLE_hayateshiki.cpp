#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>

#define Auto                decltype(auto)
#define local_alloc(T, s)   static_cast<T*>(alloca(s))
#define local_array(T, n)   local_alloc(T, sizeof(T) * n)

namespace HayateShiki {



//

template <class RandomAccessIterator>
inline void sort(RandomAccessIterator const first, RandomAccessIterator const last);

template <class RandomAccessIterator, class Compare>
inline void sort(RandomAccessIterator const first, RandomAccessIterator const last, Compare comp);



//

template <class RandomAccessIterator, class Compare> class Private
{
    private:
        static constexpr std::size_t Bit(int v) noexcept
        {
            return (1ULL << v);
        }
        
        static constexpr std::size_t cbIns = 5;
        static constexpr std::size_t cnIns = Bit(cbIns);
    
    
    
    private:
        template <class ForwardIterator, class ValueType> class Array
        {
            public:
                using val_t = ValueType;
                using ref_t = val_t&;
                using ptr_t = val_t*;
                using itr_t = ptr_t;
                using dif_t = ptrdiff_t;
            
            
            
            private:
                bool mbTemporary;
                dif_t mSize;
                ptr_t mData;
            
            
            
            public:
                ~Array() noexcept
                {
                    if (mbTemporary) ::operator delete(mData, std::nothrow);
                }
                
                
                
                Array(ForwardIterator first, ForwardIterator last)
                :mbTemporary(false)
                ,mSize(std::distance(first, last))
                ,mData(&*first)
                {}
                
                
                
                Array(dif_t Size)
                :mbTemporary(true)
                ,mSize(Size)
                ,mData(static_cast<ptr_t>(::operator new(sizeof(val_t) * Size)))
                {}
                
                
                
                itr_t begin() const noexcept
                {
                    return mData;
                }
                
                
                
                itr_t end() const noexcept
                {
                    return mData + mSize;
                }
            
            
            
            private:
                Array(const Array&) = delete;
                Array& operator =(const Array&) = delete;
        };
    
    
    
    public:
        class Technique {
            private:
                using rai_t = RandomAccessIterator;
                using rai_v = typename std::iterator_traits<rai_t>::value_type;
                
                using itr_t = typename Array<rai_t, rai_v>::itr_t;
                using val_t = typename Array<rai_t, rai_v>::val_t;
                using ref_t = typename Array<rai_t, rai_v>::ref_t;
                using dif_t = typename Array<rai_t, rai_v>::dif_t;
                
                using cmp_t = Compare;
            
            
            
            private:
                const dif_t mnOriginal;
                Array<rai_t, rai_v> maOriginal;
                Array<rai_t, rai_v> maExternal;
                const cmp_t mComp;
            
            
            
            private:
                struct Part
                {
                    enum oRow {
                        oAsc,
                        oDsc,
                        oNum,
                    };
                    
                    itr_t a[oNum];
                    dif_t n[oNum];
                    oRow o;
                };
                
                
                
                struct Unit
                {
                    itr_t a;
                    dif_t n;
                };
                
                
                
                struct Dive
                {
                    Unit mUnit;
                    itr_t miJoin;
                };
            
            
            
            private:
                int Msb(std::size_t v) noexcept
                {
                    if (v){
                        union IEEE_754 {
                            float v;
                            struct {
                                unsigned int fraction:23;
                                unsigned int exponent:8;
                                unsigned int sign:1;
                            } map;
                        };
                        IEEE_754 lzc;
                        lzc.v = v;
                        return (lzc.map.exponent - 127);
                    }
                    return -1;
                }
                
                
                
                int MsbAlignment(std::size_t v) noexcept
                {
                    return Msb(v + v - 1);
                }
                
                
                
                int LowerLimit(int v, int limit) noexcept
                {
                    return (v > limit)? v: limit;
                }
                
                
                
                itr_t Copy(itr_t iDst, itr_t iSrc, dif_t nSrc)
                {
                    while (nSrc--) *iDst++ = std::move(*iSrc++);
                    return iDst;
                }
                
                
                
                itr_t Copy(itr_t iDst, itr_t iSrc, dif_t nSrc, ref_t v)
                {
                    *iDst = std::move(v);
                    return Copy(++iDst, ++iSrc, --nSrc);
                }
                
                
                
                itr_t Join(itr_t iJoin, Unit& rUnit, const Part& rPart)
                {
                    auto nDsc = rPart.n[Part::oDsc];
                    auto nAsc = rPart.n[Part::oAsc];
                    
                    rUnit.a = iJoin;
                    rUnit.n = nDsc + nAsc;
                    
                    iJoin = Copy(iJoin, rPart.a[Part::oDsc], nDsc);
                    iJoin = Copy(iJoin, rPart.a[Part::oAsc], nAsc);
                    return iJoin;
                }
                
                
                
                itr_t Join(itr_t aJoin, Unit& rUnit, const Part& rPart0, const Part& rPart1)
                {
                    auto iJoin = aJoin;
                    auto o0 = rPart0.o;
                    auto o1 = rPart1.o;
                    auto i0 = rPart0.a[o0];
                    auto i1 = rPart1.a[o1];
                    auto n0 = rPart0.n[o0];
                    auto n1 = rPart1.n[o1];
                    auto v0 = std::move(*i0);
                    auto v1 = std::move(*i1);
                    
                    auto Comp = mComp;
                    while (true){
                        if (Comp(v1, v0)){
                            *iJoin++ = std::move(v1);
                            if (--n1){
                                v1 = std::move(*++i1);
                            } else {
                                if (o1){
                                    o1 = Part::oAsc;
                                    i1 = rPart1.a[o1];
                                    n1 = rPart1.n[o1];
                                    v1 = std::move(*i1);
                                } else {
                                    iJoin = Copy(iJoin, i0, n0, v0);
                                    if (o0) iJoin = Copy(iJoin, rPart0.a[Part::oAsc], rPart0.n[Part::oAsc]);
                                    break;
                                }
                            }
                        } else {
                            *iJoin++ = std::move(v0);
                            if (--n0){
                                v0 = std::move(*++i0);
                            } else {
                                if (o0){
                                    o0 = Part::oAsc;
                                    i0 = rPart0.a[o0];
                                    n0 = rPart0.n[o0];
                                    v0 = std::move(*i0);
                                } else {
                                    iJoin = Copy(iJoin, i1, n1, v1);
                                    if (o1) iJoin = Copy(iJoin, rPart1.a[Part::oAsc], rPart1.n[Part::oAsc]);
                                    break;
                                }
                            }
                        }
                    }
                    
                    rUnit.a = aJoin;
                    rUnit.n = std::distance(aJoin, iJoin);
                    return iJoin;
                }
                
                
                
                itr_t Join(itr_t aJoin, Unit& rUnit, const Unit& rUnit0, const Unit& rUnit1)
                {
                    auto iJoin = aJoin;
                    auto i0 = rUnit0.a;
                    auto i1 = rUnit1.a;
                    auto n0 = rUnit0.n;
                    auto n1 = rUnit1.n;
                    auto v0 = std::move(*i0);
                    auto v1 = std::move(*i1);
                    
                    auto Comp = mComp;
                    while (true){
                        if (Comp(v1, v0)){
                            *iJoin++ = std::move(v1);
                            if (--n1){
                                v1 = std::move(*++i1);
                            } else {
                                iJoin = Copy(iJoin, i0, n0, v0);
                                break;
                            }
                        } else {
                            *iJoin++ = std::move(v0);
                            if (--n0){
                                v0 = std::move(*++i0);
                            } else {
                                iJoin = Copy(iJoin, i1, n1, v1);
                                break;
                            }
                        }
                    }
                    
                    rUnit.a = aJoin;
                    rUnit.n = std::distance(aJoin, iJoin);
                    return iJoin;
                }
                
                
                
                itr_t Ascending(itr_t iSrc, itr_t eSrc, dif_t nSrc)
                {
                    auto nIns = (nSrc < cnIns)? nSrc: cnIns;
                    auto aIns = iSrc - 1;
                    auto eIns = iSrc + nIns;
                    
                    auto Comp = mComp;
                    while (++iSrc != eIns){
                        if (Comp(iSrc[0], iSrc[-1])){
                            auto i = iSrc;
                            auto v = std::move(i[0]);
                            do {
                                i[0] = std::move(i[-1]);
                            } while (--i != aIns && Comp(v, i[-1]));
                            i[0] = std::move(v);
                        }
                    }
                    
                    for (; (iSrc != eSrc) && !Comp(iSrc[0], iSrc[-1]); ++iSrc);
                    return iSrc;
                }
                
                
                
                itr_t Descending(itr_t iSrc, itr_t eSrc, dif_t nSrc)
                {
                    auto nIns = (nSrc < cnIns)? nSrc: cnIns;
                    auto aIns = iSrc - 1;
                    auto eIns = iSrc + nIns;
                    
                    auto Comp = mComp;
                    while (++iSrc != eIns){
                        if (!Comp(iSrc[0], iSrc[-1])){
                            auto i = iSrc;
                            auto v = std::move(i[0]);
                            do {
                                i[0] = std::move(i[-1]);
                            } while (--i != aIns && !Comp(v, i[-1]));
                            i[0] = std::move(v);
                        }
                    }
                    
                    for (; (iSrc != eSrc) && Comp(iSrc[0], iSrc[-1]); ++iSrc);
                    
                    std::reverse(aIns, iSrc);
                    return iSrc;
                }
                
                
                
                dif_t MakePart(Part& rPart, itr_t& riSrc, itr_t eSrc, itr_t& raDsc)
                {
                    auto iSrc = riSrc;
                    auto aAsc = iSrc;
                    auto eAsc = eSrc;
                    auto Comp = mComp;
                    
                    {   //
                        Auto nSrc = std::distance(iSrc, eSrc);
                        if (nSrc > 1){
                            if (Comp(iSrc[1], iSrc[0])){
                                eAsc = Descending(iSrc+1, eSrc, nSrc-1);
                            } else {
                                eAsc = Ascending(iSrc+1, eSrc, nSrc-1);
                            }
                        }
                    }
                    
                    {   //
                        auto aDsc = raDsc;
                        auto eDsc = aDsc;
                        
                        auto iOdd = eAsc;
                        auto nOdd = std::distance(iOdd, eSrc);
                        if (nOdd){
                            if (Comp(*iOdd, aAsc[0]/*Min*/)){
                                *--aDsc = std::move(*iOdd++);
                                
                                while (--nOdd){
                                    if (Comp(*iOdd, eAsc[-1]/*Max*/)){
                                        if (Comp(*iOdd, aDsc[0]/*Min*/)){
                                            *--aDsc = std::move(*iOdd++);
                                        } else {
                                            break;
                                        }
                                    } else {
                                        *eAsc++ = std::move(*iOdd++);
                                    }
                                }
                            }
                        }
                        
                        {   //
                            Auto nDsc = std::distance(aDsc, eDsc);
                            rPart.a[Part::oAsc] = aAsc;
                            rPart.n[Part::oAsc] = std::distance(aAsc, eAsc);
                            rPart.a[Part::oDsc] = aDsc;
                            rPart.n[Part::oDsc] = nDsc;
                            rPart.o = (nDsc)? Part::oDsc: Part::oAsc;
                        }
                        
                        riSrc = iOdd;
                        raDsc = aDsc;
                        return nOdd;
                    }
                }
                
                
                
                void Turn(itr_t iDst, itr_t iSrc, dif_t nSrc)
                {
                    iDst += nSrc;
                    iSrc += nSrc;
                    while (nSrc--) *--iDst = std::move(*--iSrc);
                }
                
                
                
                void Turn(const Part& rPart)
                {
                    auto nDsc = rPart.n[Part::oDsc];
                    auto nAsc = rPart.n[Part::oAsc];
                    auto aDsc = maOriginal.begin();
                    auto aAsc = aDsc + nDsc;
                    
                    if (nDsc){
                        Turn(aAsc, rPart.a[Part::oAsc], nAsc);
                        Turn(aDsc, rPart.a[Part::oDsc], nDsc);
                    }
                }
            
            
            
            public:
                ~Technique() noexcept
                {}
                
                
                
                Technique(rai_t const first, rai_t const last, cmp_t comp)
                :mnOriginal(std::distance(first, last))
                ,maOriginal(first, last)
                ,maExternal(mnOriginal)
                ,mComp(comp)
                {}
                
                
                
                void Sort()
                {
                    if (mnOriginal > 1){
                        Auto nDive = LowerLimit((MsbAlignment(mnOriginal) - cbIns), 1);
                        Auto aDive = local_array(Dive, (nDive+1));
                        for (int oDive = 0; oDive < nDive; ++oDive) aDive[oDive].miJoin = (oDive & Bit(0))? maExternal.begin(): maOriginal.begin();
                        
                        {   //
                            std::size_t nJoin = 0;
                            
                            {   //
                                auto iJoin = maExternal.begin();
                                
                                Auto iSrc = maOriginal.begin();
                                Auto eSrc = maOriginal.end();
                                while (iSrc != eSrc){
                                    Unit vUnit;
                                    
                                    {   //
                                        Part vPart0, vPart1;
                                        auto aDsc = maExternal.end();
                                        if (MakePart(vPart0, iSrc, eSrc, aDsc)){
                                            MakePart(vPart1, iSrc, eSrc, aDsc);
                                            iJoin = Join(iJoin, vUnit, vPart0, vPart1);
                                        } else {
                                            if (nJoin){
                                                iJoin = Join(iJoin, vUnit, vPart0);
                                            } else {
                                                Turn(vPart0);
                                                break;
                                            }
                                        }
                                    }
                                    
                                    {   //
                                        auto pDive = &aDive[0];
                                        auto Carry = nJoin++;
                                        Carry = (nJoin ^ Carry) & Carry;
                                        for (; Carry; Carry >>= 1, ++pDive){
                                            pDive->miJoin = Join(pDive->miJoin, vUnit, pDive->mUnit, vUnit);
                                        }
                                        pDive->mUnit = vUnit;
                                    }
                                }
                            }
                            
                            if (nJoin){
                                auto bJoin = nJoin & -nJoin;
                                auto oDive = Msb(bJoin);
                                auto pResult = &aDive[oDive++];
                                
                                {   //
                                    auto pDive = &aDive[oDive];
                                    auto Carry = nJoin ^ bJoin;
                                    Carry >>= oDive;
                                    for (; Carry; Carry >>= 1, ++pDive){
                                        if (Carry & Bit(0)){
                                            Join(pDive->miJoin, pResult->mUnit, pDive->mUnit, pResult->mUnit);
                                        }
                                    }
                                }
                                
                                if (pResult->mUnit.a == maExternal.begin()){
                                    Copy(maOriginal.begin(), pResult->mUnit.a, pResult->mUnit.n);
                                }
                            }
                        }
                    }
                }
        };
    
    
    
    public:
        static void Sort(RandomAccessIterator const first, RandomAccessIterator const last, Compare comp)
        {
            Technique(first, last, comp).Sort();
        }
};



template <class RandomAccessIterator>
inline void sort(RandomAccessIterator const first, RandomAccessIterator const last)
{
    HayateShiki::sort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}



template <class RandomAccessIterator, class Compare>
inline void sort(RandomAccessIterator const first, RandomAccessIterator const last, Compare comp)
{
    HayateShiki::Private<RandomAccessIterator, Compare>::Sort(first, last, comp);
}
}

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	std::vector<int>a(N);
	for(int i=0;i<N;i++)a[i]=i+1;
	int lastx=0;
	for(;Q--;){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		x--;y--;
		if(t==1)std::swap(a[x],a[x+1]);
		if(t==2){
			//std::sort(a.begin()+x,a.begin()+y+1);
			HayateShiki::sort(a.begin()+x,a.begin()+y+1);
		}
	}
	for(auto &e:a)printf("%d ",e);
}
