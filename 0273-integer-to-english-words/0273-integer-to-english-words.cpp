class Solution {
public:
        
    string numberToWords(int num) {
        string belowten[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string belowtwenty[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tens[]={"","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        // string majors[]={"Billion","Million","Thousand","Hundred"};
        if(num==0)return "Zero";
        if(num<10){
            return belowten[num];
        }
        if(num<20){
            return belowtwenty[num-10];
        }
        if(num<100){
            if(num%10==0){
                return tens[(num/10)-1];
            }
            return tens[(num/10)-1]+" "+belowten[num%10];
        }
        if(num<1000){
            if(num%100==0){
                return belowten[num/100]+" Hundred";
            }
            return belowten[num/100]+" Hundred "+numberToWords(num%100);
        }
        if(num<1000000){
             if(num%1000==0){
                return numberToWords(num/1000)+" Thousand";
            }
                return numberToWords(num/1000)+" Thousand "+numberToWords(num%1000);
        }
        if(num<1000000000){
            if(num%1000000==0){
                return numberToWords(num/1000000)+" Million";
            }
            return numberToWords(num/1000000)+" Million "+numberToWords(num%1000000);
        }
        if(num%1000000000==0){
                return numberToWords(num/1000000000)+" Billion";
            }
        return numberToWords(num/1000000000)+" Billion "+numberToWords(num%1000000000);
    }
};