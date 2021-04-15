class Solution {
public:
    int getElement(vector<int> & count,int pos)
    {
        long long p =0;
        for(int i=0;i<count.size();i++)
        {
            p+=count[i];
            if(p >= pos)
            {
                return i;
            }
        }
        return -1;
    }
    vector<double> sampleStats(vector<int>& count) {
        double sum=0,mode,median,mean,least=256,largest = -1;
        long long mostoccur =0,n=0;
        for(long long i=0;i<count.size();i++)
        {
            if(count[i] > 0)
            {
                if(i < least)
                    least=i;
                if( i > largest)
                    largest = i;
            }
            sum+=(i*count[i]);
            n+=count[i];
            if(count[i] > mostoccur)
            {
                mostoccur = count[i];
                mode = i;
            }
        }
        if(n&1)
        {
            median = getElement(count,(n+1)/2);
        }
        else
        {
            median = getElement(count,n/2);
            median += getElement(count,n/2 + 1);
            median /=2;
        }
        mean = sum / n;
        vector<double> ans = {least,largest,mean,median,mode};
        return ans;
        
    }
};
