#include <string>
void test(const std::string &input, const std::string &expect);
void testloader(){ //insert test cases here
/*0*/ test( "ADFC", "510" );    
/*1*/ test( "CFDA", "500" );    
/*2*/ test( "AB", "460" );    
/*3*/ test( "BA", "460" );    
/*4*/ test( "CD", "400" );    
/*5*/ test( "DC", "350" );    
/*6*/ test( "BG", "520" );    
/*7*/ test( "GB", "530" );    
/*8*/ test( "FDA", "450" );    
/*9*/ test( "ADF", "450" );    
/*10*/ test( "FDACB", "750" );    
/*11*/ test( "BCADF", "710" );    
/*12*/ test( "EDACB", "800" );    
/*13*/ test( "BCADE", "810" );    
/*14*/ test( "EGFCADE", "920" );    
/*15*/ test( "EDACFGE", "910" );    
/*16*/ test( "ABCDA", "960" );    
/*17*/ test( "ADCBA", "1000" );    
/*18*/ test( "BADCFGB", "1180" );    
/*19*/ test( "BGFCDAB", "1180" );    
/*20*/ test( "CDFC", "460" );    
/*21*/ test( "CFDC", "450" );    
/*22*/ test( "ABGEDA", "1420" );    
/*23*/ test( "ADEGBA", "1470" );    
/*24*/ test( "CFGB", "640" );    
/*25*/ test( "BGFC", "630" );    
/*26*/ test( "ABGEDFC", "1480" );    
/*27*/ test( "CFDEGBA", "1520" );    
/*28*/ test( "CDFGEDABG", "1770" );    
/*29*/ test( "GBADEGFDC", "1680" );
}
