
class Fraction {
public:
	int num = 0, den = 1;

	Fraction(int x, int y)
	{
		int gcd = __gcd(x, y);
		x /= gcd;
		y /= gcd;
		this-> num = x;
		this -> den = y;
	}
    Fraction()
    {
        this->num=0;
        this->den=1;
    }
    Fraction (Fraction &x)
    {
        this->num = x.num;
        this->den =x.den;
    }
	void Add(Fraction y)
	{
		int num = this->num * y.den + y.num * this->den;
		int den = this->den * y.den;
		int gcd = __gcd(abs(num), abs(den));
		num /= gcd;
		den /= gcd;
		this->num = num;
		this->den = den;
	}
	void Subtract(Fraction y)
	{
		int num = this->num * y.den - y.num * this->den;
		int den = this->den * y.den;
		int gcd = __gcd(abs(num), abs(den));
		num /= gcd;
		den /= gcd;
		this->num = num;
		this->den = den;
	}
	void Mulitply(Fraction y)
	{
		int num = this->num * y.num;
		int den = this->den * y.den;
		int gcd = __gcd(num, den);
		num /= gcd;
		den /= gcd;
		this->num = num;
		this->den = den;
	}
};

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return false;
        }
        int sum=0;
        for(auto it: nums)
        {
            sum += it;
        }
        Fraction Average = Fraction(sum,nums.size());
        Fraction temp[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            Fraction tempp =Fraction(nums[i],1);
            tempp.Subtract(Average);
            temp[i]=tempp;
        }
        int firsthalf = nums.size()/2;
        int secondhalf = nums.size() - firsthalf;
        map<pair<int,int>,int> firstMap,secondMap;
        bool flag=false;
        pair<int,int> fall,sall;
        for(int i=1;i<(1<<firsthalf);i++)
        {
            Fraction curr = Fraction(0,1);
            int j=0;
            while(j<firsthalf)
            {
                if((1<<j) & i)
                {
                    curr.Add(temp[j]);
                }
                j++;
            }
            if(curr.num == 0)
            {
                flag=false;
                break;
            }
            pair<int,int> p= {curr.num,curr.den};
            firstMap[p] ++;
            if( i == (1<<firsthalf) - 1)
            {
                fall = p;
            }
        }   
        for(int i=1;i<(1<<secondhalf) ;i++)
        {
            Fraction curr = Fraction(0,1);
            int j=0;
            while(j<secondhalf)
            {
                if((1<<j) & i)
                {
                    curr.Add(temp[firsthalf+j]);
                }
                j++;
            }
            if(curr.num == 0)
            {
                flag=true;
                break;
            }
            pair<int,int> p = {curr.num,curr.den};
            secondMap[p] ++;
            if(i == (1<<secondhalf) - 1)
            {
                sall =p;
            }
        }
        for(auto it: firstMap)
        {
            pair<int,int> req ={-1 * it.first.first,it.first.second};
            auto it1 = secondMap.find(req);
            if(it1 == secondMap.end())
                continue;
            int occur = (*it1).second;
            if(it.first == fall)
            {
                if(req == sall && it.second == 1 && occur == 1)
                {
                    continue;
                }
            }
            flag=true;
        }
        return flag;
    }
};
