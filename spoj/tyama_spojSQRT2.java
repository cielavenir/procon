import java.math.BigDecimal;
import java.math.MathContext;
class Main{
	public static BigDecimal sqrt(BigDecimal a, int scale){
		BigDecimal x = new BigDecimal(Math.sqrt(a.doubleValue()), MathContext.DECIMAL64);
		if(scale<17)return x;

		BigDecimal b2 = new BigDecimal(2);
		for(int tempScale = 16; tempScale < scale; tempScale *= 2){
			//x = x - (x * x - a) / (2 * x);
			x = x.subtract(
				x.multiply(x).subtract(a).divide(x.multiply(b2), Math.min(scale, tempScale * 2), BigDecimal.ROUND_HALF_EVEN));
		}	
		return x;
	}
	public static void main(String[] args){
		System.out.println(sqrt(new BigDecimal(2), 60000));
	}
}